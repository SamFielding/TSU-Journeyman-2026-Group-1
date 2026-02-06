#include "LockOn.h"
#include "Camera/CameraComponent.h"
#include "LockOnTarget.h"
#include "Engine/OverlapResult.h"
#include "GameFramework/Actor.h"


ULockOn::ULockOn()
{
	PrimaryComponentTick.bCanEverTick = true;
}


void ULockOn::OnLockOnPressed()
{
	//LockOnNearest();

	CameraTransform = Camera->GetRelativeTransform();
	Camera->SetWorldTransform(InitialCameraTransform);

	if(APlayerController* Controller = Cast<APlayerController>(GetOwner()->GetInstigatorController()))
	{
		Controller->SetIgnoreLookInput(Target != nullptr);
	}
}


void ULockOn::OnLockOnReleased()
{
	ClearLockOn();

	if(APlayerController* Controller = Cast<APlayerController>(GetOwner()->GetInstigatorController()))
	{
		Controller->SetIgnoreLookInput(false);
	}
	Camera->SetRelativeTransform(CameraTransform);
}


void ULockOn::OnSwitchTarget(const FVector2D& Input)
{
	if (!Target)
		return;

	SwitchTarget(Input);
}


void ULockOn::FindAvailable()
{
	Available.Empty();

	const FVector Location = GetOwner()->GetActorLocation();
	TArray<FOverlapResult> Overlaps;

	FCollisionShape Sphere = FCollisionShape::MakeSphere(Range);
	GetWorld()->OverlapMultiByObjectType(Overlaps, Location, FQuat::Identity, FCollisionObjectQueryParams(ECollisionChannel::ECC_WorldDynamic), Sphere);

	for (const FOverlapResult& Overlap : Overlaps)
	{
		UE_LOG(LogTemp, Warning, TEXT("Overlap: %s"), *Overlap.GetActor()->GetName());

		AActor* OverlapedActor = Overlap.GetActor();
		if (!OverlapedActor)
			continue;

		if(ULockOnTarget* LockOnTarget = OverlapedActor->FindComponentByClass<ULockOnTarget>())
		{
			Available.Add(LockOnTarget);
		}
	}
}


void ULockOn::LockOnNearest()
{
	FindAvailable();

	if(Available.IsEmpty())
		return;

	const FVector Location = GetOwner()->GetActorLocation();

	Available.Sort([Location](const ULockOnTarget& A, const ULockOnTarget& B)
	{
		return FVector::DistSquared(Location, A.GetTargetLocation()) < FVector::DistSquared(Location, B.GetTargetLocation());
	});

	Target = Available[0];
}


void ULockOn::ClearLockOn()
{
	Target = nullptr;
	Available.Empty();
}


void ULockOn::UpdateCameraRotation(float DeltaTime)
{
	if(!Camera || !Target)
		return;

	const FVector CameraLocation = Camera->GetComponentLocation();
	const FRotator CameraRotation = Camera->GetComponentRotation();

	const FVector TargetLocation = Target->GetTargetLocation();
	const FRotator ToTarget = (TargetLocation - CameraLocation).Rotation();

	const FRotator NewRotation = FMath::RInterpTo(CameraRotation, ToTarget, DeltaTime, CameraRotationSpeed);

	Camera->SetWorldRotation(NewRotation);
}


void ULockOn::SwitchTarget(const FVector2D& Input)
{
	FindAvailable();

	if(FMath::Abs(Input.X) < SwitchTargetDeadzone || Available.IsEmpty())
		return;

	ULockOnTarget* BestTarget = nullptr;
	float BestScore = -1.f;

	for (ULockOnTarget* AvailableTarget : Available)
	{
		if (AvailableTarget == Target)
			continue;

		const FVector Dir = (AvailableTarget->GetTargetLocation() - GetOwner()->GetActorLocation()).GetSafeNormal();

		if (FMath::Sign(FVector::DotProduct(GetOwner()->GetActorRightVector(), Dir)) == FMath::Sign(Input.X))
		{
			if (FVector::DotProduct(GetOwner()->GetActorForwardVector(), Dir) > BestScore)
			{
				BestScore = FVector::DotProduct(GetOwner()->GetActorForwardVector(), Dir);
				BestTarget = AvailableTarget;
			}
		}
	}

	if (BestTarget)
		Target = BestTarget;
}


void ULockOn::BeginPlay()
{
	Super::BeginPlay();

	Camera = GetOwner()->FindComponentByClass<UCameraComponent>();
	InitialCameraTransform = Camera->GetRelativeTransform();
	ensureMsgf(Camera, TEXT("No CameraComponent found on actor with LockOn"));
}


void ULockOn::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	UpdateCameraRotation(DeltaTime);
}
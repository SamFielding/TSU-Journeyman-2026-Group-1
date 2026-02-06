#include "SF_CPP_TIMEPICKUP.h"
#include "SF_CPP_PLAYERTIME.h"

// Sets default values
ASF_CPP_TIMEPICKUP::ASF_CPP_TIMEPICKUP()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	Mesh->SetupAttachment(RootComponent);

	Collider = CreateDefaultSubobject<USphereComponent>(TEXT("Collision"));
	Collider->SetGenerateOverlapEvents(true);
	Collider->SetupAttachment(RootComponent);
}

void ASF_CPP_TIMEPICKUP::CollectTime(USF_CPP_PLAYERTIME* SF_CPP_PLAYERTIMEComponent)
{
	if (!SF_CPP_PLAYERTIMEComponent)
		return;

	if (bIsMoving)
		return;

	Target = SF_CPP_PLAYERTIMEComponent;
	bIsMoving = true;

	SetActorEnableCollision(false);
}

// Called when the game starts or when spawned
void ASF_CPP_TIMEPICKUP::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASF_CPP_TIMEPICKUP::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	if (!bIsMoving)
	{
		SetActorRotation(GetActorRotation() + FRotator(0.f, RotationRate * DeltaTime, 0.f));
		SetActorLocation(GetActorLocation() + FVector(0.f, 0.f, FMath::Sin(GetWorld()->GetTimeSeconds() * 2.f * PI * OscillationFrequency) * OscillationAmplitude * DeltaTime));
	}

	if (!Target)
		return;

	FVector Direction = (Target->GetCollectionPointLocation() - GetActorLocation()).GetSafeNormal();
	FVector NewLocation = GetActorLocation() + Direction * AttractionStrength * DeltaTime;

	SetActorLocation(NewLocation);

	if (FVector::Dist(NewLocation, Target->GetCollectionPointLocation()) < 10.f)
	{
		Target->AddTime(TimeValue);
		Destroy();
	}

}


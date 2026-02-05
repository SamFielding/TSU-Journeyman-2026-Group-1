// Fill out your copyright notice in the Description page of Project Settings.


#include "CurrencyPickup.h"
#include "Components/SphereComponent.h"
#include "CurrencyManager.h"

// Sets default values
ACurrencyPickup::ACurrencyPickup()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(RootComponent);

	Collision = CreateDefaultSubobject<USphereComponent>(TEXT("Collision"));
	Collision->SetupAttachment(RootComponent);
}


void ACurrencyPickup::CollectCurrency(UCurrencyManager* CurrencyManagerComponent)
{
	if (!CurrencyManagerComponent)
		return;

	if (bIsMoving)
		return;

	Target = CurrencyManagerComponent;
	bIsMoving = true;

	SetActorEnableCollision(false);
}

// Called when the game starts or when spawned
void ACurrencyPickup::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ACurrencyPickup::Tick(float DeltaTime)
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
		Target->AddCurrency(CurrencyValue);
		Destroy();
	}
}


// Fill out your copyright notice in the Description page of Project Settings.


#include "CurrencyPickup.h"
#include "Components/SphereComponent.h"
#include "CurrencyManager.h"

ACurrencyPickup::ACurrencyPickup()
{
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

void ACurrencyPickup::BeginPlay()
{
	Super::BeginPlay();

}

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

	TimeSinceCollected += DeltaTime;
	float VelocityCoefficient = FMath::Pow(3.f * TimeSinceCollected, 3.f * TimeSinceCollected) - 1;
	FVector Direction = (Target->GetCollectionPointLocation() - GetActorLocation()).GetSafeNormal();
	FVector NewLocation = GetActorLocation() + Direction * AttractionStrength * VelocityCoefficient * DeltaTime;

	SetActorLocation(NewLocation);

	if (FVector::Dist(NewLocation, Target->GetCollectionPointLocation()) <= AttractionStrength * VelocityCoefficient * DeltaTime)
	{
		Target->AddCurrency(CurrencyValue);
		Destroy();
	}
}


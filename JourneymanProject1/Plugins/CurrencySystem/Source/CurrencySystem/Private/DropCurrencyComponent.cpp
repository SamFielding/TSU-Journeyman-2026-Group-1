// Fill out your copyright notice in the Description page of Project Settings.


#include "DropCurrencyComponent.h"

UDropCurrencyComponent::UDropCurrencyComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}


void UDropCurrencyComponent::DropCurrency(FTransform SpawnTransform)
{
	for (const TSubclassOf<ACurrencyPickup>& Drop : Drops)
	{
		if (!Drop)
			continue;

		FVector Offset = FVector(
			FMath::FRandRange(-50.f, 50.f),
			FMath::FRandRange(-50.f, 50.f),
			0.f
		);

		FTransform SpawnLocation = SpawnTransform;
		SpawnLocation.SetLocation(SpawnTransform.GetLocation() + Offset);

		GetWorld()->SpawnActor<ACurrencyPickup>(Drop, SpawnLocation);
	}
}


void UDropCurrencyComponent::BeginPlay()
{
	Super::BeginPlay();
}


void UDropCurrencyComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}


// Fill out your copyright notice in the Description page of Project Settings.


#include "DropCurrencyComponent.h"

// Sets default values for this component's properties
UDropCurrencyComponent::UDropCurrencyComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
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

// Called when the game starts
void UDropCurrencyComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...

}


// Called every frame
void UDropCurrencyComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}


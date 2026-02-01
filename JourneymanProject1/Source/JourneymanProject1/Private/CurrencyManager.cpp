// Fill out your copyright notice in the Description page of Project Settings.


#include "CurrencyManager.h"

// Sets default values for this component's properties
UCurrencyManager::UCurrencyManager()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UCurrencyManager::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

// Called every frame
void UCurrencyManager::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}


FVector UCurrencyManager::GetCollectionPointLocation() const
{
	return GetComponentLocation();
}

void UCurrencyManager::AddCurrency(int32 Amount)
{
	CurrencyAmount += Amount;
}


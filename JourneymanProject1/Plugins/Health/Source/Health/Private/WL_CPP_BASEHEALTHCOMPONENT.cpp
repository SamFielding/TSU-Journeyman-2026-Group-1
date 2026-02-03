// Fill out your copyright notice in the Description page of Project Settings.


#include "WL_CPP_BASEHEALTHCOMPONENT.h"

// Sets default values for this component's properties
UWL_CPP_BASEHEALTHCOMPONENT::UWL_CPP_BASEHEALTHCOMPONENT()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UWL_CPP_BASEHEALTHCOMPONENT::BeginPlay()
{
	Super::BeginPlay();

	// ...
	CurrentHealth = FMath::Clamp(CurrentHealth, 1.0f, MaxHealth);
}


// Called every frame
void UWL_CPP_BASEHEALTHCOMPONENT::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}


// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "JourneymanProject1/Public/EnumStates.h"
#include "Components/ActorComponent.h"
#include "StateMachineComponent.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnCombatStateEnter, ECombatState, OldState, ECombatState, NewState);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnCombatStateEnter, ECombatState, OldState, ECombatState, NewState);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class JOURNEYMANPROJECT1_API UStateMachineComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UStateMachineComponent();

	UPROPERTY(BlueprintAssignable, Category = "State Machine")
	FOnCombatStateEnter OnCombatStateEnter;

	UFUNCTION(BlueprintCallable)
	void ChangeCombatState(ECombatState OldState,ECombatState NewState);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};

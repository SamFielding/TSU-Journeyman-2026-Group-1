// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Math/UnrealMathUtility.h"
#include "Components/ActorComponent.h"
#include "WL_CPP_BASEHEALTHCOMPONENT.generated.h"




DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnTakenDamage);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class	HEALTH_API UWL_CPP_BASEHEALTHCOMPONENT : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UWL_CPP_BASEHEALTHCOMPONENT();


	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Set Max Health")
	float MaxHealth = 100.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Set Current Health")
	float CurrentHealth = MaxHealth;

	UPROPERTY(BlueprintAssignable, Category = "Damage Event")
	FOnTakenDamage OnTakenDamage;

	UFUNCTION(BlueprintPure, Category = "Life State", meta = (ToolTip = " Checks if actor still has health remaining"))
	bool isAlive()
	{	
		return (CurrentHealth > 0);
	}

	UFUNCTION(BlueprintCallable, Category = "Current Health Status", meta = (ToolTip = "- Damages the actor by a specified amount"))
	void TakeDamage(float Damage)
	{
		CurrentHealth = FMath::Clamp(CurrentHealth - Damage, 0.f, MaxHealth);
		UE_LOG(LogTemp, Warning, TEXT("OW"));
		OnTakenDamage.Broadcast();
	}
	


	UFUNCTION(BlueprintCallable, Category = "Current Health Status", meta = (ToolTip = "+ Heals the actor by a specified amount"))
	void Heal(float Increment)
	{
		CurrentHealth = FMath::Clamp(CurrentHealth + Increment, 0.f, MaxHealth);
	}


	UFUNCTION(BlueprintCallable, Category = "Max Health Status", meta = (ToolTip = "+ Increases the actors MAXIMUM Health by a specified amount"))
	void IncreaseMaxHealth(float Increment)
	{
		MaxHealth += Increment;
	}

	UFUNCTION(BlueprintCallable, Category = "Max Health Status", meta = (ToolTip = "- Decreases the actors MAXIMUM Health by a specified amount"))
	void DecreaseMaxHealth(float Decrement)
	{
		MaxHealth += Decrement;
	}
	




protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};

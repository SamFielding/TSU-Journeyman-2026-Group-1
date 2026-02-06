// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CurrencyPickup.h"
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DropCurrencyComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CURRENCYSYSTEM_API UDropCurrencyComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UDropCurrencyComponent();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Currency Dropping")
	TArray<TSubclassOf<ACurrencyPickup>> Drops;

	UFUNCTION(BlueprintCallable, Category = "Currency Dropping")
	void DropCurrency(FTransform SpawnTransform);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};

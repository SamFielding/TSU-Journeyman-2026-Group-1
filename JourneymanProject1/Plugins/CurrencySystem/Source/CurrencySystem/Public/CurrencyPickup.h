// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/SphereComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CurrencyPickup.generated.h"

class UCurrencyManager;

UCLASS(Abstract)
class CURRENCYSYSTEM_API ACurrencyPickup : public AActor
{
	GENERATED_BODY()

public:
	ACurrencyPickup();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Currency Pickup")
	int32 CurrencyValue;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Currency Pickup")
	float RotationRate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Currency Pickup")
	float OscillationFrequency;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Currency Pickup")
	float OscillationAmplitude;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Currency Pickup")
	float AttractionStrength;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Currency Pickup")
	TObjectPtr<UStaticMeshComponent> Mesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Currency Pickup")
	TObjectPtr<USphereComponent> Collision;

	UFUNCTION()
	void CollectCurrency(UCurrencyManager* CurrencyManagerComponent);

	UPROPERTY()
	UCurrencyManager* Target = nullptr;

	UPROPERTY()
	bool bIsMoving = false;

	UPROPERTY()
	float TimeSinceCollected = 0.f;

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

};

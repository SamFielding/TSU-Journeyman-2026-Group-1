// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CurrencyPickup.generated.h"

class UCurrencyManager;

UCLASS(Abstract)
class JOURNEYMANPROJECT1_API ACurrencyPickup : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
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

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Currency Pickup")
	TObjectPtr<UShapeComponent> Collision;

	UFUNCTION()
	void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor,
		class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UPROPERTY()
	UCurrencyManager* Target = nullptr;

	UPROPERTY()
	bool bIsMoving = false;

	UFUNCTION()
	UCurrencyManager* GetCurrencyManager(AActor* Actor) const;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};

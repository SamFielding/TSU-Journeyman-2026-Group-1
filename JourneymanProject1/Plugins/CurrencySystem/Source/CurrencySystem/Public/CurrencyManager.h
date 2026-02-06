// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CurrencyPickup.h"
#include "Components/SphereComponent.h"
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CurrencyManager.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CURRENCYSYSTEM_API UCurrencyManager : public USphereComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCurrencyManager();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Currency")
	int32 CurrencyAmount;

	UFUNCTION()
	void OnBeginOverlap(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor,
		class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	FVector GetCollectionPointLocation() const;

	void AddCurrency(int32 Amount);
};

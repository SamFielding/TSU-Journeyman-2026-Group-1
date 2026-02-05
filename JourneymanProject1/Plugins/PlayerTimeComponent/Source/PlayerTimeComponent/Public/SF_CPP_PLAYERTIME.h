// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SphereComponent.h"
#include "Components/ActorComponent.h"
#include "SF_CPP_PLAYERTIME.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PLAYERTIMECOMPONENT_API USF_CPP_PLAYERTIME : public USphereComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	USF_CPP_PLAYERTIME();

	UPROPERTY(EditAnywhere, Category = "Variables")
	float maxPlayerTime;
	UPROPERTY(BlueprintReadWrite, Category = "Variables")
	float playerCurrentTime;
	UPROPERTY(EditAnywhere, Category = "Variables")
	float tickDownRate;
	UFUNCTION(BlueprintCallable, Category = "Functions")
	bool OutOfTimeCheck()
	{
		return playerCurrentTime == 0.f;
	}
	UFUNCTION(BlueprintCallable, Category = "Functions")
	void TimeTickDown()
	{
		
		playerCurrentTime = FMath::Clamp(playerCurrentTime - (tickDownRate*GetWorld()->GetDeltaSeconds()), 0.f, maxPlayerTime);
	}
	UFUNCTION(BlueprintCallable, Category = "Functions")
	void AddTime(float timeAdded)
	{
		playerCurrentTime = FMath::Clamp(playerCurrentTime + timeAdded, 0.f, maxPlayerTime);
	}
	UFUNCTION(BlueprintCallable, Category = "Functions")
	void RemoveTime(float damageDone)
	{
		playerCurrentTime = FMath::Clamp(playerCurrentTime - damageDone, 0.f, maxPlayerTime);
	}
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
};

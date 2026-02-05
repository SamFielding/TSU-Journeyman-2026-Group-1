// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SphereComponent.h"
#include "SF_CPP_TIMEPICKUP.generated.h"

class SF_CPP_PLAYERTIME;
    
UCLASS()
class PLAYERTIMECOMPONENT_API ASF_CPP_TIMEPICKUP : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASF_CPP_TIMEPICKUP();

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variables")
    float TimeValue;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variables")
    float RotationRate;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variables")
    float OscillationFrequency;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variables")
    float OscillationAmplitude;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variables")
    float AttractionStrength;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variables")
    TObjectPtr<UStaticMeshComponent> Mesh;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variables")
    TObjectPtr<USphereComponent> Collider;

    UFUNCTION()
    void CollectTime(USF_CPP_PLAYERTIME* SF_CPP_PLAYERTIMEComponent);

    UPROPERTY()
    USF_CPP_PLAYERTIME* Target = nullptr;

    UPROPERTY()
    bool bIsMoving = false;



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};

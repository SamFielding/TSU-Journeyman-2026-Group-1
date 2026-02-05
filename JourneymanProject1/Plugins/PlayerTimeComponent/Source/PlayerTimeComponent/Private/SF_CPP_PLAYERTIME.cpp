// Fill out your copyright notice in the Description page of Project Settings.

#include "SF_CPP_PLAYERTIME.h"
#include "SF_CPP_TIMEPICKUP.h"


// Sets default values for this component's properties
USF_CPP_PLAYERTIME::USF_CPP_PLAYERTIME()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	
	this->OnComponentBeginOverlap.AddDynamic(this, &USF_CPP_PLAYERTIME::OnBeginOverlap);
	// ...
}

void USF_CPP_PLAYERTIME::OnBeginOverlap(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor,
	class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (auto Time = Cast<ASF_CPP_TIMEPICKUP>(OtherActor))
	{
		Time->CollectTime(this);
	}
}


// Called when the game starts
void USF_CPP_PLAYERTIME::BeginPlay()
{
	Super::BeginPlay();
	playerCurrentTime = maxPlayerTime;

	// ...
	
}


// Called every frame
void USF_CPP_PLAYERTIME::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

FVector USF_CPP_PLAYERTIME::GetCollectionPointLocation() const
{
	return GetComponentLocation();
}


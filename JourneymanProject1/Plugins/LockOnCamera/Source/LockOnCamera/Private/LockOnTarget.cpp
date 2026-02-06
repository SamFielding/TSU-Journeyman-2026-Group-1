#include "LockOnTarget.h"


ULockOnTarget::ULockOnTarget()
{
	PrimaryComponentTick.bCanEverTick = true;
}


FVector ULockOnTarget::GetTargetLocation() const
{
	return GetComponentLocation();
}


void ULockOnTarget::BeginPlay()
{
	Super::BeginPlay();
}


void ULockOnTarget::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}
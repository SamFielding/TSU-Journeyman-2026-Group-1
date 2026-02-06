#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "LockOnTarget.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class LOCKONCAMERA_API ULockOnTarget : public USceneComponent
{
	GENERATED_BODY()

public:	
	ULockOnTarget();

	FVector GetTargetLocation() const;

protected:
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

};
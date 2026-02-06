#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "LockOn.generated.h"

class UCameraComponent;
class ULockOnTarget;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class LOCKONCAMERA_API ULockOn : public UActorComponent
{
	GENERATED_BODY()

public:	
	ULockOn();

	UFUNCTION(BlueprintCallable, Category = "Lock On")
	void OnLockOnPressed();

	UFUNCTION(BlueprintCallable, Category = "Lock On")
	void OnLockOnReleased();

	UFUNCTION(BlueprintCallable, Category = "Lock On")
	void OnSwitchTarget(const FVector2D& Input);

	UPROPERTY(EditAnywhere, Category = "Lock On")
	float Range;

	UPROPERTY(EditAnywhere, Category = "Lock On")
	float SwitchTargetDeadzone;

	UPROPERTY(EditAnywhere, Category = "Lock On")
	float CameraRotationSpeed;

	UPROPERTY()
	UCameraComponent* Camera;

	UPROPERTY()
	FTransform CameraTransform;

	UPROPERTY()
	FTransform InitialCameraTransform;

	UPROPERTY()
	ULockOnTarget* Target;

	UPROPERTY()
	TArray<ULockOnTarget*> Available;

	UPROPERTY()
	bool bIsLockedOn = false;

	void FindAvailable();
	void LockOnNearest();
	void ClearLockOn();
	void UpdateCameraRotation(float DeltaTime);
	void SwitchTarget(const FVector2D& Input);

protected:
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

};
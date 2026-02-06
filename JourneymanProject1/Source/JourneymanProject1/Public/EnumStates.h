// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnumStates.generated.h"

/**
 * 
 */

UENUM()
enum class ECombatState : uint8
{
	MELEE UMETA(DisplayName = "MELEE_ATTACK"),
	AB1 UMETA(DisplayName = "AB1_ATTACK"),
	AB2 UMETA(DisplayName = "AB2_ATTACK"),
};

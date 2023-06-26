// Copyright 2023 Egor "Lorgord" Voronov

#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"

UENUM(BlueprintType)
enum class EAbilityInputID : uint8
{
	// 0 None
	None				UMETA(DisplayName = "None"),
	// 1 Confirm
	IA_Confirm			UMETA(DisplayName = "Confirm"),
	// 2 Cancel
	IA_Cancel			UMETA(DisplayName = "Cancel"),
	// 3 LMB
	IA_Ability1			UMETA(DisplayName = "Ability1"),
	// 4 RMB
	IA_Ability2			UMETA(DisplayName = "Ability2"),
	// 5 Q
	IA_Ability3			UMETA(DisplayName = "Ability3"),
	// 6 E
	IA_Ability4			UMETA(DisplayName = "Ability4"),
	// 7 R
	IA_Ability5			UMETA(DisplayName = "Ability5"),
	// 8 Sprint
	IA_Sprint			UMETA(DisplayName = "Boost"),
	// 9 Jump
	IA_Jump				UMETA(DisplayName = "Jump")
};

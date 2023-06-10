// Copyright 2023 Egor "Lorgord" Voronov

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "AJ_AbilitySystemComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class ABSURDJUMP_API UAJ_AbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()

public:

	bool bCharacterAbilitiesGiven = false;
	bool bStartupEffectsApplied = false;
};

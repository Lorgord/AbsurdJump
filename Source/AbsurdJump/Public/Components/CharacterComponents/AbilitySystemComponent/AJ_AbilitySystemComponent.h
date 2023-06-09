// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "AJ_AbilitySystemComponent.generated.h"

/**
 * 
 */
UCLASS()
class ABSURDJUMP_API UAJ_AbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()

public:

	bool CharacterAbilitiesGiven = false;
	bool StartupEffectApplied = false;
	
};
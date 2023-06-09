// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilityID.h"
#include "Abilities/GameplayAbility.h"
#include "AJ_CharacterGameplayAbility.generated.h"

/**
 * 
 */
UCLASS()
class ABSURDJUMP_API UAJ_CharacterGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:

	UAJ_CharacterGameplayAbility();

	virtual void OnAvatarSet(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec) override;


	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Ability | ID")
	EAbilityID AbilityInputID = EAbilityID::None;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Ability | ID")
	EAbilityID AbilityID = EAbilityID::None;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Ability | ID")
	bool bIsAbilityGranted = false;
	
};

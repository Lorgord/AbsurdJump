// Copyright 2023 Egor "Lorgord" Voronov

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Character/GameplayAbilitySystem/AJ_AbilityID.h"
#include "AJ_GameplayAbilityBase.generated.h"

/**
 * 
 */
UCLASS()
class ABSURDJUMP_API UAJ_GameplayAbilityBase : public UGameplayAbility
{
	GENERATED_BODY()

	UAJ_GameplayAbilityBase();

public:

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Ability")
	EAbilityInputID AbilityInputID = EAbilityInputID::None;
	
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Ability")
	EAbilityInputID AbilityID = EAbilityInputID::None;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Ability")
	bool bActivateAbilityOnGranted = false;

	virtual void OnAvatarSet(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec) override;
};

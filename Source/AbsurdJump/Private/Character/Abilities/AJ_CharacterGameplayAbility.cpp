// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/Abilities/AJ_CharacterGameplayAbility.h"

#include "AbilitySystemComponent.h"

UAJ_CharacterGameplayAbility::UAJ_CharacterGameplayAbility()
{
	InstancingPolicy = EGameplayAbilityInstancingPolicy::InstancedPerActor;

	ActivationBlockedTags.AddTag(FGameplayTag::RequestGameplayTag(FName("State.Dead")));
	
}

void UAJ_CharacterGameplayAbility::OnAvatarSet(const FGameplayAbilityActorInfo* ActorInfo,
	const FGameplayAbilitySpec& Spec)
{
	Super::OnAvatarSet(ActorInfo, Spec);

	if (bIsAbilityGranted)
	{
		ActorInfo->AbilitySystemComponent->TryActivateAbility(Spec.Handle, false);
	}
}

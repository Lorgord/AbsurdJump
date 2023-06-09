// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/Attributes/AJ_CharacterAttributeSet.h"

#include "Net/UnrealNetwork.h"

void UAJ_CharacterAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION_NOTIFY(UAJ_CharacterAttributeSet, Speed, COND_None, REPNOTIFY_Always);

}

void UAJ_CharacterAttributeSet::OnRep_Speed(const FGameplayAttributeData& OldSpeed)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAJ_CharacterAttributeSet, Speed, OldSpeed);
}

// Copyright 2023 Egor "Lorgord" Voronov


#include "Character/GameplayAbilitySystem/AttributeSets/AJ_AttributeSetBase.h"
#include "GameplayEffect.h"
#include "GameplayEffectExtension.h"
#include "Character/AJ_CharacterBase.h"
#include "Net/UnrealNetwork.h"

UAJ_AttributeSetBase::UAJ_AttributeSetBase()
{
}

void UAJ_AttributeSetBase::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	
	DOREPLIFETIME_CONDITION_NOTIFY(UAJ_AttributeSetBase, Speed, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UAJ_AttributeSetBase, MaxSpeed, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UAJ_AttributeSetBase, SpeedRegenRate, COND_None, REPNOTIFY_Always);
	
	DOREPLIFETIME_CONDITION_NOTIFY(UAJ_AttributeSetBase, Boost, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UAJ_AttributeSetBase, BoostRegenRate, COND_None, REPNOTIFY_Always);
	
	DOREPLIFETIME_CONDITION_NOTIFY(UAJ_AttributeSetBase, Mobility, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UAJ_AttributeSetBase, MaxMobility, COND_None, REPNOTIFY_Always);
	
	DOREPLIFETIME_CONDITION_NOTIFY(UAJ_AttributeSetBase, Throttle, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UAJ_AttributeSetBase, MaxThrottle, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UAJ_AttributeSetBase, MinThrottle, COND_None, REPNOTIFY_Always);

	

}


void UAJ_AttributeSetBase::OnRep_Speed(const FGameplayAttributeData& OldSpeed)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAJ_AttributeSetBase, Speed, OldSpeed);
}

void UAJ_AttributeSetBase::OnRep_MaxSpeed(const FGameplayAttributeData& OldMaxSpeed)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAJ_AttributeSetBase, MaxSpeed, OldMaxSpeed);
}

void UAJ_AttributeSetBase::OnRep_SpeedRegenRate(const FGameplayAttributeData& OldSpeedRegenRate)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAJ_AttributeSetBase, SpeedRegenRate, OldSpeedRegenRate);
}

void UAJ_AttributeSetBase::OnRep_Boost(const FGameplayAttributeData& OldBoost)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAJ_AttributeSetBase, Boost, OldBoost);
}

void UAJ_AttributeSetBase::OnRep_BoostRegenRate(const FGameplayAttributeData& OldBoostRegenRate)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAJ_AttributeSetBase, BoostRegenRate, OldBoostRegenRate);
}

void UAJ_AttributeSetBase::OnRep_Mobility(const FGameplayAttributeData& OldMobility)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAJ_AttributeSetBase, Mobility, OldMobility);
}

void UAJ_AttributeSetBase::OnRep_MaxMobility(const FGameplayAttributeData& OldMaxMobility)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAJ_AttributeSetBase, MaxMobility, OldMaxMobility);
}

void UAJ_AttributeSetBase::OnRep_Throttle(const FGameplayAttributeData& OldThrottle)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAJ_AttributeSetBase, Throttle, OldThrottle);
}

void UAJ_AttributeSetBase::OnRep_MaxThrottle(const FGameplayAttributeData& OldMaxThrottle)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAJ_AttributeSetBase, MaxThrottle, OldMaxThrottle);
}

void UAJ_AttributeSetBase::OnRep_MinThrottle(const FGameplayAttributeData& OldMinThrottle)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAJ_AttributeSetBase, MinThrottle, OldMinThrottle);
}

// Copyright 2023 Egor "Lorgord" Voronov


#include "Character/GameplayAbilitySystem/AttributeSets/AJ_AttributeSetBase.h"
#include "GameplayEffect.h"
#include "GameplayEffectExtension.h"
#include "Character/AJ_CharacterBase.h"
#include "Net/UnrealNetwork.h"

UAJ_AttributeSetBase::UAJ_AttributeSetBase()
{
}

void UAJ_AttributeSetBase::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	Super::PreAttributeChange(Attribute, NewValue);

	if (Attribute == GetMaxFuelAttribute())
	{
		AdjustAttributeForMaxChange(Fuel, MaxFuel, NewValue, GetFuelAttribute());
	}
	else if (Attribute == GetMaxSpeedAttribute())
	{
		AdjustAttributeForMaxChange(Speed, MaxSpeed, NewValue, GetSpeedAttribute());
	}
	else if (Attribute == GetMaxMobilityAttribute())
	{
		AdjustAttributeForMaxChange(Mobility, MaxMobility, NewValue, GetMobilityAttribute());
	}
}

void UAJ_AttributeSetBase::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);
}

void UAJ_AttributeSetBase::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION_NOTIFY(UAJ_AttributeSetBase, Fuel, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UAJ_AttributeSetBase, MaxFuel, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UAJ_AttributeSetBase, Speed, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UAJ_AttributeSetBase, MaxSpeed, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UAJ_AttributeSetBase, Boost, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UAJ_AttributeSetBase, BoostRegenRate, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UAJ_AttributeSetBase, Mobility, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UAJ_AttributeSetBase, MaxMobility, COND_None, REPNOTIFY_Always);

	

}

void UAJ_AttributeSetBase::AdjustAttributeForMaxChange(FGameplayAttributeData& AffectedAttribute, const FGameplayAttributeData& MaxAttribute, float NewMaxValue, const FGameplayAttribute& AffectedAttributeProperty)
{
	UAbilitySystemComponent* AbilityComp = GetOwningAbilitySystemComponent();
	const float CurrentMaxValue = MaxAttribute.GetCurrentValue();
	if (!FMath::IsNearlyEqual(CurrentMaxValue, NewMaxValue) && AbilityComp)
	{
		// Change current value to maintain the current Val / Max percent
		const float CurrentValue = AffectedAttribute.GetCurrentValue();
		float NewDelta = (CurrentMaxValue > 0.f) ? (CurrentValue * NewMaxValue / CurrentMaxValue) - CurrentValue : NewMaxValue;

		AbilityComp->ApplyModToAttributeUnsafe(AffectedAttributeProperty, EGameplayModOp::Additive, NewDelta);
	}
}

void UAJ_AttributeSetBase::OnRep_Fuel(const FGameplayAttributeData& OldFuel)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAJ_AttributeSetBase, Fuel, OldFuel);
}

void UAJ_AttributeSetBase::OnRep_MaxFuel(const FGameplayAttributeData& OldMaxFuel)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAJ_AttributeSetBase, MaxFuel, OldMaxFuel);
}

void UAJ_AttributeSetBase::OnRep_Speed(const FGameplayAttributeData& OldSpeed)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAJ_AttributeSetBase, Speed, OldSpeed);
}

void UAJ_AttributeSetBase::OnRep_MaxSpeed(const FGameplayAttributeData& OldMaxSpeed)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAJ_AttributeSetBase, MaxSpeed, OldMaxSpeed);
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

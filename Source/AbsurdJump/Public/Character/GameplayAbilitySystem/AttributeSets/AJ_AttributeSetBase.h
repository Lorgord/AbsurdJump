// Copyright 2023 Egor "Lorgord" Voronov

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "AJ_AttributeSetBase.generated.h"


#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)


UCLASS()
class ABSURDJUMP_API UAJ_AttributeSetBase : public UAttributeSet
{
	GENERATED_BODY()

public:

	UAJ_AttributeSetBase();

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

protected:

	UFUNCTION()
	virtual void OnRep_Speed(const FGameplayAttributeData& OldSpeed);

	UFUNCTION()
	virtual void OnRep_MaxSpeed(const FGameplayAttributeData& OldMaxSpeed);

	UFUNCTION()
	virtual void OnRep_SpeedRegenRate(const FGameplayAttributeData& OldSpeedRegenRate);

	UFUNCTION()
	virtual void OnRep_Boost(const FGameplayAttributeData& OldBoost);

	UFUNCTION()
	virtual void OnRep_BoostRegenRate(const FGameplayAttributeData& OldBoostRegenRate);

	UFUNCTION()
	virtual void OnRep_Mobility(const FGameplayAttributeData& OldMobility);

	UFUNCTION()
	virtual void OnRep_MaxMobility(const FGameplayAttributeData& OldMaxMobility);

	UFUNCTION()
	virtual void OnRep_Throttle(const FGameplayAttributeData& OldThrottle);

	UFUNCTION()
	virtual void OnRep_MaxThrottle(const FGameplayAttributeData& OldMaxThrottle);

	UFUNCTION()
	virtual void OnRep_MinThrottle(const FGameplayAttributeData& OldMinThrottle);

public:

	UPROPERTY(BlueprintReadOnly, Category = "Speed", ReplicatedUsing = OnRep_Speed)
	FGameplayAttributeData Speed;
	ATTRIBUTE_ACCESSORS(UAJ_AttributeSetBase, Speed)

	UPROPERTY(BlueprintReadOnly, Category = "Speed", ReplicatedUsing = OnRep_MaxSpeed)
	FGameplayAttributeData MaxSpeed;
	ATTRIBUTE_ACCESSORS(UAJ_AttributeSetBase, MaxSpeed)

	UPROPERTY(BlueprintReadOnly, Category = "Speed", ReplicatedUsing = OnRep_SpeedRegenRate)
	FGameplayAttributeData SpeedRegenRate;
	ATTRIBUTE_ACCESSORS(UAJ_AttributeSetBase, SpeedRegenRate)

	UPROPERTY(BlueprintReadOnly, Category = "Boost", ReplicatedUsing = OnRep_Boost)
	FGameplayAttributeData Boost;
	ATTRIBUTE_ACCESSORS(UAJ_AttributeSetBase, Boost)

	UPROPERTY(BlueprintReadOnly, Category = "Boost", ReplicatedUsing = OnRep_BoostRegenRate)
	FGameplayAttributeData BoostRegenRate;
	ATTRIBUTE_ACCESSORS(UAJ_AttributeSetBase, BoostRegenRate)

	UPROPERTY(BlueprintReadOnly, Category = "Mobility", ReplicatedUsing = OnRep_Mobility)
	FGameplayAttributeData Mobility;
	ATTRIBUTE_ACCESSORS(UAJ_AttributeSetBase, Mobility)

	UPROPERTY(BlueprintReadOnly, Category = "Mobility", ReplicatedUsing = OnRep_MaxMobility)
	FGameplayAttributeData MaxMobility;
	ATTRIBUTE_ACCESSORS(UAJ_AttributeSetBase, MaxMobility)

	UPROPERTY(BlueprintReadOnly, Category = "Throttle", ReplicatedUsing = OnRep_Throttle)
	FGameplayAttributeData Throttle;
	ATTRIBUTE_ACCESSORS(UAJ_AttributeSetBase, Throttle)

	UPROPERTY(BlueprintReadOnly, Category = "Throttle", ReplicatedUsing = OnRep_MaxThrottle)
	FGameplayAttributeData MaxThrottle;
	ATTRIBUTE_ACCESSORS(UAJ_AttributeSetBase, MaxThrottle)

	UPROPERTY(BlueprintReadOnly, Category = "Throttle", ReplicatedUsing = OnRep_MinThrottle)
	FGameplayAttributeData MinThrottle;
	ATTRIBUTE_ACCESSORS(UAJ_AttributeSetBase, MinThrottle)
};

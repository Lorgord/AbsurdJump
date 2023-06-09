// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "AttributeSet.h"
#include "AJ_CharacterAttributeSet.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)


UCLASS()
class ABSURDJUMP_API UAJ_CharacterAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	
	UFUNCTION()
	virtual void OnRep_Speed(const FGameplayAttributeData& OldSpeed);
	
	UPROPERTY(BlueprintReadOnly, Category = "Speed", ReplicatedUsing = OnRep_Speed)
	FGameplayAttributeData Speed;
	ATTRIBUTE_ACCESSORS(UAJ_CharacterAttributeSet, Speed)
};

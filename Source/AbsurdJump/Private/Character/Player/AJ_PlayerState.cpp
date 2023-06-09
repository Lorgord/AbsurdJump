// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/Player/AJ_PlayerState.h"

#include "Character/Attributes/AJ_CharacterAttributeSet.h"
#include "Components/CharacterComponents/AbilitySystemComponent/AJ_AbilitySystemComponent.h"


AAJ_PlayerState::AAJ_PlayerState()
{
	AbilitySystemComponent = CreateDefaultSubobject<UAJ_AbilitySystemComponent>(TEXT("AbilitySystemComponent"));
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);

	AttributeSet = CreateDefaultSubobject<UAJ_CharacterAttributeSet>(TEXT("AttributeSet"));
	
	NetUpdateFrequency = 30.0f;
}

void AAJ_PlayerState::BeginPlay()
{
	Super::BeginPlay();
}

void AAJ_PlayerState::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}



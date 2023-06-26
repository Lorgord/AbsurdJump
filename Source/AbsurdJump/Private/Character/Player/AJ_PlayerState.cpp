// Copyright 2023 Egor "Lorgord" Voronov


#include "Character/Player/AJ_PlayerState.h"

#include "Character/Components/MovementComponent/AJ_CharacterMovementComponent.h"
#include "Character/GameplayAbilitySystem/AJ_AbilitySystemComponent.h"
#include "Character/Player/AJ_PlayerCharacter.h"
#include "Character/Player/AJ_PlayerController.h"
#include "UI/MainHUD_WD/AJ_MainHUD_WD.h"


AAJ_PlayerState::AAJ_PlayerState()
{
	AbilitySystemComponent = CreateDefaultSubobject<UAJ_AbilitySystemComponent>(TEXT("AbilitySystemComponent"));
	AbilitySystemComponent->SetIsReplicated(true);

	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);

	AttributeSetBase = CreateDefaultSubobject<UAJ_AttributeSetBase>(TEXT("AttributeSetBase"));

	PlayerCharacter = Cast<AAJ_PlayerCharacter>(GetPawn());

	NetUpdateFrequency = 100.0f;

	DeadTag = FGameplayTag::RequestGameplayTag(FName("State.Dead"));
}

void AAJ_PlayerState::BeginPlay()
{
	Super::BeginPlay();

	if (AbilitySystemComponent)
	{
		SpeedChangedDelegateHandle = AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AttributeSetBase->GetSpeedAttribute()).AddUObject(this, &AAJ_PlayerState::SpeedChanged);
		MaxSpeedChangedDelegateHandle = AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AttributeSetBase->GetMaxSpeedAttribute()).AddUObject(this, &AAJ_PlayerState::MaxSpeedChanged);
		BoostChangedDelegateHandle = AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AttributeSetBase->GetBoostAttribute()).AddUObject(this, &AAJ_PlayerState::BoostChanged);
		BoostRegenRateChangedDelegateHandle = AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AttributeSetBase->GetBoostRegenRateAttribute()).AddUObject(this, &AAJ_PlayerState::BoostRegenRateChanged);
		MobilityChangedDelegateHandle = AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AttributeSetBase->GetMobilityAttribute()).AddUObject(this, &AAJ_PlayerState::MobilityChanged);
		MaxMobilityChangedDelegateHandle = AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AttributeSetBase->GetMaxMobilityAttribute()).AddUObject(this, &AAJ_PlayerState::MaxMobilityChanged);


		AbilitySystemComponent->RegisterGameplayTagEvent(FGameplayTag::RequestGameplayTag(FName("State.Debuff.Stun")), EGameplayTagEventType::NewOrRemoved).AddUObject(this, &AAJ_PlayerState::StunTagChanged);
	}
}

void AAJ_PlayerState::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

UAbilitySystemComponent* AAJ_PlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

UAJ_AttributeSetBase* AAJ_PlayerState::GetAttributeSetBase() const
{
	return AttributeSetBase;
}

void AAJ_PlayerState::SpeedChanged(const FOnAttributeChangeData& Data)
{
	// HUD->ChangeValue();
}

void AAJ_PlayerState::MaxSpeedChanged(const FOnAttributeChangeData& Data)
{
}

void AAJ_PlayerState::SpeedRegenRateChanged(const FOnAttributeChangeData& Data)
{
}


void AAJ_PlayerState::BoostChanged(const FOnAttributeChangeData& Data)
{
}

void AAJ_PlayerState::BoostRegenRateChanged(const FOnAttributeChangeData& Data)
{
}

void AAJ_PlayerState::MobilityChanged(const FOnAttributeChangeData& Data)
{
}

void AAJ_PlayerState::MaxMobilityChanged(const FOnAttributeChangeData& Data)
{
}

void AAJ_PlayerState::StunTagChanged(const FGameplayTag CallbackTag, int32 NewCount)
{
	if (NewCount > 0)
	{
		FGameplayTagContainer AbilityTagsToCancel;
		AbilityTagsToCancel.AddTag(FGameplayTag::RequestGameplayTag(FName("Ability")));

		FGameplayTagContainer AbilityTagsToIgnore;
		AbilityTagsToIgnore.AddTag(FGameplayTag::RequestGameplayTag(FName("Ability.NotCanceledByStun")));

		AbilitySystemComponent->CancelAbilities(&AbilityTagsToCancel, &AbilityTagsToIgnore);
	}
}


void AAJ_PlayerState::ShowAbilityConfirmCancelText(bool ShowText)
{
}

float AAJ_PlayerState::GetSpeed() const
{
	return AttributeSetBase->GetSpeed();
}

float AAJ_PlayerState::GetMaxSpeed() const
{
	return AttributeSetBase->GetMaxSpeed();
}

float AAJ_PlayerState::GetSpeedRegenRate() const
{
	return AttributeSetBase->GetSpeedRegenRate();
}

float AAJ_PlayerState::GetBoost() const
{
	return AttributeSetBase->GetBoost();
}

float AAJ_PlayerState::GetBoostRegenRate() const
{
	return AttributeSetBase->GetBoostRegenRate();
}

float AAJ_PlayerState::GetMobility() const
{
	return AttributeSetBase->GetMobility();
}

float AAJ_PlayerState::GetMaxMobility() const
{
	return AttributeSetBase->GetMaxMobility();
}



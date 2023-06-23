// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/Player/AJ_PlayerState.h"

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

	NetUpdateFrequency = 100.0f;

	DeadTag = FGameplayTag::RequestGameplayTag(FName("State.Dead"));
}

void AAJ_PlayerState::BeginPlay()
{
	Super::BeginPlay();

	if (AbilitySystemComponent)
	{
		FuelChangedDelegateHandle = AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AttributeSetBase->GetFuelAttribute()).AddUObject(this, &AAJ_PlayerState::FuelChanged);
		MaxFuelChangedDelegateHandle = AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AttributeSetBase->GetMaxFuelAttribute()).AddUObject(this, &AAJ_PlayerState::MaxFuelChanged);
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

void AAJ_PlayerState::FuelChanged(const FOnAttributeChangeData& Data)
{
	float Fuel = Data.NewValue;

	AAJ_PlayerCharacter* PlayerCharacter = Cast<AAJ_PlayerCharacter>(GetPawn());
	if (PlayerCharacter)
	{
		// change widget value
	}
}

void AAJ_PlayerState::MaxFuelChanged(const FOnAttributeChangeData& Data)
{
	float MaxFuel = Data.NewValue;

	AAJ_PlayerCharacter* PlayerCharacter = Cast<AAJ_PlayerCharacter>(GetPawn());
	if (PlayerCharacter)
	{
		// change widget value percentage
	}

	AAJ_PlayerController* PlayerController = Cast<AAJ_PlayerController>(GetOwner());
	if (PlayerController)
	{
		// UAJ_MainHUD_WD* HUD_Wd = PlayerController->GetHUD();
		// if (HUD_Wd)
		// {
		// 	// change HUD widged value
		// }
	}
}

void AAJ_PlayerState::SpeedChanged(const FOnAttributeChangeData& Data)
{
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

float AAJ_PlayerState::GetFuel() const
{
	return AttributeSetBase->GetFuel();
}

float AAJ_PlayerState::GetMaxFuel() const
{
	return AttributeSetBase->GetMaxFuel();
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



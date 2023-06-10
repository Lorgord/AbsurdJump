// Copyright 2023 Egor "Lorgord" Voronov


#include "Character/AJ_CharacterBase.h"

#include "Character/Components/MovementComponent/AJ_CharacterMovementComponent.h"
#include "Character/GameplayAbilitySystem/AJ_AbilitySystemComponent.h"
#include "Character/GameplayAbilitySystem/Abilities/AJ_GameplayAbilityBase.h"
#include "Character/GameplayAbilitySystem/AttributeSets/AJ_AttributeSetBase.h"
#include "Components/CapsuleComponent.h"


AAJ_CharacterBase::AAJ_CharacterBase(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer.SetDefaultSubobjectClass<UAJ_CharacterMovementComponent>(CharacterMovementComponentName))
{
	PrimaryActorTick.bCanEverTick = true;

	GetCapsuleComponent()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Overlap);

	bAlwaysRelevant = true;

	DeadTag = FGameplayTag::RequestGameplayTag(FName("State.Dead"));
	EffectRemoveOnDeathTag = FGameplayTag::RequestGameplayTag(FName("Effect.RemoveOnDeath"));
}

void AAJ_CharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

void AAJ_CharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AAJ_CharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

UAbilitySystemComponent* AAJ_CharacterBase::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent.Get();
}

void AAJ_CharacterBase::AddCharacterAbilities()
{
	// Grant abilities, but only on the server	
	if (GetLocalRole() != ROLE_Authority || !AbilitySystemComponent.IsValid() || AbilitySystemComponent->bCharacterAbilitiesGiven)
	{
		return;
	}

	for (TSubclassOf<UAJ_GameplayAbilityBase>& StartupAbility : CharacterAbilities)
	{
		// AbilitySystemComponent->GiveAbility(
		// 	FGameplayAbilitySpec(StartupAbility, 1, StartupAbility.GetDefaultObject()->AbilityID));
	}

	AbilitySystemComponent->bCharacterAbilitiesGiven = true;
}

void AAJ_CharacterBase::RemoveCharacterAbilities()
{
	if (GetLocalRole() != ROLE_Authority || !AbilitySystemComponent.IsValid() || !AbilitySystemComponent->bCharacterAbilitiesGiven)
	{
		return;
	}

	// Remove any abilities added from a previous call. This checks to make sure the ability is in the startup 'CharacterAbilities' array.
	TArray<FGameplayAbilitySpecHandle> AbilitiesToRemove;
	for (const FGameplayAbilitySpec& Spec : AbilitySystemComponent->GetActivatableAbilities())
	{
		if ((Spec.SourceObject == this) && CharacterAbilities.Contains(Spec.Ability->GetClass()))
		{
			AbilitiesToRemove.Add(Spec.Handle);
		}
	}

	// Do in two passes so the removal happens after we have the full list
	for (int32 i = 0; i < AbilitiesToRemove.Num(); i++)
	{
		AbilitySystemComponent->ClearAbility(AbilitiesToRemove[i]);
	}

	AbilitySystemComponent->bCharacterAbilitiesGiven = false;
}

void AAJ_CharacterBase::InitializeAttributes()
{
	if (!AbilitySystemComponent.IsValid())
	{
		return;
	}

	if (!DefaultAttributes)
	{
		UE_LOG(LogTemp, Error, TEXT("%s() Missing DefaultAttributes for %s. Please fill in the character's Blueprint."), *FString(__FUNCTION__), *GetName());
		return;
	}

	// Can run on Server and Client
	FGameplayEffectContextHandle EffectContext = AbilitySystemComponent->MakeEffectContext();
	EffectContext.AddSourceObject(this);

	FGameplayEffectSpecHandle NewHandle = AbilitySystemComponent->MakeOutgoingSpec(DefaultAttributes, 1.0f, EffectContext);
	if (NewHandle.IsValid())
	{
		FActiveGameplayEffectHandle ActiveGEHandle = AbilitySystemComponent->ApplyGameplayEffectSpecToTarget(*NewHandle.Data.Get(), AbilitySystemComponent.Get());
	}
}

void AAJ_CharacterBase::AddStartupEffects()
{
	if (GetLocalRole() != ROLE_Authority || !AbilitySystemComponent.IsValid() || AbilitySystemComponent->bStartupEffectsApplied)
	{
		return;
	}

	FGameplayEffectContextHandle EffectContext = AbilitySystemComponent->MakeEffectContext();
	EffectContext.AddSourceObject(this);

	for (TSubclassOf<UGameplayEffect> GameplayEffect : StartupEffects)
	{
		FGameplayEffectSpecHandle NewHandle = AbilitySystemComponent->MakeOutgoingSpec(GameplayEffect, 1.0f, EffectContext);
		if (NewHandle.IsValid())
		{
			FActiveGameplayEffectHandle ActiveGEHandle = AbilitySystemComponent->ApplyGameplayEffectSpecToTarget(*NewHandle.Data.Get(), AbilitySystemComponent.Get());
		}
	}

	AbilitySystemComponent->bStartupEffectsApplied = true;
}

bool AAJ_CharacterBase::IsAlive() const
{
	return !bIsPlayerFall;
}

void AAJ_CharacterBase::Die()
{
	// Only runs on Server
	RemoveCharacterAbilities();

	GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	GetCharacterMovement()->GravityScale = 0;
	GetCharacterMovement()->Velocity = FVector(0);

	OnCharacterDied.Broadcast(this);

	if (AbilitySystemComponent.IsValid())
	{
		AbilitySystemComponent->CancelAllAbilities();

		FGameplayTagContainer EffectTagsToRemove;
		EffectTagsToRemove.AddTag(EffectRemoveOnDeathTag);
		int32 NumEffectsRemoved = AbilitySystemComponent->RemoveActiveEffectsWithTags(EffectTagsToRemove);

		AbilitySystemComponent->AddLooseGameplayTag(DeadTag);
	}
}

float AAJ_CharacterBase::GetFuel() const
{
	if (AttributeSetBase.IsValid())
	{
		return AttributeSetBase->GetFuel();
	}

	return 0.0f;
}

float AAJ_CharacterBase::GetMaxFuel() const
{
	if (AttributeSetBase.IsValid())
	{
		return AttributeSetBase->GetMaxFuel();
	}

	return 0.0f;
}

float AAJ_CharacterBase::GetSpeed() const
{
	if (AttributeSetBase.IsValid())
	{
		return AttributeSetBase->GetSpeed();
	}

	return 0.0f;
}

float AAJ_CharacterBase::GetMaxSpeed() const
{
	if (AttributeSetBase.IsValid())
	{
		return AttributeSetBase->GetMaxSpeed();
	}

	return 0.0f;
}

float AAJ_CharacterBase::GetMobility() const
{
	if (AttributeSetBase.IsValid())
	{
		return AttributeSetBase->GetMobility();
	}

	return 0.0f;
}

float AAJ_CharacterBase::GetMaxMobility() const
{
	if (AttributeSetBase.IsValid())
	{
		return AttributeSetBase->GetMaxMobility();
	}

	return 0.0f;
}


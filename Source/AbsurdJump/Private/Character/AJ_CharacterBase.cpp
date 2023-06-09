// Fill out your copyright notice in the Description page of Project Settings.


#include "AbsurdJump/Public/Character/AJ_CharacterBase.h"

#include "Character/Player/AJ_PlayerState.h"
#include "Components/CharacterComponents/AbilitySystemComponent/AJ_AbilitySystemComponent.h"
#include "Components/CharacterComponents/EquipmentComponent/AJ_CharacterEquipmentComponent.h"
#include "Components/CharacterComponents/MovementComponent/AJ_CharacterMovementComponent.h"


AAJ_CharacterBase::AAJ_CharacterBase(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer.SetDefaultSubobjectClass<UAJ_CharacterMovementComponent>(ACharacter::CharacterMovementComponentName))
{
	MovementComponent = Cast<UAJ_CharacterMovementComponent>(GetCharacterMovement());
	
	AddDefaultComponent(EquipmentComponent, UAJ_CharacterEquipmentComponent, "EquipmentComponent", true) //move to GAS
	
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;
}

void AAJ_CharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
	OnActorHit.AddDynamic(this, &AAJ_CharacterBase::OnActorHitEvent);
	
}

void AAJ_CharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AAJ_CharacterBase::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	InitPlayer();
}

void AAJ_CharacterBase::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();
	InitPlayer();
}

void AAJ_CharacterBase::InitPlayer()
{
	
	AAJ_PlayerState* PS = GetPlayerState<AAJ_PlayerState>();
	if (PS)
	{
		AbilitySystemComponent = Cast<UAJ_AbilitySystemComponent>(PS->AbilitySystemComponent);
		
		PS->AbilitySystemComponent->InitAbilityActorInfo(PS, this);
	}

	if (HasAuthority() || IsLocallyControlled())
	{
		// Initializations
	}
}

UAbilitySystemComponent* AAJ_CharacterBase::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}


void AAJ_CharacterBase::OnSlideStart_Implementation()
{
	MovementComponent->BeginSlide();
}

void AAJ_CharacterBase::OnSlideEnd_Implementation()
{
	MovementComponent->EndSlide();

	LaunchCharacter(LaunchVector, false, false);
}

void AAJ_CharacterBase::Boost_Implementation()
{
	if (!CanBoost())
	{
		return;
	}
	
	LaunchCharacter(BoostVector, false, false);
}

bool AAJ_CharacterBase::CanBoost()
{
	return MovementComponent->bIsLaunched;
}

void AAJ_CharacterBase::Fire_Implementation()
{
	EquipmentComponent->Fire();
}


void AAJ_CharacterBase::OnActorHitEvent(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit)
{
	if (!MovementComponent->bIsLaunched || MovementComponent->bWantToSlide)
	{
		return;
	}

	KillPlayer();
}

void AAJ_CharacterBase::KillPlayer_Implementation()
{
	MovementComponent->OnDeath();
	EnableRagdoll();
	bIsDead = true;
	OnPlayerDeath.Broadcast();
}

bool AAJ_CharacterBase::IsDead()
{
	return bIsDead;
}

void AAJ_CharacterBase::EnableRagdoll()
{
	GetMesh()->SetCollisionProfileName(FName("Ragdoll"));
	GetMesh()->SetSimulatePhysics(true);
}

void AAJ_CharacterBase::AddScore_Implementation(int Score)
{
	CurrentScore += Score;
	
	OnScoreUpdated.Broadcast();
}
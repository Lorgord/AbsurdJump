// Fill out your copyright notice in the Description page of Project Settings.


#include "AbsurdJump/Public/Character/AJ_CharacterBase.h"

#include "Components/CharacterEquipmentComponent/AJ_CharacterEquipmentComponent.h"
#include "Components/MovementComponent/AJ_CharacterMovementComponent.h"


AAJ_CharacterBase::AAJ_CharacterBase(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer.SetDefaultSubobjectClass<UAJ_CharacterMovementComponent>(ACharacter::CharacterMovementComponentName))
{
	MovementComponent = Cast<UAJ_CharacterMovementComponent>(GetCharacterMovement());
	EquipmentComponent = CreateDefaultSubobject<UAJ_CharacterEquipmentComponent>(TEXT("EquipmentComponent"));

	
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
	CurrentScore = Score;
	
	OnScoreUpdated.Broadcast();
}
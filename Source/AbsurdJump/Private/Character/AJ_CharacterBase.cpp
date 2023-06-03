// Fill out your copyright notice in the Description page of Project Settings.


#include "AbsurdJump/Public/Character/AJ_CharacterBase.h"

#include "Components/MovementComponent/AJ_CharacterMovementComponent.h"


AAJ_CharacterBase::AAJ_CharacterBase(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer.SetDefaultSubobjectClass<UAJ_CharacterMovementComponent>(ACharacter::CharacterMovementComponentName))
{
	MovementComponent = Cast<UAJ_CharacterMovementComponent>(GetCharacterMovement());
	
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;
}

void AAJ_CharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
	
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




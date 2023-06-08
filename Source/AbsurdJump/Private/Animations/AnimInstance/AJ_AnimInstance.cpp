// Fill out your copyright notice in the Description page of Project Settings.


#include "Animations/AnimInstance/AJ_AnimInstance.h"

#include "Character/AJ_CharacterBase.h"
#include "Components/CharacterComponents/MovementComponent/AJ_CharacterMovementComponent.h"


UAJ_AnimInstance::UAJ_AnimInstance(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
}

void UAJ_AnimInstance::NativeBeginPlay()
{
	Super::NativeBeginPlay();
}

void UAJ_AnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	CharacterBase = Cast<AAJ_CharacterBase>(TryGetPawnOwner());

	if (CharacterBase)
	{
		MovementComponent = Cast<UAJ_CharacterMovementComponent>(CharacterBase->GetMovementComponent());
	}
}

void UAJ_AnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);
	
	if (!CharacterBase || !MovementComponent)
	{
		return;
	}

	bIsSliding = MovementComponent->bWantToSlide;
	bIsLaunched = MovementComponent->bIsLaunched;
}

// Copyright 2023 Egor "Lorgord" Voronov


#include "Character/Components/MovementComponent/AJ_CharacterMovementComponent.h"

#include "Character/AJ_CharacterBase.h"


UAJ_CharacterMovementComponent::UAJ_CharacterMovementComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

	CharacterBase = Cast<AAJ_CharacterBase>(GetOwner());
}


void UAJ_CharacterMovementComponent::BeginPlay()
{
	Super::BeginPlay();

}


void UAJ_CharacterMovementComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
	MoveCharacterForward(DeltaTime);
}

void UAJ_CharacterMovementComponent::MoveCharacterForward(float DeltaTime)
{
	FVector ForwardVector = GetOwner()->GetActorForwardVector();
	float Speed = 1000.0f;
	FVector NewLocation = (Speed * DeltaTime) * ForwardVector;

	FSavedMove_Character
	FHitResult HitResult;
	SafeMoveUpdatedComponent(NewLocation, CharacterBase->GetActorRotation(), false, HitResult);
}


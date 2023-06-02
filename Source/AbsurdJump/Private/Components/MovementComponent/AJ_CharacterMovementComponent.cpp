// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/MovementComponent/AJ_CharacterMovementComponent.h"


UAJ_CharacterMovementComponent::UAJ_CharacterMovementComponent()
{
	bOrientRotationToMovement = true;
	RotationRate = FRotator(0.0f, 500.0f, 0.0f);

	JumpZVelocity = 700.0f;
	AirControl = 0.35f;
	MaxWalkSpeed = 500.0f;
	MinAnalogWalkSpeed = 20.0f;
	BrakingDecelerationWalking = 2000.0f;
}


void UAJ_CharacterMovementComponent::BeginPlay()
{
	Super::BeginPlay();
	
}


void UAJ_CharacterMovementComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}


// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/MovementComponent/AJ_CharacterMovementComponent.h"

#include "Kismet/KismetMathLibrary.h"


UAJ_CharacterMovementComponent::UAJ_CharacterMovementComponent(const FObjectInitializer& ObjectInitializer)
{
}


void UAJ_CharacterMovementComponent::BeginPlay()
{
	Super::BeginPlay();

	SetMovementMode(MOVE_None);
	
}


void UAJ_CharacterMovementComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	Slide();
	OnFly();
}

void UAJ_CharacterMovementComponent::BeginSlide()
{
	if (IsFalling())
	{
		return;
	}
	
	SetMovementMode(MOVE_Falling);
	
	GroundFriction = 0.0f;

	BrakingDecelerationWalking = 0.0f;
	
	bOrientRotationToMovement = false;

	bWantToSlide = true;
	
}

void UAJ_CharacterMovementComponent::Slide()
{
	if (!bWantToSlide || bIsLaunched)
	{
		return;
	}
	
	AddImpulse(FVector(SlideImpulse, 0.0f, 0.0f));
	
	FVector StartLoc = GetOwner()->GetActorLocation();
	FVector EndLoc = -SlideLineTraceDistance * FVector::UpVector + StartLoc;
	
	FHitResult HitResult;
	
	if (GetWorld()->LineTraceSingleByChannel(HitResult, StartLoc, EndLoc, ECC_Visibility))
	{
		
		FRotator Rotator = UKismetMathLibrary::MakeRotFromZX(HitResult.ImpactNormal, GetOwner()->GetActorForwardVector());
		GetOwner()->SetActorRotation(Rotator);
	}
}

void UAJ_CharacterMovementComponent::EndSlide()
{
	bWantToSlide = false;
	bIsLaunched = true;
	

	GroundFriction = 8.0f;
	BrakingDecelerationWalking = 2048.0f;
}

void UAJ_CharacterMovementComponent::OnFly()
{
	if (!bIsLaunched || !IsFalling())
	{
		return;
	}

	FRotator Rotator = GetOwner()->GetVelocity().ToOrientationRotator();
	GetOwner()->SetActorRotation(Rotator);
}




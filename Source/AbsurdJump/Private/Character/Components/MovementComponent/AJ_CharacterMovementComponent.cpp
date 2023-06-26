// Copyright 2023 Egor "Lorgord" Voronov


#include "Character/Components/MovementComponent/AJ_CharacterMovementComponent.h"

#include "Character/Player/AJ_PlayerCharacter.h"


UAJ_CharacterMovementComponent::UAJ_CharacterMovementComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UAJ_CharacterMovementComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UAJ_CharacterMovementComponent::OnRegister()
{
	Super::OnRegister();
	PlayerCharacter = Cast<AAJ_PlayerCharacter>(GetCharacterOwner());
	//UpdateSpeed();
}

void UAJ_CharacterMovementComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	ForwardMovement(DeltaTime);
}

void UAJ_CharacterMovementComponent::RotatePlayer(float Value)
{
	//float YawScale = Value * ForwardInputScale
	FRotator YawRotation = FRotator(0.0f, Value * RotateOnRate, 0.0f);

	GetOwner()->AddActorLocalRotation(YawRotation);
	
	if (!GetOwner()->HasAuthority())
	{
		Server_RotatePlayer(GetOwner()->GetActorRotation());
	}
}

void UAJ_CharacterMovementComponent::Server_RotatePlayer_Implementation(FRotator ActorRotation)
{
	GetOwner()->SetActorRotation(ActorRotation);
}

void UAJ_CharacterMovementComponent::ForwardMovement(float DeltaTime)
{
	ForwardInputScale = PlayerCharacter->GetThrottle() * 0.01f;
	
	GetPawnOwner()->AddMovementInput(GetOwner()->GetActorForwardVector(), ForwardInputScale);
	GEngine->AddOnScreenDebugMessage(-1, 0, FColor::Green, FString::Printf(TEXT("Current Throttle: %f\nCurrent Speed: %f"), PlayerCharacter->GetThrottle(), Velocity.Length()));
}
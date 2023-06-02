// Fill out your copyright notice in the Description page of Project Settings.


#include "AbsurdJump/Public/Character/Player/AJ_PlayerController.h"

#include "Character/AJ_CharacterBase.h"
#include "Framework/AJ_GameModeBase.h"


void AAJ_PlayerController::SetPawn(APawn* InPawn)
{
	Super::SetPawn(InPawn);
	CharacterBase = Cast<AAJ_CharacterBase>(InPawn);
}

void AAJ_PlayerController::BeginPlay()
{
	Super::BeginPlay();
	
}

void AAJ_PlayerController::SetupInputComponent()
{
	// Super::SetupInputComponent();
	//
	// InputComponent->BindAxis("MoveForward", this, &AAJ_PlayerController::MoveForward);
	// InputComponent->BindAxis("MoveRight", this, &AAJ_PlayerController::MoveRight);
	// InputComponent->BindAxis("Turn", this, &AAJ_PlayerController::Turn);
	// InputComponent->BindAxis("TurnAtRate", this, &AAJ_PlayerController::TurnAtRate);
	// InputComponent->BindAxis("LookUp", this, &AAJ_PlayerController::LookUp);
	// InputComponent->BindAxis("LookUpAtRate", this, &AAJ_PlayerController::LookUpAtRate);
	//
	// InputComponent->BindAction("Jump", EInputEvent::IE_Pressed, this, &AAJ_PlayerController::Jump);

}


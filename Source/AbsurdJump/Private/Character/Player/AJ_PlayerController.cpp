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
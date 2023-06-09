// Fill out your copyright notice in the Description page of Project Settings.


#include "AbsurdJump/Public/Character/Player/AJ_PlayerController.h"

#include "Character/Player/AJ_PlayerCharacter.h"
#include "Framework/AJ_GameHUD.h"
#include "Framework/AJ_GameInstance.h"
#include "Framework/AJ_GameModeBase.h"



void AAJ_PlayerController::BeginPlay()
{
	Super::BeginPlay();

	GameHUD = Cast<AAJ_GameHUD>(GetHUD());
	
	UAJ_GameInstance* LGameInstance = Cast<UAJ_GameInstance>(GetGameInstance());

	APawn* LPawn = GetPawn();

	// if( IsValid(LPawn) && !LGameInstance->GetIsGameStarted() && LPawn->GetLocalRole() != ROLE_AutonomousProxy )
	// {
	// 	LPawn->DisableInput(this);
	// }

}

void AAJ_PlayerController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	PlayerCharacter = Cast<AAJ_PlayerCharacter>(InPawn);

}

void AAJ_PlayerController::OnGameStart_Implementation(bool WasLoaded)
{
	if( IsValid(GameHUD) )
	{
		//GameHUD->CreateDeathWD();
		//GameHUD->CreateMainHUD();
	}

	APawn* LPawn = GetPawn();
	if( IsValid(LPawn) )
	{
		LPawn->EnableInput(this);
	}
}
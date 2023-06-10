// Copyright 2023 Egor "Lorgord" Voronov

#include "AbsurdJump/Public/Character/Player/AJ_PlayerController.h"

#include "Blueprint/UserWidget.h"
#include "Character/Player/AJ_PlayerState.h"
#include "Framework/AJ_GameHUD.h"
#include "Framework/AJ_GameInstance.h"
#include "Framework/AJ_GameModeBase.h"




// Server only
void AAJ_PlayerController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	AAJ_PlayerState* PS = GetPlayerState<AAJ_PlayerState>();
	if (PS)
	{
		PS->GetAbilitySystemComponent()->InitAbilityActorInfo(PS, InPawn);
	}
}

void AAJ_PlayerController::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();
}

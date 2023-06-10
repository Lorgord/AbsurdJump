// Copyright 2023 Egor "Lorgord" Voronov
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "AJ_PlayerController.generated.h"

class UAJ_MainHUD_WD;
class AAJ_GameHUD;

UCLASS()
class ABSURDJUMP_API AAJ_PlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	
	virtual void OnPossess(APawn* InPawn) override;
	
	virtual void OnRep_PlayerState() override;



protected:
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "PlayerController | UI")
	UAJ_MainHUD_WD* HUD_Wd;


	
	
};
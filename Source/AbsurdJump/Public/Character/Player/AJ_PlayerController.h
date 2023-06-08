// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "AJ_PlayerController.generated.h"

class AAJ_GameHUD;
class AAJ_PlayerCharacter;

UCLASS()
class ABSURDJUMP_API AAJ_PlayerController : public APlayerController
{
	GENERATED_BODY()

public:

	virtual void BeginPlay() override;
	
	virtual void OnPossess(APawn* InPawn) override;


	//Blueprint protected methods
	protected:

	UFUNCTION(BlueprintNativeEvent, Category = "PlayerController")
	void OnGameStart(bool WasLoaded);
	virtual void OnGameStart_Implementation(bool WasLoaded);


//Blueprint values
public:
	
	UPROPERTY(BlueprintReadOnly, Category = "PlayerController")
		AAJ_GameHUD* GameHUD = nullptr;

	UPROPERTY(BlueprintReadOnly, Category = "PlayerController")
		AAJ_PlayerCharacter* PlayerCharacter = nullptr;
};
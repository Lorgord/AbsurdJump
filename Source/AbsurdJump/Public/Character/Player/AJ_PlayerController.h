// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "AJ_PlayerController.generated.h"

class UInputAction;


UCLASS()
class ABSURDJUMP_API AAJ_PlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	virtual void SetPawn(APawn* InPawn) override;

	virtual void BeginPlay() override;
	
protected:
	
	virtual void SetupInputComponent() override;
	

	UPROPERTY()
	class AAJ_CharacterBase* CharacterBase;
};
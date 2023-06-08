// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "AJ_PlayerState.generated.h"

class AAJ_PlayerCharacter;

UCLASS()
class ABSURDJUMP_API AAJ_PlayerState : public APlayerState
{
	GENERATED_BODY()

public:
	AAJ_PlayerState();

	virtual void BeginPlay() override;
	
	virtual void Tick(float DeltaTime) override;
	

	

	UPROPERTY(BlueprintReadOnly, Category = "Player | State")
	bool bIsDead = false;
	

	UPROPERTY()
	AAJ_PlayerCharacter* PlayerCharacter;
};

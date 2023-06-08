// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "AJ_GameStateBase.generated.h"

UCLASS()
class ABSURDJUMP_API AAJ_GameStateBase : public AGameStateBase
{
	GENERATED_BODY()

public:
	AAJ_GameStateBase();

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	
};

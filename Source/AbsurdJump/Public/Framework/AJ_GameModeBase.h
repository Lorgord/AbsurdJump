// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "AJ_GameModeBase.generated.h"

UCLASS()
class ABSURDJUMP_API AAJ_GameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	AAJ_GameModeBase();
	
	virtual void BeginPlay() override;
	
	virtual void Tick(float DeltaTime) override;
};

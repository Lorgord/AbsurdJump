// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "AJ_GameHUD.generated.h"

UCLASS()
class ABSURDJUMP_API AAJ_GameHUD : public AHUD
{
	GENERATED_BODY()

public:
	AAJ_GameHUD();
	
	virtual void BeginPlay() override;
	
	virtual void Tick(float DeltaTime) override;
};

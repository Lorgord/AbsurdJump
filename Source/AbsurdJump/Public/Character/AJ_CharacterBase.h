// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AJ_CharacterBase.generated.h"

UCLASS()
class ABSURDJUMP_API AAJ_CharacterBase : public AActor
{
	GENERATED_BODY()

public:
	AAJ_CharacterBase();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
};

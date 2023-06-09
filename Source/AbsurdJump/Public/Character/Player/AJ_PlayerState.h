// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "AJ_PlayerState.generated.h"

class UAJ_CharacterAttributeSet;
class UAJ_AbilitySystemComponent;

UCLASS()
class ABSURDJUMP_API AAJ_PlayerState : public APlayerState
{
	GENERATED_BODY()

public:
	
	AAJ_PlayerState();

	virtual void BeginPlay() override;
	
	virtual void Tick(float DeltaTime) override;



	

	UPROPERTY()
	UAJ_AbilitySystemComponent* AbilitySystemComponent = nullptr;
	
	UPROPERTY(Transient)
	UAJ_CharacterAttributeSet* AttributeSet = nullptr;
	
};

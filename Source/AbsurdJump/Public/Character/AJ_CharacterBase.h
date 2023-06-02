// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/Character.h"
#include "AJ_CharacterBase.generated.h"

class UAJ_CharacterMovementComponent;

UCLASS()
class ABSURDJUMP_API AAJ_CharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	AAJ_CharacterBase(const FObjectInitializer& ObjectInitializer);
	
	virtual void BeginPlay() override;
	
	virtual void Tick(float DeltaTime) override;
	
	
	// virtual void Jump() override;
	// virtual bool CanJumpInternal_Implementation() const override;



	
	UPROPERTY()
	UAJ_CharacterMovementComponent* MovementComponent;
};

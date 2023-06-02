// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbsurdJump/Public/Character/AJ_CharacterBase.h"
#include "AJ_PlayerCharacter.generated.h"

UCLASS()
class ABSURDJUMP_API AAJ_PlayerCharacter : public AAJ_CharacterBase
{
	GENERATED_BODY()

public:
	AAJ_PlayerCharacter(const FObjectInitializer& ObjectInitializer);
	
	virtual void BeginPlay() override;
	
	virtual void Tick(float DeltaTime) override;
	

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;
};

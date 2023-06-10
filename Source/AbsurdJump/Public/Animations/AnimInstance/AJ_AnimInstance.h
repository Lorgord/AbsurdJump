// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "AJ_AnimInstance.generated.h"

class UAJ_CharacterMovementComponent;
class AAJ_CharacterBase;
/**
 * 
 */
UCLASS()
class ABSURDJUMP_API UAJ_AnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:

	UAJ_AnimInstance(const FObjectInitializer& ObjectInitializer);


	virtual void NativeBeginPlay() override;

	virtual void NativeInitializeAnimation() override;

	virtual void NativeUpdateAnimation(float DeltaSeconds) override;
	
};

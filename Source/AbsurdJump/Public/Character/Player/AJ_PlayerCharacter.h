// Copyright 2023 Egor "Lorgord" Voronov

#pragma once

#include "CoreMinimal.h"
#include "Character/AJ_CharacterBase.h"
#include "AJ_PlayerCharacter.generated.h"

UCLASS()
class ABSURDJUMP_API AAJ_PlayerCharacter : public AAJ_CharacterBase
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AAJ_PlayerCharacter(const FObjectInitializer& ObjectInitializer);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};

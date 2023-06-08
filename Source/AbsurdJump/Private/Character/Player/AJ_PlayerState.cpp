// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/Player/AJ_PlayerState.h"

#include "Character/Player/AJ_PlayerCharacter.h"


AAJ_PlayerState::AAJ_PlayerState()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AAJ_PlayerState::BeginPlay()
{
	Super::BeginPlay();
}

void AAJ_PlayerState::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}



// Fill out your copyright notice in the Description page of Project Settings.


#include "AbsurdJump/Public/Framework/AJ_GameStateBase.h"


AAJ_GameStateBase::AAJ_GameStateBase()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AAJ_GameStateBase::BeginPlay()
{
	Super::BeginPlay();
	
}

void AAJ_GameStateBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


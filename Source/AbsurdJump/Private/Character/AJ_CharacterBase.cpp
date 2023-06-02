// Fill out your copyright notice in the Description page of Project Settings.


#include "AbsurdJump/Public/Character/AJ_CharacterBase.h"


AAJ_CharacterBase::AAJ_CharacterBase()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AAJ_CharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

void AAJ_CharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


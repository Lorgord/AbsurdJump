// Fill out your copyright notice in the Description page of Project Settings.


#include "Framework/AJ_GameHUD.h"


AAJ_GameHUD::AAJ_GameHUD()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AAJ_GameHUD::BeginPlay()
{
	Super::BeginPlay();
	
}

void AAJ_GameHUD::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


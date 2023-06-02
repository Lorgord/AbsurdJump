// Fill out your copyright notice in the Description page of Project Settings.


#include "AbsurdJump/Public/Framework/AJ_GameModeBase.h"


// Sets default values
AAJ_GameModeBase::AAJ_GameModeBase()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AAJ_GameModeBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAJ_GameModeBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


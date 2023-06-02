// Fill out your copyright notice in the Description page of Project Settings.


#include "AbsurdJump/Public/Character/Player/AJ_PlayerController.h"


// Sets default values
AAJ_PlayerController::AAJ_PlayerController()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AAJ_PlayerController::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAJ_PlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


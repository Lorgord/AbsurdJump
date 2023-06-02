// Fill out your copyright notice in the Description page of Project Settings.


#include "AbsurdJump/Public/Character/Player/AJ_PlayerCharacter.h"


// Sets default values
AAJ_PlayerCharacter::AAJ_PlayerCharacter()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AAJ_PlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAJ_PlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


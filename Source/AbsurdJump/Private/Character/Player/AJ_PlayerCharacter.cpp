// Fill out your copyright notice in the Description page of Project Settings.


#include "AbsurdJump/Public/Character/Player/AJ_PlayerCharacter.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"


// Sets default values
AAJ_PlayerCharacter::AAJ_PlayerCharacter(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 400.0f; // The camera follows at this distance behind the character	
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	FollowCamera->bUsePawnControlRotation = false;
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

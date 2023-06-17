// Copyright 2023 Egor "Lorgord" Voronov


#include "Character/Player/AJ_PlayerCharacter.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Camera/CameraComponent.h"
#include "Character/GameplayAbilitySystem/AJ_AbilityID.h"
#include "Character/GameplayAbilitySystem/AJ_AbilitySystemComponent.h"
#include "Character/Player/AJ_PlayerController.h"
#include "Character/Player/AJ_PlayerState.h"
#include "GameFramework/SpringArmComponent.h"


AAJ_PlayerCharacter::AAJ_PlayerCharacter(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(FName("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->SetRelativeLocation(FVector(0.0f, 0.0f, 70.0f));
	CameraBoom->bUsePawnControlRotation = true;

	FollowCamera = CreateDefaultSubobject<UCameraComponent>(FName("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom);
	FollowCamera->bUsePawnControlRotation = false;

	GetMesh()->VisibilityBasedAnimTickOption = EVisibilityBasedAnimTickOption::AlwaysTickPoseAndRefreshBones;

	//AIControllerClass = AAJ_AIPlayerController::StaticClass();

	DeadTag = FGameplayTag::RequestGameplayTag(FName("State.Dead"));
	
}

void AAJ_PlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void AAJ_PlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AAJ_PlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent);


	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AAJ_PlayerCharacter::Move);
	EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &AAJ_PlayerCharacter::Look);

	BindASCInput();

	
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

// Server only
void AAJ_PlayerCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	if (AAJ_PlayerState* PS = GetPlayerState<AAJ_PlayerState>())
	{
		AbilitySystemComponent = Cast<UAJ_AbilitySystemComponent>(PS->GetAbilitySystemComponent());
		
		PS->GetAbilitySystemComponent()->InitAbilityActorInfo(PS, this);
		AttributeSetBase = PS->GetAttributeSetBase();
		
		InitializeAttributes();
		AbilitySystemComponent->SetTagMapCount(DeadTag, 0);

		AddStartupEffects();
		AddCharacterAbilities();
		

		if (AAJ_PlayerController* PC = Cast<AAJ_PlayerController>(GetController()))
		{
			if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PC->GetLocalPlayer()))
			{
				Subsystem->AddMappingContext(MappingContext, 0);
			}
			
			//PC->CreateHUD();
		}
	}
}

// Client only
void AAJ_PlayerCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();

	AAJ_PlayerState* PS = GetPlayerState<AAJ_PlayerState>();
	if (PS)
	{
		AbilitySystemComponent = Cast<UAJ_AbilitySystemComponent>(PS->GetAbilitySystemComponent());
		AbilitySystemComponent->InitAbilityActorInfo(PS, this);

		BindASCInput();

		AttributeSetBase = PS->GetAttributeSetBase();
		
		InitializeAttributes();

		AAJ_PlayerController* PC = Cast<AAJ_PlayerController>(GetController());
		if (PC)
		{
			if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PC->GetLocalPlayer()))
			{
				Subsystem->AddMappingContext(MappingContext, 0);
			}
			//PC->CreateHUD();
		}
		
		AbilitySystemComponent->SetTagMapCount(DeadTag, 0);
		
	}
}

USpringArmComponent* AAJ_PlayerCharacter::GetCameraBoom()
{
	return CameraBoom;
}

UCameraComponent* AAJ_PlayerCharacter::GetFollowCamera()
{
	return FollowCamera;
}

void AAJ_PlayerCharacter::BindASCInput()
{
	
	if (bASCInputBound || !AbilitySystemComponent.IsValid() || !IsValid(EnhancedInputComponent))
	{
		return;
	}
	FTopLevelAssetPath AbilityEnumAssetPath = FTopLevelAssetPath(FName("/Script/AbsurdJump"), FName("EAbilityInputID"));
	
	AbilitySystemComponent->BindAbilityActivationToInputComponent(EnhancedInputComponent,
		FGameplayAbilityInputBinds(FString("ConfirmTarget"), FString("CancelTarget"), AbilityEnumAssetPath,
			static_cast<int32>(EAbilityInputID::Confirm), static_cast<int32>(EAbilityInputID::Cancel)));

	bASCInputBound = true;

}

void AAJ_PlayerCharacter::Move(const FInputActionValue& Value)
{
	if (Controller && Value.IsNonZero())
	{
		FVector2D MovementVector = Value.Get<FVector2D>();
		FVector Up = GetActorUpVector();
		FVector Right = GetActorRightVector();
		
		AddMovementInput(Up, MovementVector.Y);
		AddMovementInput(Right, MovementVector.X);
	}
}

void AAJ_PlayerCharacter::Look(const FInputActionValue& Value)
{
	if (Controller && Value.IsNonZero())
	{
		FVector2D LookAxisVector = Value.Get<FVector2D>();

		AddControllerYawInput(LookAxisVector.X);
		AddControllerPitchInput(LookAxisVector.Y);
	}
}


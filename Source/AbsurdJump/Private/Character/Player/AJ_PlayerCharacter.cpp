// Copyright 2023 Egor "Lorgord" Voronov


#include "Character/Player/AJ_PlayerCharacter.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Camera/CameraComponent.h"
#include "Character/Components/MovementComponent/AJ_CharacterMovementComponent.h"
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
	
}

void AAJ_PlayerCharacter::BeginPlay()
{
	Super::BeginPlay();

	UpdateSpeed();
}

void AAJ_PlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	UpdateThrottle(DeltaTime);
}

void AAJ_PlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	
	EnhancedInputComponent->BindAction(ForwardAction, ETriggerEvent::Triggered, this, &AAJ_PlayerCharacter::MoveForward);
	EnhancedInputComponent->BindAction(ForwardAction, ETriggerEvent::Started, this, &AAJ_PlayerCharacter::MoveForwardStarted);
	EnhancedInputComponent->BindAction(ForwardAction, ETriggerEvent::Completed, this, &AAJ_PlayerCharacter::MoveForwardCompleted);
	
	EnhancedInputComponent->BindAction(RightAction, ETriggerEvent::Triggered, this, &AAJ_PlayerCharacter::MoveRight);
	
	EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &AAJ_PlayerCharacter::Look);

	BindASCInput();
	
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

// Server only
void AAJ_PlayerCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	
	InitializeGAS();
	
	AddStartupEffects();
	AddCharacterAbilities();
}

// Client only
void AAJ_PlayerCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();

	BindASCInput();
	InitializeGAS();
}

void AAJ_PlayerCharacter::InitializeGAS()
{
	if (AAJ_PlayerState* PS = GetPlayerState<AAJ_PlayerState>())
	{
		AbilitySystemComponent = Cast<UAJ_AbilitySystemComponent>(PS->GetAbilitySystemComponent());
		AbilitySystemComponent->InitAbilityActorInfo(PS, this);
		AbilitySystemComponent->SetTagMapCount(DeadTag, 0);

		AttributeSetBase = PS->GetAttributeSetBase();
		
		AttributeSetBase->SetSpeed(GetMaxSpeed());
		AttributeSetBase->SetMobility(GetMaxMobility());
		
		InitializeAttributes();

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
	const FTopLevelAssetPath AbilityEnumAssetPath = FTopLevelAssetPath(FName("/Script/AbsurdJump"), FName("EAbilityInputID"));
	
	AbilitySystemComponent->BindAbilityActivationToInputComponent(EnhancedInputComponent,
		FGameplayAbilityInputBinds(FString("ConfirmTarget"), FString("CancelTarget"), AbilityEnumAssetPath,
			static_cast<int32>(EAbilityInputID::IA_Confirm), static_cast<int32>(EAbilityInputID::IA_Cancel)));

	bASCInputBound = true;
}

void AAJ_PlayerCharacter::MoveForward(const FInputActionValue& InValue)
{
	if (Controller && InValue.IsNonZero())
	{
		const bool IsValueNegate = InValue.GetMagnitude() < 0.0f;

		const float Current = GetThrottle();
		const float Target = IsValueNegate ? GetMinThrottle() : GetMaxThrottle();
		float InterpSpeed = IsValueNegate ? -InValue.GetMagnitude() : InValue.GetMagnitude();

		float Value;
		
		if (FMath::Abs(Current) >= FMath::Abs(Target) - 1.0f &&
			((Current > 0.0f && Target > 0.0f) || (Current < 0.0f && Target < 0.0f)))
		{
			Value = Target;
		}
		else
		{
			const float InputScale = FMath::Abs(InValue.GetMagnitude()); // for gamepad axis
			Value = FMath::Lerp(Current, Target * InputScale, GetWorld()->GetDeltaSeconds() * InterpSpeed * GetMobility());
		}
		SetThrottle(Value);
		
		GEngine->AddOnScreenDebugMessage(-1, 0, FColor::Yellow, FString::Printf(TEXT("Input Value: %f"), InValue.GetMagnitude()));
	}
}

void AAJ_PlayerCharacter::MoveForwardStarted(const FInputActionValue& InValue)
{
	AbilitySystemComponent->AddLooseGameplayTag(InputReleased, 0);
	bIsForwardInputReleased = false;
}

void AAJ_PlayerCharacter::MoveForwardCompleted(const FInputActionValue& InValue)
{
	AbilitySystemComponent->AddLooseGameplayTag(InputReleased, 1);
	bIsForwardInputReleased = true;
}

void AAJ_PlayerCharacter::MoveRight(const FInputActionValue& InValue)
{
	if (Controller && InValue.IsNonZero())
	{
		const float Value = InValue.GetMagnitude() * GetMobility();

		CharacterMovementComponent->RotatePlayer(Value);
	}
}

void AAJ_PlayerCharacter::Look(const FInputActionValue& InValue)
{
	if (Controller && InValue.IsNonZero())
	{
		const FVector2D LookAxisVector = InValue.Get<FVector2D>();

		AddControllerYawInput(LookAxisVector.X);
		AddControllerPitchInput(LookAxisVector.Y);
	}
}

void AAJ_PlayerCharacter::UpdateThrottle(float DeltaTime)
{
	if (!bIsForwardInputReleased)
	{
		return;
	}

	const float Value = FMath::FInterpTo(GetThrottle(), 0.0f, DeltaTime, SlowDownSpeed);
	
	SetThrottle(Value);
}

void AAJ_PlayerCharacter::UpdateSpeed()
{
	CharacterMovementComponent->MaxWalkSpeed = GetSpeed();
}

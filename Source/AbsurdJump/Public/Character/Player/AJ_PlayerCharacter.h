// Copyright 2023 Egor "Lorgord" Voronov

#pragma once

#include "CoreMinimal.h"
#include "InputMappingQuery.h"
#include "InputActionValue.h"
#include "Character/AJ_CharacterBase.h"
#include "AJ_PlayerCharacter.generated.h"

class AAJ_PlayerState;
class USpringArmComponent;
class UCameraComponent;

UCLASS()
class ABSURDJUMP_API AAJ_PlayerCharacter : public AAJ_CharacterBase
{
	GENERATED_BODY()

public:
	
	AAJ_PlayerCharacter(const FObjectInitializer& ObjectInitializer);
	
	virtual void BeginPlay() override;
	
	virtual void Tick(float DeltaTime) override;

	
	
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void PossessedBy(AController* NewController) override;
	
	virtual void OnRep_PlayerState() override;

	void InitializeGAS();
	
	
	USpringArmComponent* GetCameraBoom();
	
	UCameraComponent* GetFollowCamera();
	

	void BindASCInput();
	
	void MoveForward(const FInputActionValue& InValue);
	void MoveForwardStarted(const FInputActionValue& InValue);
	void MoveForwardCompleted(const FInputActionValue& InValue);
	
	void MoveRight(const FInputActionValue& InValue);

	void Look(const FInputActionValue& InValue);

	UFUNCTION(BlueprintCallable, Category = "Player | Speed")
	virtual void UpdateThrottle(float DeltaTime);

	UFUNCTION(BlueprintCallable, Category = "Player | Speed")
	virtual void UpdateSpeed();
	
protected:

	UPROPERTY(EditAnywhere, BlueprintReadOnly,Category = "Player | Input")
	UInputMappingContext* MappingContext = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadOnly,Category = "Player | Input")
	UInputAction* ForwardAction = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadOnly,Category = "Player | Input")
	UInputAction* BackwardAction = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadOnly,Category = "Player | Input")
	UInputAction* RightAction = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadOnly,Category = "Player | Input")
	UInputAction* LookAction = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player | Input")
	float SlowDownSpeed = 0.5f;

	UPROPERTY(BlueprintReadOnly, Category = "Player |Camera")
	float StartingCameraBoomArmLength = 0.0f;

	UPROPERTY(BlueprintReadOnly, Category = "Player |Camera")
	FVector StartingCameraBoomLocation;

	

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Player | Components")
	USpringArmComponent* CameraBoom = nullptr;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Player | Components")
	UCameraComponent* FollowCamera = nullptr;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Player | Components")
	UEnhancedInputComponent* EnhancedInputComponent = nullptr;

private:

	bool bASCInputBound = false;
	bool bIsForwardInputReleased = false;
};

// Copyright 2023 Egor "Lorgord" Voronov

#pragma once

#include "CoreMinimal.h"
#include "InputMappingQuery.h"
#include "InputActionValue.h"
#include "Character/AJ_CharacterBase.h"
#include "AJ_PlayerCharacter.generated.h"

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
	
	
	USpringArmComponent* GetCameraBoom();
	
	UCameraComponent* GetFollowCamera();
	

	void BindASCInput();

	void Move(const FInputActionValue& Value);

	void Look(const FInputActionValue& Value);

	
protected:

	UPROPERTY(EditAnywhere, BlueprintReadOnly,Category = "Player | Input")
	UInputMappingContext* MappingContext;

	UPROPERTY(EditAnywhere, BlueprintReadOnly,Category = "Player | Input")
	UInputAction* MoveAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly,Category = "Player | Input")
	UInputAction* LookAction;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Player |Camera")
	float BaseTurnRate = 45.0f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Player |Camera")
	float BaseLookUpRate = 45.0f;

	UPROPERTY(BlueprintReadOnly, Category = "Player |Camera")
	float StartingCameraBoomArmLength;

	UPROPERTY(BlueprintReadOnly, Category = "Player |Camera")
	FVector StartingCameraBoomLocation;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Player | Components")
	USpringArmComponent* CameraBoom;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Player | Components")
	UCameraComponent* FollowCamera;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Player | Components")
	UEnhancedInputComponent* EnhancedInputComponent;

private:

	bool bASCInputBound = false;
};

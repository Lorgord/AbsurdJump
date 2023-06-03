// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/Character.h"
#include "AJ_CharacterBase.generated.h"

class UAJ_CharacterEquipmentComponent;
class UAJ_CharacterMovementComponent;

UCLASS()
class ABSURDJUMP_API AAJ_CharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	AAJ_CharacterBase(const FObjectInitializer& ObjectInitializer);
	
	virtual void BeginPlay() override;
	
	virtual void Tick(float DeltaTime) override;





	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Character | Slide")
	void OnSlideStart();
	virtual void OnSlideStart_Implementation();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Character | Slide")
	void OnSlideEnd();
	virtual void OnSlideEnd_Implementation();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Character | Fly")
	void Boost();
	virtual void Boost_Implementation();

	UFUNCTION(BlueprintCallable, Category = "Character | Fly")
	bool CanBoost();


	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Character | Slide")
	void Fire();
	virtual void Fire_Implementation();


	

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Character | Launch")
	FVector LaunchVector = FVector::ZeroVector;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Character | Launch")
	FVector BoostVector = FVector::ZeroVector;


	
	
	UPROPERTY()
	UAJ_CharacterMovementComponent* MovementComponent;

	UPROPERTY()
	UAJ_CharacterEquipmentComponent* EquipmentComponent;
};
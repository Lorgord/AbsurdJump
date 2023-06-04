// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/Character.h"
#include "AJ_CharacterBase.generated.h"

class UAJ_CharacterEquipmentComponent;
class UAJ_CharacterMovementComponent;



DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnScoreUpdated);

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

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Equipment | Weapon")
		void OnFireEvent(FTransform Transform);
		virtual void OnFireEvent_Implementation(FTransform Transform) { return; }


	UFUNCTION()
		void OnActorHitEvent(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit);

	
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Character | Death")
		void KillPlayer();
		virtual void KillPlayer_Implementation();
	
	UFUNCTION(BlueprintCallable, Category = "Character | Death")
		bool IsDead();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Character | Death")
		void OnDeath();
		virtual void OnDeath_Implementation() { return; }

	UFUNCTION(BlueprintCallable, Category = "Character | Death")
		void EnableRagdoll();	
	


	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Character | Score")
		void AddScore(int Score);
		virtual void AddScore_Implementation(int Score);

	UPROPERTY(BlueprintAssignable, Category = "Character | Score")
		FOnScoreUpdated OnScoreUpdated;
	
	

	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Character | Launch")
	FVector LaunchVector = FVector::ZeroVector;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Character | Launch")
	FVector BoostVector = FVector::ZeroVector;



	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Character | State")
	bool bIsDead = false;
	
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Character | State")
	float CurrentScore = 0.0f;
	


	
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Character | Components")
	UAJ_CharacterMovementComponent* MovementComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Character | Components")
	UAJ_CharacterEquipmentComponent* EquipmentComponent;
};
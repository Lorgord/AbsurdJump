// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "GameplayTagContainer.h"
#include "Abilities/AbilityID.h"
#include "AJ_CharacterBase.generated.h"


class UGameplayEffect;
class UAJ_AbilitySystemComponent;
class UAJ_CharacterEquipmentComponent;
class UAJ_CharacterMovementComponent;



#define AddDefaultComponent(ComponentObject, ComponentName, DisplayName, Replicated)\
ComponentObject = CreateDefaultSubobject<ComponentName>(TEXT(DisplayName));\
ComponentObject->SetIsReplicated(Replicated);



DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnScoreUpdated);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPlayerDeath);

UCLASS()
class ABSURDJUMP_API AAJ_CharacterBase : public ACharacter , public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	AAJ_CharacterBase(const FObjectInitializer& ObjectInitializer);
	
	virtual void BeginPlay() override;
	
	virtual void Tick(float DeltaTime) override;

	

	virtual void PossessedBy(AController* NewController) override;

	virtual void OnRep_PlayerState() override;

	
	UFUNCTION()
	void InitPlayer();

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	UFUNCTION()
	int32 GetAbilityLevel(EAbilityID AbilityID) const { return 0; }

	UFUNCTION()
	void AddCharacterAttributes() { return;}

	UFUNCTION()
	void InitializeAttributes(){ return;}

	UFUNCTION()
	void AddStartupEffects(){ return;}
	
	




	
	

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
	

	UFUNCTION(BlueprintGetter, Category = "Character | Components")
		UAJ_CharacterEquipmentComponent* GetEquipmentComponent() const { return EquipmentComponent; }
	



	
	UPROPERTY(BlueprintAssignable, Category = "Character | Score")
		FOnScoreUpdated OnScoreUpdated;

	UPROPERTY(BlueprintAssignable, Category = "Character | Score")
		FOnPlayerDeath OnPlayerDeath;
	
	

	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Character | Launch")
	FVector LaunchVector = FVector::ZeroVector;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Character | Launch")
	FVector BoostVector = FVector::ZeroVector;



	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Character | State")
	bool bIsDead = false;
	
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Character | State")
	float CurrentScore = 0.0f;
	



	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Character | Name")
	FText CharacterName;

	UPROPERTY()
	FGameplayTag DeadTag;

	
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Character | Abilities")
	TSubclassOf<UGameplayEffect> DefaultAttributes;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Character | Abilities")
	TArray<TSubclassOf<UGameplayEffect>> StartupAttributes;
	
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Character | Components")
	UAJ_CharacterMovementComponent* MovementComponent = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Character | Components")
	UAJ_CharacterEquipmentComponent* EquipmentComponent = nullptr; //move to GAS

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Player | Components")
	UAJ_AbilitySystemComponent* AbilitySystemComponent = nullptr;
	
};
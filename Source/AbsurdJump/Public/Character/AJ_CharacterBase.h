// Copyright 2023 Egor "Lorgord" Voronov

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameplayEffect.h"
#include "GameplayTagContainer.h"
#include "GameFramework/Character.h"
#include "AJ_CharacterBase.generated.h"


class UAJ_GameplayAbilityBase;
class UAJ_AttributeSetBase;
class UAJ_AbilitySystemComponent;



DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCharacterDiedEvent, AAJ_CharacterBase*, Character);



UCLASS()
class ABSURDJUMP_API AAJ_CharacterBase : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

	

public:
	AAJ_CharacterBase(const FObjectInitializer& ObjectInitializer);

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


	

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	virtual void AddCharacterAbilities();

	virtual void RemoveCharacterAbilities();

	virtual void InitializeAttributes();

	virtual void AddStartupEffects();


	virtual bool IsAlive() const;

	virtual void Die();


	

	UFUNCTION(BlueprintCallable, Category = "Character | Attributes")
	float GetFuel() const;

	UFUNCTION(BlueprintCallable, Category = "Character | Attributes")
	float GetMaxFuel() const;

	UFUNCTION(BlueprintCallable, Category = "Character | Attributes")
	float GetSpeed() const;

	UFUNCTION(BlueprintCallable, Category = "Character | Attributes")
	float GetMaxSpeed() const;

	UFUNCTION(BlueprintCallable, Category = "Character | Attributes")
	float GetMobility() const;

	UFUNCTION(BlueprintCallable, Category = "Character | Attributes")
	float GetMaxMobility() const;


	UPROPERTY(BlueprintAssignable, Category = "Character | Events")
	FOnCharacterDiedEvent OnCharacterDied;

protected:

	bool bIsPlayerFall;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Character")
	FName CharacterName;
	

	UPROPERTY()
	FGameplayTag DeadTag;
	UPROPERTY()
	FGameplayTag EffectRemoveOnDeathTag;
	
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Character | Abilities")
	TArray<TSubclassOf<UAJ_GameplayAbilityBase>> CharacterAbilities;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Character | Abilities")
	TArray<TSubclassOf<UGameplayEffect>> StartupEffects;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Character | Abilities")
	TSubclassOf<UGameplayEffect> DefaultAttributes;
	
	
	TWeakObjectPtr<UAJ_AbilitySystemComponent> AbilitySystemComponent;
	TWeakObjectPtr<UAJ_AttributeSetBase> AttributeSetBase;
	
};

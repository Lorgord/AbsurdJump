// Copyright 2023 Egor "Lorgord" Voronov

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "AbilitySystemInterface.h"
#include "GameplayTagContainer.h"
#include "Character/GameplayAbilitySystem/AttributeSets/AJ_AttributeSetBase.h"
#include "AJ_PlayerState.generated.h"


class UAJ_AbilitySystemComponent;
class UAJ_AttributeSetBase;

UCLASS()
class ABSURDJUMP_API AAJ_PlayerState : public APlayerState, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	
	AAJ_PlayerState();

	virtual void BeginPlay() override;
	
	virtual void Tick(float DeltaTime) override;
	


	UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	UAJ_AttributeSetBase* GetAttributeSetBase() const;



	virtual void FuelChanged(const FOnAttributeChangeData& Data);
	virtual void MaxFuelChanged(const FOnAttributeChangeData& Data);
	virtual void SpeedChanged(const FOnAttributeChangeData& Data);
	virtual void MaxSpeedChanged(const FOnAttributeChangeData& Data);
	virtual void SpeedRegenRateChanged(const FOnAttributeChangeData& Data);
	virtual void BoostChanged(const FOnAttributeChangeData& Data);
	virtual void BoostRegenRateChanged(const FOnAttributeChangeData& Data);
	virtual void MobilityChanged(const FOnAttributeChangeData& Data);
	virtual void MaxMobilityChanged(const FOnAttributeChangeData& Data);

	virtual void StunTagChanged(const FGameplayTag CallbackTag, int32 NewCount);


	

	UFUNCTION(BlueprintCallable, Category = "PlayerState | UI")
	void ShowAbilityConfirmCancelText(bool ShowText);



	UFUNCTION(BlueprintCallable, Category = "PlayerState | Attributes")
	float GetFuel() const;

	UFUNCTION(BlueprintCallable, Category = "PlayerState | Attributes")
	float GetMaxFuel() const;

	UFUNCTION(BlueprintCallable, Category = "PlayerState | Attributes")
	float GetSpeed() const;

	UFUNCTION(BlueprintCallable, Category = "PlayerState | Attributes")
	float GetMaxSpeed() const;

	UFUNCTION(BlueprintCallable, Category = "PlayerState | Attributes")
	float GetSpeedRegenRate() const;

	UFUNCTION(BlueprintCallable, Category = "PlayerState | Attributes")
	float GetBoost() const;

	UFUNCTION(BlueprintCallable, Category = "PlayerState | Attributes")
	float GetBoostRegenRate() const;

	UFUNCTION(BlueprintCallable, Category = "PlayerState | Attributes")
	float GetMobility() const;

	UFUNCTION(BlueprintCallable, Category = "PlayerState | Attributes")
	float GetMaxMobility() const;

protected:

	UPROPERTY()
	UAJ_AbilitySystemComponent* AbilitySystemComponent;

	UPROPERTY()
	UAJ_AttributeSetBase* AttributeSetBase;

	FGameplayTag DeadTag;

	FDelegateHandle FuelChangedDelegateHandle;
	FDelegateHandle MaxFuelChangedDelegateHandle;
	FDelegateHandle SpeedChangedDelegateHandle;
	FDelegateHandle SpeedRegenRateChangedDelegateHandle;
	FDelegateHandle MaxSpeedChangedDelegateHandle;
	FDelegateHandle BoostChangedDelegateHandle;
	FDelegateHandle BoostRegenRateChangedDelegateHandle;
	FDelegateHandle MobilityChangedDelegateHandle;
	FDelegateHandle MaxMobilityChangedDelegateHandle;
};

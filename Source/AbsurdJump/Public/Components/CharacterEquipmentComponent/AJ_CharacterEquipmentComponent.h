// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AJ_CharacterEquipmentComponent.generated.h"


class AAJ_CharacterBase;
class AAJ_RangeWeapon;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class ABSURDJUMP_API UAJ_CharacterEquipmentComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAJ_CharacterEquipmentComponent();

	virtual void BeginPlay() override;

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Weapon")
	TSubclassOf<AAJ_RangeWeapon> WeaponClass;

	
	UPROPERTY(BlueprintReadOnly, Category = "Weapon")
	AAJ_RangeWeapon* CurrentWeapon;

	UPROPERTY()
	AAJ_CharacterBase* CharacterBase;
	
};

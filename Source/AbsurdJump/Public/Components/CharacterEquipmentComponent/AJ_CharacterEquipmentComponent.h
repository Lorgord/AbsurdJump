// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AJ_CharacterEquipmentComponent.generated.h"


class AAJ_Projectile;
class AAJ_CharacterBase;
class AAJ_RangeWeapon;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class ABSURDJUMP_API UAJ_CharacterEquipmentComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAJ_CharacterEquipmentComponent();

	virtual void BeginPlay() override;


	UFUNCTION(BlueprintCallable, Category = "Equipment | Weapon")
	void Fire();

	UFUNCTION(BlueprintCallable, Category = "Equipment | Weapon")
	bool CanFire();

	
	
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Equipment | Ammo")
		int MaxAmmo = 10;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Equipment | Ammo")
		int CurrentAmmo = 9;

	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Equipment | Weapon")
		FVector MuzzleOffset = FVector::ZeroVector;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Equipment | Weapon")
		TSubclassOf<AAJ_Projectile> Projectile;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Equipment | Weapon")
		TSubclassOf<AAJ_RangeWeapon> WeaponClass;
	
	UPROPERTY(BlueprintReadOnly, Category = "Equipment | Weapon")
		AAJ_RangeWeapon* CurrentWeapon = nullptr;	


	
	UPROPERTY()
		AAJ_CharacterBase* CharacterBase = nullptr;
	
};

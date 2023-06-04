// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AJ_RangeWeapon.generated.h"

class UAJ_WeaponBarrelComponent;

UCLASS()
class ABSURDJUMP_API AAJ_RangeWeapon : public AActor
{
	GENERATED_BODY()

public:
	AAJ_RangeWeapon();

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;
	

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Equipable | Fire")
	TSubclassOf<AActor> Projectile;
	

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Equipable | Components")
	USkeletalMeshComponent* WeaponMesh;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Equipable | Components")
	USceneComponent* WeaponMuzzle;
};

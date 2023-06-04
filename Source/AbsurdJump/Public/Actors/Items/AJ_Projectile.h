// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AJ_Projectile.generated.h"

class USphereComponent;
class UProjectileMovementComponent;

UCLASS(Blueprintable)
class ABSURDJUMP_API AAJ_Projectile : public AActor
{
	GENERATED_BODY()

public:
	AAJ_Projectile(const FObjectInitializer& ObjectInitializer);

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;


	void FireInDirection(const FVector& ShootDirection);

	

	UPROPERTY(VisibleDefaultsOnly, Category = "Projectile | Components")
	USphereComponent* CollisionComponent;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Projectile | Components")
	UStaticMeshComponent* ProjectileMesh;

	UPROPERTY(VisibleDefaultsOnly, Category = "Projectile | Components")
	UMaterialInstanceDynamic* ProjectileMaterialInstance;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Projectile | Components")
	UProjectileMovementComponent* ProjectileMovementComponent;
};

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

	UFUNCTION(BlueprintCallable, Category = "Projectile")
	void FireInDirection(const FVector& ShootDirection, float CharacterVelocity);

	


	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Projectile | Components")
	UStaticMeshComponent* ProjectileMesh;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Projectile | Components")
	UProjectileMovementComponent* ProjectileMovementComponent;
};

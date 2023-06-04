// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/Items/AJ_Projectile.h"

#include "HairStrandsInterface.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"


AAJ_Projectile::AAJ_Projectile(const FObjectInitializer& ObjectInitializer)
{
	PrimaryActorTick.bCanEverTick = true;

	ProjectileMesh = CreateDefaultSubobject<UStaticMeshComponent>("ProjectileMesh");

	SetRootComponent(ProjectileMesh);

	ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileComponent"));
	ProjectileMovementComponent->InitialSpeed = 2000.0f;
	ProjectileMovementComponent->MaxSpeed = 2000.0f;
	
}

void AAJ_Projectile::BeginPlay()
{
	Super::BeginPlay();
}

void AAJ_Projectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AAJ_Projectile::FireInDirection(const FVector& ShootDirection, float CharacterVelocity)
{
	ProjectileMovementComponent->Velocity = ShootDirection * (ProjectileMovementComponent->InitialSpeed + CharacterVelocity);
}


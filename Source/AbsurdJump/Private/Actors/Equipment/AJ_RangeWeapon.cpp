// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/Equipment/AJ_RangeWeapon.h"

#include "Components/Weapon/AJ_WeaponBarrelComponent.h"


AAJ_RangeWeapon::AAJ_RangeWeapon()
{
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("WeaponRoot"));

	WeaponMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("WeaponMesh"));
	WeaponMesh->SetupAttachment(RootComponent);

	WeaponBarrel = CreateDefaultSubobject<UAJ_WeaponBarrelComponent>(TEXT("WeaponBarrel"));
	WeaponBarrel->SetupAttachment(WeaponMesh, FName("MuzzleSocket"));
}

void AAJ_RangeWeapon::BeginPlay()
{
	Super::BeginPlay();
}

void AAJ_RangeWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AAJ_RangeWeapon::Fire()
{
	
}


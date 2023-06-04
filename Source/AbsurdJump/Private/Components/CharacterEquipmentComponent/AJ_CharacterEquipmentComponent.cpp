// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/CharacterEquipmentComponent/AJ_CharacterEquipmentComponent.h"

#include "Actors/Equipment/AJ_RangeWeapon.h"
#include "Actors/Items/AJ_Projectile.h"
#include "Character/AJ_CharacterBase.h"


UAJ_CharacterEquipmentComponent::UAJ_CharacterEquipmentComponent()
{

}


void UAJ_CharacterEquipmentComponent::BeginPlay()
{
	Super::BeginPlay();

	CharacterBase = Cast<AAJ_CharacterBase>(GetOwner());

	CurrentWeapon = GetWorld()->SpawnActor<AAJ_RangeWeapon>(WeaponClass);
	CurrentWeapon->AttachToComponent(CharacterBase->GetMesh(), FAttachmentTransformRules::KeepRelativeTransform, FName("WeaponSocket"));
}

void UAJ_CharacterEquipmentComponent::Fire()
{
	if (!CurrentWeapon || !Projectile || !CanFire())
	{
		return;
	}

	FVector CameraLocation;
	FRotator CameraRotation;
	GetOwner()->GetActorEyesViewPoint(CameraLocation, CameraRotation);

	FVector MuzzleLocation = CurrentWeapon->WeaponMuzzle->GetComponentLocation();
	FRotator MuzzleRotation = CameraRotation;

	MuzzleRotation.Pitch += 10.0f;

	FActorSpawnParameters SpawnParameters;
	SpawnParameters.Owner = GetOwner();
	SpawnParameters.Instigator = GetOwner()->GetInstigator();

	AAJ_Projectile* NewProjectile = GetWorld()->SpawnActor<AAJ_Projectile>(Projectile, MuzzleLocation, MuzzleRotation, SpawnParameters);

	if (NewProjectile)
	{
		NewProjectile->FireInDirection(MuzzleRotation.Vector());
		DrawDebugLine(GetWorld(), MuzzleLocation, MuzzleLocation + MuzzleRotation.Vector() * 100.0f, FColor::Green, true, 5.0f);
	}
}

bool UAJ_CharacterEquipmentComponent::CanFire()
{
	return CurrentAmmo != 0;
}


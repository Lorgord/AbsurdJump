// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/CharacterComponents/EquipmentComponent/AJ_CharacterEquipmentComponent.h"

#include "Components/CharacterComponents/MovementComponent/AJ_CharacterMovementComponent.h"
#include "Character/AJ_CharacterBase.h"
#include "Actors/Equipment/AJ_RangeWeapon.h"


UAJ_CharacterEquipmentComponent::UAJ_CharacterEquipmentComponent()
{

}


void UAJ_CharacterEquipmentComponent::BeginPlay()
{
	Super::BeginPlay();

	CharacterBase = Cast<AAJ_CharacterBase>(GetOwner());

	if (WeaponClass)
	{
		CurrentWeapon = GetWorld()->SpawnActor<AAJ_RangeWeapon>(WeaponClass);
		CurrentWeapon->AttachToComponent(CharacterBase->GetMesh(), FAttachmentTransformRules::KeepRelativeTransform, FName("WeaponSocket"));
	}
}

void UAJ_CharacterEquipmentComponent::Fire()
{
	if (!CurrentWeapon || !CanFire())
	{
		return;
	}

	CurrentAmmo -= 1;
	AmmoUpdate();
	
	

	
	FVector CameraLocation;
	FRotator CameraRotation;
	GetOwner()->GetActorEyesViewPoint(CameraLocation, CameraRotation);
	
	FVector MuzzleLocation = CurrentWeapon->WeaponMuzzle->GetComponentLocation();
	FRotator MuzzleRotation = CameraRotation;

	FTransform Transform = FTransform(MuzzleRotation, MuzzleLocation);
	
	CharacterBase->OnFireEvent(Transform);

	//............................................................Working only in BP..........................................................//
	
	//MuzzleRotation.Pitch += 10.0f;
	
	// FActorSpawnParameters SpawnParameters;
	// SpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	// // SpawnParameters.bNoFail = true;
	// // SpawnParameters.Owner = GetOwner();
	// // SpawnParameters.Instigator = GetOwner()->GetInstigator();
	//
	// AAJ_Projectile* NewProjectile = GetWorld()->SpawnActor<AAJ_Projectile>(Projectile, MuzzleLocation, MuzzleRotation, SpawnParameters);
	//
	// if (NewProjectile)
	// {
	// 	//NewProjectile->FireInDirection(MuzzleRotation.Vector());
	// 	DrawDebugLine(GetWorld(), MuzzleLocation, MuzzleLocation + MuzzleRotation.Vector() * 100.0f, FColor::Green, true, 5.0f);
	// }
}

bool UAJ_CharacterEquipmentComponent::CanFire()
{
	return CurrentAmmo != 0 && !CharacterBase->bIsDead && (CharacterBase->MovementComponent->bWantToSlide || CharacterBase->MovementComponent->bIsLaunched);
}

void UAJ_CharacterEquipmentComponent::GiveAmmo(int Amount)
{
	CurrentAmmo += Amount;
	AmmoUpdate();
}

int UAJ_CharacterEquipmentComponent::AmmoUpdate_Implementation()
{
	OnAmmoUpdated.Broadcast();
	
	return CurrentAmmo;
}


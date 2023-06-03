// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/CharacterEquipmentComponent/AJ_CharacterEquipmentComponent.h"

#include "Actors/Equipment/AJ_RangeWeapon.h"
#include "Character/AJ_CharacterBase.h"


UAJ_CharacterEquipmentComponent::UAJ_CharacterEquipmentComponent()
{

}


void UAJ_CharacterEquipmentComponent::BeginPlay()
{
	Super::BeginPlay();

	CharacterBase = Cast<AAJ_CharacterBase>(GetOwner());

	CurrentWeapon = GetWorld()->SpawnActor<AAJ_RangeWeapon>();
	CurrentWeapon->AttachToComponent(CharacterBase->GetMesh(), FAttachmentTransformRules::KeepRelativeTransform, FName("WeaponSocket"));
}



void UAJ_CharacterEquipmentComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

void UAJ_CharacterEquipmentComponent::Fire()
{
	CurrentWeapon->Fire();
}


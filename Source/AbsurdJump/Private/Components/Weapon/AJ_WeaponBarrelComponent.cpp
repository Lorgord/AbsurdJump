// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/Weapon/AJ_WeaponBarrelComponent.h"


// Sets default values for this component's properties
UAJ_WeaponBarrelComponent::UAJ_WeaponBarrelComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UAJ_WeaponBarrelComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UAJ_WeaponBarrelComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                              FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}


// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/CharacterComponents/AttributeComponent/AJ_CharacterAttributesComponent.h"


UAJ_CharacterAttributesComponent::UAJ_CharacterAttributesComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}


void UAJ_CharacterAttributesComponent::BeginPlay()
{
	Super::BeginPlay();
}


void UAJ_CharacterAttributesComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}


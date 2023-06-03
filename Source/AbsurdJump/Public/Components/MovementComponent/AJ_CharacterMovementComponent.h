// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "AJ_CharacterMovementComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class ABSURDJUMP_API UAJ_CharacterMovementComponent : public UCharacterMovementComponent
{
	GENERATED_BODY()

public:
	UAJ_CharacterMovementComponent(const FObjectInitializer& ObjectInitializer);
	
	virtual void BeginPlay() override;

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;


	

	UFUNCTION(BlueprintCallable, Category = "Movement | Slide")
	void BeginSlide();

	UFUNCTION(BlueprintCallable, Category = "Movement | Slide")
	void Slide();

	UFUNCTION(BlueprintCallable, Category = "Movement | Slide")
	void EndSlide();

	UFUNCTION(BlueprintCallable, Category = "Movement | OnFly")
	void OnFly();



	

	UPROPERTY(EditDefaultsOnly, Category = "Movement | Slide")
	float SlideImpulse = 300.0f;

	UPROPERTY(BlueprintReadOnly, Category = "Movement | Slide")
	bool bIsLaunched = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "Movement | Slide")
	bool bWantToSlide = false;


private:

	UPROPERTY()
	float SlideLineTraceDistance = 100.0f;
};

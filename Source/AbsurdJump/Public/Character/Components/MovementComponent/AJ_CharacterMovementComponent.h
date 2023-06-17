// Copyright 2023 Egor "Lorgord" Voronov

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "AJ_CharacterMovementComponent.generated.h"


class AAJ_CharacterBase;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class ABSURDJUMP_API UAJ_CharacterMovementComponent : public UCharacterMovementComponent
{
	GENERATED_BODY()

public:
	UAJ_CharacterMovementComponent();

	virtual void BeginPlay() override;

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION()
	void MoveCharacterForward(float DeltaTime);

protected:

	UPROPERTY()
	AAJ_CharacterBase* CharacterBase;
};

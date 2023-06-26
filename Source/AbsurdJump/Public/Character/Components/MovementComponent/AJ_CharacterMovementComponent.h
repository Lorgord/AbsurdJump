// Copyright 2023 Egor "Lorgord" Voronov

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "AJ_CharacterMovementComponent.generated.h"


class AAJ_PlayerCharacter;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class ABSURDJUMP_API UAJ_CharacterMovementComponent : public UCharacterMovementComponent
{
	GENERATED_BODY()

public:
	
	UAJ_CharacterMovementComponent();
	
	virtual void BeginPlay() override;
	virtual void OnRegister() override;
	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	

	void RotatePlayer(float Value);

	void ForwardMovement(float DeltaTime);
	

	UFUNCTION(Server, Unreliable)
	void Server_RotatePlayer(FRotator ActorRotation);
	virtual void Server_RotatePlayer_Implementation(FRotator ActorRotation);
	

	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Movement | Rotation")
	float RotateOnRate = 1.5f;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Movement | Speed")
	float SlowdownSpeedRate = 1.5f;

	
private:

	float ForwardInputScale = 0.0f;
	
	UPROPERTY()
	AAJ_PlayerCharacter* PlayerCharacter = nullptr;
};

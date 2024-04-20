// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "ABAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class ARENABATTLE_API UABAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
	
public:
	UABAnimInstance();

protected:
	// 애님 인스턴스가 처음 생성될 때 한번 호출
	virtual void NativeInitializeAnimation() override;

	// 프레임마다 호출
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadonly, Category = Character)
	TObjectPtr<class ACharacter> Owner;

	UPROPERTY(VisibleAnywhere, BlueprintReadonly, Category = Character)
	TObjectPtr<class UCharacterMovementComponent> Movement;

	UPROPERTY(EditAnywhere, BlueprintReadonly, Category = Character)
	FVector Velocity;

	UPROPERTY(EditAnywhere, BlueprintReadonly, Category = Character)
	float GroundSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadonly, Category = Character)
	uint8 bIsIdle : 1;

	UPROPERTY(EditAnywhere, BlueprintReadonly, Category = Character)
	float MovingThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadonly, Category = Character)
	uint8 bIsFalling : 1;

	UPROPERTY(EditAnywhere, BlueprintReadonly, Category = Character)
	uint8 bIsJumping : 1;

	UPROPERTY(EditAnywhere, BlueprintReadonly, Category = Character)
	float JumpingThreshold;
};

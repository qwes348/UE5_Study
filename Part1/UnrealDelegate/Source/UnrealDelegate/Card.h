// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Card.generated.h"

/*
* 언리얼의 enum타입
* UENUM과 UMETA를 사용 안하면 그대로 C++의 열겨형이다.
*/ 
UENUM()
enum class ECardType : uint8
{
	Student = 1 UMETA(DisplayName = "For Student"),
	Teacher UMETA(DisplayName = "For Teacher"),
	Staff UMETA(DisplayName = "For Staff"),
	Invalid
};

/**
 * 
 */
UCLASS()
class UNREALDELEGATE_API UCard : public UObject
{
	GENERATED_BODY()
	
public:
	UCard();

	ECardType GetCardType() const { return CardType; }
	void SetCardType(ECardType InCardType) { CardType = InCardType; }

private:
	UPROPERTY()
	ECardType CardType;

	UPROPERTY()
	uint32 Id;
};

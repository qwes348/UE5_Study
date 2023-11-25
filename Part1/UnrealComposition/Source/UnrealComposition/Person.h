// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Person.generated.h"

/**
 * 
 */
UCLASS()
class UNREALCOMPOSITION_API UPerson : public UObject
{
	GENERATED_BODY()
	
public:
	UPerson();

	// const로 변경함 -> 반환타입이 &(레퍼런스)인 경우 반환 타입에도 const를 붙여줘야 함
	FORCEINLINE const FString& GetName() const { return Name; }
	FORCEINLINE void SetName(const FString& InName) { Name = InName; }

	FORCEINLINE class UCard* GetCard() const { return Card; }
	FORCEINLINE void SetCard(class UCard* InCard) { Card = InCard; }

protected:
	UPROPERTY()
	FString Name;

	// 전방선언을 통해 헤더를 Include하지 않을 수 있음
	UPROPERTY()
	// 언리얼4까진 이렇게 해도 됐음
	//class UCard* Card;
	// 언리얼5에선 아래 방법을 권장 함
	TObjectPtr<class UCard> Card;
};

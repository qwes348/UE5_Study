// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MyGameInstance.generated.h"

USTRUCT()
struct FStudentData
{
	GENERATED_BODY()

	// public 생략 가능 -> 자동 public

	FStudentData()
	{
		Name = TEXT("홍길동");
		Order = -1;
	}

	// Struct는 인자를 받는 초기화 함수를 만들 수 있음
	FStudentData(FString InName, int32 InOrder) : Name(InName), Order(InOrder) {}

	bool operator==(const FStudentData& InOther) const
	{
		return Order == InOther.Order;
	}

	friend FORCEINLINE uint32 GetTypeHash(const FStudentData& InStudentData)
	{
		return GetTypeHash(InStudentData.Order);
	}

	UPROPERTY()
	FString Name;

	UPROPERTY()
	int32 Order;
};

/**
 * 
 */
UCLASS()
class UNREALCONTAINER_API UMyGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
	
	virtual void Init() override;

private:
	// 값타입이기 때문에 메모리 관리를 할 필요가 없다고 함
	TArray<FStudentData> StudentData;

	// 헤더에서 언리얼 오브젝트 포인터를 선언할때는 TobjectPtr로 감싸야 함
	// 엔진이 자동으로 메모리를 관리할 수 있게 UPROPERTY 매크로를 필수로 붙여줘야 함
	UPROPERTY()
	TArray<TObjectPtr<class UStudent>> Students;

	// Key or Value에 UObject타입이 들어간다면 UPROPERTY 매크로를 필수로 선언해야 함
	TMap<int32, FString> StudentsMap;
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "LessonInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class ULessonInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 인터페이스로 구현할 내용(하위 클래스가 반드시 구현해야 할 내용)은 이쪽 클래스에 구현
 */
class UNREALDELEGATE_API ILessonInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	// 하위 클래스는 이 함수를 반드시 구현해야 함 -> C#과 똑같음
	// 다른점: 인터페이스 함수의 내용을 구현할 수 있음
	// 내용을 구현했다면 하위 클래스는 반드시 override할 필요 없음
	virtual void DoLesson()
	{
		UE_LOG(LogTemp, Log, TEXT("수업에 입장합니다."));
	}
};

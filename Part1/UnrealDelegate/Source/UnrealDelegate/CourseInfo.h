// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CourseInfo.generated.h"

// 델리게이트 매크로
DECLARE_MULTICAST_DELEGATE_TwoParams(FCourseInfoOnChangedSignature, const FString&, const FString&);

/**
 * 
 */
UCLASS()
class UNREALDELEGATE_API UCourseInfo : public UObject
{
	GENERATED_BODY()
	
public:
	UCourseInfo();

	// 멤버 변수로 델리게이트 선언
	FCourseInfoOnChangedSignature OnChanged;

	// 학사 정보를 변경하는 함수
	void ChangeCourseInfo(const FString& InSchoolName, const FString& InNewContents);

private:
	FString Contents;
};

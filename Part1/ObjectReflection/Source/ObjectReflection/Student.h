// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Person.h"
// .generated.h 헤더파일 Include는 제일 밑에 있어야한다. (그렇지 않으면 컴파일 시 에러)
#include "Student.generated.h"

/**
 * 
 */
UCLASS()
class OBJECTREFLECTION_API UStudent : public UPerson
{
	GENERATED_BODY()

public:
	UStudent();

	virtual void DoLesson() override;

private:
	UPROPERTY()
	int32 Id;	// 학번

};

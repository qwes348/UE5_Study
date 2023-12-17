// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CourseInfo.h"
#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MyGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class UNREALDELEGATE_API UMyGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
	UMyGameInstance();

	virtual void Init() override;

private:

	UPROPERTY()
	TObjectPtr<UCourseInfo> CourseInfo;

	UPROPERTY()
	FString SchoolName;

};

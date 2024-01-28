// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 일반 C++ 클래스
 * => UPROPERTY같은 매크로함수를 쓸 수 없음
 */
class UNREALMEMORY_API FStudentManager : public FGCObject
{
public:
	FStudentManager(class UStudent* InStudent) : SafeStudent(InStudent) {}

	const class UStudent* GetStudent() const { return SafeStudent; }

private:
	class UStudent* SafeStudent = nullptr;

	// FGCObject을(를) 통해 상속됨
	void AddReferencedObjects(FReferenceCollector& Collector) override;

	FString GetReferencerName() const override
	{
		// 고유한 클래스 이름을 리턴해주면 됨
		return TEXT("FStudentManager");
	}
};

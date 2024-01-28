// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * �Ϲ� C++ Ŭ����
 * => UPROPERTY���� ��ũ���Լ��� �� �� ����
 */
class UNREALMEMORY_API FStudentManager : public FGCObject
{
public:
	FStudentManager(class UStudent* InStudent) : SafeStudent(InStudent) {}

	const class UStudent* GetStudent() const { return SafeStudent; }

private:
	class UStudent* SafeStudent = nullptr;

	// FGCObject��(��) ���� ��ӵ�
	void AddReferencedObjects(FReferenceCollector& Collector) override;

	FString GetReferencerName() const override
	{
		// ������ Ŭ���� �̸��� �������ָ� ��
		return TEXT("FStudentManager");
	}
};

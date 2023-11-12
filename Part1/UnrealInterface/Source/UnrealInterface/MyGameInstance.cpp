// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameInstance.h"
#include "Person.h"
#include "Student.h"
#include "Teacher.h"
#include "Staff.h"

// 생성자
UMyGameInstance::UMyGameInstance()
{
	// 기본값 설정
	SchoolName = TEXT("기본학교");
}

void UMyGameInstance::Init()
{
	// 필수!!
	Super::Init();

	UE_LOG(LogTemp, Log, TEXT("==================================="));
	// 가변 Array를 생성해서 UStudent, UTeacher, UStaff를 인스턴싱과 동시에 담음
	TArray<UPerson*> Persons = { NewObject<UStudent>(), NewObject<UTeacher>(), NewObject<UStaff>() };
	// 언리얼식 foreach
	for (const auto Person : Persons)
	{
		UE_LOG(LogTemp, Log, TEXT("구성원 이름: %s"), *Person->GetName());
	
	}
	UE_LOG(LogTemp, Log, TEXT("==================================="));

	for (const auto Person : Persons)
	{
		ILessonInterface* LessonInterface = Cast<ILessonInterface>(Person);
		if (LessonInterface)
		{
			UE_LOG(LogTemp, Log, TEXT("%s 님은 수업에 참여할 수 있습니다."), *Person->GetName());
			LessonInterface->DoLesson();
		}
		else
		{
			UE_LOG(LogTemp, Log, TEXT("%s 님은 수업에 참여할 수 없습니다."), *Person->GetName());
		}		
	}
	UE_LOG(LogTemp, Log, TEXT("==================================="));
}

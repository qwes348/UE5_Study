// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameInstance.h"
#include "Student.h"
#include "StudentManager.h"

void CheckUObjectIsValid(const UObject* InObject, const FString& InTag)
{
	if (InObject->IsValidLowLevel())
	{
		UE_LOG(LogTemp, Log, TEXT("[%s] 유효한 언리얼 오브젝트"), *InTag);
	}
	else
	{
		UE_LOG(LogTemp, Log, TEXT("[%s] 유효하지 않은 언리얼 오브젝트"), *InTag);
	}
}

void CheckUObjectIsNull(const UObject* InObject, const FString& InTag)
{
	if (InObject == nullptr)
	{
		UE_LOG(LogTemp, Log, TEXT("[%s] 널 포인터 언리얼 오브젝트"), *InTag);
	}
	else
	{
		UE_LOG(LogTemp, Log, TEXT("[%s] 널 포인터가 아닌 언리얼 오브젝트"), *InTag);
	}
}

void UMyGameInstance::Init()
{
	Super::Init();	

	NonPropStudent = NewObject<UStudent>();
	PropStudent = NewObject<UStudent>();

	NonPropStudents.Add(NewObject<UStudent>());
	PropStudents.Add(NewObject<UStudent>());

	StudentManager = new FStudentManager(NewObject<UStudent>());
}

void UMyGameInstance::Shutdown()
{
	Super::Shutdown();

	CheckUObjectIsNull(NonPropStudent, TEXT("NonPropStudent"));
	CheckUObjectIsValid(NonPropStudent, TEXT("NonPropStudent"));

	CheckUObjectIsNull(PropStudent, TEXT("PropStudent"));
	CheckUObjectIsValid(PropStudent, TEXT("PropStudent"));
	// 결과
	//LogTemp:  [NonPropStudent] 널 포인터가 아닌 언리얼 오브젝트
	//LogTemp : [NonPropStudent] 유효하지 않은 언리얼 오브젝트	-> 댕글링 포인터 문제
	//LogTemp : [PropStudent] 널 포인터가 아닌 언리얼 오브젝트
	//LogTemp : [PropStudent] 유효한 언리얼 오브젝트


	CheckUObjectIsNull(NonPropStudents[0], TEXT("NonPropStudents"));
	CheckUObjectIsValid(NonPropStudents[0], TEXT("NonPropStudents"));

	CheckUObjectIsNull(PropStudents[0], TEXT("PropStudents"));
	CheckUObjectIsValid(PropStudents[0], TEXT("PropStudents"));
	// 결과
	//LogTemp: [NonPropStudents] 널 포인터가 아닌 언리얼 오브젝트
	//LogTemp : [NonPropStudents] 유효하지 않은 언리얼 오브젝트	-> 댕글링 포인터 문제
	//LogTemp : [PropStudents] 널 포인터가 아닌 언리얼 오브젝트
	//LogTemp : [PropStudents] 유효한 언리얼 오브젝트

	// 일반 C++클래스의 경우 예제
	const UStudent* StudentInManager = StudentManager->GetStudent();
	delete StudentManager;
	StudentManager = nullptr;

	CheckUObjectIsNull(StudentInManager, TEXT("StudentInManager"));
	CheckUObjectIsValid(StudentInManager, TEXT("StudentInManager"));
	// 결과 (FGCObject 상속 전)
	//LogTemp: [StudentInManager] 널 포인터가 아닌 언리얼 오브젝트
	//LogTemp : [StudentInManager] 유효하지 않은 언리얼 오브젝트	 -> 댕글링 포인터 문제

	// 결과 (FGCObject 상속 후)
	//LogTemp: [StudentInManager] 널 포인터가 아닌 언리얼 오브젝트
	//LogTemp : [StudentInManager] 유효한 언리얼 오브젝트	-> 댕글링 포인터 문제 해결 !
}

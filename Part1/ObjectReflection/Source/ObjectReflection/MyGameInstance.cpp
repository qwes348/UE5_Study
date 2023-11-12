// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameInstance.h"
#include "Student.h"
#include "Teacher.h"

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

	UE_LOG(LogTemp, Log, TEXT("============================================="));

	// 이 둘은 동일한 객체를 가리킨다.
	UClass* ClassRuntime = GetClass();
	UClass* ClassCompile = UMyGameInstance::StaticClass();
	//! check에 false가 들어가면 크래시 리포트가 뜨면서 에디터가 종료됨
	//check(ClassRuntime == ClassCompile);
	//! 에디터가 종료되는게 싫다면 아래 ensure함수를 쓰면 에디터가 종료되지 않고 에러 로그를 띄움
	//ensure(ClassRuntime != ClassCompile);
	//! 원하는 텍스트를 에러에 추가하고 싶다면 ensureMsgf함수를 사용
	ensureMsgf(ClassRuntime != ClassCompile, TEXT("일부러 에러를 발생시킨 코드"));

	// 출력: LogTemp: 학교를 담당하는 클래스 이름 : MyGameInstance
	UE_LOG(LogTemp, Log, TEXT("학교를 담당하는 클래스 이름 : %s"), *ClassRuntime->GetName());

	SchoolName = TEXT("청강문화산업대학교");

	// 인스턴스의 값 출력하기 : 청강문화산업대학교
	UE_LOG(LogTemp, Log, TEXT("학교 이름 : %s"), *SchoolName);
	// 클래스의 기본 값 출력하기 : 공백 문자 출력
	//! 공백 문자가 출력되는 이유: 기본 값 초기화는 에디터 실행 시 진행된다. -> 에디터 재시작 필요
	UE_LOG(LogTemp, Log, TEXT("학교 이름 기본값 : %s"), *GetClass()->GetDefaultObject<UMyGameInstance>()->SchoolName);

	UE_LOG(LogTemp, Log, TEXT("============================================="));

	// UObject클래스를 상속받은 클래스를 인스턴싱 하는 방법
	UStudent* Student = NewObject<UStudent>();
	UTeacher* Teacher = NewObject<UTeacher>();
	
	// getter, setter 활용
	Student->SetName(TEXT("학생1"));
	UE_LOG(LogTemp, Log, TEXT("새로운 학생 이름: %s"), *Student->GetName());		// 학생1

	// 언리얼 리플렉션 시스템을 이용한 getter, setter
	FString CurrentTeacherName;
	FString NewTeacherName(TEXT("이득우"));
	FProperty* NameProp = UTeacher::StaticClass()->FindPropertyByName(TEXT("Name"));
	if (NameProp)
	{
		NameProp->GetValue_InContainer(Teacher, &CurrentTeacherName);
		UE_LOG(LogTemp, Log, TEXT("현재 선생님 이름: %s"), *CurrentTeacherName);		// 이선생

		NameProp->SetValue_InContainer(Teacher, &NewTeacherName);
		UE_LOG(LogTemp, Log, TEXT("새로운 선생님 이름: %s"), *Teacher->GetName());	// 이득우
	}

	UE_LOG(LogTemp, Log, TEXT("============================================="));

	Student->DoLesson();

	// 언리얼 리플렉션 시스템을 이용한 함수 호출
	// 함수를 찾아서 함수 포인터에 담음
	UFunction* DoLessonFunc = Teacher->GetClass()->FindFunctionByName(TEXT("DoLesson"));
	if (DoLessonFunc)
	{
		// 함수가 존재한다면 실행 두번째 인자는 파라미터 -> Unity의 Invoke()
		Teacher->ProcessEvent(DoLessonFunc, nullptr);
	}

	UE_LOG(LogTemp, Log, TEXT("============================================="));
}

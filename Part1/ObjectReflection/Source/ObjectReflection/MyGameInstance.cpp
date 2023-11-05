// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameInstance.h"

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
}

// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameInstance.h"

void UMyGameInstance::Init()
{
	//! 중요! 빼먹으면 안됨
	Super::Init();

	static const TCHAR LogCharArray[] = TEXT("Hello Unreal");
	UE_LOG(LogTemp, Log, LogCharArray);

	FString LogCharString = LogCharArray;
	UE_LOG(LogTemp, Log, TEXT("%s"), *LogCharString);

	const TCHAR* LongCharPtr = *LogCharString;
	//! const가 아닌 직접 포인터로 받고싶다면(수정할 일이 있다면) 아래 방법으로 접근 가능
	TCHAR* LogcharDataPtr = LogCharString.GetCharArray().GetData();

	TCHAR LogCharArrayWithSize[100];
	FCString::Strcpy(LogCharArrayWithSize, LogCharString.Len(), *LogCharString);

	//! 특정 문자열을 포함하는지 확인하기
	// ESearchCase::CaseSensitive를 넣으면 대소문자를 구분함
	if (LogCharString.Contains(TEXT("unreal"), ESearchCase::IgnoreCase))
	{
		// 특정 문자열이 시작하는 인덱스 찾기
		int32 Index = LogCharString.Find(TEXT("unreal"), ESearchCase::IgnoreCase);
		// "unreal"이 시작되는 위치부터 끝까지 문자열을 자름
		FString EndString = LogCharString.Mid(Index);
		UE_LOG(LogTemp, Log, TEXT("Find Test: %s"), *EndString);	// output: Find Test: Unreal
	}

	//! 특정 문자를 기준으로 문자열 나누기
	FString Left, Right;
	if (LogCharString.Split(TEXT(" "), &Left, &Right))
	{
		// 한글을 출력하려면 다른이름으로 저장에서 UTF-8로 인코딩을 바꿔야한다.
		UE_LOG(LogTemp, Log, TEXT("Split Test: %s 와 %s"), *Left, *Right);
	}

	int32 IntValue = 32;
	float FloatValue = 3.141592;

	//! int, float 타입을 직접 출력
	FString FloatIntString = FString::Printf(TEXT("Int:%d Float:%f"), IntValue, FloatValue);
	//! int, float 타입을 string으로 변환해서 출력
	FString FloatString = FString::SanitizeFloat(FloatValue);
	FString IntString = FString::FromInt(IntValue);
	
	UE_LOG(LogTemp, Log, TEXT("%s"), *FloatIntString);
	UE_LOG(LogTemp, Log, TEXT("Int:%s Float:%s"), *IntString, *FloatString);
	// output: 
	// LogTemp: Int:32 Float:3.141592
	// LogTemp: Int:32 Float:3.141592

	//! String에서 int, float으로 변환
	int32 IntValueFromString = FCString::Atoi(*IntString);
	float FloatValueFromString = FCString::Atof(*FloatString);
	FString FloatIntString2 = FString::Printf(TEXT("Int:%d Float:%f"), IntValueFromString, FloatValueFromString);
	UE_LOG(LogTemp, Log, TEXT("%s"), *FloatIntString2);
	// output: LogTemp: Int:32 Float:3.141592

	//! FName의 대소문가 구별 안함 특성 확인
	FName key1(TEXT("PELVIS"));
	FName key2(TEXT("pelvis"));
	UE_LOG(LogTemp, Log, TEXT("FName 비교 결과: %s"), key1 == key2 ? TEXT("같음") : TEXT("다름"));
	// output: LogTemp: FName 비교 결과: 같음

	for (int i = 0; i < 10000; i++)
	{
		// !key가 글로벌pool에 있는지 확인하기
		// 이렇게 하면 오버헤드 발생할 수 있음
		FName SearchInNamePool = FName(TEXT("pelvis"));
		// 이렇게 한번만 처리해주게 하는게 오버헤드를 방지한다고 한다.
		const static FName StaticOnlyOnce(TEXT("pelvis"));
	}
}

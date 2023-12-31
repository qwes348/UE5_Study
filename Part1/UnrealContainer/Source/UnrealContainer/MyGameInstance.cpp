// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameInstance.h"
#include "Algo/Accumulate.h"

FString MakeRandomName()
{
	TCHAR FirstChar[] = TEXT("김이박최");
	TCHAR MiddleChar[] = TEXT("상혜지성");
	TCHAR LastChar[] = TEXT("수은원연");

	TArray<TCHAR> RandArray;
	RandArray.SetNum(3);
	// 언리얼에서 제공하는 랜덤인덱스 뽑기 함수 -> FMath::RandRange()
	RandArray[0] = FirstChar[FMath::RandRange(0, 3)];
	RandArray[1] = MiddleChar[FMath::RandRange(0, 3)];
	RandArray[2] = LastChar[FMath::RandRange(0, 3)];

	// TArray<TCHAR> => FString
	return RandArray.GetData();
}

void UMyGameInstance::Init()
{
	Super::Init();

	const int32 ArrayNum = 10;
	TArray<int32> Int32Array;

	for (int32 ix = 1; ix <= ArrayNum; ix++)
	{
		// 1~10까지 TArray에 넣음
		Int32Array.Add(ix);
	}

	// 파라미터로 짝수인지를 확인하는 람다 함수를 넣음
	Int32Array.RemoveAll(
		[](int32 Val)
		{
			return Val % 2 == 0;
		}
	);

	// 다시 짝수를 넣어줌
	Int32Array += {2, 4, 6, 8, 10};

	// C언어 스타일로 Array를 초기화하고 값을 넣기
	TArray<int32> Int32ArrayCompare;
	int32 CArray[] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 10 };
	Int32ArrayCompare.AddUninitialized(ArrayNum);
	FMemory::Memcpy(Int32ArrayCompare.GetData(), CArray, sizeof(int32) * ArrayNum);

	// 처음 TArray와 C스타일 Array로 카피한 TArray의 값이 같은지 확인 -> 실패라면 에러가 출력됨
	ensure(Int32Array == Int32ArrayCompare);

	// 일반적으로 루프를 돌며 합계를 구하는 방법
	int32 Sum = 0;
	for (const int32& Int32Elem : Int32Array)
	{
		Sum += Int32Elem;
	}

	ensure(Sum == 55);

	// 미리 만들어진 함수를 사용해서 합계를 구하는 방법
	int32 SumByAlgo = Algo::Accumulate(Int32Array, 0);
	ensure(Sum == SumByAlgo);

	TSet<int32> Int32Set;
	for (int32 ix = 1; ix <= ArrayNum; ix++)
	{
		Int32Set.Add(ix);
	}

	// TSet는 RemoveAll함수가 없다.
	Int32Set.Remove(2);
	Int32Set.Remove(4);
	Int32Set.Remove(6);
	Int32Set.Remove(8);
	Int32Set.Remove(10);
	// 다시 짝수를 넣어주지만 순서가 보장되지 않는다
	// 즉 { 1, 3, 5, 7, 9, 2, 4, 6, 8, 10 } 순서로 들어가지 않는다.
	Int32Set.Add(2);
	Int32Set.Add(4);
	Int32Set.Add(6);
	Int32Set.Add(8);
	Int32Set.Add(10);

	
	const int32 StudentNum = 300;
	for (int32 ix = 1; ix <= StudentNum; ix++)
	{
		// 랜덤네임과 index로 FStudentData인스턴스를 생성
		StudentData.Emplace(FStudentData(MakeRandomName(), ix));
	}

	TArray<FString> AllStudentsNames;
	// Algo라이브러리를 사용해 StudentData -> AllStudentsName으로 이름만 복사
	// 1: source, 2: dest, 3: lamda
	Algo::Transform(StudentData, AllStudentsNames,
		[](const FStudentData& Val)
		{
			return Val.Name;
		}
	);

	UE_LOG(LogTemp, Log, TEXT("모든 학생 이름의 수 : %d"), AllStudentsNames.Num());

	// TSet은 중복을 혀용하지 않음
	TSet<FString> AllUniqueNames;
	Algo::Transform(StudentData, AllUniqueNames,
		[](const FStudentData& Val)
		{
			return Val.Name;
		}
	);

	UE_LOG(LogTemp, Log, TEXT("중복 없는 학생 이름의 수 : %d"), AllUniqueNames.Num());

	// TMap
	Algo::Transform(StudentData, StudentsMap,
		[](const FStudentData& Val)
		{
			return TPair<int32, FString>(Val.Order, Val.Name);
		}
	);

	UE_LOG(LogTemp, Log, TEXT("순번에 따른 학생 맵의 레코드 수 : %d"), StudentsMap.Num());

	// TMap - 키, 밸류 스왑
	TMap<FString, int32> StudentsMapByUniqueName;
	Algo::Transform(StudentData, StudentsMapByUniqueName,
		[](const FStudentData& Val)
		{
			return TPair<FString, int32>(Val.Name, Val.Order);
		}
	);

	UE_LOG(LogTemp, Log, TEXT("이름에 따른 학생 맵의 레코드 수 : %d"), StudentsMapByUniqueName.Num());

	// 중복을 허용하는 TMultiMap
	TMultiMap<FString, int32> StudentsMapByName;
	Algo::Transform(StudentData, StudentsMapByName,
		[](const FStudentData& Val)
		{
			return TPair<FString, int32>(Val.Name, Val.Order);
		}
	);

	UE_LOG(LogTemp, Log, TEXT("이름에 따른 학생 멀티맵의 레코드 수 : %d"), StudentsMapByName.Num());

	// 특정 이름 찾기
	const FString TargetName(TEXT("이혜은"));
	TArray<int32> AllOrders;
	StudentsMapByName.MultiFind(TargetName, AllOrders);

	UE_LOG(LogTemp, Log, TEXT("이름이 %s인 학생 수 : %d"), *TargetName, AllOrders.Num());

	// TSet의 담아보기
	// 커스텀 구조체에 GetTypeHash함수가 없으면 에러가 난다
	TSet<FStudentData> StudentsSet;
	for (int32 ix = 1; ix <= 300; ix++)
	{
		StudentsSet.Emplace(FStudentData(MakeRandomName(), ix));
	}
}


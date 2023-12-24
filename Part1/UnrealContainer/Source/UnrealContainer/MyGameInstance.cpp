// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameInstance.h"
#include "Algo/Accumulate.h"

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

	
}

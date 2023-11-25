// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameInstance.h"
#include "Person.h"
#include "Student.h"
#include "Teacher.h"
#include "Staff.h"
#include "Card.h"

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

	for (const auto person : Persons)
	{
		const UCard* OwnCard = person->GetCard();
		check(OwnCard);
		ECardType CardType = OwnCard->GetCardType();
		// 카드 타입으 int형으로 찍힘 (1, 2, 3)
		UE_LOG(LogTemp, Log, TEXT("%s님이 소유한 카드 종류 %d"), *person->GetName(), CardType);

		const UEnum* CardEnumType = FindObject<UEnum>(nullptr, TEXT("/Script/UnrealComposition.ECardType"));
		if (CardEnumType)
		{
			FString CardMetaData = CardEnumType->GetDisplayNameTextByValue((int64)CardType).ToString();
			// enum타입의 UMETA로 설정한 DisplayName이 찍힘 (For Teacher, For Student, For Staff)
			UE_LOG(LogTemp, Log, TEXT("%s님이 소유한 카드 종류 %s"), *person->GetName(), *CardMetaData);
		}
	}

	UE_LOG(LogTemp, Log, TEXT("==================================="));
}

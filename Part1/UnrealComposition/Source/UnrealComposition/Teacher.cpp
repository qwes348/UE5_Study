// Fill out your copyright notice in the Description page of Project Settings.


#include "Teacher.h"
#include "Card.h"

UTeacher::UTeacher()
{
	Name = TEXT("이선생");
	// 카드는 상위 클래스에서 생성했기 때문에 카드 타입만 변경
	Card->SetCardType(ECardType::Teacher);
}

void UTeacher::DoLesson()
{
	ILessonInterface::DoLesson();
	UE_LOG(LogTemp, Log, TEXT("%s님은 가르칩니다."), *Name);
}

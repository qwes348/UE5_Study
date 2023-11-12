---
sticker: emoji//1f47e
tistoryBlogName: trialdeveloper
tistoryTitle: "[Part1] 6.언리얼 오브젝트 리플렉션 시스템 2"
tistoryTags: UE5, 인프런, 이득우
tistoryVisibility: "3"
tistoryCategory: "1149193"
tistoryPostId: "92"
tistoryPostUrl: https://trialdeveloper.tistory.com/92
---

# 실습
---
## 예제를 위한 클래스 다이어그램
---
- 지난 프로젝트에 이어서 예제 구현
- 어떤 학교에서 학생과 교수가 함께 수업하는 상황의 구현
- 학교 정보는 `GameInstance`에서 지정
- `UObject`를 상속받는 3개의 클래스
	- 인물 클래스 `Person`
	- 학생 클래스 `Student`
	- 선생 클래스 `Teacher`
![512x250](https://i.imgur.com/LRJkzZd.png)

## 언리얼 오브젝트의 속성과 함수
---
- 클래스에 설정할 프로퍼티 정보
- `Person`에는 `DoLesson`이라는 가상 함수가 있음.
	- `Student`의 `DoLesson`은 수업을 듣는 행동
	- `Teacher`의 `DoLesson`은 수업을 가르치는 행동
![512x250](https://i.imgur.com/4gBcAfK.png)

```ad-tip
1. `.generated.h` 헤더 `#Include`는 제일 밑에 있어야한다. (그렇지 않으면 컴파일 시 에러)
2. `TEXT()`의 포맷으로 `FString`을 넘길때는 앞에 `*(포인터)`를 붙이자
3. 클래스 변수의 기본값을 선언해놨으면 미리 컴파일을 해두자
4. `Super::`를 통해 상위 클래스의 함수 호출하는데 **빨간줄이** 뜨면 하위 클래스의 헤더파일에서 엔터 한번 띄워주고 다시 컴파일을 하면 된다.
5. `cpp`에서 다른 클래스의 헤더를 `#Include`할 때 현재 `cpp`파일의 헤더파일이 최상단에 와야한다.
	1. 예시 in `MyGameInstance.cpp` 
	```cpp
	#include "MyGameInstance.h"
	#include "Student.h"
	#include "Teacher.h"
	```
```

```ad-note
title: UObject클래스를 상속받은 클래스를 인스턴싱 하는 방법

`UStudent* Student = NewObject<UStudent>();`
```


## 코드
---
### Person.h
```cpp
#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Person.generated.h"

/**
 * 
 */
UCLASS()
class OBJECTREFLECTION_API UPerson : public UObject
{
	GENERATED_BODY()
	
public:
	// 생성자
	UPerson();

	UFUNCTION()
	virtual void DoLesson();

	// getter
	const FString& GetName() const;
	// setter
	void SetName(const FString& InName);

protected:
	UPROPERTY()
	FString Name;

	UPROPERTY()
	int32 Year;

private:

};

```
### Person.cpp
```cpp
#include "Person.h"

UPerson::UPerson()
{
	// 디폴트값 세팅
	Name = TEXT("홍길동");
	Year = 1;
}

void UPerson::DoLesson()
{
	UE_LOG(LogTemp, Log, TEXT("%s 님이 수업에 참여합니다."), *Name);
}

const FString& UPerson::GetName() const
{
	return Name;
}

void UPerson::SetName(const FString& InName)
{
	Name = InName;
}
```
### Student.h
```cpp
#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Person.h"
// .generated.h 헤더파일 Include는 제일 밑에 있어야한다. (그렇지 않으면 컴파일 시 에러)
#include "Student.generated.h"

/**
 * 
 */
UCLASS()
class OBJECTREFLECTION_API UStudent : public UPerson
{
	GENERATED_BODY()

public:
	UStudent();

	virtual void DoLesson() override;

private:
	UPROPERTY()
	int32 Id;	// 학번

};
```
### Student.cpp
```cpp
#include "Student.h"

UStudent::UStudent()
{
	// 기본값 설정 -> 기본값을 설정하면 컴파일을 해두자
	Name = TEXT("이학생");
	Year = 1;
	Id = 1;
}

void UStudent::DoLesson()
{
	Super::DoLesson();

	UE_LOG(LogTemp, Log, TEXT("%d학년 %d번 %s님이 수업을 듣습니다."), Year, Id, *Name);
}
```
### Teacher.h
```cpp
#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Person.h"
#include "Teacher.generated.h"

/**
 * 
 */
UCLASS()
class OBJECTREFLECTION_API UTeacher : public UPerson
{
	GENERATED_BODY()

	
public:
	UTeacher();

	virtual void DoLesson() override;

private:
	UPROPERTY()
	int32 Id;
};
```
### Teacher.Cpp
```cpp
#include "Teacher.h"

UTeacher::UTeacher()
{
	Name = TEXT("이선생");
	Year = 3;
	Id = 1;
}

void UTeacher::DoLesson()
{
	Super::DoLesson();

	UE_LOG(LogTemp, Log, TEXT("%d년차 선생님 %s님이 수업을 강의합니다."), Year, *Name);
}
```
### MyGameInstance.cpp (추가된 부분만)
```cpp
#include "MyGameInstance.h"
#include "Student.h"
#include "Teacher.h"

.
.
.
{
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
```

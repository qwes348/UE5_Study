---
sticker: emoji//1f47e
tistoryBlogName: trialdeveloper
tistoryTitle: "[Part1] 5.언리얼 오브젝트 리플렉션 시스템 1"
tistoryTags: UE5, 인프런, 이득우
tistoryVisibility: "3"
tistoryCategory: "1149193"
tistoryPostId: "89"
tistoryPostUrl: https://trialdeveloper.tistory.com/89
---
# 언리얼 오브젝트의 특징
---

## 언리얼 오브젝트의 리플렉션 시스템
---
🔗[언리얼 리플렉션 시스템](https://www.unrealengine.com/ko/blog/unreal-property-system-reflection)
- 리플렉션(Reflection)은 프로그램이 실행시간에 자기 자신을 조사하는 기능.
- C++ 는 어떠한 형태의 리플렉션도 지원하지 않는다.
- 언리얼에서는 자체 리플렉션 시스템을 구축 함.
- `UENUM(), UCLASS(), USTRUCT(), UFUNCTION(), UPROPERTY()`매크로를 클래스에 달아주면 작동
- `UPROPERTY()`매크로를 붙이지 않은 멤버 변수는 언리얼 엔진의 자동 메모리 관리(GC)에 포함되지 않는다.
	- 따라서 개발자가 직접 메모리 관리를 해줘야한다.

## 언리얼 오브젝트의 구성
---
- 언리얼 오브젝트에는 특별한 프로퍼티와 함수를 지정할 수 있음.
	- 관리되는 클래스 멤벼 변수: `UPROPERTY()`
	- 관리되는 클레스 멤버 함수: `UFUNCTION()`
	- 에디터와 연동되는 메타데이터를 심을 수 있음
- 모든 언리올 으베즉트는 클래스 정봐와 함께 함.
	- 클래스를 사용해 자신이 가진 프로퍼티와 함수 정보를 컴파일 타임과 런타임에서 조회할 수 있음
- 이렇게 다양한 기능을 제공하는 언리얼 오브젝트는 NewObject API를 사용해 생성해야 함.
![](https://i.imgur.com/vfxMJq5.png)

## 언리얼 오브젝트의 클래스 기본 오브젝트
---
- 언리얼 클래스 정보에는 클래스 기본 오브젝트(Class Defaulut Object)가 함께 포함되어 있음.
	- 클래스 기본 오브젝트는 줄여서 **CDO**라고 부름
- CDO는 언리얼 객체가 가진 기본 값을 보관하는 템플릿 객체임.
- 한 클래스로부터 다수의 물체를 생성해 게임 콘텐츠에 배치할 때 일관성 있게 기본 값을 조정하는데 유용하게 사용됨.
- CDO는 클래스 정보로부터 `GetDefaultObject()`함수를 통해 얻을 수 있음.
- UClass 및 CDO는 엔진 초기화 과정에서 생성되므로 콘텐츠 제작에서 안심하고 사용할 수 있음
![](https://i.imgur.com/zQ1PyIb.png)
🔗[언리얼 오브젝트의 처리](https://docs.unrealengine.com/4.27/ko/ProgrammingAndScripting/ProgrammingWithCPP/UnrealArchitecture/Objects/Optimizations/)

## 예제를 위한 클래스 다이어그램
---
- 어떤 학교에서 학생과 교수가 함께 수업하는 상황의 구현 (다음 강의에서)
- 학교 정보는 `GameInstance`에서 지정
- 인물 클래스 `Person`
	- 학생 클래스 `Student`
	- 선생 클리스 `Teacher`
![](https://i.imgur.com/o7JVRUL.png)

## 실습 코드
---
### MyGameInstance.h
```cpp
// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MyGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class OBJECTREFLECTION_API UMyGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
	UMyGameInstance();

	virtual void Init() override;

private:
	UPROPERTY()
	FString SchoolName;

};

```
### MyGameInstance.cpp
```cpp
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

```

# 정리
---
## 언리얼 오브젝트 시스템
---
1. 언리얼 오브젝트에는 항상 클래스 정보를 담은 UClass 객체가 매칭되어 있다.
2. UClass로부터 언리얼 오브젝트의 정보를 파악할 수 있음
3. UClass에는 클래스 기본 오브젝트(CDO)가 연결되어 있어 이를 활용해 개발의 생산성을 향상시킬 수 있음.
4. 클래스 정보와 CDO는 엔진 초기화 과정에서 생성되므로 게임 개발에서 안전하게 사용 가능.
5. **헤더 정보를 변경하거나 생성자 정보를 변경하면 에디터를 끄고 컴파일하는것이 안정적임.**
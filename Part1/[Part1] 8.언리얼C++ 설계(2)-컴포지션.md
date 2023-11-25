---
sticker: emoji//1f47e
tistoryBlogName: trialdeveloper
tistoryTitle: "[Part1] 8.언리얼C++ 설계(2)-컴포지션"
tistoryTags: UE5, 인프런, 이득우
tistoryVisibility: "3"
tistoryCategory: "0"
tistoryPostId: "95"
tistoryPostUrl: https://trialdeveloper.tistory.com/95
---
# 언리얼 오브젝트의 컴포지션
---
## 컴포지션(Composition)
---
- 객체 지향 설계에서 상속이 가진 Is-A 관계만 의존해서는 설계와 유지보수가 어려움.
- 컴포지션은 객체 지향 설계에서 Has-A 관계를 구현하는 설계 방법
- 컴포지션의 활용
	- 복합적인 기능을 가진 거대한 클래스를 효과적으로 설계하는데 유용하게 사용할 수 있음.
	- 아래 코드는 어떤 사람이 카드를 소유하는 개념을 컴포지션을 사용해서 구현한 예시
```cpp
class Card
{
public:
	CarD(int InId) : Id(InId) {}
	int Id = 0;
};

class Person
{
public:
	Person(Card InCard) : IdCard(InCard) {}

protected:
	Card IdCard;
};
```

## 모던 객체 설계 기법과 컴포지션
---
- 좋은 객체지향 설계 패턴을 제작하기 위한 모던 객체 설계 기법(**SOLID**)
	- **S**ingle Responsibility Principle (단일 책임 원칙)
		- → 하나의 객체는 하나의 의무만을 가지도록 설계한다.
	- **O**pen-Closed Principle (개방 폐쇠 원칙)
		- → 기존에 구현된 코드를 변경하지 않으면서 새로운 기능을 추가할 수 있도록 설계한다.
	- **L**iskov Subsituion Principle (리스코프 치환 원칙)
		- → 자식 객체를 부모 객체로 변경해도 작동우 문제 없을 정도로 상속을 단순히 사용한다.
	- **I**nterface Segregation Design (인터페이스 분리 원칙)
		- → 객체가 구현해야 할 기능이 많다면 이들을 여러 개의 단순한 인터페이스들로 분리해 설계한다.
	- **D**ependency Injection Principle (의존성 역전 원칙)
		- 구현된 실물보다 구축해야 할 추상적 개념에 의존한다.

> 모던 객체 설계 기법의 설계 핵심은 상속을 단순화하고, 단순한 기능을 가진 다수의 객체를 조합해 복잡한 객체를 구성하는데 있음.


## 컴포지션 설계 예제 
---
- 학교 구성원 시스템의 설계 예시
	- 학교 구성원을 위해 **출입증**을 만들기로 한다.
	- 출입증은 `Person`에서 구현해 상속시킬 것인가? 아니면 컴포지션으로 분리할 것인가?
- `Person`에서 직접구현해 상속시키는 경우의 문제
	- 새로운 형태의 구성원이 등장한다면(예를 들어 출입증이 없는 외부 연수생)`Person`을 수정할 것인가?
	- 상위 클래스 `Person`을 수정하면, 하위 클래스들의 동작은 문제 없음을 보장할 수 있는가?
- 따라서 설계적으로 출입증은 **컴포지션**으로 분리하는 것이 바람직함.
- 그렇다면 컴포지션으로만 포삼시키면 모든 것이 해결될 수 있는가?

> 효과적인 설계를 위해 프로그래밍 언어가 제공하는 고급 기법을 활용해야 함.


## 언리얼 엔진에서의 컴포지션 구현 방법
---
- 하나의 언리얼 오브젝트에는 항상 클래스 기본 오브젝트 `CDO`가 있다.
- 언리얼 오브젝트간의 컴포지션은 어떻게 구현할 것인가?
- 언리얼 오브젝트에 다른 언리얼 오브젝트를 조함할 때 다음의 선택지가 존재한다.
	- `방법 1`: `CDO`에 미리 언리얼 오브젝트를 생성해 조합한다. (필수적 포함)
	- `방법 2`: `CDO`에 빈 포인터만 넣고 런타임에서 언리얼 오브젝트를 생성해 조합한다. (선택적 포함)
- 언리얼 오브젝트를 생성할 때 컴포지션 정보를 구축할 수 있다.
	- 내가 소유한 언리얼 오브젝트를 `Subobject`라고 한다.
	- 나를 소유한 언리얼 오브젝트를 Outher라고 한다.
![600](https://i.imgur.com/lT6GdZ6.png)


## 📌기억해야 할 것들
---
- 언리얼에서의 `열거형`은 다음과 같이 선언한다.
```cpp
/*
* 언리얼의 enum타입
* UENUM과 UMETA를 사용 안하면 그대로 C++의 열겨형이다.
*/ 
UENUM()
enum class ECardType : uint8
{
	Student = 1 UMETA(DisplayName = "For Student"),
	Teacher UMETA(DisplayName = "For Teacher"),
	Staff UMETA(DisplayName = "For Staff"),
	Invalid
};
```
- 열거형의 `UMETA`를 받아와서 `DisplayName`을 출력할려면 다음과 같이 한다.
```cpp
const UEnum* CardEnumType = FindObject<UEnum>(nullptr, TEXT("/Script/UnrealComposition.ECardType"));
if (CardEnumType)
{
	FString CardMetaData = CardEnumType->GetDisplayNameTextByValue((int64)CardType).ToString();
	// enum타입의 UMETA로 설정한 DisplayName이 찍힘 (For Teacher, For Student, For Staff)
	UE_LOG(LogTemp, Log, TEXT("%s님이 소유한 카드 종류 %s"), *person->GetName(), *CardMetaData);
}
```
- 언리얼5에서의 `클래스 전방선언`은 아래와 같이 한다.
```cpp
	// 전방선언을 통해 헤더를 Include하지 않을 수 있음
	UPROPERTY()
	// 언리얼4까진 이렇게 해도 됐음
	class UCard* Card;
	// 언리얼5에선 아래 방법을 권장 함
	TObjectPtr<class UCard> Card;
```


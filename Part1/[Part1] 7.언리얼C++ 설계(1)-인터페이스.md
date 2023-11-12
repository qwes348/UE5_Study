---
sticker: emoji//1f47e
tistoryBlogName: trialdeveloper
tistoryTitle: "[Part1] 7.언리얼C++ 설계(1)-인터페이스"
tistoryTags: UE5, 인프런, 이득우
tistoryVisibility: "3"
tistoryCategory: "1149193"
tistoryPostId: "93"
tistoryPostUrl: https://trialdeveloper.tistory.com/93
---
## 언리얼 C++ 인터페이스
---
- 인터페이스란?
	- 객체가 **반드시** 구현해야 할 행동을 지정하는데 활용되는 타입
	- 다형성(Polymorphism)의 구현, 의존성이 분리(Decouple)된 설계에 유용하게 활용.
- 언리얼 엔진에서 게임 콘텐으를 구성하는 오브젝트의 설계 예시
	- 월드에 배치되는 모든 오브젝트. 안 움직이는 오브젝트를 포함(`Actor`)
	- 움직이는 오브젝트(`Pawn`)
	- 길찾기 시스템을 **반드시** 사용하면서 움직이는 오브젝트 ⇒ (`INavAgentInterface` 인터페이스를 구현한 `Pawn`)
![512x 250](https://i.imgur.com/MTLWiIq.png)

## 예제를 위한 클래스 다이어그램
---
- 수업에 참여하는 사람과 참여하지 않는 사람의 구분
	- 수업에 **반드시** 참여해야 하는 학교 구성원: 학생, 선생
	- 수업에 참여하지 않는 학교 구성원: 교직원
	- 수업 행동에 관련된 인터페이스: `ILessonInterface`
![512x250](https://i.imgur.com/D7UJb8s.png)

## 언리얼 C++ 인터페이스 특징
---
- 인터페이스를 생성하면 두 개의 클래스가 생성됨
	- `U`로 시작하는 타입 클래스
	- `I`로 시작하는 인터페이스 클래스
- 객체를 설계할 때 I인터페이스 클래스를 사용
	- U타입 클래스 정보는 런타임에서 인터페이스 구현 여부를 파악하는 용도로 사용됨.
	- 실제로 U타입 클래스에서 작업할 일은 없음
	- 인터페이스에 관련된 구성 및 구현은 I인터페이스 클래스에서 진행
- C++ 인터페이스의 특징
	- 추상 타입으로만 선언할 수 있는 `Java`, `C#`과 달리 언리얼은 인터페이스에도 구현이 가능함.
![512](https://i.imgur.com/cM1TjLz.png)


## 📌기억해야 할 것들
---
- 언리얼 인터페이스는 두 개의 클래스를 생성한다.
	- 인터페이스로서 구현할 내용은 `UNREALINTERFACE_API`가 붙은 클래스에 구현하면 된다.
- 언리얼 인터페이스는 추상 함수의 내용을 구현할 수 있다.
	- 내용을 구현하게 되면 상속받는 하위 클래스가 반드시 함수를 구현 할 필요가 없다.
- 하위 클래스에서 상위 인터페이스의 함수를 호출하고 싶을때는 `Super::`키워드를 쓸 수 없다.
	- `Super::`는 클래스가 상속받고있는 상위 클래스에 우선된다.
	- `인터페이스 이름::함수이름()`으로 써야한다.
- 어떤 인스턴스 `A`가 `ILessonInterface`를 상속받고 있는지 확인하기 위해서는 다음과 같이 캐스팅을 사용한다.
```cpp
ILessonInterface* LessonInterface = Cast<ILessonInterface>(A);
if (LessonInterface)
{
	// A는 ILessonInterface를 상속받는다.
}
else
{
	// A는 ILessonInterface를 상속받지않는다.
}	
```
- 언리얼식 `foreach`문은 아래와 같이 쓴다.
```cpp
for (const auto Person : Persons)
{
	UE_LOG(LogTemp, Log, TEXT("구성원 이름: %s"), *Person→GetName());
}
```
- 언리얼식 `Generic`타입의 `List`는 아래와 같이 쓴다.
```cpp
// 가변 Array를 생성해서 UStudent, UTeacher, UStaff를 인스턴싱과 동시에 담음
TArray<UPerson*> Persons = { NewObject<UStudent>(), NewObject<UTeacher>(), NewObject<UStaff>() };
```

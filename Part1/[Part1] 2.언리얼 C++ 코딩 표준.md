---
sticker: emoji//2328-fe0f
---
> 📢언리얼 엔진은 자체적으로 코딩 표준을 정했기 때문에
> **기존 C++ 코딩 방법을 버리고 언리얼 엔진 코딩 표준을 따라야 함**

🔗언리얼 코딩 표준 문서 링크
```embed
title: "언리얼 엔진을 위한 에픽 C++ 코딩 표준"
image: "https://docs.unrealengine.com/5.1/Images/placeholder-social.png"
description: "기존에 확립된 표준 및 모범 사례를 준수하여 유지보수 가능한 코드를 작성합니다."
url: "https://docs.unrealengine.com/5.1/ko/epic-cplusplus-coding-standard-for-unreal-engine/"
```


## 언리얼 C++ 표준 요약
---
### 1. 클래스 체계
- **public** 인터페이스를 먼저 선언하고 **private** 인터페이스를 선언 해야한다.


### 2. 명명 규칙
- 언리얼 엔진은 **Pascal Case**만을(변수 이름도 포함) 사용한다.
	- `Health`, `UPrimitiveComponent` → 🆗
	- `lastMouseCoordinates`, `delta_coordinates` → ❌
- 타입 이름에는 대문자로 이루어진 접두사를 포함하여 변수 이름과 구분한다.
	- `UObject` 에서 상속받는 클래스에는 접두사 U를 포함합니다.
	- `AActor` 에서 상속받는 클래스에는 접두사 A를 포함합니다.
	- `SWidget` 에서 상속받는 클래스에는 접두사 S를 포함합니다.
	- `bool` 변수는 접두사 b를 포함 (예: `bPendingDestruction` 또는 `bHasFadedIn` )
	- 저번 시간에 작성한 `UMyGameInstance`는 `UObject`를 상속받고있다.
- 파일 이름에는 접두사를 붙이지 않는다.
	- 예를들어 `UScene`타입의 파일 이름은 `Scene.cpp`


### 3. 포터블 C++ 코드
- `int`와 `uint`타입의 경우 `int32`, `int16`, `uint64`타입으로 몇 바이트의 크기인지 명시해서 사용해야한다.
	- 일반적으로는 4바이트(`int32`)를 많이 사용한다.
	- 네트워크에 전송될거라면 1바이트(`int8`, `uint8`)를 주로 사용한다.
- 문자열의 경우 `TCHAR`타입을 사용한다.
- 참고로 그냥 `int`타입을 사용하면 최소 크기는 32비트로 보장이된다.


### 4. 표준 라이브러리 사용
- 표준 라이브러리는 팀바팀이지만 언리얼 자체 라이브러리를 사용하는게 좋다.
	- 컴파일 시간과 복잡도가 증가하기떄문
- 표준 라이브러리에 있는거는 언리얼 라이브러리에 거의 다 있다.


### 5. Const 지시자(directive)의 적극적인 활용⭐
- 다음과 같은 상황에서는 Const를 사용해주는게 좋다.
- 함수 아규먼트가 함수에 의해 수정되지 않는 경우 
	- → 함수 아규먼트를 `const` 포인터 또는 참조로 전달
- 메서드가 오브젝트를 수정하지 않는 경우
	- → `const`로 플래그를 지정하는
- 루프에서 컨테이너 수정을 하지 않는 경우
	- → `const`를 사용하여 컨테이너에 반복작업을 수행
**예시**
```cpp
void SomeMutatingOperation(FThing& OutResult, const TArray<Int32>& InArray)
{
    // InArray는 여기서 수정되지 않지만, OutResult는 수정될 수도 있습니다.
}

void FThing::SomeNonMutatingOperation() const
{
    // 이 코드는 자신을 호출한 FThing을 수정하지 않습니다.
}

TArray<FString> StringArray;
for (const FString& : StringArray)
{
    // 이 루프의 바디는 StringArray를 수정하지 않습니다.
}
```
- `reference`에는 `const`를 달아주면 안된다.
**예시**
```cpp
// const 포인터에서 const 이외 오브젝트 - 포인터로의 재할당은 불가하나, T는 여전히 수정 가능합니다.
T* const Ptr = ...;

// 틀림
T& const Ref = ...;
```


### 6. 헤더 include
- 헤더 `include` 대신 전방 선언(forward declaration)이 가능한 경우 전방 선언을 한다.
- `include`는 최대한 세밀하게 한다.
	- `include`하는 만큼 컴파일 시간이 늘어나기 때문에 세밀해야한다.
	- 예를 들면, `Core.h`를 `include`하지 말고 `Core`의 헤더 중 정의가 필요한 특정 부분을 include한다.


### 7. 일반적인 스타일 문제
- 포인터를 선언할 때의 옳은 예와 틀린 예
	- `FShaderType* Ptr` → 🆗
	- `FShaderType * Ptr`, `FShaderType *Ptr` → ❌
	- 개발 중 타입에 대한 레퍼런스 검색(Find in Files)시 속도가 느려진다.

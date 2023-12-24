---
sticker: emoji//1f47e
tistoryBlogName: trialdeveloper
tistoryTitle: "[Part1] 10.언리얼 컨테이너 라이브러리1 - Array와 Set"
tistoryTags: UE5, 이득우, 인프런
tistoryVisibility: "3"
tistoryCategory: "1149193"
tistorySkipModal: true
tistoryPostId: "97"
tistoryPostUrl: https://trialdeveloper.tistory.com/97
---
# 개요
---

## 언리얼 컨테이너 라이브러리
---
- 언리얼 엔진이 자체 제작해 제공하는 자료구조 라이브러리
- 줄여서 **UCL(Unreal Container Library)** 라고도 함.
- 언리얼 오브젝트를 안정적으로 지원하며 다수 오브젝트 처리에 유용하게 사용됨.
- 언리얼 C++는 다양한 자료구조 라이버르리를 직접 만들어 제공하고 있음.
- 실제 게임 제작에 유용하게 사용되는 라이브러리로 세 가지를 추천함.
	- ⇒ `TArray`, `TMap`, `TSet`


## C++ STL과 언리얼 컨테이너 라이브러리의 차이점
---
- C++ STL은 **범용적**으로 설계되어 있다.
- C++ STL은 표준이기 때문에 호환성이 높다.
- C++ STL에는 많은 기능이 엮여 있어 **컴파일 시간이 오래걸림.**

- 언리얼 컨테이너 라이브러리는 언리얼 엔진에 **특화**돼 있음.
- 언리얼 컨테이너 라이브러리는 언리얼 오브젝트 구조를 안정적으로 지원한다.
- 언링러 컨테이너 라이브러리는 **가볍고 게임 제작에 최적화**되어 잇음.

## 언리얼 C++ 주요 컨테이너 라이브러리
---
- 두 라이브러리의 이름과 용도는 **유사**하지만, **내부적으로 다르게** 구현되어 있음.
	- `TArray`: 오브젝트를 순서대로 담아 효율적으로 관리하는 용도로 사용
		- → C++ STL의 `vector`와 대응
	- `TSet`: 중복되지 않는 요소로 구성된 집합을 만드는 용도로 사용
		- → C++ STL의 `set`과 대응
	- `TMap`: 키, 밸류 조합의 레코드를 관리하는 용도로 사용
		- → C++ STL의 `map`과 대응



# `TArray의` 구조와 활용
---

## `TArray` 개요
---
- `TArray`는 가변 배열(Dynamic Array)자료 구조
- STL의 `vector`와 동작 원리가 유사함
- 게임 제작에서는 가변 배열 자료구조를 효과적으로 활용하는 것이 좋음.
	- 데이터가 순차적으로 모여있기 때문에 메모리를 효과적으로 사용할 수 있고 캐시 효율이 높다.
	- 컴퓨터 사양이 좋아지면서, **캐시 지역성(Locality)** 으로 인한 성능 향상은 굉장히 중요해짐.
	- 임의 데이터의 접근이 빠르고, 고속으로 요소를 순회하는 것이 가능.
- 가변 배열의 단점
	- 맨 끝에 데이터를 추가하는 것은 가볍지만, **중간에 요소를 추가하거나 삭제하는 작업은 비용이 큼**
- *데이터가 많아질 수록 검색, 삭제, 수정 작업이 느려지기 때문에, 많은 수의 데이터에서 검색 작업이 빈번하게 일어난다면 `TArray`대신 `TSet`을 사용하는것이 좋음.*


## TArray의 내부 구조
---
![](https://i.imgur.com/YGn2EmU.png)

🔗<u>TArray 공식 문서 링크</u>

<div class="rich-link-card-container"><a class="rich-link-card" href="https://docs.unrealengine.com/4.27/ko/ProgrammingAndScripting/ProgrammingWithCPP/UnrealArchitecture/TArrays/" target="_blank">
	<div class="rich-link-image-container">
		<div class="rich-link-image" style="background-image: url('https://docs.unrealengine.com/4.27/Images/placeholder-social.png')">
	</div>
	</div>
	<div class="rich-link-card-text">
		<h1 class="rich-link-card-title">TArray: 언리얼 엔진의 배열</h1>
		<p class="rich-link-card-description">
		
		</p>
		<p class="rich-link-href">
		https://docs.unrealengine.com/4.27/ko/ProgrammingAndScripting/ProgrammingWithCPP/UnrealArchitecture/TArrays/
		</p>
	</div>
</a></div>


## TArray 실습
---
```cpp
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
}
```


# TSet의 구조와 활용
---

## TSet의 특징
---
- STL의 `set`과 언리얼 `TSet`의 비교
	- STL `set`의 특징
		- STL `set`은 이진 트리로 구성되어 있어 정렬을 지원함.
		- STL `set`은 메모리 구성이 효율적이지 않음.
		- STL `set`은 요소가 삭제될 때 균형을 위한 재구축이 일어날 수 있음.
		- STL `set`의 모든 자료를 순회하는데 적합하지 않음.
	- 언리얼 `TSet` 특징
		- `TSet`은 해시테이블 형태로 키 데이터가 구축되어 있어 빠른 검색이 가능함.
		- `TSet`은 동적 배열의 형태로 데이터가 모여있음
		- `TSet`의 데이터는 빠르게 순회할 수 있음.
		- `TSet`의 데이터는 삭제해도 재구축이 일어나지 않음.
		- `TSet`의 자료에는 비어있는 데이터가 있을 수 있음.
- 따라서 STL `set`과 언리얼 `TSet`의 **활용 방법은 서로 다르기 때문에 주의할 것.**
- STL의 `unordered_set`과 유사하게 동작하지만 동일하진 않음
- `TSet`은 중복 없는 데이터 집합을 구축하는데 유용하게 사용할 수 있음.


## `TSet`의 내부 구조
---
![](https://i.imgur.com/xYwwD6T.png)

🔗<u>`TSet`공식 문서 링크</u>

<div class="rich-link-card-container"><a class="rich-link-card" href="https://docs.unrealengine.com/4.27/ko/ProgrammingAndScripting/ProgrammingWithCPP/UnrealArchitecture/TSet/" target="_blank">
	<div class="rich-link-image-container">
		<div class="rich-link-image" style="background-image: url('https://docs.unrealengine.com/4.27/Images/placeholder-social.png')">
	</div>
	</div>
	<div class="rich-link-card-text">
		<h1 class="rich-link-card-title">TSet</h1>
		<p class="rich-link-card-description">
		TSet, 세트는 보통 순서가 중요치 않은 상황에서 고유 엘리먼트를 저장하는 데 사용되는 고속 컨테이너 클래스입니다.
		</p>
		<p class="rich-link-href">
		https://docs.unrealengine.com/4.27/ko/ProgrammingAndScripting/ProgrammingWithCPP/UnrealArchitecture/TSet/
		</p>
	</div>
</a></div>


## `TSet` 실습
---
```cpp
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

```



## 자료구조의 시간 복잡도 비교
---
- 각 자료구조의 시간 복잡도

|      | TArray | TSet   |
| ---- | ------ | ------ |
| 접근 | `O(1)` | `O(1)` |
| 검색 | `O(N)` | `O(1)` |
| 삽입 | `O(N)` | `O(1)` |
| 삭제 | `O(N)` | `O(1)` |

- `TArray`
	- 빈틈없는 메모리
	- 가장 높은 접근성능
	- 가장 높은 순회성능
- `TSet`
	- 빠른 중복 감지
	- 하지만 메모리에 빈틈이 생길 수 있음


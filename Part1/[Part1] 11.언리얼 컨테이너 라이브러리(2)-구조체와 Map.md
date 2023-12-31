---
sticker: emoji//1f47e
---
> [!note]
> 실습은 지난번 프로젝트인 `UnrealContainer`에 이어서 작성


# 언리얼 구조체
---
🔗공식 문서
→ 강의와 똑같은 문서는 사라진것 같음

<div class="rich-link-card-container"><a class="rich-link-card" href="https://docs.unrealengine.com/5.1/ko/structs-in-unreal-engine/" target="_blank">
	<div class="rich-link-image-container">
		<div class="rich-link-image" style="background-image: url('https://docs.unrealengine.com/5.1/Images/placeholder-social.png')">
	</div>
	</div>
	<div class="rich-link-card-text">
		<h1 class="rich-link-card-title">구조체</h1>
		<p class="rich-link-card-description">
		게임플레이 클래스용 구조체 생성 및 구현 관련 레퍼런스입니다.
		</p>
		<p class="rich-link-href">
		https://docs.unrealengine.com/5.1/ko/structs-in-unreal-engine/
		</p>
	</div>
</a></div>

#### 구조체 사용시 알아둘 정보
- 구조체는 단순한 데이터 타입에 적합하므로 `UObjects`와는 다름
	- 프로젝트 내부에서 보다 복잡한 인터랙션을 하기 위해서는 `UObject` 또는 `AActor` 서브클래스를 만드는것이 좋음
- `UStruct`는 리플리케이션용으로 간주되지 **않음**
	- `UProperty`변수는 리플리케이션응으로 `간주됨`



## 언리얼 구조체 `UStruct`
---
- 데이터 저장/전송에 특화된 가벼운 객체
- 대부분 `GENERATED_BODY` 매크로를 선언해준다.
	- 리플레션, 직렬화와 같은 유용한 기능을 지원함.
	- `GENERATED_BODY`를 선언한 구조체는 `UScriptStruct`클래스로 구현됨.
	- 이 경우 제한적으로 리플렉션을 지원함
		- 속성 `UPROPERTY`만 선언할 수 있고 함수 `UFUNCTION`은 선언할 수 없음
- 언리얼 엔진의 **구조체 이름은 F로** 시작함. (엔진이 메모리관리를 해주지 않음)
	- 대부분 힘 메모리 할당(포인터 연산)없이 스택 내 데이터로 사용됨.
	- `NewObject` API를 사용할 수 없음



## 언리얼 리플렉션 관련 계층 구조
---
- 리플렉션에 관련된 언링러 오브젝트의 계층 구조
![](https://i.imgur.com/aguTraF.png)


## 객체의 동적 배열 관리를 위한 예제 다이어그램
---
- 언리얼 오브젝트 학생의 동적 배열 관리 방법
- 언리얼 구조체 학생 정보의 동적 배열 관리 방법
![](https://i.imgur.com/S5eM2qj.png)
- `UObject`를 상속받는 `UStudent`를 컨테이너에 담으면 `UPROPERTY`매크로를 필수로 붙여줘야 한다.
- 예시 코드
```cpp
MyGameInstance.h

	// 값타입이기 때문에 메모리 관리를 할 필요가 없다고 함
	TArray<FStudentData> StudentData;

	// 헤더에서 언리얼 오브젝트 포인터를 선언할때는 TobjectPtr로 감싸야 함
	// 엔진이 자동으로 메모리를 관리할 수 있게 UPROPERTY 매크로를 필수로 붙여줘야 함
	UPROPERTY()
	TArray<TObjectPtr<class Ustudent>> Students;
```



# `TMap`의 구조와 활용
---


## `TMap`의 특징
---
- `STL map`과 `TMap`의 비교
	- `STL map`의 특징
		- `STL map`은 `STL set`과 동일하게 이진트리로 구성돼있음.
		- 정렬은 지원하지만, 메모리 구성이 효율적이지 않으며, 데이터 삭제시 재구축이 일어날 수 있음.
		- **모든 자료를 순회하는데 적합하진 않음**
	- `언리얼 TMap`의 특징
		- 키,밸류 구성의 튜플(Tuple) 데이터의 `TSet` 구조로 구현돼있음
		- 해시테이블 형태로 구축되어 있어 빠른 검색이 가능
		- 동적 배열의 형태로 데이터가 모여있음
		- 데이터는 **빠르게 순회할 수 있음**
		- 데이터는 **삭제해도 재구축이 일어나지 않음**
		- **비어있는 데이터**가 있을 수 있음
		- `TMultiMap`을 사용하면 중복 데이터를 관리할 수 있음(**중복 허용 필요 시 사용**)
- 동작 원리는 `STL unordered_map`과 유사함
- 키,밸류 쌍이 필요한 자료구조에 광범위하게 사용됨 



## `TMap`의 내부 구조
---
![](https://i.imgur.com/Tzav9Rw.png)
`TSet`을 Pair로 구현한 구조이기때문에 `TSet`과 성질이 동일하다.

🔗공식 문서 링크

<div class="rich-link-card-container"><a class="rich-link-card" href="https://docs.unrealengine.com/5.1/ko/map-containers-in-unreal-engine/" target="_blank">
	<div class="rich-link-image-container">
		<div class="rich-link-image" style="background-image: url('https://docs.unrealengine.com/5.1/Images/placeholder-social.png')">
	</div>
	</div>
	<div class="rich-link-card-text">
		<h1 class="rich-link-card-title">TMap</h1>
		<p class="rich-link-card-description">
		TMap, 맵은 크게 키 유형과 값 유형, 두 가지로 정의되며, 맵에 하나의 짝으로 저장됩니다.
		</p>
		<p class="rich-link-href">
		https://docs.unrealengine.com/5.1/ko/map-containers-in-unreal-engine/
		</p>
	</div>
</a></div>


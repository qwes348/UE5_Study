---
sticker: emoji//1f916
---
## 이번 강의에서 다루는 게임 프레임웍 요소(주황)
![500](https://i.imgur.com/DxnVGkU.png)


# 새로운 캐릭터 제작
---
- 캐릭터 모델은 에픽 마켓플레이스의 무료에셋인 **Infinity Blade:Warrios**를 사용
- 애니메이션 에셋은 강의 자료에서 다운로드
- 애니메이션 컨트롤러
	- 기존 캐릭터 블루프린트의 **Mesh**컴포넌트를 확인
	- **Animation**카테고리의 `Animation Mode : Use Animation Blueprint`로 설정이 돼있다
	- 그리고 아래 `Anim Class`속성에 들어가는 클래스의 블루프린트가 애니메이션 컨트롤을 담당한다 (현재 단계에서는 ABP_Quinn_C)


## 캐릭터 애니메이션 시스템 사전 준비
---
- `AnimInstance`클래스를 상속받고 클래스를 새로 생성

![250](https://i.imgur.com/Us1w3rr.png)

- 컨텐츠 브라우저에서 **Animation Blueprint**에셋을 새로 생성하고 사용할 스켈레톤을 고르고, **Parent Class**는 새로 만든 클래스를 선택
- `ACharacter`를 상속받는 `ABCharcterBase.cpp`(이 프로젝트 기준)으로 가서 스켈레탈 메시의 에셋 레퍼런스를 원하는 모델의 스켈레탈 메시 에셋 레퍼런스로 교체
- `AnimInstance`도 마찬가지로 교체 
```cpp
AABCharcterBase::AABCharcterBase()
{	
	...
	
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> CharacterMeshRef(TEXT("/Script/Engine.SkeletalMesh'/Game/InfinityBladeWarriors/Character/CompleteCharacters/SK_CharM_Cardboard.SK_CharM_Cardboard'"));
	if (CharacterMeshRef.Object)
	{
		GetMesh()->SetSkeletalMesh(CharacterMeshRef.Object);
	}

	static ConstructorHelpers::FClassFinder<UAnimInstance> AnimInstanceRef(TEXT("/Game/Animation/ABP_ABCharacter.ABP_ABCharacter_C"));
	if (AnimInstanceRef.Class)
	{
		GetMesh()->SetAnimInstanceClass(AnimInstanceRef.Class);
	}
	
	...
}
```

- 생성자를 수정했기때문에 에디터를 끄고 빌드를 통해 에디터를 다시 실행
- 캐릭터가 바뀐것을 확인 but 지금은 T포즈
![](https://i.imgur.com/JTOu5HX.png)


## 캐릭터 애니메이션 시스템의 생성
---
- 스켈레탈 메시 컴포넌트의 애니메이션 블루프린트 클래스를 지정한다. → ok
- 캐릭터가 초기화될 때 AnimInstance 클래스의 인스턴스를 생선한다. → ok
- 캐릭터는 `GetAnimInstance()` 함수를 사용해 애니메이션 인스턴스를 얻을 수 있음 → ok
- 애니메이션 인스턴스는 `GetOwningActor()` 함수를 사용해 자신을 소유한 액터 정보를 얻을 수 있음
![](https://i.imgur.com/yWk4XxP.png)


## 캐릭터 애니메이션 시스템의 설계
---
- 애니메이션 블루프린트는 **이벤트 그래프**와 **애님 그래프**의 두 영역으로 구성돼있음
- 이벤트 그래프에서는 이벤트로부터 상태를 파악할 수 있는 주요 변수를 저장하는데 사용
- 애님 그래프에서는 저장된 변수로부터 지정된 상태의 애니메이션을 재생
- 애님 그래프의 복잡한 상태는 **Sate Alias**로 분리해 효과적으로 설계할 수 있음
![600](https://i.imgur.com/aJycnqg.png)
- `NativeInitializeAnimation()` ⇒ 애님 인스턴스가 처음 생성될 때 호출
- `NativeUpdateAnimation(float DeltaSeconds)` ⇒ 프레임마다 호출


## 애님인스턴스 블루프린트 세팅 기억할 것만 기록
---
- `AnimInstance`(를 상속받은) 클래스에서 선언한 변수들을 블루프린트에서 확인할려면 아래 사진의 **Show Inherited Variables** 옵션을 체크 해줘야한다.
![500](https://i.imgur.com/mmMOTiC.png)

- 스테이트머신 1개가 너무 더러워질것 같다면
	- 스테이트 머신을 하나 더 만들고 최종 결과를 `New Cached Save Pose`블록으로 저장한 후
	- 사용할 곳에서 `Use cached Pose`블록으로 저장한 애니메이션 결과를 불러와서 연결할 수 있다.

- 유니티의 블렌드 트리 같은 기능은
- 컨텐츠 브라우져 우클릭 → Add → Animation → Legacy → Blend Space 1D로 사용한다
- 유니티와는 다르게 에셋으로서 생성하고 사용해야한다
	- **AnimGraph에서** 드래그앤드롭으로 노드를 놓을 수 있다.
![](https://i.imgur.com/YN36zdh.png)

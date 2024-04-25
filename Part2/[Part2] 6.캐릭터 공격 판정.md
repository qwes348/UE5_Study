---
sticker: emoji//1f916
---
# 이번 강의에서 다루는 게임프레임워크 요소
---
![600](https://i.imgur.com/Oxp4WdS.png)


# 강의 목표
---
- 애니메이션 이벤트 발생을 위한 노티파이 설정 방법의 학습
- 공격 판정을 위한 트레이스 채널 설정과 펀정을 시각적으로 디버깅하는 방법의 학습
- 데미지 프레임워크를 활용한 데미지 전달과 Dead상태의 구현


# 충돌 채널의 설정
---

### 캐릭터 액션의 충돌 판정
---
- 월드가 제공하는 충돌 판정 서비스를 사용
- 월드는 크게 세 가지의 충돌 판정 서비스를 제공함
- 월드 내 배치된 충돌체와 충돌하는지 파악하고, 충돌한 액터 정보를 얻을 수 있음

![](https://i.imgur.com/2ygYfOS.png)

⇒ 유니티의 Raycast, 도형Cast, 도형Overlap같은 느낌

## 트레이스 채널과 충돌 프로필 생성
---
- `Edit → Project Settings → Collision`메뉴
- 액션 판정을 위한 트레이스 채널의 생성: `ABAction`
	- → 기본 반응은 무시 (`Default Respons`를 `Ignore`로 설정)
- 캐릭터 캡슐용 프로필: `ABAction` 트레이스 채널에 반응
	- → 오브젝트 타입은 Pawn
- 스켈레탈 메시용 프로필: 랙돌 구현을 위해 주로 활용됨
- 기믹 트리거용 프로필: 폰 캡슐에만 반응하도록 설정
	- → 오브젝트 타입은 `WorldStatic`

![](https://i.imgur.com/fTkDtS9.png)


# 공격 판정의 구현
---

## 월드 트레이싱 함수의 선택
---
- 3가지 카테고리로 원하는 함수 이름을 얻을 수 있음
- **카테고리 1**: 처리 방법
	- `LineTrace`
	- `Sweep`
	- `Overlap`
- **카테고리 2**: 대상
	- `Test`: 무언가 감지되었는지를 테스트
	- `Single` 또는 `AnyTest`: 감지된 단일 물체 정보를 반환
	- `Multi`: 감지된 모든 물체 정보를 배열로 반환
- **카테고리 3**: 처리 설정
	- `ByChannel`: 채널 정보를 사용해 감지
	- `ByObjectType`: 물체제 지정된 물리 타입 정보를 사용해 감지
	- `ByProfile`: 프로필 정보를 사용해 감지

⇒ `{처리방법}{대상}{처리설정}`

## 캐릭터 공격 판정의 구현
---
- 캐릭터 위치에서 시선 방향으로 물체가 있는지 감지
- 작은 구체를 제작하고 시선 방향으로 특정 거리까지만 투사
	- ⇒ `Sweep`
- 하나의 물체만 감지
	- ⇒ `Single`
- 트레이스 채널을 사용해 감지
	- ⇒ `ByChannel`

⇒ `{Sweep}{Single}{ByChannel}`

**실제 사용 예시**
```Cpp
void AABCharacterBase::AttackHitCheck()
{
	FHitResult OutHitResult;
	FCollisionQueryParams Params(SCENE_QUERY_STAT(Attack), true, this);

	const float AttackRange = 40.0f;
	const float AttackRadius = 50.0f;
	const float AttackDamage = 30.0f;
	const FVector Start = GetActorLocation() + GetActorForwardVector() * GetCapsuleComponent()->GetScaledCapsuleRadius();
	const FVector End = Start + GetActorForwardVector() * AttackRange;

	bool HitDetected = GetWorld()->SweepSingleByChannel(OutHitResult, Start, End, FQuat::Identity, CCHANNEL_ABACTION, FCollisionShape::MakeSphere(AttackRadius), Params);
}
```


## 물리 충돌 테스트
---
- 디버그 드로잉 함수를 사용해 물리 충돌을 시각적으로 테스트
- 90도로 회전시킨 캡슐을 그리기
	- `Origin`
	- `HalfHeight`
	- `Radius`

![](https://i.imgur.com/yAduyvP.png)


# 이번 강의에서 배운 것
---
1. 공격 판정 구현을 위한 물리 트레이스 채널 및 프로필 설정

2. 디버그 드로잉 기능을 활용한 충돌 디버깅
**디버그 드로잉 코드**
```cpp
#if ENABLE_DRAW_DEBUG

	FVector CapsuleOrigin = Start + (End - Start) * 0.5f;
	float CapsuleHalfHeight = AttackRange * 0.5f;
	FColor DrawColor = HitDetected ? FColor::Green : FColor::Red;

	// 히트박스 기즈모
	DrawDebugCapsule(GetWorld(), CapsuleOrigin, CapsuleHalfHeight, AttackRadius, FRotationMatrix::MakeFromZ(GetActorForwardVector()).ToQuat(), DrawColor, false, 5.0f);

#endif
```

3. 데미지 프레임워크를 사용한 데미지 전달
	- `AActor`클래스의 `TakeDamage`함수를 오버라이딩해서 구현

4. 델리게이트와 람다함수의 간편한 활용
**활용한 코드** → 지연시간 후 `Destroy()` 실행
```cpp
	FTimerHandle DeadTimerHandle;
	// 타이머와 람다함수 사용
	GetWorld()->GetTimerManager().SetTimer(DeadTimerHandle, FTimerDelegate::CreateLambda(
		[&]()
		{
			Destroy();
		})
	, DeadEventDelayTime, false);
```


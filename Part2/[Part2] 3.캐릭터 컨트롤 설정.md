---
sticker: emoji//1f916
---
## 이번 강의에서 다루는 게임 프레임웍 요소(주황)
![500](https://i.imgur.com/15w1Xtb.png)


# 캐릭터 컨트롤 요소
---
## 캐릭터 컨트롤
---
- 일반적으로 \[컨트롤러 폰, 카메라, 스프링암, 캐릭터 무브번트]의 다섯가지 요소를 사용해 설정
- **컨트롤러**: 입력자의 의지(목표지점)을 지정할 때 사용. `ControlRotation` 속성
- **폰**: 폰의 트랜스폼을 지정
- **카메라**: 화면 구도를 설정하기 위해 사용 (주로 1인칭 시점에서 사용)
- **스프링 암**: 화면 구도를 설정하기 위해 사용 (주로 3인칭 시점에서 사용)
- **캐릭터 무브먼트**: 캐릭터의 이동과 회전을 조정하는 용도로 사용
![500](https://i.imgur.com/Ai8uxR3.png)


## 폰의 이동 함수
---
- **Look 함수**: 마우스 입력으로부터 컨트롤러의 컨트롤 회전을 설정
- **Move 함수**: 컨트롤러의 컨트롤 회전으로부터 Yaw 값을 참고해 이동 방향을 설정
- 콘솔 커맨드 창(단축키 `~`)으로부터 `DisplayAll PlayerController ControlRotation` 명령으로 `Control Rotation` 값을 확인할 수 있음
	- ⇒ 확인해보면 마우스 움직임에 따라 값이 변하는것을 확인할 수 있음
	- ⇒ 이런식으로 `UPROPERTY`로 지정한 변수는 디버그 모니터링을 할 수 있음


## 폰의 컨트롤 옵션
---
- `Use Controller Rotation (Yaw/Roll/Pitch)`
	- ⇒ 컨트롤러에 지정된 `Control Rotation` 값에 폰의 Rotation을 맞출 것인가?
- 이 옵션을 켜면 폰의 회전은 컨트롤러의 `Control Rotation`과 동기화됨.
	- ⇒ 즉, 마우스를 움직이면 캐릭터도 회전한다.
![600](https://i.imgur.com/BTvfcFH.png)


## 스프링암의 컨트롤 옵션
---
- `Use Pawn Control Rotation`
	- ⇒ 폰의 컨트롤 회전 (컨트롤러의 Control Rotation)을 사용할 것인가?
- `Inherit (Yaw/Roll/Pitch)`
	- ⇒ 부모 컴포넌트 (주로 RootComponent)의 회전을 그대로 따를 것인가?
- `Do Collision Test`
	- ⇒ 스프링암 중간에 장애물이 있으면 앞으로 당길 것인가? (Camera라는 트레이스 채널을 사용)
- 3인칭 시점 설정에 주로 사용
![800](https://i.imgur.com/ztAlPq3.png)


## 카메라의 컨트롤 옵션
---
- `Use Pawn Control Rotation`
	- ⇒ 폰의 컨트롤 회전 (컨트롤러의 Control Rotation)을 사용할 것인가?
- 스프링암에 달려있다면 스프링암의 회전과 함께 고려
- 1인칭 카메라 회전에 주로 사용
![600](https://i.imgur.com/xIAY4yd.png)


## 캐릭터 무브먼트의 이동 옵션
---
- `Movement Mode`: \[None Walking, Falling]
	- 땅(Ground)위에 있으면 → `Walking` 모드
	- 땅 위에 없으면 → `Falling` 모드
	- 이동 기능을 끄고싶으면 → `None` 모드
- `MaxWalkSpeed`: 이동모드에서의 이동 수치
- `JumpZVelocity`: 폴링 모드에서의 점프 수치
![600](https://i.imgur.com/gcCceB5.png)


## 캐릭터 무브먼트의 회전 옵션
---
- `Rotation Rate`: 회전 속도의 지정
- `Use Controller Desired Rotation`: 컨트롤 회전을 목표 회전으로 삼고 지정한 속도로 돌리기
- `Orient Rotation To Movement`: 캐릭터의 이동 방향에 회전을 일치시키기
- **폰의 회전 옵션과 충돌이 나지 않도록 주의**
![600](https://i.imgur.com/m41o9CR.png)


# 데이터 에셋
---
## 설명
---
- `UDataAsset`을 상속받은 언리얼 오브젝트 클래스
- 에디터에서 에셋 형태로 편리하게 데이터를 관리할 수 있음
- 캐릭터 컨트롤에 관련된 주요 옵션을 모아 에셋으로 관리
![](https://i.imgur.com/vrpB82v.png)


## 데이터 에셋의 관리
---
- 두 가지의 컨트롤 모드를 제공
	- 현재 구현된 컨트롤 모드 → 3인칭 숄더뷰
	- 추가로 구현할 컨트롤 모드 → 3인칭 쿼터뷰
- 입력키 V를 통해 컨트롤 설정을 변경
- `ENUM`을 통해 두 개의 컨트롤 데이터를 관리
![500](https://i.imgur.com/mHHQg9F.png)


## 데이터 에셋의 구성과 적용
---
- 각 센션별로 데이터를 저장
	- Pawn 카테고리
	- 캐릭터 무브먼트 카테고리
	- 입력 카테고리
	- 스프링암 카테고리
- Pawn과 캐릭터 무브먼트 데이터는 `CharacterBase`에서 설정
- 입력과 스프링암 데이터는 `CharacterPlayer`에서 설정
![500](https://i.imgur.com/Yyw2CmU.png)


## 뷰의 변환
---
- 컨트롤을 변경할 때 서로 다른 입력 매핑 콘텍스트를 지정
- 숄더뷰: `ShoulderMove`와 `ShoulderLook`을 사용
- 쿼터뷰: `QuaterMove`만 사용
- 입력 액션(V 키)를 사용해 변경
![](https://i.imgur.com/3rf1Y9m.png)


## 이번 강의에서 기억할 것
---
- 디테일 뷰에서 `Use Pawn Control Rotation`값을 수정함으로 객체의 회전값을 컨트롤러(마우스)가 자동으로 변경하게 할지를 설정할 수 있다.
	- Pawn, SpringArm, Camera 카테고리가 해당 값을 가지고있다.
- 디테일뷰에서 `Character Movement`카테고리 아래에 `UseController Desired Rotation` 값을 체크하면 이동하려는 방향으로 캐릭터가 회전한다.
- `UPrimaryDataAsset`클래스를 상속받아서 유니티의 `ScriptableObject`같은 데이터 에셋을 만들 수 있다.
- 콘솔 커맨드 창(단축키 `~`)으로부터 `DisplayAll <Class Name> <Property Name>` 명령으로 변수를 모니터링 할 수 있다.
- `Input Mapping Context` 에셋을 여러개 두고 교체함으로써 입력에대한 매핑 세팅을 교체할수 있다.
	- 이번 예제처럼 쿼터뷰에서는 카메라 회전 매핑을 제거할 수도 있겠고
	- 제거없이 매핑된 함수들만 교체해서 확장성있게 사용할 수 있을것 같다.
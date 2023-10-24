---
sticker: emoji//1f590-fe0f
---
## 이번 강의에서 설명하는 것
---
1. 언리얼 엔진 설치와 프로그래밍 환경 구축
2. 언리얼 에디터에서의 클래스 추가
3. 언리얼 C++의 클래스 상속 및 오버라이딩 구현
4. 언리얼 엔진의 문자열 처리의 이해
5. 게임인스턴스 클래스의 적용과 카테고리를 활용한 로그 확인

## 사전 세팅
---
- 언리얼 마켓플레이스에서 `Visual Studio Integration Tool`플러그인 설치 (*VS 2022이상 필요*)


## 언리얼 코드 컴파일 방법
---
- 헤더 파일에 변경이 발생하면
	- → 에디터를 끄고 VS에서 컴파일 한다.
	- 그냥 빌드를 눌러보면 빌드 실패가 뜬다.
	- 실패 이유는: `Unable to build while Live Coding is active. Exit the editor and game, or press Ctrl+Alt+F11 if iterating on code in the editor or game`
	- 에디터 끄고 코드 작업 하고, **솔루션 빌드** 진행 후 `Ctrl + F5`를 누르면 에디터가 켜진다.
- 소스 파일에만 변경이 발생하면
	- → 라이브 코딩으로 컴파일한다.
	- `Ctrl + Alt + F11`


## 언리얼 C++
---
- `Header`에서 함수를 구성할때는 `public`을 먼저 구성해주고 `private`을 구성하자
- `C++`에서 `override`를 선언할때는
	- `virtual void Init() override;` 이렇게 `Header`에 선언한다.
- `C#`에서 `override`함수에 쓰는 `base.`는 C++에서는 `Super::`이다.
- 언리얼에서 `String`을 다룰때는 `TEXT(string)`라는 매크로 함수를 사용한다.
- 언리얼에서 로그찍는 함수는 `UE_LOG(카테고리, 로그 수준, 포맷, 문자열)`


## 언리얼 에디터
---
- `GameInstance`클래스를 상속받아 만든 클래스를 기본 `GameInstance` 싱글톤으로 교체할려면
	- `ProjectSettings → Project → Maps & Modes`제일 아래에 드롭다운 항목이 있다.
	- 여기서 상속받아 구현한 클래스로 변경 가능
- 시작 콘텐츠 (UE5의 경우에는 `Terrain`)을 안뜨게할려면
	- `ProjectSettings → Project → Maps & Modes`에서 `Editor Startup Map`과 `Editor Template Map Overrides`를 `Clear`한다.

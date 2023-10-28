---
sticker: emoji//1f5d2-fe0f
---

# 🚩강의 목표
---
- 언리얼 환경에서 알아두어야 할 기본 타입과 고려할 점
- 캐릭터(Char) 인코딩 시스템에 대한 이해
- 언리얼 C++이 제공하는 다양한 문자열 처리 방법과 내부 구성 이해


# 기본 타입

## 왜 언리얼은 기본 타입을 따로 지정하는가?
---
- 1970년대에 개발되서 아직도 사용 중인 C++ 언어
	- 시대에 따라 발전한 하드웨어 사양
	- 플랫폼 파편화(Platform Fragmentation)
- C++ 최신 규약에서 `int`는 최소 32비트를 보장하도록 규정되어 있음.
	- 특정 플랫폼에서는 `64bit`로 해석될 수 있음.
	- 따라서 데이터를 저장할 때 `int`타입의 **크기를 확신할 수 없음**
	- 후발 언어 C#의 경우 4바이트(32비트)인 `int32`로 명확히 정의돼있음
- 게임 제작의 특징
	- 데이터 정보가 **명확해야** 한다.
	- 단일 컴퓨터에서 최대 퍼포먼스를 뽑아내야 한다.
	- 네트워크 상에서 데이터 통신이 **효율적이고 안정적**이어야 한다.

## bool 타입의 선언
---
- `bool`은 크기가 명확하지 않음.
- **헤더**에는 가급적 `bool` 대신 `uint8` 타입을 사용하되 `Bit Field` 오퍼레이터를 사용.
	- 예시 → `uint8 bIsBoolen:1;`
- 일반 `uint8`과의 구분을 위해 b접두사를 사용.
- **Cpp** 로직에서는 자유롭게 `bool`을 사용.



# 캐릭터(Char) 인코딩

## 왜 언리얼은 문자열을 따로 지정하는가? 
---
- 1990년대 후반에 이르러서야 표준화된 아시안 문자욜 표준 (한, 중, 일)
- 하지만 컴퓨터는 그전에도 사용했었다.
- 문자열 처리의 종류
	- **Single byte**(`ANSI`, `ASCII`): 컴퓨터 초창기
	- **Multi byte**(`EUC-KR`, `CP949`): 컴퓨터 보급기 (1990년대 초중반)
	- **Unicode**(`UTF-8`, `UTF-16`): 국제 표준 정착기 (1990년대 후반)
- 하지만 이 모든 문자열은 아직도 사용되고 있음
	- **C++ STL**은 `ASCII`, `UTF-8`, `UTF-16`만 지원함.
	- **Windows 10**은 **Multi byte**를 지원함. 하지만 다른 운영체제는 지원하지 않음.
- 🔗[언리얼 엔진 캐릭터 인코딩 문서 링크](https://docs.unrealengine.com/5.3/ko/character-encoding-in-unreal-engine/)


# TCHAR와 FString
## 복잡한 문자열 처리를 하나로.
---
- 유니코드를 사용해 문자열 처리를 통일
	- 이 중에서 2byte로 사이즈가 균일한 `UTF-16`을 사용
	- 유니코드를 위한 언리얼 표준 캐릭터 타입: `TCHAR`
- 문자열은 언제나 `TEXT` 매크로를 사용해 지정.
	- `TEXT`매크로로 감싼 문자열은 `TCHAR` 배열로 지정됨.
- 문자열을 다루는 클래스로 `FString`을 제공함
	- `FString`은 `TCHAR` 배열을 포함하는 헬퍼 클래스
	- 🔗[FString 클래스 문서](https://docs.unrealengine.com/5.3/ko/fstring-in-unreal-engine/)

## FString의 구조와 활용
---
- 다른 타입에서 FString으로의 변환
	- `FString::Printf`
	- `FString::SanitizeFloat` → float to string
	- `FString::FromInt` → int to string
- C런타임 수준에서 문자열을 처리하는 클래스 `FCString`
	- 예) 문자열을 찾는 `strstr`을 사용
- FString에서 다른 타입으로의 변환 (안전하진 않으므로 주의)
	- `FCString::Atoi` → ASCII to int
	- `FCString::Atof` → ASCII to float
![](https://i.imgur.com/rUVFnZB.png)


# FName의 활용
## 언리얼이 제공하는 다양한 문자열 처리
---
- **FName**: 에셋 관리를 위해 사양되는 문자열 체계.
	- 대소문가 구분 없음
	- 한번 선언되면 바꿀 수 없음
	- 가볍고 빠름
	- 문자를 표현하는 용도가 아닌 에셋 키를 지정하는 용도로 사용 ⇒ 빌드시 해시값으로 변한됨
	- 🔗[FName 클래스 문서 링크](https://docs.unrealengine.com/5.3/ko/fname-in-unreal-engine/)
- **FText**: 다국어 진원을 위한 문자열 관리 체계.
	- 일종의 키로 작용함
	- 별도의 문자열 테이블 정보가 추가로 요구됨
	- 게임 빌드 시 자동으로 다양한 국가별 언어로 변환됨
![](https://i.imgur.com/VO2ddp9.png)

## FName의 구조와 활용
---
- 언리얼은 FName과 관련된 글로벌 Pool 자료구조를 가지고 있음
- **FName과 글로벌 Pool**
	- 문자열이 들어오면 해시 값을 추출해 키를 생성해 FName에서 보관
	- FName 값에 저장된 값을 사용해 전역 Pool에서 원하는 자료를 검색해 반환
	- 문자 정보는 대소문자를 구분하지 않고 저장함. (Ignore Case)
- **FName의 형성**
	- 생성자에 문자열 정보를 넣으면 풀을 조사해 적당한 키로 변환하는 작업이 수반됨
	- Find or Add
![](https://i.imgur.com/KBAvnpU.png)


# 기타
---
- 이번강의에서 UE_LOG를 영상과 똑같이 입력 하면 UE_LOG 함수에 에러가난다.
```cpp
	TCHAR LogCharArray[] = TEXT("Hello Unreal");
	UE_LOG(LogTemp, Log, LogCharArray);
```
- **해결법**은 `array`를 `static const`로 선언해주는것
	- 원인은 언리얼엔진 버전마다 UE_LOG 함수의 구현이 달라져서 매개변수 조건이 달라졌다고 한다.
	- 강의는 언리얼 5.1버전 / 내 버전은 5.3.1
```cpp
	static const TCHAR LogCharArray[] = TEXT("Hello Unreal");
	UE_LOG(LogTemp, Log, LogCharArray);
```

단축키
- Cpp파일 수정 후 코드 빌드 → `Ctrl + Alt + F11`
	- 에디터에서 눌러도되고, VS에도 눌러도 됨
- 헤더파일 수정 후 에디터 실행 → `Ctrl + F5`

한글 출력
- 로그에 한글을 찍을려면 cpp파일을 `UTF-8` 인코딩으로 저장해야한다.

🔗[언리얼 라이브 코딩 문서](https://docs.unrealengine.com/5.0/ko/using-live-coding-to-recompile-unreal-engine-applications-at-runtime/)


# 이번시간 코드
```cpp
void UMyGameInstance::Init()
{
	//! 중요! 빼먹으면 안됨
	Super::Init();

	static const TCHAR LogCharArray[] = TEXT("Hello Unreal");
	UE_LOG(LogTemp, Log, LogCharArray);

	FString LogCharString = LogCharArray;
	UE_LOG(LogTemp, Log, TEXT("%s"), *LogCharString);

	const TCHAR* LongCharPtr = *LogCharString;
	//! const가 아닌 직접 포인터로 받고싶다면(수정할 일이 있다면) 아래 방법으로 접근 가능
	TCHAR* LogcharDataPtr = LogCharString.GetCharArray().GetData();

	TCHAR LogCharArrayWithSize[100];
	FCString::Strcpy(LogCharArrayWithSize, LogCharString.Len(), *LogCharString);

	//! 특정 문자열을 포함하는지 확인하기
	// ESearchCase::CaseSensitive를 넣으면 대소문자를 구분함
	if (LogCharString.Contains(TEXT("unreal"), ESearchCase::IgnoreCase))
	{
		// 특정 문자열이 시작하는 인덱스 찾기
		int32 Index = LogCharString.Find(TEXT("unreal"), ESearchCase::IgnoreCase);
		// "unreal"이 시작되는 위치부터 끝까지 문자열을 자름
		FString EndString = LogCharString.Mid(Index);
		UE_LOG(LogTemp, Log, TEXT("Find Test: %s"), *EndString);	// output: Find Test: Unreal
	}

	//! 특정 문자를 기준으로 문자열 나누기
	FString Left, Right;
	if (LogCharString.Split(TEXT(" "), &Left, &Right))
	{
		// 한글을 출력하려면 다른이름으로 저장에서 UTF-8로 인코딩을 바꿔야한다.
		UE_LOG(LogTemp, Log, TEXT("Split Test: %s 와 %s"), *Left, *Right);
	}

	int32 IntValue = 32;
	float FloatValue = 3.141592;

	//! int, float 타입을 직접 출력
	FString FloatIntString = FString::Printf(TEXT("Int:%d Float:%f"), IntValue, FloatValue);
	//! int, float 타입을 string으로 변환해서 출력
	FString FloatString = FString::SanitizeFloat(FloatValue);
	FString IntString = FString::FromInt(IntValue);
	
	UE_LOG(LogTemp, Log, TEXT("%s"), *FloatIntString);
	UE_LOG(LogTemp, Log, TEXT("Int:%s Float:%s"), *IntString, *FloatString);
	// output: 
	// LogTemp: Int:32 Float:3.141592
	// LogTemp: Int:32 Float:3.141592

	//! String에서 int, float으로 변환
	int32 IntValueFromString = FCString::Atoi(*IntString);
	float FloatValueFromString = FCString::Atof(*FloatString);
	FString FloatIntString2 = FString::Printf(TEXT("Int:%d Float:%f"), IntValueFromString, FloatValueFromString);
	UE_LOG(LogTemp, Log, TEXT("%s"), *FloatIntString2);
	// output: LogTemp: Int:32 Float:3.141592

	//! FName의 대소문가 구별 안함 특성 확인
	FName key1(TEXT("PELVIS"));
	FName key2(TEXT("pelvis"));
	UE_LOG(LogTemp, Log, TEXT("FName 비교 결과: %s"), key1 == key2 ? TEXT("같음") : TEXT("다름"));
	// output: LogTemp: FName 비교 결과: 같음

	for (int i = 0; i < 10000; i++)
	{
		// !key가 글로벌pool에 있는지 확인하기
		// 이렇게 하면 오버헤드 발생할 수 있음
		FName SearchInNamePool = FName(TEXT("pelvis"));
		// 이렇게 한번만 처리해주게 하는게 오버헤드를 방지한다고 한다.
		const static FName StaticOnlyOnce(TEXT("pelvis"));
	}
}
```
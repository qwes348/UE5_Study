// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameInstance.h"
#include "Student.h"
#include "JsonObjectConverter.h"
#include "UObject/SavePackage.h"

// 게임에서 사용되는 에셋들을 모아놓은 폴더 -> Game (컨텐츠 브라우저에서 확인 가능)
// UE 5.3에서는 패키지이름과 에셋이름이 일치해야 정상적으로 실행됨
const FString UMyGameInstance::PackageName = TEXT("/Game/TopStudent");
const FString UMyGameInstance::AssetName = TEXT("TopStudent");

void PrintStudentInfo(const UStudent* InStudent, const FString& InTag)
{
	UE_LOG(LogTemp, Log, TEXT("[%s] 이름 %s 순번 %d"), *InTag, *InStudent->GetName(), InStudent->GetOrder());
}

UMyGameInstance::UMyGameInstance()
{
	// 생성자에서 에셋 로드하기 -> 게임이 시작되는 시점에 에셋이 메모리에 올라와있어야 하는 경우
	const FString TopSoftObjectPath = FString::Printf(TEXT("%s.%s"), *PackageName, *AssetName);
	static ConstructorHelpers::FObjectFinder<UStudent> UASSET_TopStudent(*TopSoftObjectPath);
	// 로드에 성공한 경우 true
	if (UASSET_TopStudent.Succeeded())
	{
		//! 에디터가 로드될 때 한번, 에디터에서 게임을 플레이할 때 한번 => 총 2번 로그가 찍힘
		PrintStudentInfo(UASSET_TopStudent.Object, TEXT("Constructor"));
	}
}

void UMyGameInstance::Init()
{
	Super::Init();

	FStudentData RawDataSrc(16, TEXT("이득우"));

	// 프로젝트 경로/Saved 폴더의 경로를 얻어옴
	const FString SavedDir = FPaths::Combine(FPlatformMisc::ProjectDir(), TEXT("Saved"));
	// 출력: 저장할 파일 폴더: ../../../../../../UE5_Inflearn/Part1/UnrealSerialization/Saved
	UE_LOG(LogTemp, Log, TEXT("저장할 파일 폴더: %s"), *SavedDir);	

	{
		const FString RawDataFileName(TEXT("RawData.bin"));
		FString RawDataAbsolutePath = FPaths::Combine(*SavedDir, *RawDataFileName);
		// 출력: 저장할 파일전체 경로: ../../../../../../UE5_Inflearn/Part1/UnrealSerialization/Saved/RawData.bin
		UE_LOG(LogTemp, Log, TEXT("저장할 파일전체 경로: %s"), *RawDataAbsolutePath);

		// 절대경로로 변환해줌 기존값은 상대경로임
		FPaths::MakeStandardFilename(RawDataAbsolutePath);
		// 출력: 변경할 파일전체 경로: E:/UE5_Inflearn/Part1/UnrealSerialization/Saved/RawData.bin
		UE_LOG(LogTemp, Log, TEXT("변경할 파일전체 경로: %s"), *RawDataAbsolutePath);

		FArchive* RawFileWriteAr = IFileManager::Get().CreateFileWriter(*RawDataAbsolutePath);
		if (nullptr != RawFileWriteAr)
		{
			/**RawFileWriteAr << RawDataSrc.Order;
			*RawFileWriteAr << RawDataSrc.Name;*/

			// 연산자 오버라이딩을 구현했기때문에 위 주석처럼 일일히 여기서 안넣어도 됨
			*RawFileWriteAr << RawDataSrc;
			RawFileWriteAr->Close();
			delete RawFileWriteAr;
			RawFileWriteAr = nullptr;
		}

		FStudentData RawDataDest;
		FArchive* RawFileReaderAr = IFileManager::Get().CreateFileReader(*RawDataAbsolutePath);
		if (nullptr != RawFileReaderAr)
		{
			// 읽기라도 저장과 똑같이 (<<) 쉬프트 연산자를 사용함
			*RawFileReaderAr << RawDataDest;
			RawFileReaderAr->Close();
			delete RawFileReaderAr;
			RawFileReaderAr = nullptr;

			// 출력: [RawData] 이름 이득우 순번 16
			// 저장했던 데이터 그대로 읽어왔음
			UE_LOG(LogTemp, Log, TEXT("[RawData] 이름 %s 순번 %d"), *RawDataDest.Name, RawDataDest.Order);
		}
	}

	// 여기부터는 언리얼 오브젝트를 직렬화 하는 방법
	StudentSrc = NewObject<UStudent>();
	StudentSrc->SetName(TEXT("이득우"));
	StudentSrc->SetOrder(59);

	{
		const FString ObjectDataFileName(TEXT("ObjectData.bin"));
		FString ObjectDataAbsolutePath = FPaths::Combine(*SavedDir, *ObjectDataFileName);
		FPaths::MakeStandardFilename(ObjectDataAbsolutePath);

		TArray<uint8> BufferArray;
		FMemoryWriter MemoryWriteAr(BufferArray);
		// 메모리에 직렬화
		StudentSrc->Serialize(MemoryWriteAr);

		// 바로 쓰고 지울 용도로 편리하게 쓸 수 있는 스마트 포인터 라이브러리
		if (TUniquePtr<FArchive> FileWriteAr = TUniquePtr<FArchive>(IFileManager::Get().CreateFileWriter(*ObjectDataAbsolutePath)))
		{
			*FileWriteAr << BufferArray;
			FileWriteAr->Close();
			//!  스마트 포인터라서 delete까지 신경 안써도 됨
		}

		// 파일에서 읽어서 BufferArray로 담음
		TArray<uint8> BufferArrayFromFile;
		if (TUniquePtr<FArchive> FileReaderAr = TUniquePtr<FArchive>(IFileManager::Get().CreateFileReader(*ObjectDataAbsolutePath)))
		{
			*FileReaderAr << BufferArrayFromFile;
			FileReaderAr->Close();
		}

		// 버퍼에서 메모리로
		FMemoryReader MemoryReaderAr(BufferArrayFromFile);
		UStudent* StudentDest = NewObject<UStudent>();
		// 메모리에 옮긴 데이터를 StudentDest에 덮어씌움
		StudentDest->Serialize(MemoryReaderAr);
		PrintStudentInfo(StudentDest, TEXT("ObjectData"));
	}


	// Json으로 읽고 쓰기
	{
		FString JsonDataFileName(TEXT("StudentJsonData.json"));
		FString JsonDataAbsolutePath = FPaths::Combine(*SavedDir, *JsonDataFileName);
		FPaths::MakeStandardFilename(JsonDataAbsolutePath);

		// "JsonObjectConverter.h" include 필요
		//!중요 [프로젝트 명].build.cs파일에 Json관련 모듈 2개를 추가해줘야함
		// 공유 레퍼런스 - Null이 아님을 보장함
		TSharedRef<FJsonObject> JsonObjectSrc = MakeShared<FJsonObject>();
		// 이렇게하면 StudentSrc 인스턴스의 값이 Json으로 변환이 됨
		FJsonObjectConverter::UStructToJsonObject(StudentSrc->GetClass(), StudentSrc, JsonObjectSrc);

		// 파일로 디스크에 저장
		FString JsonOutString;
		TSharedRef<TJsonWriter<TCHAR>> JsonWriterAr = TJsonWriterFactory<TCHAR>::Create(&JsonOutString);
		if (FJsonSerializer::Serialize(JsonObjectSrc, JsonWriterAr))
		{
			FFileHelper::SaveStringToFile(JsonOutString, *JsonDataAbsolutePath);
		}

		FString JsonInString;
		FFileHelper::LoadFileToString(JsonInString, *JsonDataAbsolutePath);

		TSharedRef<TJsonReader<TCHAR>> JsonReaderAr = TJsonReaderFactory<TCHAR>::Create(JsonInString);
		// 파일에 문제가 있으면 Json이 안만들어질 수 있으므로 Null을 허용하는 TsharedPtr사용
		TSharedPtr<FJsonObject> JsonObjectDest;
		if (FJsonSerializer::Deserialize(JsonReaderAr, JsonObjectDest))
		{
			UStudent* JsonStudentDest = NewObject<UStudent>();
			if (FJsonObjectConverter::JsonObjectToUStruct(JsonObjectDest.ToSharedRef(), JsonStudentDest->GetClass(), JsonStudentDest))
			{
				PrintStudentInfo(JsonStudentDest, TEXT("JsonData"));
			}
		}
	}


	//! 14강 패키지
	SaveStudentPackage();
	LoadStudentPackage();
	LoadStudentObject();

	// 비동기로 에셋 로드
	const FString TopSoftObjectPath = FString::Printf(TEXT("%s.%s"), *PackageName, *AssetName);
	Handle = StreamableManager.RequestAsyncLoad(TopSoftObjectPath, 
		[&]()
		{
			if (Handle.IsValid() && Handle->HasLoadCompleted())
			{
				// 오브젝트를 UStudent로 변환
				UStudent* TopStudent = Cast<UStudent>(Handle->GetLoadedAsset());
				if (TopStudent)
				{
					PrintStudentInfo(TopStudent, TEXT("AsyncLoad"));

					Handle->ReleaseHandle();
					Handle.Reset();
				}
			}
		}
	);
}

void UMyGameInstance::SaveStudentPackage() const
{
	// 패키지가 이미 있을 수 있으니 로드를 먼저 시도함
	UPackage* StudentPackage = ::LoadPackage(nullptr, *PackageName, LOAD_None);
	if (StudentPackage)
	{
		StudentPackage->FullyLoad();
	}

	StudentPackage = CreatePackage(*PackageName);
	EObjectFlags ObjectFlag = RF_Public | RF_Standalone;

	// 오브젝트 생성하면서 패키지에 넣을 수 있게 파라미터를 채워넣음
	// 이름은 3번째 인자로 들어가기때문에 2번째인자는 강제로 넣어야함
	UStudent* TopStudent = NewObject<UStudent>(StudentPackage, UStudent::StaticClass(), *AssetName, ObjectFlag);
	TopStudent->SetName(TEXT("이득우"));
	TopStudent->SetOrder(36);

	// 서브 학생 10개 만들기
	const int32 NumofSubs = 10;
	for (int32 i = 1; i <= NumofSubs; i++)
	{
		FString SubObjectName = FString::Printf(TEXT("Student%d"), i);
		UStudent* SubStudent = NewObject<UStudent>(TopStudent, UStudent::StaticClass(), *SubObjectName, ObjectFlag);
		SubStudent->SetName(FString::Printf(TEXT("학생%d"), i));
		SubStudent->SetOrder(i);
	}

	// FPackageName::GetAssetPackageExtension() -> .uasset확장자
	// 최종적으로 /Game/Student.uasset으로 저장될 것
	const FString PackageFileName = FPackageName::LongPackageNameToFilename(PackageName, FPackageName::GetAssetPackageExtension());
	FSavePackageArgs SaveArgs;
	SaveArgs.TopLevelFlags = ObjectFlag;

	// 저장 실행
	if (UPackage::SavePackage(StudentPackage, nullptr, *PackageFileName, SaveArgs))
	{
		UE_LOG(LogTemp, Log, TEXT("패키지가 성공적으로 저장되었습니다."));
	}
}

void UMyGameInstance::LoadStudentPackage() const
{
	UPackage* StudentPackage = ::LoadPackage(nullptr, *PackageName, LOAD_None);
	if (nullptr == StudentPackage)
	{
		UE_LOG(LogTemp, Warning, TEXT("패키지를 찾을 수 없습니다."));
		return;
	}

	// 패키지를 로드
	StudentPackage->FullyLoad();

	UStudent* TopStudent = FindObject<UStudent>(StudentPackage, *AssetName);
	PrintStudentInfo(TopStudent, TEXT("FindObject Asset"));
}

// 패키지를 로드하지않고 바로 에셋을 로드하는 함수
void UMyGameInstance::LoadStudentObject() const
{
	const FString TopSoftObjectPath = FString::Printf(TEXT("%s.%s"), *PackageName, *AssetName);

	UStudent* TopStudent = LoadObject<UStudent>(nullptr, *TopSoftObjectPath);
	PrintStudentInfo(TopStudent, TEXT("LoadObject Asset"));
}

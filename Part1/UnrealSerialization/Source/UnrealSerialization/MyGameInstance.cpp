// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameInstance.h"
#include "Student.h"
#include "JsonObjectConverter.h"

void PrintStudentInfo(const UStudent* InStudent, const FString& InTag)
{
	UE_LOG(LogTemp, Log, TEXT("[%s] 이름 %s 순번 %d"), *InTag, *InStudent->GetName(), InStudent->GetOrder());
}

UMyGameInstance::UMyGameInstance()
{
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
	//? 여기서 이름만 불러오면 한글이 깨지는데 이유를 모르겠음
	StudentSrc->SetName("이득우");
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
}

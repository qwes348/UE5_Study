// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UnrealDelegate/Card.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCard() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	UNREALDELEGATE_API UClass* Z_Construct_UClass_UCard();
	UNREALDELEGATE_API UClass* Z_Construct_UClass_UCard_NoRegister();
	UNREALDELEGATE_API UEnum* Z_Construct_UEnum_UnrealDelegate_ECardType();
	UPackage* Z_Construct_UPackage__Script_UnrealDelegate();
// End Cross Module References
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_ECardType;
	static UEnum* ECardType_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_ECardType.OuterSingleton)
		{
			Z_Registration_Info_UEnum_ECardType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_UnrealDelegate_ECardType, (UObject*)Z_Construct_UPackage__Script_UnrealDelegate(), TEXT("ECardType"));
		}
		return Z_Registration_Info_UEnum_ECardType.OuterSingleton;
	}
	template<> UNREALDELEGATE_API UEnum* StaticEnum<ECardType>()
	{
		return ECardType_StaticEnum();
	}
	struct Z_Construct_UEnum_UnrealDelegate_ECardType_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_UnrealDelegate_ECardType_Statics::Enumerators[] = {
		{ "ECardType::Student", (int64)ECardType::Student },
		{ "ECardType::Teacher", (int64)ECardType::Teacher },
		{ "ECardType::Staff", (int64)ECardType::Staff },
		{ "ECardType::Invalid", (int64)ECardType::Invalid },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_UnrealDelegate_ECardType_Statics::Enum_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n* \xec\x96\xb8\xeb\xa6\xac\xec\x96\xbc\xec\x9d\x98 enum\xed\x83\x80\xec\x9e\x85\n* UENUM\xea\xb3\xbc UMETA\xeb\xa5\xbc \xec\x82\xac\xec\x9a\xa9 \xec\x95\x88\xed\x95\x98\xeb\xa9\xb4 \xea\xb7\xb8\xeb\x8c\x80\xeb\xa1\x9c C++\xec\x9d\x98 \xec\x97\xb4\xea\xb2\xa8\xed\x98\x95\xec\x9d\xb4\xeb\x8b\xa4.\n*/" },
#endif
		{ "Invalid.Name", "ECardType::Invalid" },
		{ "ModuleRelativePath", "Card.h" },
		{ "Staff.DisplayName", "For Staff" },
		{ "Staff.Name", "ECardType::Staff" },
		{ "Student.DisplayName", "For Student" },
		{ "Student.Name", "ECardType::Student" },
		{ "Teacher.DisplayName", "For Teacher" },
		{ "Teacher.Name", "ECardType::Teacher" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* \xec\x96\xb8\xeb\xa6\xac\xec\x96\xbc\xec\x9d\x98 enum\xed\x83\x80\xec\x9e\x85\n* UENUM\xea\xb3\xbc UMETA\xeb\xa5\xbc \xec\x82\xac\xec\x9a\xa9 \xec\x95\x88\xed\x95\x98\xeb\xa9\xb4 \xea\xb7\xb8\xeb\x8c\x80\xeb\xa1\x9c C++\xec\x9d\x98 \xec\x97\xb4\xea\xb2\xa8\xed\x98\x95\xec\x9d\xb4\xeb\x8b\xa4." },
#endif
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_UnrealDelegate_ECardType_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_UnrealDelegate,
		nullptr,
		"ECardType",
		"ECardType",
		Z_Construct_UEnum_UnrealDelegate_ECardType_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_UnrealDelegate_ECardType_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_UnrealDelegate_ECardType_Statics::Enum_MetaDataParams), Z_Construct_UEnum_UnrealDelegate_ECardType_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_UnrealDelegate_ECardType()
	{
		if (!Z_Registration_Info_UEnum_ECardType.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_ECardType.InnerSingleton, Z_Construct_UEnum_UnrealDelegate_ECardType_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_ECardType.InnerSingleton;
	}
	void UCard::StaticRegisterNativesUCard()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UCard);
	UClass* Z_Construct_UClass_UCard_NoRegister()
	{
		return UCard::StaticClass();
	}
	struct Z_Construct_UClass_UCard_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UECodeGen_Private::FBytePropertyParams NewProp_CardType_Underlying;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CardType_MetaData[];
#endif
		static const UECodeGen_Private::FEnumPropertyParams NewProp_CardType;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Id_MetaData[];
#endif
		static const UECodeGen_Private::FUInt32PropertyParams NewProp_Id;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UCard_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_UnrealDelegate,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCard_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCard_Statics::Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "Card.h" },
		{ "ModuleRelativePath", "Card.h" },
	};
#endif
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UCard_Statics::NewProp_CardType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCard_Statics::NewProp_CardType_MetaData[] = {
		{ "ModuleRelativePath", "Card.h" },
	};
#endif
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UCard_Statics::NewProp_CardType = { "CardType", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCard, CardType), Z_Construct_UEnum_UnrealDelegate_ECardType, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UCard_Statics::NewProp_CardType_MetaData), Z_Construct_UClass_UCard_Statics::NewProp_CardType_MetaData) }; // 2070168478
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCard_Statics::NewProp_Id_MetaData[] = {
		{ "ModuleRelativePath", "Card.h" },
	};
#endif
	const UECodeGen_Private::FUInt32PropertyParams Z_Construct_UClass_UCard_Statics::NewProp_Id = { "Id", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::UInt32, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCard, Id), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UCard_Statics::NewProp_Id_MetaData), Z_Construct_UClass_UCard_Statics::NewProp_Id_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UCard_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCard_Statics::NewProp_CardType_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCard_Statics::NewProp_CardType,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCard_Statics::NewProp_Id,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UCard_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCard>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UCard_Statics::ClassParams = {
		&UCard::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UCard_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UCard_Statics::PropPointers),
		0,
		0x001000A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UCard_Statics::Class_MetaDataParams), Z_Construct_UClass_UCard_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCard_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UCard()
	{
		if (!Z_Registration_Info_UClass_UCard.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UCard.OuterSingleton, Z_Construct_UClass_UCard_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UCard.OuterSingleton;
	}
	template<> UNREALDELEGATE_API UClass* StaticClass<UCard>()
	{
		return UCard::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UCard);
	UCard::~UCard() {}
	struct Z_CompiledInDeferFile_FID_UnrealDelegate_Source_UnrealDelegate_Card_h_Statics
	{
		static const FEnumRegisterCompiledInInfo EnumInfo[];
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FEnumRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealDelegate_Source_UnrealDelegate_Card_h_Statics::EnumInfo[] = {
		{ ECardType_StaticEnum, TEXT("ECardType"), &Z_Registration_Info_UEnum_ECardType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2070168478U) },
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealDelegate_Source_UnrealDelegate_Card_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UCard, UCard::StaticClass, TEXT("UCard"), &Z_Registration_Info_UClass_UCard, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UCard), 3805466464U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealDelegate_Source_UnrealDelegate_Card_h_1599715483(TEXT("/Script/UnrealDelegate"),
		Z_CompiledInDeferFile_FID_UnrealDelegate_Source_UnrealDelegate_Card_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealDelegate_Source_UnrealDelegate_Card_h_Statics::ClassInfo),
		nullptr, 0,
		Z_CompiledInDeferFile_FID_UnrealDelegate_Source_UnrealDelegate_Card_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealDelegate_Source_UnrealDelegate_Card_h_Statics::EnumInfo));
PRAGMA_ENABLE_DEPRECATION_WARNINGS

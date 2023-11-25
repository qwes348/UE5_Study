// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UnrealComposition/Person.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePerson() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	UNREALCOMPOSITION_API UClass* Z_Construct_UClass_UCard_NoRegister();
	UNREALCOMPOSITION_API UClass* Z_Construct_UClass_UPerson();
	UNREALCOMPOSITION_API UClass* Z_Construct_UClass_UPerson_NoRegister();
	UPackage* Z_Construct_UPackage__Script_UnrealComposition();
// End Cross Module References
	void UPerson::StaticRegisterNativesUPerson()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UPerson);
	UClass* Z_Construct_UClass_UPerson_NoRegister()
	{
		return UPerson::StaticClass();
	}
	struct Z_Construct_UClass_UPerson_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_Name;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Card_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPtrPropertyParams NewProp_Card;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UPerson_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_UnrealComposition,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPerson_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPerson_Statics::Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "Person.h" },
		{ "ModuleRelativePath", "Person.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPerson_Statics::NewProp_Name_MetaData[] = {
		{ "ModuleRelativePath", "Person.h" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UPerson_Statics::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0020080000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPerson, Name), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPerson_Statics::NewProp_Name_MetaData), Z_Construct_UClass_UPerson_Statics::NewProp_Name_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPerson_Statics::NewProp_Card_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xec\xa0\x84\xeb\xb0\xa9\xec\x84\xa0\xec\x96\xb8\xec\x9d\x84 \xed\x86\xb5\xed\x95\xb4 \xed\x97\xa4\xeb\x8d\x94\xeb\xa5\xbc Include\xed\x95\x98\xec\xa7\x80 \xec\x95\x8a\xec\x9d\x84 \xec\x88\x98 \xec\x9e\x88\xec\x9d\x8c\n// \xec\x96\xb8\xeb\xa6\xac\xec\x96\xbc""4\xea\xb9\x8c\xec\xa7\x84 \xec\x9d\xb4\xeb\xa0\x87\xea\xb2\x8c \xed\x95\xb4\xeb\x8f\x84 \xeb\x90\x90\xec\x9d\x8c\n//class UCard* Card;\n// \xec\x96\xb8\xeb\xa6\xac\xec\x96\xbc""5\xec\x97\x90\xec\x84\xa0 \xec\x95\x84\xeb\x9e\x98 \xeb\xb0\xa9\xeb\xb2\x95\xec\x9d\x84 \xea\xb6\x8c\xec\x9e\xa5 \xed\x95\xa8\n" },
#endif
		{ "ModuleRelativePath", "Person.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xec\xa0\x84\xeb\xb0\xa9\xec\x84\xa0\xec\x96\xb8\xec\x9d\x84 \xed\x86\xb5\xed\x95\xb4 \xed\x97\xa4\xeb\x8d\x94\xeb\xa5\xbc Include\xed\x95\x98\xec\xa7\x80 \xec\x95\x8a\xec\x9d\x84 \xec\x88\x98 \xec\x9e\x88\xec\x9d\x8c\n\xec\x96\xb8\xeb\xa6\xac\xec\x96\xbc""4\xea\xb9\x8c\xec\xa7\x84 \xec\x9d\xb4\xeb\xa0\x87\xea\xb2\x8c \xed\x95\xb4\xeb\x8f\x84 \xeb\x90\x90\xec\x9d\x8c\nclass UCard* Card;\n\xec\x96\xb8\xeb\xa6\xac\xec\x96\xbc""5\xec\x97\x90\xec\x84\xa0 \xec\x95\x84\xeb\x9e\x98 \xeb\xb0\xa9\xeb\xb2\x95\xec\x9d\x84 \xea\xb6\x8c\xec\x9e\xa5 \xed\x95\xa8" },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPtrPropertyParams Z_Construct_UClass_UPerson_Statics::NewProp_Card = { "Card", nullptr, (EPropertyFlags)0x0024080000000000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPerson, Card), Z_Construct_UClass_UCard_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPerson_Statics::NewProp_Card_MetaData), Z_Construct_UClass_UPerson_Statics::NewProp_Card_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UPerson_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPerson_Statics::NewProp_Name,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPerson_Statics::NewProp_Card,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UPerson_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPerson>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UPerson_Statics::ClassParams = {
		&UPerson::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UPerson_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UPerson_Statics::PropPointers),
		0,
		0x001000A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPerson_Statics::Class_MetaDataParams), Z_Construct_UClass_UPerson_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPerson_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UPerson()
	{
		if (!Z_Registration_Info_UClass_UPerson.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UPerson.OuterSingleton, Z_Construct_UClass_UPerson_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UPerson.OuterSingleton;
	}
	template<> UNREALCOMPOSITION_API UClass* StaticClass<UPerson>()
	{
		return UPerson::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UPerson);
	UPerson::~UPerson() {}
	struct Z_CompiledInDeferFile_FID_UnrealComposition_Source_UnrealComposition_Person_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealComposition_Source_UnrealComposition_Person_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UPerson, UPerson::StaticClass, TEXT("UPerson"), &Z_Registration_Info_UClass_UPerson, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UPerson), 2922125891U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealComposition_Source_UnrealComposition_Person_h_4076647121(TEXT("/Script/UnrealComposition"),
		Z_CompiledInDeferFile_FID_UnrealComposition_Source_UnrealComposition_Person_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealComposition_Source_UnrealComposition_Person_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS

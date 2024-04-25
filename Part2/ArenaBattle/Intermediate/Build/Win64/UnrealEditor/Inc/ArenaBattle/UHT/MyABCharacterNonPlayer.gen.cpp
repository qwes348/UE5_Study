// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Character/MyABCharacterNonPlayer.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMyABCharacterNonPlayer() {}
// Cross Module References
	ARENABATTLE_API UClass* Z_Construct_UClass_AABCharacterBase();
	ARENABATTLE_API UClass* Z_Construct_UClass_AMyABCharacterNonPlayer();
	ARENABATTLE_API UClass* Z_Construct_UClass_AMyABCharacterNonPlayer_NoRegister();
	UPackage* Z_Construct_UPackage__Script_ArenaBattle();
// End Cross Module References
	void AMyABCharacterNonPlayer::StaticRegisterNativesAMyABCharacterNonPlayer()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AMyABCharacterNonPlayer);
	UClass* Z_Construct_UClass_AMyABCharacterNonPlayer_NoRegister()
	{
		return AMyABCharacterNonPlayer::StaticClass();
	}
	struct Z_Construct_UClass_AMyABCharacterNonPlayer_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AMyABCharacterNonPlayer_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AABCharacterBase,
		(UObject* (*)())Z_Construct_UPackage__Script_ArenaBattle,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AMyABCharacterNonPlayer_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyABCharacterNonPlayer_Statics::Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "Character/MyABCharacterNonPlayer.h" },
		{ "ModuleRelativePath", "Character/MyABCharacterNonPlayer.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AMyABCharacterNonPlayer_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AMyABCharacterNonPlayer>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AMyABCharacterNonPlayer_Statics::ClassParams = {
		&AMyABCharacterNonPlayer::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AMyABCharacterNonPlayer_Statics::Class_MetaDataParams), Z_Construct_UClass_AMyABCharacterNonPlayer_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_AMyABCharacterNonPlayer()
	{
		if (!Z_Registration_Info_UClass_AMyABCharacterNonPlayer.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AMyABCharacterNonPlayer.OuterSingleton, Z_Construct_UClass_AMyABCharacterNonPlayer_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AMyABCharacterNonPlayer.OuterSingleton;
	}
	template<> ARENABATTLE_API UClass* StaticClass<AMyABCharacterNonPlayer>()
	{
		return AMyABCharacterNonPlayer::StaticClass();
	}
	AMyABCharacterNonPlayer::AMyABCharacterNonPlayer() {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AMyABCharacterNonPlayer);
	AMyABCharacterNonPlayer::~AMyABCharacterNonPlayer() {}
	struct Z_CompiledInDeferFile_FID_UE5_Inflearn_Part2_ArenaBattle_Source_ArenaBattle_Character_MyABCharacterNonPlayer_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UE5_Inflearn_Part2_ArenaBattle_Source_ArenaBattle_Character_MyABCharacterNonPlayer_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AMyABCharacterNonPlayer, AMyABCharacterNonPlayer::StaticClass, TEXT("AMyABCharacterNonPlayer"), &Z_Registration_Info_UClass_AMyABCharacterNonPlayer, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AMyABCharacterNonPlayer), 2365680822U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UE5_Inflearn_Part2_ArenaBattle_Source_ArenaBattle_Character_MyABCharacterNonPlayer_h_1170743528(TEXT("/Script/ArenaBattle"),
		Z_CompiledInDeferFile_FID_UE5_Inflearn_Part2_ArenaBattle_Source_ArenaBattle_Character_MyABCharacterNonPlayer_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UE5_Inflearn_Part2_ArenaBattle_Source_ArenaBattle_Character_MyABCharacterNonPlayer_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS

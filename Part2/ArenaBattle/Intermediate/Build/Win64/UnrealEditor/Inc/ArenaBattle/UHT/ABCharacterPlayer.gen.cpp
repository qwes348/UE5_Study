// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Character/ABCharacterPlayer.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeABCharacterPlayer() {}
// Cross Module References
	ARENABATTLE_API UClass* Z_Construct_UClass_AABCharacterBase();
	ARENABATTLE_API UClass* Z_Construct_UClass_AABCharacterPlayer();
	ARENABATTLE_API UClass* Z_Construct_UClass_AABCharacterPlayer_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UCameraComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USpringArmComponent_NoRegister();
	ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputAction_NoRegister();
	UPackage* Z_Construct_UPackage__Script_ArenaBattle();
// End Cross Module References
	void AABCharacterPlayer::StaticRegisterNativesAABCharacterPlayer()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AABCharacterPlayer);
	UClass* Z_Construct_UClass_AABCharacterPlayer_NoRegister()
	{
		return AABCharacterPlayer::StaticClass();
	}
	struct Z_Construct_UClass_AABCharacterPlayer_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CameraBoom_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPtrPropertyParams NewProp_CameraBoom;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_FollowCamera_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPtrPropertyParams NewProp_FollowCamera;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_JumpAction_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPtrPropertyParams NewProp_JumpAction;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ChangeControlAction_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPtrPropertyParams NewProp_ChangeControlAction;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ShoulderMoveAction_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPtrPropertyParams NewProp_ShoulderMoveAction;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ShoulderLookAction_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPtrPropertyParams NewProp_ShoulderLookAction;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_QuaterMoveAction_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPtrPropertyParams NewProp_QuaterMoveAction;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AttackAction_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPtrPropertyParams NewProp_AttackAction;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AABCharacterPlayer_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AABCharacterBase,
		(UObject* (*)())Z_Construct_UPackage__Script_ArenaBattle,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AABCharacterPlayer_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AABCharacterPlayer_Statics::Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "Character/ABCharacterPlayer.h" },
		{ "ModuleRelativePath", "Character/ABCharacterPlayer.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AABCharacterPlayer_Statics::NewProp_CameraBoom_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Camera" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xec\xb9\xb4\xeb\xa9\x94\xeb\x9d\xbc \xec\xa7\x80\xec\xa7\x80\xeb\x8c\x80\n// AllowPrivateAccess => \xec\x96\xb8\xeb\xa6\xac\xec\x96\xbc \xec\x98\xa4\xeb\xb8\x8c\xec\xa0\x9d\xed\x8a\xb8\xeb\xa5\xbc \xeb\xb8\x94\xeb\xa3\xa8\xed\x94\x84\xeb\xa6\xb0\xed\x8a\xb8\xec\x97\x90\xec\x84\x9c\xeb\x8f\x84 \xec\xa0\x91\xea\xb7\xbc\xed\x95\xa0 \xec\x88\x98 \xec\x9e\x88\xeb\x8f\x84\xeb\xa1\x9d \xed\x95\xa8\n" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Character/ABCharacterPlayer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xec\xb9\xb4\xeb\xa9\x94\xeb\x9d\xbc \xec\xa7\x80\xec\xa7\x80\xeb\x8c\x80\nAllowPrivateAccess => \xec\x96\xb8\xeb\xa6\xac\xec\x96\xbc \xec\x98\xa4\xeb\xb8\x8c\xec\xa0\x9d\xed\x8a\xb8\xeb\xa5\xbc \xeb\xb8\x94\xeb\xa3\xa8\xed\x94\x84\xeb\xa6\xb0\xed\x8a\xb8\xec\x97\x90\xec\x84\x9c\xeb\x8f\x84 \xec\xa0\x91\xea\xb7\xbc\xed\x95\xa0 \xec\x88\x98 \xec\x9e\x88\xeb\x8f\x84\xeb\xa1\x9d \xed\x95\xa8" },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPtrPropertyParams Z_Construct_UClass_AABCharacterPlayer_Statics::NewProp_CameraBoom = { "CameraBoom", nullptr, (EPropertyFlags)0x00240800000a001d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AABCharacterPlayer, CameraBoom), Z_Construct_UClass_USpringArmComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AABCharacterPlayer_Statics::NewProp_CameraBoom_MetaData), Z_Construct_UClass_AABCharacterPlayer_Statics::NewProp_CameraBoom_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AABCharacterPlayer_Statics::NewProp_FollowCamera_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Camera" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xed\x8c\x94\xeb\xa1\x9c\xec\x9a\xb0 \xec\xba\xa0\n" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Character/ABCharacterPlayer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xed\x8c\x94\xeb\xa1\x9c\xec\x9a\xb0 \xec\xba\xa0" },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPtrPropertyParams Z_Construct_UClass_AABCharacterPlayer_Statics::NewProp_FollowCamera = { "FollowCamera", nullptr, (EPropertyFlags)0x00240800000a001d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AABCharacterPlayer, FollowCamera), Z_Construct_UClass_UCameraComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AABCharacterPlayer_Statics::NewProp_FollowCamera_MetaData), Z_Construct_UClass_AABCharacterPlayer_Statics::NewProp_FollowCamera_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AABCharacterPlayer_Statics::NewProp_JumpAction_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Input" },
		{ "ModuleRelativePath", "Character/ABCharacterPlayer.h" },
	};
#endif
	const UECodeGen_Private::FObjectPtrPropertyParams Z_Construct_UClass_AABCharacterPlayer_Statics::NewProp_JumpAction = { "JumpAction", nullptr, (EPropertyFlags)0x0024080000000015, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AABCharacterPlayer, JumpAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AABCharacterPlayer_Statics::NewProp_JumpAction_MetaData), Z_Construct_UClass_AABCharacterPlayer_Statics::NewProp_JumpAction_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AABCharacterPlayer_Statics::NewProp_ChangeControlAction_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Input" },
		{ "ModuleRelativePath", "Character/ABCharacterPlayer.h" },
	};
#endif
	const UECodeGen_Private::FObjectPtrPropertyParams Z_Construct_UClass_AABCharacterPlayer_Statics::NewProp_ChangeControlAction = { "ChangeControlAction", nullptr, (EPropertyFlags)0x0024080000000015, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AABCharacterPlayer, ChangeControlAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AABCharacterPlayer_Statics::NewProp_ChangeControlAction_MetaData), Z_Construct_UClass_AABCharacterPlayer_Statics::NewProp_ChangeControlAction_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AABCharacterPlayer_Statics::NewProp_ShoulderMoveAction_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Input" },
		{ "ModuleRelativePath", "Character/ABCharacterPlayer.h" },
	};
#endif
	const UECodeGen_Private::FObjectPtrPropertyParams Z_Construct_UClass_AABCharacterPlayer_Statics::NewProp_ShoulderMoveAction = { "ShoulderMoveAction", nullptr, (EPropertyFlags)0x0024080000000015, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AABCharacterPlayer, ShoulderMoveAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AABCharacterPlayer_Statics::NewProp_ShoulderMoveAction_MetaData), Z_Construct_UClass_AABCharacterPlayer_Statics::NewProp_ShoulderMoveAction_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AABCharacterPlayer_Statics::NewProp_ShoulderLookAction_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Input" },
		{ "ModuleRelativePath", "Character/ABCharacterPlayer.h" },
	};
#endif
	const UECodeGen_Private::FObjectPtrPropertyParams Z_Construct_UClass_AABCharacterPlayer_Statics::NewProp_ShoulderLookAction = { "ShoulderLookAction", nullptr, (EPropertyFlags)0x0024080000000015, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AABCharacterPlayer, ShoulderLookAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AABCharacterPlayer_Statics::NewProp_ShoulderLookAction_MetaData), Z_Construct_UClass_AABCharacterPlayer_Statics::NewProp_ShoulderLookAction_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AABCharacterPlayer_Statics::NewProp_QuaterMoveAction_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Input" },
		{ "ModuleRelativePath", "Character/ABCharacterPlayer.h" },
	};
#endif
	const UECodeGen_Private::FObjectPtrPropertyParams Z_Construct_UClass_AABCharacterPlayer_Statics::NewProp_QuaterMoveAction = { "QuaterMoveAction", nullptr, (EPropertyFlags)0x0024080000000015, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AABCharacterPlayer, QuaterMoveAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AABCharacterPlayer_Statics::NewProp_QuaterMoveAction_MetaData), Z_Construct_UClass_AABCharacterPlayer_Statics::NewProp_QuaterMoveAction_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AABCharacterPlayer_Statics::NewProp_AttackAction_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Input" },
		{ "ModuleRelativePath", "Character/ABCharacterPlayer.h" },
	};
#endif
	const UECodeGen_Private::FObjectPtrPropertyParams Z_Construct_UClass_AABCharacterPlayer_Statics::NewProp_AttackAction = { "AttackAction", nullptr, (EPropertyFlags)0x0024080000000015, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AABCharacterPlayer, AttackAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AABCharacterPlayer_Statics::NewProp_AttackAction_MetaData), Z_Construct_UClass_AABCharacterPlayer_Statics::NewProp_AttackAction_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AABCharacterPlayer_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AABCharacterPlayer_Statics::NewProp_CameraBoom,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AABCharacterPlayer_Statics::NewProp_FollowCamera,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AABCharacterPlayer_Statics::NewProp_JumpAction,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AABCharacterPlayer_Statics::NewProp_ChangeControlAction,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AABCharacterPlayer_Statics::NewProp_ShoulderMoveAction,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AABCharacterPlayer_Statics::NewProp_ShoulderLookAction,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AABCharacterPlayer_Statics::NewProp_QuaterMoveAction,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AABCharacterPlayer_Statics::NewProp_AttackAction,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AABCharacterPlayer_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AABCharacterPlayer>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AABCharacterPlayer_Statics::ClassParams = {
		&AABCharacterPlayer::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_AABCharacterPlayer_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_AABCharacterPlayer_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AABCharacterPlayer_Statics::Class_MetaDataParams), Z_Construct_UClass_AABCharacterPlayer_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AABCharacterPlayer_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_AABCharacterPlayer()
	{
		if (!Z_Registration_Info_UClass_AABCharacterPlayer.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AABCharacterPlayer.OuterSingleton, Z_Construct_UClass_AABCharacterPlayer_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AABCharacterPlayer.OuterSingleton;
	}
	template<> ARENABATTLE_API UClass* StaticClass<AABCharacterPlayer>()
	{
		return AABCharacterPlayer::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AABCharacterPlayer);
	AABCharacterPlayer::~AABCharacterPlayer() {}
	struct Z_CompiledInDeferFile_FID_UE5_Inflearn_Part2_ArenaBattle_Source_ArenaBattle_Character_ABCharacterPlayer_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UE5_Inflearn_Part2_ArenaBattle_Source_ArenaBattle_Character_ABCharacterPlayer_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AABCharacterPlayer, AABCharacterPlayer::StaticClass, TEXT("AABCharacterPlayer"), &Z_Registration_Info_UClass_AABCharacterPlayer, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AABCharacterPlayer), 3297812293U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UE5_Inflearn_Part2_ArenaBattle_Source_ArenaBattle_Character_ABCharacterPlayer_h_2642564689(TEXT("/Script/ArenaBattle"),
		Z_CompiledInDeferFile_FID_UE5_Inflearn_Part2_ArenaBattle_Source_ArenaBattle_Character_ABCharacterPlayer_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UE5_Inflearn_Part2_ArenaBattle_Source_ArenaBattle_Character_ABCharacterPlayer_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS

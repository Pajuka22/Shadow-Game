// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ShadowGame/ShadowGameGameMode.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeShadowGameGameMode() {}
// Cross Module References
	SHADOWGAME_API UClass* Z_Construct_UClass_AShadowGameGameMode_NoRegister();
	SHADOWGAME_API UClass* Z_Construct_UClass_AShadowGameGameMode();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_ShadowGame();
// End Cross Module References
	void AShadowGameGameMode::StaticRegisterNativesAShadowGameGameMode()
	{
	}
	UClass* Z_Construct_UClass_AShadowGameGameMode_NoRegister()
	{
		return AShadowGameGameMode::StaticClass();
	}
	struct Z_Construct_UClass_AShadowGameGameMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AShadowGameGameMode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_ShadowGame,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AShadowGameGameMode_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "ShadowGameGameMode.h" },
		{ "ModuleRelativePath", "ShadowGameGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AShadowGameGameMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AShadowGameGameMode>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AShadowGameGameMode_Statics::ClassParams = {
		&AShadowGameGameMode::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x008802A8u,
		METADATA_PARAMS(Z_Construct_UClass_AShadowGameGameMode_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_AShadowGameGameMode_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AShadowGameGameMode()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AShadowGameGameMode_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AShadowGameGameMode, 735238229);
	template<> SHADOWGAME_API UClass* StaticClass<AShadowGameGameMode>()
	{
		return AShadowGameGameMode::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AShadowGameGameMode(Z_Construct_UClass_AShadowGameGameMode, &AShadowGameGameMode::StaticClass, TEXT("/Script/ShadowGame"), TEXT("AShadowGameGameMode"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AShadowGameGameMode);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif

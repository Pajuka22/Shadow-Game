// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ShadowGame/ShadowGameHUD.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeShadowGameHUD() {}
// Cross Module References
	SHADOWGAME_API UClass* Z_Construct_UClass_AShadowGameHUD_NoRegister();
	SHADOWGAME_API UClass* Z_Construct_UClass_AShadowGameHUD();
	ENGINE_API UClass* Z_Construct_UClass_AHUD();
	UPackage* Z_Construct_UPackage__Script_ShadowGame();
// End Cross Module References
	void AShadowGameHUD::StaticRegisterNativesAShadowGameHUD()
	{
	}
	UClass* Z_Construct_UClass_AShadowGameHUD_NoRegister()
	{
		return AShadowGameHUD::StaticClass();
	}
	struct Z_Construct_UClass_AShadowGameHUD_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AShadowGameHUD_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AHUD,
		(UObject* (*)())Z_Construct_UPackage__Script_ShadowGame,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AShadowGameHUD_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Rendering Actor Input Replication" },
		{ "IncludePath", "ShadowGameHUD.h" },
		{ "ModuleRelativePath", "ShadowGameHUD.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AShadowGameHUD_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AShadowGameHUD>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AShadowGameHUD_Statics::ClassParams = {
		&AShadowGameHUD::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x008002ACu,
		METADATA_PARAMS(Z_Construct_UClass_AShadowGameHUD_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_AShadowGameHUD_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AShadowGameHUD()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AShadowGameHUD_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AShadowGameHUD, 90315385);
	template<> SHADOWGAME_API UClass* StaticClass<AShadowGameHUD>()
	{
		return AShadowGameHUD::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AShadowGameHUD(Z_Construct_UClass_AShadowGameHUD, &AShadowGameHUD::StaticClass, TEXT("/Script/ShadowGame"), TEXT("AShadowGameHUD"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AShadowGameHUD);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif

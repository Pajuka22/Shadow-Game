// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ShadowGame/SLStealth.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSLStealth() {}
// Cross Module References
	SHADOWGAME_API UClass* Z_Construct_UClass_ASLStealth_NoRegister();
	SHADOWGAME_API UClass* Z_Construct_UClass_ASLStealth();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_ShadowGame();
	ENGINE_API UClass* Z_Construct_UClass_USpotLightComponent_NoRegister();
// End Cross Module References
	void ASLStealth::StaticRegisterNativesASLStealth()
	{
	}
	UClass* Z_Construct_UClass_ASLStealth_NoRegister()
	{
		return ASLStealth::StaticClass();
	}
	struct Z_Construct_UClass_ASLStealth_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Source_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Source;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ASLStealth_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_ShadowGame,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASLStealth_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "SLStealth.h" },
		{ "ModuleRelativePath", "SLStealth.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASLStealth_Statics::NewProp_Source_MetaData[] = {
		{ "Category", "SLStealth" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "SLStealth.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASLStealth_Statics::NewProp_Source = { "Source", nullptr, (EPropertyFlags)0x0040000000080009, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASLStealth, Source), Z_Construct_UClass_USpotLightComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ASLStealth_Statics::NewProp_Source_MetaData, ARRAY_COUNT(Z_Construct_UClass_ASLStealth_Statics::NewProp_Source_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ASLStealth_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASLStealth_Statics::NewProp_Source,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ASLStealth_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ASLStealth>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ASLStealth_Statics::ClassParams = {
		&ASLStealth::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_ASLStealth_Statics::PropPointers,
		nullptr,
		ARRAY_COUNT(DependentSingletons),
		0,
		ARRAY_COUNT(Z_Construct_UClass_ASLStealth_Statics::PropPointers),
		0,
		0x009000A0u,
		METADATA_PARAMS(Z_Construct_UClass_ASLStealth_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_ASLStealth_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ASLStealth()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ASLStealth_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ASLStealth, 333100043);
	template<> SHADOWGAME_API UClass* StaticClass<ASLStealth>()
	{
		return ASLStealth::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ASLStealth(Z_Construct_UClass_ASLStealth, &ASLStealth::StaticClass, TEXT("/Script/ShadowGame"), TEXT("ASLStealth"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ASLStealth);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif

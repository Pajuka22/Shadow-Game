// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ShadowGame/Point_Stealth.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePoint_Stealth() {}
// Cross Module References
	SHADOWGAME_API UClass* Z_Construct_UClass_UPoint_Stealth_NoRegister();
	SHADOWGAME_API UClass* Z_Construct_UClass_UPoint_Stealth();
	ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
	UPackage* Z_Construct_UPackage__Script_ShadowGame();
	ENGINE_API UClass* Z_Construct_UClass_USpotLightComponent_NoRegister();
// End Cross Module References
	void UPoint_Stealth::StaticRegisterNativesUPoint_Stealth()
	{
	}
	UClass* Z_Construct_UClass_UPoint_Stealth_NoRegister()
	{
		return UPoint_Stealth::StaticClass();
	}
	struct Z_Construct_UClass_UPoint_Stealth_Statics
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
	UObject* (*const Z_Construct_UClass_UPoint_Stealth_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UActorComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_ShadowGame,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPoint_Stealth_Statics::Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Custom" },
		{ "IncludePath", "Point_Stealth.h" },
		{ "ModuleRelativePath", "Point_Stealth.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPoint_Stealth_Statics::NewProp_Source_MetaData[] = {
		{ "Category", "Point_Stealth" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Point_Stealth.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UPoint_Stealth_Statics::NewProp_Source = { "Source", nullptr, (EPropertyFlags)0x0040000000080009, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UPoint_Stealth, Source), Z_Construct_UClass_USpotLightComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UPoint_Stealth_Statics::NewProp_Source_MetaData, ARRAY_COUNT(Z_Construct_UClass_UPoint_Stealth_Statics::NewProp_Source_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UPoint_Stealth_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPoint_Stealth_Statics::NewProp_Source,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UPoint_Stealth_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPoint_Stealth>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UPoint_Stealth_Statics::ClassParams = {
		&UPoint_Stealth::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UPoint_Stealth_Statics::PropPointers,
		nullptr,
		ARRAY_COUNT(DependentSingletons),
		0,
		ARRAY_COUNT(Z_Construct_UClass_UPoint_Stealth_Statics::PropPointers),
		0,
		0x00B000A4u,
		METADATA_PARAMS(Z_Construct_UClass_UPoint_Stealth_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UPoint_Stealth_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UPoint_Stealth()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UPoint_Stealth_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UPoint_Stealth, 3792942550);
	template<> SHADOWGAME_API UClass* StaticClass<UPoint_Stealth>()
	{
		return UPoint_Stealth::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UPoint_Stealth(Z_Construct_UClass_UPoint_Stealth, &UPoint_Stealth::StaticClass, TEXT("/Script/ShadowGame"), TEXT("UPoint_Stealth"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UPoint_Stealth);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif

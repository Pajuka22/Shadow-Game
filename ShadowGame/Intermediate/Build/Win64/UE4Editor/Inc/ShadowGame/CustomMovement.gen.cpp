// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ShadowGame/CustomMovement.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCustomMovement() {}
// Cross Module References
	SHADOWGAME_API UClass* Z_Construct_UClass_UCustomMovement_NoRegister();
	SHADOWGAME_API UClass* Z_Construct_UClass_UCustomMovement();
	ENGINE_API UClass* Z_Construct_UClass_UPawnMovementComponent();
	UPackage* Z_Construct_UPackage__Script_ShadowGame();
// End Cross Module References
	void UCustomMovement::StaticRegisterNativesUCustomMovement()
	{
	}
	UClass* Z_Construct_UClass_UCustomMovement_NoRegister()
	{
		return UCustomMovement::StaticClass();
	}
	struct Z_Construct_UClass_UCustomMovement_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_maxAngle_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_maxAngle;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_RunSpeed_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_RunSpeed;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_WalkSpeed_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_WalkSpeed;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UCustomMovement_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UPawnMovementComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_ShadowGame,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCustomMovement_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "CustomMovement.h" },
		{ "ModuleRelativePath", "CustomMovement.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCustomMovement_Statics::NewProp_maxAngle_MetaData[] = {
		{ "Category", "CustomMovement" },
		{ "ModuleRelativePath", "CustomMovement.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCustomMovement_Statics::NewProp_maxAngle = { "maxAngle", nullptr, (EPropertyFlags)0x0040000000000001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UCustomMovement, maxAngle), METADATA_PARAMS(Z_Construct_UClass_UCustomMovement_Statics::NewProp_maxAngle_MetaData, ARRAY_COUNT(Z_Construct_UClass_UCustomMovement_Statics::NewProp_maxAngle_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCustomMovement_Statics::NewProp_RunSpeed_MetaData[] = {
		{ "Category", "CustomMovement" },
		{ "ModuleRelativePath", "CustomMovement.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCustomMovement_Statics::NewProp_RunSpeed = { "RunSpeed", nullptr, (EPropertyFlags)0x0040000000000001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UCustomMovement, RunSpeed), METADATA_PARAMS(Z_Construct_UClass_UCustomMovement_Statics::NewProp_RunSpeed_MetaData, ARRAY_COUNT(Z_Construct_UClass_UCustomMovement_Statics::NewProp_RunSpeed_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCustomMovement_Statics::NewProp_WalkSpeed_MetaData[] = {
		{ "Category", "CustomMovement" },
		{ "ModuleRelativePath", "CustomMovement.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCustomMovement_Statics::NewProp_WalkSpeed = { "WalkSpeed", nullptr, (EPropertyFlags)0x0040000000000001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UCustomMovement, WalkSpeed), METADATA_PARAMS(Z_Construct_UClass_UCustomMovement_Statics::NewProp_WalkSpeed_MetaData, ARRAY_COUNT(Z_Construct_UClass_UCustomMovement_Statics::NewProp_WalkSpeed_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UCustomMovement_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCustomMovement_Statics::NewProp_maxAngle,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCustomMovement_Statics::NewProp_RunSpeed,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCustomMovement_Statics::NewProp_WalkSpeed,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UCustomMovement_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCustomMovement>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UCustomMovement_Statics::ClassParams = {
		&UCustomMovement::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UCustomMovement_Statics::PropPointers,
		nullptr,
		ARRAY_COUNT(DependentSingletons),
		0,
		ARRAY_COUNT(Z_Construct_UClass_UCustomMovement_Statics::PropPointers),
		0,
		0x00B000A4u,
		METADATA_PARAMS(Z_Construct_UClass_UCustomMovement_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UCustomMovement_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UCustomMovement()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UCustomMovement_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UCustomMovement, 3084726291);
	template<> SHADOWGAME_API UClass* StaticClass<UCustomMovement>()
	{
		return UCustomMovement::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UCustomMovement(Z_Construct_UClass_UCustomMovement, &UCustomMovement::StaticClass, TEXT("/Script/ShadowGame"), TEXT("UCustomMovement"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UCustomMovement);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif

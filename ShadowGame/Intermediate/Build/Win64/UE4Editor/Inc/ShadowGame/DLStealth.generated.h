// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef SHADOWGAME_DLStealth_generated_h
#error "DLStealth.generated.h already included, missing '#pragma once' in DLStealth.h"
#endif
#define SHADOWGAME_DLStealth_generated_h

#define ShadowGame_Source_ShadowGame_DLStealth_h_12_RPC_WRAPPERS
#define ShadowGame_Source_ShadowGame_DLStealth_h_12_RPC_WRAPPERS_NO_PURE_DECLS
#define ShadowGame_Source_ShadowGame_DLStealth_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesADLStealth(); \
	friend struct Z_Construct_UClass_ADLStealth_Statics; \
public: \
	DECLARE_CLASS(ADLStealth, AActor, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/ShadowGame"), NO_API) \
	DECLARE_SERIALIZER(ADLStealth)


#define ShadowGame_Source_ShadowGame_DLStealth_h_12_INCLASS \
private: \
	static void StaticRegisterNativesADLStealth(); \
	friend struct Z_Construct_UClass_ADLStealth_Statics; \
public: \
	DECLARE_CLASS(ADLStealth, AActor, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/ShadowGame"), NO_API) \
	DECLARE_SERIALIZER(ADLStealth)


#define ShadowGame_Source_ShadowGame_DLStealth_h_12_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ADLStealth(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ADLStealth) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ADLStealth); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ADLStealth); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ADLStealth(ADLStealth&&); \
	NO_API ADLStealth(const ADLStealth&); \
public:


#define ShadowGame_Source_ShadowGame_DLStealth_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ADLStealth(ADLStealth&&); \
	NO_API ADLStealth(const ADLStealth&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ADLStealth); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ADLStealth); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ADLStealth)


#define ShadowGame_Source_ShadowGame_DLStealth_h_12_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__Source() { return STRUCT_OFFSET(ADLStealth, Source); }


#define ShadowGame_Source_ShadowGame_DLStealth_h_9_PROLOG
#define ShadowGame_Source_ShadowGame_DLStealth_h_12_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ShadowGame_Source_ShadowGame_DLStealth_h_12_PRIVATE_PROPERTY_OFFSET \
	ShadowGame_Source_ShadowGame_DLStealth_h_12_RPC_WRAPPERS \
	ShadowGame_Source_ShadowGame_DLStealth_h_12_INCLASS \
	ShadowGame_Source_ShadowGame_DLStealth_h_12_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define ShadowGame_Source_ShadowGame_DLStealth_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ShadowGame_Source_ShadowGame_DLStealth_h_12_PRIVATE_PROPERTY_OFFSET \
	ShadowGame_Source_ShadowGame_DLStealth_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	ShadowGame_Source_ShadowGame_DLStealth_h_12_INCLASS_NO_PURE_DECLS \
	ShadowGame_Source_ShadowGame_DLStealth_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> SHADOWGAME_API UClass* StaticClass<class ADLStealth>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID ShadowGame_Source_ShadowGame_DLStealth_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS

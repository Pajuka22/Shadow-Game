// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef SHADOWGAME_PLStealth_generated_h
#error "PLStealth.generated.h already included, missing '#pragma once' in PLStealth.h"
#endif
#define SHADOWGAME_PLStealth_generated_h

#define ShadowGame_Source_ShadowGame_PLStealth_h_13_RPC_WRAPPERS
#define ShadowGame_Source_ShadowGame_PLStealth_h_13_RPC_WRAPPERS_NO_PURE_DECLS
#define ShadowGame_Source_ShadowGame_PLStealth_h_13_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAPLStealth(); \
	friend struct Z_Construct_UClass_APLStealth_Statics; \
public: \
	DECLARE_CLASS(APLStealth, AActor, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/ShadowGame"), NO_API) \
	DECLARE_SERIALIZER(APLStealth)


#define ShadowGame_Source_ShadowGame_PLStealth_h_13_INCLASS \
private: \
	static void StaticRegisterNativesAPLStealth(); \
	friend struct Z_Construct_UClass_APLStealth_Statics; \
public: \
	DECLARE_CLASS(APLStealth, AActor, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/ShadowGame"), NO_API) \
	DECLARE_SERIALIZER(APLStealth)


#define ShadowGame_Source_ShadowGame_PLStealth_h_13_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API APLStealth(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(APLStealth) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, APLStealth); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(APLStealth); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API APLStealth(APLStealth&&); \
	NO_API APLStealth(const APLStealth&); \
public:


#define ShadowGame_Source_ShadowGame_PLStealth_h_13_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API APLStealth(APLStealth&&); \
	NO_API APLStealth(const APLStealth&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, APLStealth); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(APLStealth); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(APLStealth)


#define ShadowGame_Source_ShadowGame_PLStealth_h_13_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__Source() { return STRUCT_OFFSET(APLStealth, Source); }


#define ShadowGame_Source_ShadowGame_PLStealth_h_10_PROLOG
#define ShadowGame_Source_ShadowGame_PLStealth_h_13_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ShadowGame_Source_ShadowGame_PLStealth_h_13_PRIVATE_PROPERTY_OFFSET \
	ShadowGame_Source_ShadowGame_PLStealth_h_13_RPC_WRAPPERS \
	ShadowGame_Source_ShadowGame_PLStealth_h_13_INCLASS \
	ShadowGame_Source_ShadowGame_PLStealth_h_13_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define ShadowGame_Source_ShadowGame_PLStealth_h_13_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ShadowGame_Source_ShadowGame_PLStealth_h_13_PRIVATE_PROPERTY_OFFSET \
	ShadowGame_Source_ShadowGame_PLStealth_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	ShadowGame_Source_ShadowGame_PLStealth_h_13_INCLASS_NO_PURE_DECLS \
	ShadowGame_Source_ShadowGame_PLStealth_h_13_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> SHADOWGAME_API UClass* StaticClass<class APLStealth>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID ShadowGame_Source_ShadowGame_PLStealth_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS

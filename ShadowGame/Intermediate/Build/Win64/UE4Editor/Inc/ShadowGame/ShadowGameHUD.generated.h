// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef SHADOWGAME_ShadowGameHUD_generated_h
#error "ShadowGameHUD.generated.h already included, missing '#pragma once' in ShadowGameHUD.h"
#endif
#define SHADOWGAME_ShadowGameHUD_generated_h

#define ShadowGame_Source_ShadowGame_ShadowGameHUD_h_12_RPC_WRAPPERS
#define ShadowGame_Source_ShadowGame_ShadowGameHUD_h_12_RPC_WRAPPERS_NO_PURE_DECLS
#define ShadowGame_Source_ShadowGame_ShadowGameHUD_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAShadowGameHUD(); \
	friend struct Z_Construct_UClass_AShadowGameHUD_Statics; \
public: \
	DECLARE_CLASS(AShadowGameHUD, AHUD, COMPILED_IN_FLAGS(0 | CLASS_Transient | CLASS_Config), CASTCLASS_None, TEXT("/Script/ShadowGame"), NO_API) \
	DECLARE_SERIALIZER(AShadowGameHUD)


#define ShadowGame_Source_ShadowGame_ShadowGameHUD_h_12_INCLASS \
private: \
	static void StaticRegisterNativesAShadowGameHUD(); \
	friend struct Z_Construct_UClass_AShadowGameHUD_Statics; \
public: \
	DECLARE_CLASS(AShadowGameHUD, AHUD, COMPILED_IN_FLAGS(0 | CLASS_Transient | CLASS_Config), CASTCLASS_None, TEXT("/Script/ShadowGame"), NO_API) \
	DECLARE_SERIALIZER(AShadowGameHUD)


#define ShadowGame_Source_ShadowGame_ShadowGameHUD_h_12_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AShadowGameHUD(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AShadowGameHUD) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AShadowGameHUD); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AShadowGameHUD); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AShadowGameHUD(AShadowGameHUD&&); \
	NO_API AShadowGameHUD(const AShadowGameHUD&); \
public:


#define ShadowGame_Source_ShadowGame_ShadowGameHUD_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AShadowGameHUD(AShadowGameHUD&&); \
	NO_API AShadowGameHUD(const AShadowGameHUD&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AShadowGameHUD); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AShadowGameHUD); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AShadowGameHUD)


#define ShadowGame_Source_ShadowGame_ShadowGameHUD_h_12_PRIVATE_PROPERTY_OFFSET
#define ShadowGame_Source_ShadowGame_ShadowGameHUD_h_9_PROLOG
#define ShadowGame_Source_ShadowGame_ShadowGameHUD_h_12_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ShadowGame_Source_ShadowGame_ShadowGameHUD_h_12_PRIVATE_PROPERTY_OFFSET \
	ShadowGame_Source_ShadowGame_ShadowGameHUD_h_12_RPC_WRAPPERS \
	ShadowGame_Source_ShadowGame_ShadowGameHUD_h_12_INCLASS \
	ShadowGame_Source_ShadowGame_ShadowGameHUD_h_12_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define ShadowGame_Source_ShadowGame_ShadowGameHUD_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ShadowGame_Source_ShadowGame_ShadowGameHUD_h_12_PRIVATE_PROPERTY_OFFSET \
	ShadowGame_Source_ShadowGame_ShadowGameHUD_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	ShadowGame_Source_ShadowGame_ShadowGameHUD_h_12_INCLASS_NO_PURE_DECLS \
	ShadowGame_Source_ShadowGame_ShadowGameHUD_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> SHADOWGAME_API UClass* StaticClass<class AShadowGameHUD>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID ShadowGame_Source_ShadowGame_ShadowGameHUD_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS

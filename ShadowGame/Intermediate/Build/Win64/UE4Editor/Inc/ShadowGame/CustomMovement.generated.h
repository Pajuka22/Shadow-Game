// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef SHADOWGAME_CustomMovement_generated_h
#error "CustomMovement.generated.h already included, missing '#pragma once' in CustomMovement.h"
#endif
#define SHADOWGAME_CustomMovement_generated_h

#define ShadowGame_Source_ShadowGame_CustomMovement_h_15_RPC_WRAPPERS
#define ShadowGame_Source_ShadowGame_CustomMovement_h_15_RPC_WRAPPERS_NO_PURE_DECLS
#define ShadowGame_Source_ShadowGame_CustomMovement_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUCustomMovement(); \
	friend struct Z_Construct_UClass_UCustomMovement_Statics; \
public: \
	DECLARE_CLASS(UCustomMovement, UPawnMovementComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/ShadowGame"), NO_API) \
	DECLARE_SERIALIZER(UCustomMovement)


#define ShadowGame_Source_ShadowGame_CustomMovement_h_15_INCLASS \
private: \
	static void StaticRegisterNativesUCustomMovement(); \
	friend struct Z_Construct_UClass_UCustomMovement_Statics; \
public: \
	DECLARE_CLASS(UCustomMovement, UPawnMovementComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/ShadowGame"), NO_API) \
	DECLARE_SERIALIZER(UCustomMovement)


#define ShadowGame_Source_ShadowGame_CustomMovement_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UCustomMovement(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UCustomMovement) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UCustomMovement); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UCustomMovement); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UCustomMovement(UCustomMovement&&); \
	NO_API UCustomMovement(const UCustomMovement&); \
public:


#define ShadowGame_Source_ShadowGame_CustomMovement_h_15_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UCustomMovement(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UCustomMovement(UCustomMovement&&); \
	NO_API UCustomMovement(const UCustomMovement&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UCustomMovement); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UCustomMovement); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UCustomMovement)


#define ShadowGame_Source_ShadowGame_CustomMovement_h_15_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__WalkSpeed() { return STRUCT_OFFSET(UCustomMovement, WalkSpeed); } \
	FORCEINLINE static uint32 __PPO__RunSpeed() { return STRUCT_OFFSET(UCustomMovement, RunSpeed); } \
	FORCEINLINE static uint32 __PPO__maxAngle() { return STRUCT_OFFSET(UCustomMovement, maxAngle); }


#define ShadowGame_Source_ShadowGame_CustomMovement_h_12_PROLOG
#define ShadowGame_Source_ShadowGame_CustomMovement_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ShadowGame_Source_ShadowGame_CustomMovement_h_15_PRIVATE_PROPERTY_OFFSET \
	ShadowGame_Source_ShadowGame_CustomMovement_h_15_RPC_WRAPPERS \
	ShadowGame_Source_ShadowGame_CustomMovement_h_15_INCLASS \
	ShadowGame_Source_ShadowGame_CustomMovement_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define ShadowGame_Source_ShadowGame_CustomMovement_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ShadowGame_Source_ShadowGame_CustomMovement_h_15_PRIVATE_PROPERTY_OFFSET \
	ShadowGame_Source_ShadowGame_CustomMovement_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	ShadowGame_Source_ShadowGame_CustomMovement_h_15_INCLASS_NO_PURE_DECLS \
	ShadowGame_Source_ShadowGame_CustomMovement_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> SHADOWGAME_API UClass* StaticClass<class UCustomMovement>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID ShadowGame_Source_ShadowGame_CustomMovement_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS

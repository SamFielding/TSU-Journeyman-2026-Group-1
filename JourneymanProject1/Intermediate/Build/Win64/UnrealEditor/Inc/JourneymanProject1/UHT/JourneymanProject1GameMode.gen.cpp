// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "JourneymanProject1/JourneymanProject1GameMode.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeJourneymanProject1GameMode() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
JOURNEYMANPROJECT1_API UClass* Z_Construct_UClass_AJourneymanProject1GameMode();
JOURNEYMANPROJECT1_API UClass* Z_Construct_UClass_AJourneymanProject1GameMode_NoRegister();
UPackage* Z_Construct_UPackage__Script_JourneymanProject1();
// End Cross Module References

// Begin Class AJourneymanProject1GameMode
void AJourneymanProject1GameMode::StaticRegisterNativesAJourneymanProject1GameMode()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AJourneymanProject1GameMode);
UClass* Z_Construct_UClass_AJourneymanProject1GameMode_NoRegister()
{
	return AJourneymanProject1GameMode::StaticClass();
}
struct Z_Construct_UClass_AJourneymanProject1GameMode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "JourneymanProject1GameMode.h" },
		{ "ModuleRelativePath", "JourneymanProject1GameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AJourneymanProject1GameMode>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_AJourneymanProject1GameMode_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AGameModeBase,
	(UObject* (*)())Z_Construct_UPackage__Script_JourneymanProject1,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AJourneymanProject1GameMode_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AJourneymanProject1GameMode_Statics::ClassParams = {
	&AJourneymanProject1GameMode::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x008802ACu,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AJourneymanProject1GameMode_Statics::Class_MetaDataParams), Z_Construct_UClass_AJourneymanProject1GameMode_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AJourneymanProject1GameMode()
{
	if (!Z_Registration_Info_UClass_AJourneymanProject1GameMode.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AJourneymanProject1GameMode.OuterSingleton, Z_Construct_UClass_AJourneymanProject1GameMode_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AJourneymanProject1GameMode.OuterSingleton;
}
template<> JOURNEYMANPROJECT1_API UClass* StaticClass<AJourneymanProject1GameMode>()
{
	return AJourneymanProject1GameMode::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AJourneymanProject1GameMode);
AJourneymanProject1GameMode::~AJourneymanProject1GameMode() {}
// End Class AJourneymanProject1GameMode

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_e4086040_Documents_GitHub_TSU_Journeyman_2026_Group_1_JourneymanProject1_Source_JourneymanProject1_JourneymanProject1GameMode_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AJourneymanProject1GameMode, AJourneymanProject1GameMode::StaticClass, TEXT("AJourneymanProject1GameMode"), &Z_Registration_Info_UClass_AJourneymanProject1GameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AJourneymanProject1GameMode), 249259597U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_e4086040_Documents_GitHub_TSU_Journeyman_2026_Group_1_JourneymanProject1_Source_JourneymanProject1_JourneymanProject1GameMode_h_2990934456(TEXT("/Script/JourneymanProject1"),
	Z_CompiledInDeferFile_FID_Users_e4086040_Documents_GitHub_TSU_Journeyman_2026_Group_1_JourneymanProject1_Source_JourneymanProject1_JourneymanProject1GameMode_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_e4086040_Documents_GitHub_TSU_Journeyman_2026_Group_1_JourneymanProject1_Source_JourneymanProject1_JourneymanProject1GameMode_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS

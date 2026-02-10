// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class JourneymanProject1 : ModuleRules
{
	public JourneymanProject1(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}

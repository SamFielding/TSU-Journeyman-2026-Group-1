using UnrealBuildTool;

public class LockOnCamera : ModuleRules
{
    public LockOnCamera(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicIncludePaths.AddRange(
            new string[] {
            });

        PrivateIncludePaths.AddRange(
            new string[] {
            });

        PublicDependencyModuleNames.AddRange(
            new string[]
            {
                "Core",
                "CoreUObject",
                "Engine"
            });

        PrivateDependencyModuleNames.AddRange(
            new string[]
            {
                "Slate",
                "SlateCore",
            });

        DynamicallyLoadedModuleNames.AddRange(
            new string[]
            {
            });
    }
}

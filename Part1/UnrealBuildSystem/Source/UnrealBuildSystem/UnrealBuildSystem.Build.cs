using UnrealBuildTool;

public class UnrealBuildSystem : ModuleRules
{
    public UnrealBuildSystem(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        // CommonUtility플러그인 추가
        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "CommonUtility" });

        PrivateDependencyModuleNames.AddRange(new string[] { });
    }
}
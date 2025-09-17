using UnrealBuildTool;

public class MyVRProject : ModuleRules
{
    public MyVRProject(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        PublicDependencyModuleNames.AddRange(new string[] {
            "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "EnhancedInput"
        });
    }
}

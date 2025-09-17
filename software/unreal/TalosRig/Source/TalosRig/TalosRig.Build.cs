using UnrealBuildTool;

public class TalosRig : ModuleRules
{
    public TalosRig(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] {
            "Core", "CoreUObject", "Engine", "InputCore", "Sockets", "Networking", "Json", "JsonUtilities"
        });
    }
}

using UnrealBuildTool;
using System.Collections.Generic;

public class MyVRProjectTarget : TargetRules
{
    public MyVRProjectTarget(TargetInfo Target) : base(Target)
    {
        Type = TargetType.Game;
        DefaultBuildSettings = BuildSettingsVersion.V5;
        ExtraModuleNames.Add("MyVRProject");
    }
}

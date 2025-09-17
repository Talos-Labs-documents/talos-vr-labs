using UnrealBuildTool;
using System.Collections.Generic;

public class MyVRProjectEditorTarget : TargetRules
{
    public MyVRProjectEditorTarget(TargetInfo Target) : base(Target)
    {
        Type = TargetType.Editor;
        DefaultBuildSettings = BuildSettingsVersion.V5;
        ExtraModuleNames.Add("MyVRProject");
    }
}

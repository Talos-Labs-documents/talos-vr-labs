using UnityEditor;
using UnityEngine;
#if USING_URP
using UnityEngine.Rendering.Universal;
using UnityEngine.Rendering;
#endif

public static class TalosUrpSetup
{
    [MenuItem("Tools/TALOS/Setup URP (Quest Preset)")]
    public static void SetupUrp()
    {
#if !USING_URP
        if (!EditorUtility.DisplayDialog("URP not detected",
            "Install 'Universal RP' via Package Manager first. After it compiles, define 'USING_URP' in Project Settings → Player → Scripting Define Symbols (or just re-run if auto added).",
            "OK")) return;
#else
        // Ensure settings folder
        string settingsFolder = "Assets/Settings";
        if (!AssetDatabase.IsValidFolder(settingsFolder))
            AssetDatabase.CreateFolder("Assets", "Settings");

        // Create URP asset
        var rp = ScriptableObject.CreateInstance<UniversalRenderPipelineAsset>();
        rp.name = "TalosURP_RenderPipeline";
        // Quest-friendly defaults
        rp.msaaSampleCount = MsaaQuality._2x;
        rp.renderScale = 0.9f;
        rp.supportsHDR = false;

        AssetDatabase.CreateAsset(rp, settingsFolder + "/TalosURP_RenderPipeline.asset");
        AssetDatabase.SaveAssets();

        // Assign in Graphics/Quality
        GraphicsSettings.renderPipelineAsset = rp;
        QualitySettings.renderPipeline = rp;
        QualitySettings.antiAliasing = 2;

        EditorUtility.DisplayDialog("TALOS URP", "URP asset created and assigned.
MSAA x2, render scale 0.9, HDR off.", "OK");
#endif
    }
}

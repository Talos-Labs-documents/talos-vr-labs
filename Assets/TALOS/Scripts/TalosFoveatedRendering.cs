using UnityEngine;
using UnityEngine.XR;

public class TalosFoveatedRendering : MonoBehaviour
{
    public int level = 2; // 0: Off, 1: Low, 2: Medium, 3: High, 4: VeryHigh (if supported)

    void Start()
    {
        try
        {
            // Not all runtimes support XRSettings.foveatedRenderingLevel; call guarded.
#if UNITY_2021_3_OR_NEWER
            var t = typeof(XRSettings);
            var prop = t.GetProperty("foveatedRenderingLevel");
            if (prop != null && prop.CanWrite)
            {
                int clamped = Mathf.Clamp(level, 0, 4);
                prop.SetValue(null, clamped, null);
                Debug.Log($"[TALOS] Requested FFR level: {clamped}");
            }
            else
            {
                Debug.Log("[TALOS] FFR property not available on this runtime.");
            }
#else
            Debug.Log("[TALOS] FFR requires newer Unity.");
#endif
        }
        catch { }
    }
}

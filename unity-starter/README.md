# Unity VR Starter

Baseline setup targeting **Unity 2022 LTS+** with **OpenXR** and **XR Interaction Toolkit**.

## Quick Start
1. Install Unity 2022 LTS (or newer) with Android + Windows build modules.
2. Open this folder in Unity Hub as a project.
3. In Package Manager:
   - Add **OpenXR Plugin** (com.unity.xr.openxr)
   - Add **XR Interaction Toolkit** (com.unity.xr.interaction.toolkit)
4. Enable **XR Plug‑in Management** → **OpenXR** for target platforms.
5. Play the sample scene once you've added it under `Assets/Scenes/`.

## Notes
- Use **Action‑based** controllers.
- Test both **Room‑scale** and **Seated** configurations.
- For Quest: set Graphics API to Vulkan, texture compression ASTC.

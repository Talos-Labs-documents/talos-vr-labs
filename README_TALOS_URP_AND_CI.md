# TALOS Unity URP Preset + Android CI

This package gives you:
1) **URP one-click setup** (creates/assigns a URP asset, MSAA x2, render scale 0.9).  
2) **Runtime Fixed Foveated Rendering** toggle (if the runtime supports it).  
3) **GitHub Actions** workflow to build Android (Quest) using **game-ci/unity-builder**.

## Use

### URP
- Copy `Assets/TALOS` into your Unity project.
- Install the **Universal RP** package from Package Manager.
- Menu: **Tools → TALOS → Setup URP (Quest Preset)**  
  → Creates `Assets/Settings/TalosURP_RenderPipeline.asset` and assigns it in Graphics/Quality.

### FFR (optional)
- Add the `TalosFoveatedRendering` component to any bootstrap GameObject.  
  It will try to set a FFR level at runtime (ignored if unsupported).

### CI (Android build)
- Copy `.github/workflows/unity-android.yml` to your repo root.
- In GitHub repo **Settings → Secrets and variables → Actions**, add:
  - `UNITY_LICENSE` → paste your **ULF** (Unity free/personal activation file).  
- Optionally set variables at top of the workflow: `UNITY_VERSION` (e.g., `2022.3.40f1`).

Trigger the workflow via **Actions → Run workflow**, or on push to `main` touching `unity-starter/**`.

# TALOS VR Labs — Unity + Unreal (Quest & PCVR)

**One repo, two engines.** This project contains production-ready starters for **Unity (OpenXR + XR Interaction Toolkit)** and **Unreal Engine 5 (OpenXR)**, optimized for **Quest (Android)** and **PCVR/SteamVR (Windows)**. It ships with Git LFS, CI stubs, contributor hygiene, and a one‑click Unity scene builder.

> If you’re here to build *now*: follow **Quick Start**. If you’re contributing, see **Contributing**.

---

## Table of Contents
- [Repo Layout](#repo-layout)
- [Quick Start](#quick-start)
  - [A. Unity — Quest (Android)](#a-unity--quest-android)
  - [B. Unity — PCVR (Windows)](#b-unity--pcvr-windows)
  - [C. Unreal — PCVR/Quest Link](#c-unreal--pcvrquest-link)
  - [D. Unreal — Quest (Android)](#d-unreal--quest-android)
- [CI / Builds](#ci--builds)
- [Branching & Releases](#branching--releases)
- [Git LFS](#git-lfs)
- [Contributing](#contributing)
- [License](#license)

---

## Repo Layout
```
/
├─ unity-starter/                  # Unity project root (OpenXR + XRI)
│  └─ Assets/TALOS                 # One‑shot scene builder, URP setup, FFR helper
├─ unreal-starter/                 # UE5 project scaffold (OpenXR)
│  ├─ MyVRProject.uproject
│  └─ Source/MyVRProject           # Module + targets
├─ .github/workflows/              # CI (Unity Android build via game-ci)
├─ .gitattributes                  # Git LFS rules for assets
├─ .gitignore                      # Global ignores
├─ LICENSE                         # MIT
└─ CONTRIBUTING.md                 # Workflow & guidelines
```

---

## Quick Start

### Prereqs
- **Git + Git LFS** installed.
- **Unity 2022/2023 LTS** *or* **Unreal Engine 5.3+**.
- **Quest 3/Pro** (for Android builds) or a **PCVR** runtime.

> Windows tip: `git config core.longpaths true`

### Clone & bootstrap
```bash
git clone https://github.com/Talos-Labs-documents/talos-vr-labs.git
cd talos-vr-labs
git lfs install
```

---

### A. Unity — Quest (Android)
1. Open **`unity-starter/`** in Unity Hub (2022/2023 LTS).
2. **Install packages** (Package Manager):
   - OpenXR Plugin
   - XR Interaction Toolkit (XRI)
   - XR Plugin Management
   - (Optional) Universal RP (URP)
3. **Project Settings → XR Plug-in Management**: enable **OpenXR** for **Android** and **Windows**.
4. *(Optional)* **URP setup**: **Tools → TALOS → Setup URP (Quest Preset)** (MSAA x2, render scale 0.9).
5. **Create sample scene**: **Tools → TALOS → Create Sample VR Scene** → `Assets/Scenes/SampleVR.unity`.
6. **Android Player Settings**:
   - Graphics API: **Vulkan**; Texture Compression: **ASTC**; Target Architectures: **ARM64**
   - Min API Level: **Android 12 (31)** or newer
7. **Build & Run** to Quest (Developer Mode + USB).

### B. Unity — PCVR (Windows)
- Keep **OpenXR** enabled for Windows.
- Use the same sample scene; run in Editor or build Windows x64.

---

### C. Unreal — PCVR/Quest Link
1. Open **`unreal-starter/MyVRProject.uproject`** in **UE5.3+**.
2. Enable plugins: **OpenXR**, **XR Visualization**.
3. Use the VR template or add a pawn + controller bindings.
4. Play in-editor or with **Quest Link** for fast iteration.

### D. Unreal — Quest (Android)
- Install Android SDK/NDK per UE docs.
- Package for Android with **OpenXR Mobile** features enabled.

---

## CI / Builds

### Unity Android (Quest) via GitHub Actions
The repo includes `.github/workflows/unity-android.yml` using **game-ci/unity-builder**.

**Setup:**
1. In GitHub: **Settings → Secrets and variables → Actions** → add:
   - `UNITY_LICENSE` → paste your ULF (Personal/Free manual activation file).
2. Optional: edit at top of workflow:
   - `UNITY_VERSION` (e.g., `2022.3.40f1`)
   - `PROJECT_PATH: unity-starter`

**Trigger:**
- Push to `main` touching `unity-starter/**`, or run manually via **Actions**.  
- Artifact: APK attached to the run (`TALOSVR-Android-APK`).

> Unreal CI typically needs a **self‑hosted Windows runner** with UE installed; keep the included stub until you’re ready.

---

## Branching & Releases
- Default: `main` (protected), active dev: `dev`
- Feature branches: `feat/<name>`, fixes: `fix/<name>`
- **Conventional Commits** (`feat:`, `fix:`, `docs:`, `chore:` …)
- Tag releases: `v0.1.0`, `v0.1.1`…

---

## Git LFS
Large binary assets are tracked via `.gitattributes`:
```
*.fbx, *.obj, *.png, *.jpg, *.tga, *.wav, *.mp3, *.ogg, *.mp4, *.mov, *.uasset, *.umap
```
If you add new binary types, also add them to `.gitattributes` and run:
```bash
git lfs track "*.ext"
git add .gitattributes
git commit -m "chore(lfs): track *.ext"
```

---

## Contributing
See **CONTRIBUTING.md**. TL;DR:
- Open an issue first for large changes.
- Keep PRs small & focused.
- Include device targets in your PR description (Quest/PCVR).
- Don’t commit giant binaries without LFS.

---

## License
MIT — see `LICENSE`.

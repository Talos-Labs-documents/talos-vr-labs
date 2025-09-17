# VR Project Starter (Unity & Unreal)

This repository is a clean, batteries‑included starter for a VR project. It includes:
- **Unity** and **Unreal Engine** starter layouts (pick one and delete the other).
- Ready‑to‑use `.gitignore` files.
- **Git LFS** configuration for large binary assets.
- Suggested **GitHub Actions** CI stubs.
- Project hygiene: `LICENSE`, `CODE_OF_CONDUCT`, `CONTRIBUTING`, issue templates.

## Getting Started

1. **Choose your engine**:
   - `unity-starter/` (Unity 2022+ with OpenXR + XR Interaction Toolkit)
   - `unreal-starter/` (Unreal Engine 5.3+ with OpenXR)

2. **Initialize Git & LFS**
   ```bash
   git init
   git lfs install
   git lfs track "*.fbx" "*.wav" "*.png" "*.jpg" "*.uasset" "*.umap" "*.mp4" "*.mov"
   git add .gitattributes
   ```

3. **Create the GitHub repo** and push:
   ```bash
   gh repo create YOUR_ORG/YOUR_REPO --public --source=. --remote=origin --push
   # or create on github.com then:
   git remote add origin https://github.com/YOUR_ORG/YOUR_REPO.git
   git push -u origin main
   ```

4. **Pick one starter**: move its contents to the root or keep as a subfolder until you’re ready.

## Branching & Releases
- Default branch: `main`
- Active dev branch: `dev`
- Feature branches: `feat/<short-name>`
- Use Conventional Commits: `feat:`, `fix:`, `docs:`, `chore:`, etc.
- Tag releases with SemVer: `v0.1.0`

## Folders
- `.github/workflows/`: CI stubs for Unity/Unreal
- `unity-starter/`: Minimal Unity layout and README
- `unreal-starter/`: Minimal Unreal layout and README

---

> Tip: After cloning on Windows, enable long paths: `git config core.longpaths true`.

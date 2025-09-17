# Contributing to TALOS VR Labs

Thanks for helping push open VR forward.

## Workflow
- Work off `dev`. Use feature branches (`feat/<name>`).
- Open an issue describing your change.
- Use **Conventional Commits** in messages.
- Keep PRs small; include test/notes for target device(s).

## Code/Asset Guidelines
- Prefer **OpenXR** features for cross‑vendor compatibility.
- Use **Git LFS** for large binaries; include source files when possible.
- Unity: follow folder layout under `Assets/` (`Scenes`, `Scripts`, `Materials`, `Prefabs`).  
- Unreal: keep modules minimal; avoid committing Derived Data.

## PR Checklist
- [ ] Builds on Quest or PCVR as applicable
- [ ] No large files without LFS
- [ ] Updated README/docs as needed

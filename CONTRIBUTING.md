# Contributing

Thanks for considering a contribution!

## Workflow
1. Create an issue describing the change.
2. Create a branch: `feat/short-name` or `fix/short-name`.
3. Use **Conventional Commits** in messages (e.g., `feat: add teleport locomotion`).
4. Open a PR targeting `dev`. The repo maintainer will merge to `main` on release.

## Coding/Asset Guidelines
- Prefer **OpenXR** and cross‑vendor SDKs.
- Keep binary assets out of Git history; use **Git LFS**.
- Include source files for generated assets when possible.
- Document platform requirements (Quest/PCVR/SteamVR) in the README.

## Commit Types
- `feat:` new feature
- `fix:` bug fix
- `perf:` performance improvement
- `refactor:` code changes without behavior change
- `docs:` documentation
- `test:` tests
- `chore:` tooling/infra

## PR Checklist
- [ ] Tested on target(s): Quest, PCVR, SteamVR
- [ ] No large files without LFS
- [ ] README updated
- [ ] CI green (if enabled)

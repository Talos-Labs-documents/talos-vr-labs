# TALOS VR Rig — Full Stack (Software + Hardware)

This repo is a **one-stop kit**: code + firmware + hardware + docs to build a rotation-capable VR rig with a **motor safety governor** and a **real-time bridge** to Unreal/Unity.

---

## 🚀 Quickstart

**Clone**
```bash
git clone https://github.com/<you>/talos-vr-rig.git
cd talos-vr-rig
```

**Setup**
- Windows: `orchestration/scripts/setup_windows.ps1`
- macOS/Linux: `orchestration/scripts/setup_unix.sh`

**Launch Unreal**
```bash
"<UE_Editor_Path>/UnrealEditor" ./software/unreal/TalosRig/TalosRig.uproject
```

**Start Bridge**
```bash
docker compose -f orchestration/docker/compose.yml up
```

**Play** in Unreal → live motor telemetry + safety limits enforced.

---

## 📂 Repo Structure

```
software/        # Unreal + Unity projects + bridge
firmware/        # Motor controller (Arduino/STM32)
hardware/        # CAD, schematics, BOM, safety docs
orchestration/   # Docker + setup scripts
docs/            # MkDocs documentation site
.github/         # CI/CD workflows
```

---

## 🛡 Safety

- Physical **E-stop** switch (required).
- **MCU watchdog** → motor stops if no new command within 300ms.
- **RPM ceiling** enforced in firmware (default 40 RPM).
- **Seatbelt/harness** spec in `/hardware/safety`.

---

## 📦 BOM (starter)

See [`hardware/bom/bom.csv`](hardware/bom/bom.csv).

---

## 📚 Documentation

- [Build guide](./docs) (autobuilt to GitHub Pages via CI)
- [Firmware notes](./firmware/motor-controller/README.md)
- [Bridge API](./software/bridge/README.md)

---

## 📜 License

- MIT for software  
- CC BY 4.0 for docs/hardware  

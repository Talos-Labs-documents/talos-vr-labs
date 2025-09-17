# TALOS Labs — 6DOF Immersion Starter (MVP)

**Ignition Node: 0 → 1**  
This repository contains the starter kit for building and testing a modular, low-RPM, six-degrees-of-freedom (6DOF) immersion platform.  
It combines **rotational hardware + VR software + safety protocols + reproducible methods**.  
The goal: enable anyone to replicate, log, and contribute to a global open-science experiment.  

---
## ✨ Fibonacci Mode (Natural Camouflage)
Fibonacci Mode layers rotation, visuals, audio, haptics, and timing using the same patterns found in nature
(1, 1, 2, 3, 5, 8… and φ ≈ 1.618). The result is motion and pacing that feel “organic,” so the tech disappears into
the background. This repo ships a default config, demo code, and a **Proof Pack** (hashes + raw logs workflow) so
anyone can verify and reproduce results.

- Natural spin ramps (1–2–3–5–8 s), “Golden windows” at 34/55 RPM, micro-dither ±0.618 RPM.
- Visuals use phyllotaxis (sunflower spiral), golden-spiral overlays, frame gates at 34/55/89 frames.
- Audio/breath patterns on 1-1-2-3-5 and 3-5-8.
- Session blocks at 1/2/3/5/8 minutes.
- **Proof Pack**: SHA-256 hashing + timestamping workflow so results are tamper-evident and easy to replicate.

See `docs/FibonacciMode.md` and `config/fibonacci.yml`.

---

## ⚡ Quickstart

1. **Download release:** [talos-mvp.zip](./releases)  
   - Contains Unity + Unreal demo scenes, wiring diagrams, hardware specs, consent template, and session log CSV.  
2. **Assemble hardware:** follow `HARDWARE.md` (low-RPM motor, top clutch, emergency stop wiring).  
3. **Run demo:** open prefab scene in Unity or Unreal → sync with motor controller → test spin (max 2 min first run).  
4. **Log session:** use `session_log.csv` template, record baseline + exposure + post metrics.  
5. **Submit replication:** SHA256 your `session_log.csv` + ZIP, share via pull request or replicator portal.  

---

## 🛡 Safety First

- **Emergency Stop:** Big red E-STOP wired directly to motor controller. Must be tested before every session.  
- **Medical exclusions:** Do **not** participate if you have seizures, vestibular disorders, heart conditions, are pregnant, or have recent head trauma.  
- **Session limits:** Start with **2 min max exposure**. Increase only gradually across sessions if no adverse effects.  
- **Never run solo:** A session buddy must always be present with access to the E-STOP.  
- **Adverse events:** Stop immediately on nausea, dizziness, double vision, chest pain, confusion, or loss of consciousness. Seek medical attention.  

See [`SAFETY.md`](./SAFETY.md) for full checklist + printable consent form.  

---

## 🧪 Methods

We are treating this as **open community science**.  
Follow [`METHODS.md`](./METHODS.md) for a reproducible protocol:  

- **Baseline (pre):** HR, HRV, SpO₂, BP, balance test, subjective mood/perception.  
- **Session (during):** Log RPM, exposure duration, continuous HR/HRV if possible.  
- **Post (after):** Repeat baseline + subjective scales (nausea 0-10, dissociation 0-10, mood, clarity).  
- **Data format:** see `session_log.csv` for column schema.  

Always publish raw logs + SHA256 fingerprint. This preserves provenance and credibility.  

---

## 🤝 Contribute

We welcome **replicators** who follow safety protocols.  
To contribute:  

1. Fork this repo.  
2. Upload your raw session logs (`.csv`) + SHA256 hash.  
3. Include short video (30–90s) of hardware + E-STOP test.  
4. Submit via pull request or contact through the verified replicator channel.  

Replications that meet safety + provenance requirements will be listed as **Verified Builds**.  

---

## 📜 License & Disclaimer

- Licensed under **GPL-3.0** — forks must preserve attribution.  
- This is **experimental hardware**.  
- **Not a medical device. Not FDA approved. Use at your own risk.**  
- Participation requires informed consent.  

---

## 🌍 Contact & Community

- **Verified Replicator Channel (Discord/Telegram):** [link placeholder]  
- **Substack:** [link placeholder]  
- **TikTok / Twitter:** [link placeholder]  

If you build, log, or fork this project — please cite **TALOS Labs — 6DOF Immersion Starter (MVP)**.  
This is how we go **Civilization 0 → 1** together.  


# Unreal: TalosRig

## Build
1. Open `TalosRig.uproject` in UE5 (tested 5.3+).
2. When prompted, generate project files and build.
3. Place an **ATalosOscListener** actor in your level.
4. Hit **Play**. You should see on-screen RPM/Angle readouts when the bridge is running.

## Notes
- Listens on UDP port **9000** (configurable via the actor property).
- Expects JSON packets from the Python bridge:
  ```json
  {"address":"/talos/telemetry","args":{"rpm":12.3,"angle":45.0,"fault":false}}
  ```
- Use a UMG slider or keyboard input to write to the bridge's STDIN (e.g., `{"rpm": 20}`). A sample UI script is planned.

# Talos Bridge (OSC/UDP + Serial)

- Listens to MCU telemetry on Serial.
- Forwards telemetry as UDP JSON to Unreal at `127.0.0.1:9000`.
- Accepts control JSON via STDIN (e.g., `{"rpm": 20}`) and sends to MCU.

Env vars (via `orchestration/docker/.env`):
- `OSC_PORT` (default 9000)
- `SERIAL_PORT` (e.g., `/dev/ttyACM0` or `COM3`)
- `BAUD` (115200)
- `MAX_RPM` (40)

#!/usr/bin/env bash
set -euo pipefail

python3 -m venv .venv
source .venv/bin/activate
pip install -r software/bridge/requirements.txt

cat > orchestration/docker/.env <<EOF
OSC_PORT=9000
SERIAL_PORT=/dev/ttyACM0
BAUD=115200
MAX_RPM=40
EOF

echo "✔ Setup complete. Next: docker compose -f orchestration/docker/compose.yml up"

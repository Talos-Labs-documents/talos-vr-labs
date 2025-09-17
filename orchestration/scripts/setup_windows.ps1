$ErrorActionPreference = "Stop"

py -3 -m venv .venv
. .\.venv\Scripts\Activate.ps1
pip install -r software\bridge\requirements.txt

@"
OSC_PORT=9000
SERIAL_PORT=COM3
BAUD=115200
MAX_RPM=40
"@ | Out-File -Encoding ascii orchestration\docker\.env

Write-Host "✔ Setup complete. Next: docker compose -f orchestration\docker\compose.yml up"

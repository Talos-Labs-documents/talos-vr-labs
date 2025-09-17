#!/usr/bin/env bash
# Usage: scripts/publish_hash.sh <path-to-raw-folder>

set -euo pipefail

RAW_DIR="${1:-}"
if [[ -z "$RAW_DIR" || ! -d "$RAW_DIR" ]]; then
  echo "ERROR: Provide a valid RAW directory (got: '$RAW_DIR')."
  exit 1
fi

OUT_DIR="$(dirname "$RAW_DIR")"
RUN_NAME="$(basename "$(dirname "$RAW_DIR")")"
STAMP_FILE="$OUT_DIR/TIMESTAMP.txt"
HASH_FILE="$OUT_DIR/HASHES.txt"
BUNDLE="$OUT_DIR/${RUN_NAME}.zip"
BUNDLE_HASH="$OUT_DIR/BUNDLE_SHA256.txt"

echo "# TIMESTAMP (UTC) & GIT COMMIT" > "$STAMP_FILE"
date -u +"%Y-%m-%dT%H:%M:%SZ" >> "$STAMP_FILE"
git rev-parse --short HEAD 2>/dev/null || echo "no-git" >> "$STAMP_FILE"

# Per-file SHA-256
echo "# SHA256 hashes per file" > "$HASH_FILE"
find "$RAW_DIR" -type f | sort | while read -r f; do
  sha256sum "$f" | awk '{print $1 "  " $2}'
done >> "$HASH_FILE"

# Bundle zip
rm -f "$BUNDLE"
( cd "$OUT_DIR" && zip -r "$(basename "$BUNDLE")" "$(basename "$RAW_DIR")" >/dev/null )
sha256sum "$BUNDLE" | awk '{print $1}' > "$BUNDLE_HASH"

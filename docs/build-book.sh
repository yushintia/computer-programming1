#!/usr/bin/env bash
# build-book.sh — Build the lab manual as web (book/) and PDF (docs/lab-manual.pdf)
# Usage: bash docs/build-book.sh
#        Run from the repo root (the directory that contains book.toml)
set -euo pipefail

REPO_ROOT="$(cd "$(dirname "$0")/.." && pwd)"
cd "$REPO_ROOT"

echo "==> Building mdBook (web)..."
mdbook build

echo "==> Generating PDF from book/print.html..."
chromium \
  --headless \
  --no-sandbox \
  --disable-gpu \
  --run-all-compositor-stages-before-draw \
  --print-to-pdf="$REPO_ROOT/docs/lab-manual.pdf" \
  --no-pdf-header-footer \
  --print-to-pdf-no-header \
  "$REPO_ROOT/book/print.html"

echo ""
echo "Done."
echo "  Web  → book/index.html"
echo "  PDF  → docs/lab-manual.pdf"

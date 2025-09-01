#!/usr/bin/env bash
set -euo pipefail
/usr/bin/time -f "\nWall: %E\nCPU: %P\nMem: %M KB" ./build/trace -layout $1 -rule $2 -output $3

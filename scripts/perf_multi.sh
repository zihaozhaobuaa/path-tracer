#!/usr/bin/env bash
set -euo pipefail
THREADS=${THREADS:-8}
/usr/bin/time -f "\nWall: %E\nCPU: %P\nMem: %M KB" ./build/trace -layout $1 -rule $2 -thread ${THREADS} -output $3

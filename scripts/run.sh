#!/usr/bin/env bash
set -euo pipefail
./build/trace -layout data/sample_layout.txt -rule data/sample_rule_1.txt -output out.txt
echo "Output written to out.txt"

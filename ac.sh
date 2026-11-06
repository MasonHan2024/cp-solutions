#!/bin/bash
# usage: ./ac.sh 2276A "key idea in one line"
# Run after submitting on Codeforces: fetches the verdict, files the code, updates README, pushes.
cd "$(dirname "$0")" && python3 tools/cf_log.py "$@"

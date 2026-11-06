#!/bin/bash
# usage: ./run.sh A   -> compiles A.cpp, runs it with input from A.in (if it exists)
set -e
p="$1"
g++ -std=c++20 -O2 -Wall -Wextra -Wshadow -fsanitize=address,undefined -g "$p.cpp" -o "$p"
if [ -f "$p.in" ]; then ./"$p" < "$p.in"; else ./"$p"; fi

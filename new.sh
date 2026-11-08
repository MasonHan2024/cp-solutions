#!/bin/bash
# usage: ./new.sh A   -> creates A.cpp from template.cpp and an empty A.in
# Always works in the cp folder (where this script lives), wherever you run it from.
cd "$(dirname "$(readlink -f "$0")")" || exit 1
if [ -z "$1" ]; then echo "usage: ./new.sh <problem>   e.g. ./new.sh 2275C"; exit 1; fi
if [ -e "$1.cpp" ]; then echo "$1.cpp already exists in $PWD"; exit 1; fi
cp template.cpp "$1.cpp"
touch "$1.in"
echo "created $PWD/$1.cpp and $1.in"

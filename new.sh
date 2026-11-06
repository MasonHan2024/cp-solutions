#!/bin/bash
# usage: ./new.sh A   -> creates A.cpp from template.cpp and an empty A.in
if [ -e "$1.cpp" ]; then echo "$1.cpp already exists"; exit 1; fi
cp template.cpp "$1.cpp"
touch "$1.in"
echo "created $1.cpp and $1.in"

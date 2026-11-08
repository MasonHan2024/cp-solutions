#!/bin/bash
# usage: scratch            -> new ~/code/scratch/<date-time>.cpp
#        scratch constexpr  -> new ~/code/scratch/constexpr.cpp (or opens it if it exists)
#        scratch notes.md   -> name with an extension = plain empty file (notes, txt, etc.)
# Not for Codeforces (use ./new.sh for that). Files live outside the cp repo.
dir="$HOME/code/scratch"
mkdir -p "$dir"

name="${1:-$(date +%Y-%m-%d_%H%M%S)}"
[[ "$name" == *.* ]] || name="$name.cpp"
file="$dir/$name"

if [ -e "$file" ]; then
    echo "opening existing $file"
elif [[ "$name" == *.cpp ]]; then
    cat > "$file" <<'EOF'
#include <iostream>

int main()
{


    return 0;
}
EOF
    echo "created $file"
else
    touch "$file"
    echo "created $file"
fi

if command -v code >/dev/null; then code "$file"; fi

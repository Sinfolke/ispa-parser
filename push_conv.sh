#!/bin/bash

file="./.vscode/counter"

if [[ -f "$file" ]]; then
  value=$(<"$file")
fi

value=${value:-0}

value=$((value + 1))



./push.sh "Progress of converting parser rules to C++ [$value]"
echo "$value" > "$file"
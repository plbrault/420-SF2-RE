#!/bin/bash

# Calculate release filename with conflict resolution and sanitization
# Usage: get_release_name <markdown_file_path> <basename_count_array_name>
get_release_name() {
  local f="$1"
  local -n counts="$2"
  local base=$(basename "$f" .md)
  local release_base
  
  if [ "${counts[$base]}" -gt 1 ]; then
    release_base="${f%.md}"
    release_base="${release_base//\//-}"
  else
    release_base="${base}"
  fi
  
  # Sanitize: replace spaces and problematic characters
  release_base="${release_base// /_}"
  release_base="${release_base//[^a-zA-Z0-9._-]/_}"
  
  echo "$release_base"
}

# Build basename count associative array
# Usage: build_basename_counts <files_string>
build_basename_counts() {
  declare -gA basename_count
  while IFS= read -r f; do
    [ -z "$f" ] && continue
    base=$(basename "$f" .md)
    basename_count["$base"]=$((${basename_count["$base"]:-0} + 1))
  done < <(printf '%s\n' "$1")
}

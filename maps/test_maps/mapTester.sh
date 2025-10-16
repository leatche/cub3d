#!/bin/bash
# Usage: ./testMapFolder.sh <path_to_folder> [timeout_in_seconds] [max_parallel_jobs]
# Example: ./testMapFolder.sh ./maps 0.3 4

set -u

if [ -z "${1-}" ]; then
    echo "Usage: $0 <path_to_folder> [timeout_in_seconds] [max_parallel_jobs]"
    exit 1
fi

DIR="$1"
TIMEOUT="${2:-0.2}"       # default wait before kill
MAX_JOBS="${3:-8}"        # default concurrency
[ "$MAX_JOBS" -lt 1 ] && MAX_JOBS=1

if [ ! -d "$DIR" ]; then
    echo "Error: '$DIR' is not a valid directory."
    exit 1
fi

TMP_DIR=$(mktemp -d)
found_any=false

# --- Single-file test (logs to per-file files to avoid scrambled output) ---
run_test() {
    local file="$1"
    local base="$(basename "$file")"
    local logfile="$TMP_DIR/$base.log"
    local statusfile="$TMP_DIR/$base.status"

    {
        echo "🚀 Testing $base"

        # Start cub3d in background (quiet), give it time to start, then check
        ../../cub3d "$file" > /dev/null 2>&1 &
        local pid=$!

        sleep "$TIMEOUT"

        if ps -p "$pid" > /dev/null 2>&1; then
            # It started -> kill and mark success
            kill "$pid" > /dev/null 2>&1
            echo "   | (No visible error output)"
            echo "✅ $base: Started successfully."
            echo "SUCCESS" > "$statusfile"
        else
            # It exited quickly -> run again to capture the error output
            echo "   | Output:"
            ../../cub3d "$file" 2>&1 | sed 's/^/   | /'
            echo "❌ $base: Failed to start or crashed."
            echo "FAIL" > "$statusfile"
        fi

        echo
    } &> "$logfile"
}

# --- Concurrency limiter ---
run_with_limit() {
    local file="$1"
    while (( $(jobs -r | wc -l) >= MAX_JOBS )); do
        sleep 0.1
    done
    run_test "$file" &
}

# --- Launch all tests (async, limited) ---
for file in "$DIR"/*.cub; do
    if [ ! -e "$file" ]; then
        continue
    fi
    found_any=true
    run_with_limit "$file"
done

# If no files, exit early
if [ "$found_any" = false ]; then
    echo "⚠️  No .cub files found in $DIR."
    rm -rf "$TMP_DIR"
    exit 0
fi

# Wait for all background jobs
wait

# --- Print results grouped: successes first, then failures ---
success_count=0
fail_count=0

# Successes
for file in "$DIR"/*.cub; do
    [ ! -e "$file" ] && continue
    base="$(basename "$file")"
    statusfile="$TMP_DIR/$base.status"
    logfile="$TMP_DIR/$base.log"
    if [ -f "$statusfile" ] && [ "$(cat "$statusfile")" = "SUCCESS" ]; then
        cat "$logfile"
        success_count=$((success_count + 1))
    fi
done

# Failures
for file in "$DIR"/*.cub; do
    [ ! -e "$file" ] && continue
    base="$(basename "$file")"
    statusfile="$TMP_DIR/$base.status"
    logfile="$TMP_DIR/$base.log"
    if [ -f "$statusfile" ] && [ "$(cat "$statusfile")" = "FAIL" ]; then
        cat "$logfile"
        fail_count=$((fail_count + 1))
    fi
done

# Cleanup
rm -rf "$TMP_DIR"

# --- Summary ---
echo "==============================="
echo "📊 Summary:"
echo "   ✅ Successful starts: $success_count"
echo "   ❌ Failed starts: $fail_count"
echo "==============================="

if [ "$fail_count" -eq 0 ]; then
    echo "🎉 All tests passed successfully!"
elif [ "$success_count" -eq 0 ]; then
    echo "💀 All tests failed to start."
else
    echo "⚙️  $success_count configurations ran fine, while $fail_count encountered issues."
fi

#!/usr/bin/env bash
set -e

CXXFLAGS="-std=c++17 -Wall -Wextra -g"
LDFLAGS=""
OUTDIR="build"
OUTBIN="$OUTDIR/main"

SRCS=(main.cpp console.cpp data_loader.cpp party.cpp)

mkdir -p "$OUTDIR"

echo "Compiling: ${SRCS[*]}"
g++ $CXXFLAGS "${SRCS[@]}" -o "$OUTBIN" $LDFLAGS

echo "Build successful: $OUTBIN"

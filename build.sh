#!/usr/bin/env bash

usage() {
  echo "USAGE: $0 [ debug | test | clean ]"
  exit 1
}

parse_args() {
  if [[ $1 == "debug" ]]; then
    DEBUG=1
    BUILD_TYPE="Debug"
  elif [[ $1 == "test" ]]; then
    TEST=1
  elif [[ $1 == "clean" ]]; then
    clean_build
    exit 0
  else
    usage
  fi
}

clean_build() {
  rm -rf build
  rm -rf 1_Data_Structures/bin
  # Add more directories as needed
}

compile_project() {
  mkdir -p build
  cd build
  set -e # Allows CI/CD pipeline to report error
  cmake .. -DCMAKE_BUILD_TYPE=${BUILD_TYPE}
  make -j$(nproc)
  (( TEST )) && ctest --output-on-failure
  cd ..
}

# Args
DEBUG=0
TEST=0
CLEAN=0
BUILD_TYPE="Release"

# Arg parser
[ $# -ne 0 ] && parse_args $1

# Compile according to arg flags
compile_project

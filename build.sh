#!/bin/bash

PROJECT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
BUILD_DIR="${PROJECT_DIR}/build"
EXECUTABLE="${BUILD_DIR}/derelict_land.exe" 

if ! command -v cmake &> /dev/null
then
    echo "cmake could not be found. Please install it."
    exit 1
fi

if [ ! -d "${BUILD_DIR}" ]; then
  echo "Creating build directory: ${BUILD_DIR}"
  mkdir -p "${BUILD_DIR}"
fi

echo "Changing directory to: ${BUILD_DIR}"
cd "${BUILD_DIR}"

echo "Running cmake .."
cmake ..
if [ $? -ne 0 ]; then
  echo "Error: cmake configuration failed."
  exit 1
fi

echo "Building the project..."
cmake --build .
if [ $? -ne 0 ]; then
  echo "Error: Project build failed."
  exit 1
fi

if [ -f "${EXECUTABLE}" ]; then
  echo "Build successful. Executable: ${EXECUTABLE}"
  echo "Do you want to run the executable? (y/n)"
  read -r run_executable
  if [[ "$run_executable" =~ ^([yY][eE][sS]|[yY])$ ]]; then
    echo "Running the executable..."
    "${EXECUTABLE}"
    if [ $? -ne 0 ]; then
        echo "Error: Executable failed to run."
        exit 1
    fi
  fi
else
  echo "Error: Executable not found at ${EXECUTABLE}. Build may have failed."
  exit 1
fi

echo "Build process completed."
exit 0
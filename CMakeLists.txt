cmake_minimum_required(VERSION 3.10)

# Project name and version
project(TreeMap VERSION 1.0)

# C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories
include_directories(include)

# Gather source files
file(GLOB_RECURSE SRC_FILES src/*.cpp)
# file(GLOB_RECURSE LIB_FILES lib/*.cpp)

# Create executable (or library if needed)
add_executable(${PROJECT_NAME} ./src/main.c)

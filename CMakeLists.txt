cmake_minimum_required(VERSION 3.28)

# Project name and version
project(TreeMapApp VERSION 1.0)

# C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories
include_directories(include)

# Gather source files
file(GLOB_RECURSE SRC_FILES src/*.c)
file(GLOB_RECURSE LIB_FILES lib/*.c)

add_library(TreeMap ./src/TreeMap.c)

# Create executable (or library if needed)
add_executable(${PROJECT_NAME} ./src/main.c)

install(TARGETS ${PROJECT_NAME} DESTINATION bin)



include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
  TreeMap_test
  test/TreeMap_test.cc
)

target_include_directories(
  TreeMap_test
  PRIVATE
  include
)

target_link_libraries(
  TreeMap_test
  TreeMap
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(TreeMap_test)
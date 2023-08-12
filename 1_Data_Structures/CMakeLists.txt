cmake_minimum_required(VERSION 3.16)
project(datastructures1 VERSION 0.0.0 LANGUAGES C)

# Specify the C standard if required
set(CMAKE_C_STANDARD 11)

# Include directories
include_directories(${datastructures1_SOURCE_DIR}/include)

# Find or require dependencies (adjust as needed)
# find_package(CUnit REQUIRED)
# find_library(Common REQUIRED)

# Compiler options
find_program(CLANG_TIDY_PROG clang-tidy)
if(CLANG_TIDY_PROG)
  set(CMAKE_C_CLANG_TIDY 
    ${CLANG_TIDY_PROG};
    "--checks=* -llvm-include-order, -cppcoreguidelines-*, -readability-magic-numbers, -clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling, -hiccp-no-assembler")
  set(CMAKE_C_FLAGS_DEBUG "-g")
else()
  set(CMAKE_C_COMPILER gcc)
  set(CMAKE_C_FLAGS_DEBUG "-g -Wall -pedantic")
endif()

# Function to add a data structure library and its corresponding test
function(add_datastructure_library name)
  # Check if the source file for the given data structure exists
  if(EXISTS ${datastructures1_SOURCE_DIR}/src/${name}.c)
    # Add a shared library for the data structure
    add_library(${name} SHARED ${datastructures1_SOURCE_DIR}/src/${name}.c)
    # Set compile options for the library
    target_compile_options(${name} PRIVATE ${CMAKE_C_FLAGS_DEBUG})

    # Check if the test file for the given data structure exists
    if(EXISTS ${datastructures1_SOURCE_DIR}/tests/${name}_tests.c)
      # Add an executable for testing the data structure
      add_executable(test_${name} ${datastructures1_SOURCE_DIR}/tests/${name}_tests.c)
      # Link the test executable with the data structure library and other dependencies
      target_link_libraries(test_${name} ${name} cunit Common)
      # Set include directories for the test executable
      target_include_directories(test_${name} PRIVATE ${datastructures1_SOURCE_DIR}/include)
    endif()
  endif()
endfunction()

# Add data structure libraries and tests
add_datastructure_library(linked_list)
add_datastructure_library(vector)
add_datastructure_library(adjacency_list)

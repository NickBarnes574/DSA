# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/nick/Programming/DSA

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/nick/Programming/DSA/build

# Include any dependencies generated for this target.
include 0_Common/CMakeFiles/Common.dir/depend.make

# Include the progress variables for this target.
include 0_Common/CMakeFiles/Common.dir/progress.make

# Include the compile flags for this target's objects.
include 0_Common/CMakeFiles/Common.dir/flags.make

0_Common/CMakeFiles/Common.dir/src/utilities.c.o: 0_Common/CMakeFiles/Common.dir/flags.make
0_Common/CMakeFiles/Common.dir/src/utilities.c.o: ../0_Common/src/utilities.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nick/Programming/DSA/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object 0_Common/CMakeFiles/Common.dir/src/utilities.c.o"
	cd /home/nick/Programming/DSA/build/0_Common && $(CMAKE_COMMAND) -E __run_co_compile --tidy="clang-tidy;-checks=*,-readability-function-cognitive-complexity,-altera*,-cert-dcl03-c,-misc-static-assert,-llvm-include-order,-llvmlibc-*,-hicpp-*,-concurrency-mt-unsafe,-bugprone-easily-swappable-parameters,-cppcoreguidelines-*,-clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling" --source=/home/nick/Programming/DSA/0_Common/src/utilities.c -- /usr/bin/clang-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Common.dir/src/utilities.c.o   -c /home/nick/Programming/DSA/0_Common/src/utilities.c

0_Common/CMakeFiles/Common.dir/src/utilities.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Common.dir/src/utilities.c.i"
	cd /home/nick/Programming/DSA/build/0_Common && /usr/bin/clang-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/nick/Programming/DSA/0_Common/src/utilities.c > CMakeFiles/Common.dir/src/utilities.c.i

0_Common/CMakeFiles/Common.dir/src/utilities.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Common.dir/src/utilities.c.s"
	cd /home/nick/Programming/DSA/build/0_Common && /usr/bin/clang-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/nick/Programming/DSA/0_Common/src/utilities.c -o CMakeFiles/Common.dir/src/utilities.c.s

0_Common/CMakeFiles/Common.dir/src/comparisons.c.o: 0_Common/CMakeFiles/Common.dir/flags.make
0_Common/CMakeFiles/Common.dir/src/comparisons.c.o: ../0_Common/src/comparisons.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nick/Programming/DSA/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object 0_Common/CMakeFiles/Common.dir/src/comparisons.c.o"
	cd /home/nick/Programming/DSA/build/0_Common && $(CMAKE_COMMAND) -E __run_co_compile --tidy="clang-tidy;-checks=*,-readability-function-cognitive-complexity,-altera*,-cert-dcl03-c,-misc-static-assert,-llvm-include-order,-llvmlibc-*,-hicpp-*,-concurrency-mt-unsafe,-bugprone-easily-swappable-parameters,-cppcoreguidelines-*,-clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling" --source=/home/nick/Programming/DSA/0_Common/src/comparisons.c -- /usr/bin/clang-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Common.dir/src/comparisons.c.o   -c /home/nick/Programming/DSA/0_Common/src/comparisons.c

0_Common/CMakeFiles/Common.dir/src/comparisons.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Common.dir/src/comparisons.c.i"
	cd /home/nick/Programming/DSA/build/0_Common && /usr/bin/clang-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/nick/Programming/DSA/0_Common/src/comparisons.c > CMakeFiles/Common.dir/src/comparisons.c.i

0_Common/CMakeFiles/Common.dir/src/comparisons.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Common.dir/src/comparisons.c.s"
	cd /home/nick/Programming/DSA/build/0_Common && /usr/bin/clang-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/nick/Programming/DSA/0_Common/src/comparisons.c -o CMakeFiles/Common.dir/src/comparisons.c.s

# Object files for target Common
Common_OBJECTS = \
"CMakeFiles/Common.dir/src/utilities.c.o" \
"CMakeFiles/Common.dir/src/comparisons.c.o"

# External object files for target Common
Common_EXTERNAL_OBJECTS =

0_Common/libCommon.a: 0_Common/CMakeFiles/Common.dir/src/utilities.c.o
0_Common/libCommon.a: 0_Common/CMakeFiles/Common.dir/src/comparisons.c.o
0_Common/libCommon.a: 0_Common/CMakeFiles/Common.dir/build.make
0_Common/libCommon.a: 0_Common/CMakeFiles/Common.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/nick/Programming/DSA/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C static library libCommon.a"
	cd /home/nick/Programming/DSA/build/0_Common && $(CMAKE_COMMAND) -P CMakeFiles/Common.dir/cmake_clean_target.cmake
	cd /home/nick/Programming/DSA/build/0_Common && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Common.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
0_Common/CMakeFiles/Common.dir/build: 0_Common/libCommon.a

.PHONY : 0_Common/CMakeFiles/Common.dir/build

0_Common/CMakeFiles/Common.dir/clean:
	cd /home/nick/Programming/DSA/build/0_Common && $(CMAKE_COMMAND) -P CMakeFiles/Common.dir/cmake_clean.cmake
.PHONY : 0_Common/CMakeFiles/Common.dir/clean

0_Common/CMakeFiles/Common.dir/depend:
	cd /home/nick/Programming/DSA/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nick/Programming/DSA /home/nick/Programming/DSA/0_Common /home/nick/Programming/DSA/build /home/nick/Programming/DSA/build/0_Common /home/nick/Programming/DSA/build/0_Common/CMakeFiles/Common.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : 0_Common/CMakeFiles/Common.dir/depend


# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

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
CMAKE_COMMAND = /usr/bin/cmake.exe

# The command to remove a file.
RM = /usr/bin/cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /cygdrive/e/Documents/code/c++/cpp-practices/projects/SalaryPayment

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /cygdrive/e/Documents/code/c++/cpp-practices/projects/SalaryPayment/cmake-build-debug

# Include any dependencies generated for this target.
include Google_tests/CMakeFiles/Google_Tests_run.dir/depend.make

# Include the progress variables for this target.
include Google_tests/CMakeFiles/Google_Tests_run.dir/progress.make

# Include the compile flags for this target's objects.
include Google_tests/CMakeFiles/Google_Tests_run.dir/flags.make

Google_tests/CMakeFiles/Google_Tests_run.dir/AddEmployTest.cpp.o: Google_tests/CMakeFiles/Google_Tests_run.dir/flags.make
Google_tests/CMakeFiles/Google_Tests_run.dir/AddEmployTest.cpp.o: ../Google_tests/AddEmployTest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/e/Documents/code/c++/cpp-practices/projects/SalaryPayment/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object Google_tests/CMakeFiles/Google_Tests_run.dir/AddEmployTest.cpp.o"
	cd /cygdrive/e/Documents/code/c++/cpp-practices/projects/SalaryPayment/cmake-build-debug/Google_tests && /usr/bin/g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Google_Tests_run.dir/AddEmployTest.cpp.o -c /cygdrive/e/Documents/code/c++/cpp-practices/projects/SalaryPayment/Google_tests/AddEmployTest.cpp

Google_tests/CMakeFiles/Google_Tests_run.dir/AddEmployTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Google_Tests_run.dir/AddEmployTest.cpp.i"
	cd /cygdrive/e/Documents/code/c++/cpp-practices/projects/SalaryPayment/cmake-build-debug/Google_tests && /usr/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/e/Documents/code/c++/cpp-practices/projects/SalaryPayment/Google_tests/AddEmployTest.cpp > CMakeFiles/Google_Tests_run.dir/AddEmployTest.cpp.i

Google_tests/CMakeFiles/Google_Tests_run.dir/AddEmployTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Google_Tests_run.dir/AddEmployTest.cpp.s"
	cd /cygdrive/e/Documents/code/c++/cpp-practices/projects/SalaryPayment/cmake-build-debug/Google_tests && /usr/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/e/Documents/code/c++/cpp-practices/projects/SalaryPayment/Google_tests/AddEmployTest.cpp -o CMakeFiles/Google_Tests_run.dir/AddEmployTest.cpp.s

# Object files for target Google_Tests_run
Google_Tests_run_OBJECTS = \
"CMakeFiles/Google_Tests_run.dir/AddEmployTest.cpp.o"

# External object files for target Google_Tests_run
Google_Tests_run_EXTERNAL_OBJECTS =

Google_tests/Google_Tests_run.exe: Google_tests/CMakeFiles/Google_Tests_run.dir/AddEmployTest.cpp.o
Google_tests/Google_Tests_run.exe: Google_tests/CMakeFiles/Google_Tests_run.dir/build.make
Google_tests/Google_Tests_run.exe: lib/libgtestd.a
Google_tests/Google_Tests_run.exe: lib/libgtest_maind.a
Google_tests/Google_Tests_run.exe: lib/libgtestd.a
Google_tests/Google_Tests_run.exe: Google_tests/CMakeFiles/Google_Tests_run.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/cygdrive/e/Documents/code/c++/cpp-practices/projects/SalaryPayment/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Google_Tests_run.exe"
	cd /cygdrive/e/Documents/code/c++/cpp-practices/projects/SalaryPayment/cmake-build-debug/Google_tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Google_Tests_run.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Google_tests/CMakeFiles/Google_Tests_run.dir/build: Google_tests/Google_Tests_run.exe

.PHONY : Google_tests/CMakeFiles/Google_Tests_run.dir/build

Google_tests/CMakeFiles/Google_Tests_run.dir/clean:
	cd /cygdrive/e/Documents/code/c++/cpp-practices/projects/SalaryPayment/cmake-build-debug/Google_tests && $(CMAKE_COMMAND) -P CMakeFiles/Google_Tests_run.dir/cmake_clean.cmake
.PHONY : Google_tests/CMakeFiles/Google_Tests_run.dir/clean

Google_tests/CMakeFiles/Google_Tests_run.dir/depend:
	cd /cygdrive/e/Documents/code/c++/cpp-practices/projects/SalaryPayment/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /cygdrive/e/Documents/code/c++/cpp-practices/projects/SalaryPayment /cygdrive/e/Documents/code/c++/cpp-practices/projects/SalaryPayment/Google_tests /cygdrive/e/Documents/code/c++/cpp-practices/projects/SalaryPayment/cmake-build-debug /cygdrive/e/Documents/code/c++/cpp-practices/projects/SalaryPayment/cmake-build-debug/Google_tests /cygdrive/e/Documents/code/c++/cpp-practices/projects/SalaryPayment/cmake-build-debug/Google_tests/CMakeFiles/Google_Tests_run.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Google_tests/CMakeFiles/Google_Tests_run.dir/depend


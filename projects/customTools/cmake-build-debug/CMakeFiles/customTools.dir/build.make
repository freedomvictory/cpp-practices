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
CMAKE_SOURCE_DIR = /cygdrive/e/documents/Documents/code/c++/cpp-practices/projects/customTools

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /cygdrive/e/documents/Documents/code/c++/cpp-practices/projects/customTools/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/customTools.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/customTools.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/customTools.dir/flags.make

CMakeFiles/customTools.dir/main.cpp.o: CMakeFiles/customTools.dir/flags.make
CMakeFiles/customTools.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/e/documents/Documents/code/c++/cpp-practices/projects/customTools/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/customTools.dir/main.cpp.o"
	/usr/bin/g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/customTools.dir/main.cpp.o -c /cygdrive/e/documents/Documents/code/c++/cpp-practices/projects/customTools/main.cpp

CMakeFiles/customTools.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/customTools.dir/main.cpp.i"
	/usr/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/e/documents/Documents/code/c++/cpp-practices/projects/customTools/main.cpp > CMakeFiles/customTools.dir/main.cpp.i

CMakeFiles/customTools.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/customTools.dir/main.cpp.s"
	/usr/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/e/documents/Documents/code/c++/cpp-practices/projects/customTools/main.cpp -o CMakeFiles/customTools.dir/main.cpp.s

CMakeFiles/customTools.dir/convhelper.cpp.o: CMakeFiles/customTools.dir/flags.make
CMakeFiles/customTools.dir/convhelper.cpp.o: ../convhelper.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/e/documents/Documents/code/c++/cpp-practices/projects/customTools/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/customTools.dir/convhelper.cpp.o"
	/usr/bin/g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/customTools.dir/convhelper.cpp.o -c /cygdrive/e/documents/Documents/code/c++/cpp-practices/projects/customTools/convhelper.cpp

CMakeFiles/customTools.dir/convhelper.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/customTools.dir/convhelper.cpp.i"
	/usr/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/e/documents/Documents/code/c++/cpp-practices/projects/customTools/convhelper.cpp > CMakeFiles/customTools.dir/convhelper.cpp.i

CMakeFiles/customTools.dir/convhelper.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/customTools.dir/convhelper.cpp.s"
	/usr/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/e/documents/Documents/code/c++/cpp-practices/projects/customTools/convhelper.cpp -o CMakeFiles/customTools.dir/convhelper.cpp.s

# Object files for target customTools
customTools_OBJECTS = \
"CMakeFiles/customTools.dir/main.cpp.o" \
"CMakeFiles/customTools.dir/convhelper.cpp.o"

# External object files for target customTools
customTools_EXTERNAL_OBJECTS =

customTools.exe: CMakeFiles/customTools.dir/main.cpp.o
customTools.exe: CMakeFiles/customTools.dir/convhelper.cpp.o
customTools.exe: CMakeFiles/customTools.dir/build.make
customTools.exe: CMakeFiles/customTools.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/cygdrive/e/documents/Documents/code/c++/cpp-practices/projects/customTools/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable customTools.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/customTools.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/customTools.dir/build: customTools.exe

.PHONY : CMakeFiles/customTools.dir/build

CMakeFiles/customTools.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/customTools.dir/cmake_clean.cmake
.PHONY : CMakeFiles/customTools.dir/clean

CMakeFiles/customTools.dir/depend:
	cd /cygdrive/e/documents/Documents/code/c++/cpp-practices/projects/customTools/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /cygdrive/e/documents/Documents/code/c++/cpp-practices/projects/customTools /cygdrive/e/documents/Documents/code/c++/cpp-practices/projects/customTools /cygdrive/e/documents/Documents/code/c++/cpp-practices/projects/customTools/cmake-build-debug /cygdrive/e/documents/Documents/code/c++/cpp-practices/projects/customTools/cmake-build-debug /cygdrive/e/documents/Documents/code/c++/cpp-practices/projects/customTools/cmake-build-debug/CMakeFiles/customTools.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/customTools.dir/depend


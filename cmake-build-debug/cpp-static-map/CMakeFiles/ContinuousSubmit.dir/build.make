# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/ranoiaetep/CLionProjects/cpp-flag-registrar

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/ranoiaetep/CLionProjects/cpp-flag-registrar/cmake-build-debug

# Utility rule file for ContinuousSubmit.

# Include any custom commands dependencies for this target.
include cpp-static-map/CMakeFiles/ContinuousSubmit.dir/compiler_depend.make

# Include the progress variables for this target.
include cpp-static-map/CMakeFiles/ContinuousSubmit.dir/progress.make

cpp-static-map/CMakeFiles/ContinuousSubmit:
	cd /Users/ranoiaetep/CLionProjects/cpp-flag-registrar/cmake-build-debug/cpp-static-map && /Applications/CLion.app/Contents/bin/cmake/mac/bin/ctest -D ContinuousSubmit

ContinuousSubmit: cpp-static-map/CMakeFiles/ContinuousSubmit
ContinuousSubmit: cpp-static-map/CMakeFiles/ContinuousSubmit.dir/build.make
.PHONY : ContinuousSubmit

# Rule to build all files generated by this target.
cpp-static-map/CMakeFiles/ContinuousSubmit.dir/build: ContinuousSubmit
.PHONY : cpp-static-map/CMakeFiles/ContinuousSubmit.dir/build

cpp-static-map/CMakeFiles/ContinuousSubmit.dir/clean:
	cd /Users/ranoiaetep/CLionProjects/cpp-flag-registrar/cmake-build-debug/cpp-static-map && $(CMAKE_COMMAND) -P CMakeFiles/ContinuousSubmit.dir/cmake_clean.cmake
.PHONY : cpp-static-map/CMakeFiles/ContinuousSubmit.dir/clean

cpp-static-map/CMakeFiles/ContinuousSubmit.dir/depend:
	cd /Users/ranoiaetep/CLionProjects/cpp-flag-registrar/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/ranoiaetep/CLionProjects/cpp-flag-registrar /Users/ranoiaetep/CLionProjects/cpp-flag-registrar/cpp-static-map /Users/ranoiaetep/CLionProjects/cpp-flag-registrar/cmake-build-debug /Users/ranoiaetep/CLionProjects/cpp-flag-registrar/cmake-build-debug/cpp-static-map /Users/ranoiaetep/CLionProjects/cpp-flag-registrar/cmake-build-debug/cpp-static-map/CMakeFiles/ContinuousSubmit.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : cpp-static-map/CMakeFiles/ContinuousSubmit.dir/depend


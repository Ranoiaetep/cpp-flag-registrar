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

# Include any dependencies generated for this target.
include tests/CMakeFiles/main.dir/depend.make
# Include the progress variables for this target.
include tests/CMakeFiles/main.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/main.dir/flags.make

tests/CMakeFiles/main.dir/main_test_1.cpp.o: tests/CMakeFiles/main.dir/flags.make
tests/CMakeFiles/main.dir/main_test_1.cpp.o: ../tests/main_test_1.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ranoiaetep/CLionProjects/cpp-flag-registrar/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tests/CMakeFiles/main.dir/main_test_1.cpp.o"
	cd /Users/ranoiaetep/CLionProjects/cpp-flag-registrar/cmake-build-debug/tests && /opt/homebrew/bin/g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/main_test_1.cpp.o -c /Users/ranoiaetep/CLionProjects/cpp-flag-registrar/tests/main_test_1.cpp

tests/CMakeFiles/main.dir/main_test_1.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/main_test_1.cpp.i"
	cd /Users/ranoiaetep/CLionProjects/cpp-flag-registrar/cmake-build-debug/tests && /opt/homebrew/bin/g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ranoiaetep/CLionProjects/cpp-flag-registrar/tests/main_test_1.cpp > CMakeFiles/main.dir/main_test_1.cpp.i

tests/CMakeFiles/main.dir/main_test_1.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/main_test_1.cpp.s"
	cd /Users/ranoiaetep/CLionProjects/cpp-flag-registrar/cmake-build-debug/tests && /opt/homebrew/bin/g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ranoiaetep/CLionProjects/cpp-flag-registrar/tests/main_test_1.cpp -o CMakeFiles/main.dir/main_test_1.cpp.s

tests/CMakeFiles/main.dir/__/library.cpp.o: tests/CMakeFiles/main.dir/flags.make
tests/CMakeFiles/main.dir/__/library.cpp.o: ../library.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ranoiaetep/CLionProjects/cpp-flag-registrar/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object tests/CMakeFiles/main.dir/__/library.cpp.o"
	cd /Users/ranoiaetep/CLionProjects/cpp-flag-registrar/cmake-build-debug/tests && /opt/homebrew/bin/g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/__/library.cpp.o -c /Users/ranoiaetep/CLionProjects/cpp-flag-registrar/library.cpp

tests/CMakeFiles/main.dir/__/library.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/__/library.cpp.i"
	cd /Users/ranoiaetep/CLionProjects/cpp-flag-registrar/cmake-build-debug/tests && /opt/homebrew/bin/g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ranoiaetep/CLionProjects/cpp-flag-registrar/library.cpp > CMakeFiles/main.dir/__/library.cpp.i

tests/CMakeFiles/main.dir/__/library.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/__/library.cpp.s"
	cd /Users/ranoiaetep/CLionProjects/cpp-flag-registrar/cmake-build-debug/tests && /opt/homebrew/bin/g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ranoiaetep/CLionProjects/cpp-flag-registrar/library.cpp -o CMakeFiles/main.dir/__/library.cpp.s

# Object files for target main
main_OBJECTS = \
"CMakeFiles/main.dir/main_test_1.cpp.o" \
"CMakeFiles/main.dir/__/library.cpp.o"

# External object files for target main
main_EXTERNAL_OBJECTS =

tests/main: tests/CMakeFiles/main.dir/main_test_1.cpp.o
tests/main: tests/CMakeFiles/main.dir/__/library.cpp.o
tests/main: tests/CMakeFiles/main.dir/build.make
tests/main: tests/CMakeFiles/main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/ranoiaetep/CLionProjects/cpp-flag-registrar/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable main"
	cd /Users/ranoiaetep/CLionProjects/cpp-flag-registrar/cmake-build-debug/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/CMakeFiles/main.dir/build: tests/main
.PHONY : tests/CMakeFiles/main.dir/build

tests/CMakeFiles/main.dir/clean:
	cd /Users/ranoiaetep/CLionProjects/cpp-flag-registrar/cmake-build-debug/tests && $(CMAKE_COMMAND) -P CMakeFiles/main.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/main.dir/clean

tests/CMakeFiles/main.dir/depend:
	cd /Users/ranoiaetep/CLionProjects/cpp-flag-registrar/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/ranoiaetep/CLionProjects/cpp-flag-registrar /Users/ranoiaetep/CLionProjects/cpp-flag-registrar/tests /Users/ranoiaetep/CLionProjects/cpp-flag-registrar/cmake-build-debug /Users/ranoiaetep/CLionProjects/cpp-flag-registrar/cmake-build-debug/tests /Users/ranoiaetep/CLionProjects/cpp-flag-registrar/cmake-build-debug/tests/CMakeFiles/main.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/CMakeFiles/main.dir/depend


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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/kiran/Projects/GitHub/Algorithms/Algorithms/GeeksForGeeks/CompetativeProgramming_CP1/Feb_01_stack_divideAndConquor

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/kiran/Projects/GitHub/Algorithms/Algorithms/GeeksForGeeks/CompetativeProgramming_CP1/Feb_01_stack_divideAndConquor/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Feb_01_stack_divideAndConquor.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Feb_01_stack_divideAndConquor.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Feb_01_stack_divideAndConquor.dir/flags.make

CMakeFiles/Feb_01_stack_divideAndConquor.dir/nextGreatestElement.cpp.o: CMakeFiles/Feb_01_stack_divideAndConquor.dir/flags.make
CMakeFiles/Feb_01_stack_divideAndConquor.dir/nextGreatestElement.cpp.o: ../nextGreatestElement.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/kiran/Projects/GitHub/Algorithms/Algorithms/GeeksForGeeks/CompetativeProgramming_CP1/Feb_01_stack_divideAndConquor/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Feb_01_stack_divideAndConquor.dir/nextGreatestElement.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Feb_01_stack_divideAndConquor.dir/nextGreatestElement.cpp.o -c /Users/kiran/Projects/GitHub/Algorithms/Algorithms/GeeksForGeeks/CompetativeProgramming_CP1/Feb_01_stack_divideAndConquor/nextGreatestElement.cpp

CMakeFiles/Feb_01_stack_divideAndConquor.dir/nextGreatestElement.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Feb_01_stack_divideAndConquor.dir/nextGreatestElement.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/kiran/Projects/GitHub/Algorithms/Algorithms/GeeksForGeeks/CompetativeProgramming_CP1/Feb_01_stack_divideAndConquor/nextGreatestElement.cpp > CMakeFiles/Feb_01_stack_divideAndConquor.dir/nextGreatestElement.cpp.i

CMakeFiles/Feb_01_stack_divideAndConquor.dir/nextGreatestElement.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Feb_01_stack_divideAndConquor.dir/nextGreatestElement.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/kiran/Projects/GitHub/Algorithms/Algorithms/GeeksForGeeks/CompetativeProgramming_CP1/Feb_01_stack_divideAndConquor/nextGreatestElement.cpp -o CMakeFiles/Feb_01_stack_divideAndConquor.dir/nextGreatestElement.cpp.s

# Object files for target Feb_01_stack_divideAndConquor
Feb_01_stack_divideAndConquor_OBJECTS = \
"CMakeFiles/Feb_01_stack_divideAndConquor.dir/nextGreatestElement.cpp.o"

# External object files for target Feb_01_stack_divideAndConquor
Feb_01_stack_divideAndConquor_EXTERNAL_OBJECTS =

Feb_01_stack_divideAndConquor: CMakeFiles/Feb_01_stack_divideAndConquor.dir/nextGreatestElement.cpp.o
Feb_01_stack_divideAndConquor: CMakeFiles/Feb_01_stack_divideAndConquor.dir/build.make
Feb_01_stack_divideAndConquor: CMakeFiles/Feb_01_stack_divideAndConquor.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/kiran/Projects/GitHub/Algorithms/Algorithms/GeeksForGeeks/CompetativeProgramming_CP1/Feb_01_stack_divideAndConquor/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Feb_01_stack_divideAndConquor"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Feb_01_stack_divideAndConquor.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Feb_01_stack_divideAndConquor.dir/build: Feb_01_stack_divideAndConquor

.PHONY : CMakeFiles/Feb_01_stack_divideAndConquor.dir/build

CMakeFiles/Feb_01_stack_divideAndConquor.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Feb_01_stack_divideAndConquor.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Feb_01_stack_divideAndConquor.dir/clean

CMakeFiles/Feb_01_stack_divideAndConquor.dir/depend:
	cd /Users/kiran/Projects/GitHub/Algorithms/Algorithms/GeeksForGeeks/CompetativeProgramming_CP1/Feb_01_stack_divideAndConquor/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/kiran/Projects/GitHub/Algorithms/Algorithms/GeeksForGeeks/CompetativeProgramming_CP1/Feb_01_stack_divideAndConquor /Users/kiran/Projects/GitHub/Algorithms/Algorithms/GeeksForGeeks/CompetativeProgramming_CP1/Feb_01_stack_divideAndConquor /Users/kiran/Projects/GitHub/Algorithms/Algorithms/GeeksForGeeks/CompetativeProgramming_CP1/Feb_01_stack_divideAndConquor/cmake-build-debug /Users/kiran/Projects/GitHub/Algorithms/Algorithms/GeeksForGeeks/CompetativeProgramming_CP1/Feb_01_stack_divideAndConquor/cmake-build-debug /Users/kiran/Projects/GitHub/Algorithms/Algorithms/GeeksForGeeks/CompetativeProgramming_CP1/Feb_01_stack_divideAndConquor/cmake-build-debug/CMakeFiles/Feb_01_stack_divideAndConquor.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Feb_01_stack_divideAndConquor.dir/depend


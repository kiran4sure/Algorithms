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
CMAKE_SOURCE_DIR = /Users/kiran/Projects/GitHub/Algorithms/Algorithms/DesignPatterns/udemy

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/kiran/Projects/GitHub/Algorithms/Algorithms/DesignPatterns/udemy/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/udemy.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/udemy.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/udemy.dir/flags.make

CMakeFiles/udemy.dir/factory.cpp.o: CMakeFiles/udemy.dir/flags.make
CMakeFiles/udemy.dir/factory.cpp.o: ../factory.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/kiran/Projects/GitHub/Algorithms/Algorithms/DesignPatterns/udemy/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/udemy.dir/factory.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/udemy.dir/factory.cpp.o -c /Users/kiran/Projects/GitHub/Algorithms/Algorithms/DesignPatterns/udemy/factory.cpp

CMakeFiles/udemy.dir/factory.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/udemy.dir/factory.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/kiran/Projects/GitHub/Algorithms/Algorithms/DesignPatterns/udemy/factory.cpp > CMakeFiles/udemy.dir/factory.cpp.i

CMakeFiles/udemy.dir/factory.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/udemy.dir/factory.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/kiran/Projects/GitHub/Algorithms/Algorithms/DesignPatterns/udemy/factory.cpp -o CMakeFiles/udemy.dir/factory.cpp.s

# Object files for target udemy
udemy_OBJECTS = \
"CMakeFiles/udemy.dir/factory.cpp.o"

# External object files for target udemy
udemy_EXTERNAL_OBJECTS =

udemy: CMakeFiles/udemy.dir/factory.cpp.o
udemy: CMakeFiles/udemy.dir/build.make
udemy: CMakeFiles/udemy.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/kiran/Projects/GitHub/Algorithms/Algorithms/DesignPatterns/udemy/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable udemy"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/udemy.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/udemy.dir/build: udemy

.PHONY : CMakeFiles/udemy.dir/build

CMakeFiles/udemy.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/udemy.dir/cmake_clean.cmake
.PHONY : CMakeFiles/udemy.dir/clean

CMakeFiles/udemy.dir/depend:
	cd /Users/kiran/Projects/GitHub/Algorithms/Algorithms/DesignPatterns/udemy/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/kiran/Projects/GitHub/Algorithms/Algorithms/DesignPatterns/udemy /Users/kiran/Projects/GitHub/Algorithms/Algorithms/DesignPatterns/udemy /Users/kiran/Projects/GitHub/Algorithms/Algorithms/DesignPatterns/udemy/cmake-build-debug /Users/kiran/Projects/GitHub/Algorithms/Algorithms/DesignPatterns/udemy/cmake-build-debug /Users/kiran/Projects/GitHub/Algorithms/Algorithms/DesignPatterns/udemy/cmake-build-debug/CMakeFiles/udemy.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/udemy.dir/depend

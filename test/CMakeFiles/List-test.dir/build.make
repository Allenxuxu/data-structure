# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = /home/xuxu/work/data-structure

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/xuxu/work/data-structure

# Include any dependencies generated for this target.
include test/CMakeFiles/List-test.dir/depend.make

# Include the progress variables for this target.
include test/CMakeFiles/List-test.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/List-test.dir/flags.make

# Object files for target List-test
List__test_OBJECTS =

# External object files for target List-test
List__test_EXTERNAL_OBJECTS =

bin-debug/List-test: test/CMakeFiles/List-test.dir/build.make
bin-debug/List-test: lib-debug/libxxlib.a
bin-debug/List-test: test/CMakeFiles/List-test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/xuxu/work/data-structure/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Linking CXX executable ../bin-debug/List-test"
	cd /home/xuxu/work/data-structure/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/List-test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/List-test.dir/build: bin-debug/List-test

.PHONY : test/CMakeFiles/List-test.dir/build

test/CMakeFiles/List-test.dir/requires:

.PHONY : test/CMakeFiles/List-test.dir/requires

test/CMakeFiles/List-test.dir/clean:
	cd /home/xuxu/work/data-structure/test && $(CMAKE_COMMAND) -P CMakeFiles/List-test.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/List-test.dir/clean

test/CMakeFiles/List-test.dir/depend:
	cd /home/xuxu/work/data-structure && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/xuxu/work/data-structure /home/xuxu/work/data-structure/test /home/xuxu/work/data-structure /home/xuxu/work/data-structure/test /home/xuxu/work/data-structure/test/CMakeFiles/List-test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/List-test.dir/depend

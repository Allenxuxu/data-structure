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
include test/CMakeFiles/SmartPointer-test.dir/depend.make

# Include the progress variables for this target.
include test/CMakeFiles/SmartPointer-test.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/SmartPointer-test.dir/flags.make

test/CMakeFiles/SmartPointer-test.dir/SmartPointer-test.cpp.o: test/CMakeFiles/SmartPointer-test.dir/flags.make
test/CMakeFiles/SmartPointer-test.dir/SmartPointer-test.cpp.o: test/SmartPointer-test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xuxu/work/data-structure/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/CMakeFiles/SmartPointer-test.dir/SmartPointer-test.cpp.o"
	cd /home/xuxu/work/data-structure/test && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SmartPointer-test.dir/SmartPointer-test.cpp.o -c /home/xuxu/work/data-structure/test/SmartPointer-test.cpp

test/CMakeFiles/SmartPointer-test.dir/SmartPointer-test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SmartPointer-test.dir/SmartPointer-test.cpp.i"
	cd /home/xuxu/work/data-structure/test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xuxu/work/data-structure/test/SmartPointer-test.cpp > CMakeFiles/SmartPointer-test.dir/SmartPointer-test.cpp.i

test/CMakeFiles/SmartPointer-test.dir/SmartPointer-test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SmartPointer-test.dir/SmartPointer-test.cpp.s"
	cd /home/xuxu/work/data-structure/test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xuxu/work/data-structure/test/SmartPointer-test.cpp -o CMakeFiles/SmartPointer-test.dir/SmartPointer-test.cpp.s

test/CMakeFiles/SmartPointer-test.dir/SmartPointer-test.cpp.o.requires:

.PHONY : test/CMakeFiles/SmartPointer-test.dir/SmartPointer-test.cpp.o.requires

test/CMakeFiles/SmartPointer-test.dir/SmartPointer-test.cpp.o.provides: test/CMakeFiles/SmartPointer-test.dir/SmartPointer-test.cpp.o.requires
	$(MAKE) -f test/CMakeFiles/SmartPointer-test.dir/build.make test/CMakeFiles/SmartPointer-test.dir/SmartPointer-test.cpp.o.provides.build
.PHONY : test/CMakeFiles/SmartPointer-test.dir/SmartPointer-test.cpp.o.provides

test/CMakeFiles/SmartPointer-test.dir/SmartPointer-test.cpp.o.provides.build: test/CMakeFiles/SmartPointer-test.dir/SmartPointer-test.cpp.o


# Object files for target SmartPointer-test
SmartPointer__test_OBJECTS = \
"CMakeFiles/SmartPointer-test.dir/SmartPointer-test.cpp.o"

# External object files for target SmartPointer-test
SmartPointer__test_EXTERNAL_OBJECTS =

bin-debug/SmartPointer-test: test/CMakeFiles/SmartPointer-test.dir/SmartPointer-test.cpp.o
bin-debug/SmartPointer-test: test/CMakeFiles/SmartPointer-test.dir/build.make
bin-debug/SmartPointer-test: lib-debug/libxxlib.a
bin-debug/SmartPointer-test: test/CMakeFiles/SmartPointer-test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/xuxu/work/data-structure/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../bin-debug/SmartPointer-test"
	cd /home/xuxu/work/data-structure/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SmartPointer-test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/SmartPointer-test.dir/build: bin-debug/SmartPointer-test

.PHONY : test/CMakeFiles/SmartPointer-test.dir/build

test/CMakeFiles/SmartPointer-test.dir/requires: test/CMakeFiles/SmartPointer-test.dir/SmartPointer-test.cpp.o.requires

.PHONY : test/CMakeFiles/SmartPointer-test.dir/requires

test/CMakeFiles/SmartPointer-test.dir/clean:
	cd /home/xuxu/work/data-structure/test && $(CMAKE_COMMAND) -P CMakeFiles/SmartPointer-test.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/SmartPointer-test.dir/clean

test/CMakeFiles/SmartPointer-test.dir/depend:
	cd /home/xuxu/work/data-structure && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/xuxu/work/data-structure /home/xuxu/work/data-structure/test /home/xuxu/work/data-structure /home/xuxu/work/data-structure/test /home/xuxu/work/data-structure/test/CMakeFiles/SmartPointer-test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/SmartPointer-test.dir/depend

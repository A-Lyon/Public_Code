# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /s/parsons/n/under/alyon/cs253/HW4/testdir

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /s/parsons/n/under/alyon/cs253/HW4/testdir

# Include any dependencies generated for this target.
include CMakeFiles/test.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test.dir/flags.make

CMakeFiles/test.dir/test.cc.o: CMakeFiles/test.dir/flags.make
CMakeFiles/test.dir/test.cc.o: test.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/s/parsons/n/under/alyon/cs253/HW4/testdir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/test.dir/test.cc.o"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test.dir/test.cc.o -c /s/parsons/n/under/alyon/cs253/HW4/testdir/test.cc

CMakeFiles/test.dir/test.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test.dir/test.cc.i"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /s/parsons/n/under/alyon/cs253/HW4/testdir/test.cc > CMakeFiles/test.dir/test.cc.i

CMakeFiles/test.dir/test.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test.dir/test.cc.s"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /s/parsons/n/under/alyon/cs253/HW4/testdir/test.cc -o CMakeFiles/test.dir/test.cc.s

# Object files for target test
test_OBJECTS = \
"CMakeFiles/test.dir/test.cc.o"

# External object files for target test
test_EXTERNAL_OBJECTS =

test: CMakeFiles/test.dir/test.cc.o
test: CMakeFiles/test.dir/build.make
test: libhw4.a
test: CMakeFiles/test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/s/parsons/n/under/alyon/cs253/HW4/testdir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test.dir/build: test

.PHONY : CMakeFiles/test.dir/build

CMakeFiles/test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/test.dir/clean

CMakeFiles/test.dir/depend:
	cd /s/parsons/n/under/alyon/cs253/HW4/testdir && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /s/parsons/n/under/alyon/cs253/HW4/testdir /s/parsons/n/under/alyon/cs253/HW4/testdir /s/parsons/n/under/alyon/cs253/HW4/testdir /s/parsons/n/under/alyon/cs253/HW4/testdir /s/parsons/n/under/alyon/cs253/HW4/testdir/CMakeFiles/test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/test.dir/depend


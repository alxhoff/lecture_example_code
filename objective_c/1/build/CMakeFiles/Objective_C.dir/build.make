# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_SOURCE_DIR = /home/alxhoff/git/GitHub/lecture_example_code/objective_c/1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/alxhoff/git/GitHub/lecture_example_code/objective_c/1/build

# Include any dependencies generated for this target.
include CMakeFiles/Objective_C.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Objective_C.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Objective_C.dir/flags.make

CMakeFiles/Objective_C.dir/src/hello_object.c.o: CMakeFiles/Objective_C.dir/flags.make
CMakeFiles/Objective_C.dir/src/hello_object.c.o: ../src/hello_object.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alxhoff/git/GitHub/lecture_example_code/objective_c/1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Objective_C.dir/src/hello_object.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Objective_C.dir/src/hello_object.c.o   -c /home/alxhoff/git/GitHub/lecture_example_code/objective_c/1/src/hello_object.c

CMakeFiles/Objective_C.dir/src/hello_object.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Objective_C.dir/src/hello_object.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/alxhoff/git/GitHub/lecture_example_code/objective_c/1/src/hello_object.c > CMakeFiles/Objective_C.dir/src/hello_object.c.i

CMakeFiles/Objective_C.dir/src/hello_object.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Objective_C.dir/src/hello_object.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/alxhoff/git/GitHub/lecture_example_code/objective_c/1/src/hello_object.c -o CMakeFiles/Objective_C.dir/src/hello_object.c.s

CMakeFiles/Objective_C.dir/src/main.c.o: CMakeFiles/Objective_C.dir/flags.make
CMakeFiles/Objective_C.dir/src/main.c.o: ../src/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alxhoff/git/GitHub/lecture_example_code/objective_c/1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/Objective_C.dir/src/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Objective_C.dir/src/main.c.o   -c /home/alxhoff/git/GitHub/lecture_example_code/objective_c/1/src/main.c

CMakeFiles/Objective_C.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Objective_C.dir/src/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/alxhoff/git/GitHub/lecture_example_code/objective_c/1/src/main.c > CMakeFiles/Objective_C.dir/src/main.c.i

CMakeFiles/Objective_C.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Objective_C.dir/src/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/alxhoff/git/GitHub/lecture_example_code/objective_c/1/src/main.c -o CMakeFiles/Objective_C.dir/src/main.c.s

# Object files for target Objective_C
Objective_C_OBJECTS = \
"CMakeFiles/Objective_C.dir/src/hello_object.c.o" \
"CMakeFiles/Objective_C.dir/src/main.c.o"

# External object files for target Objective_C
Objective_C_EXTERNAL_OBJECTS =

../bin/Objective_C: CMakeFiles/Objective_C.dir/src/hello_object.c.o
../bin/Objective_C: CMakeFiles/Objective_C.dir/src/main.c.o
../bin/Objective_C: CMakeFiles/Objective_C.dir/build.make
../bin/Objective_C: CMakeFiles/Objective_C.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/alxhoff/git/GitHub/lecture_example_code/objective_c/1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable ../bin/Objective_C"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Objective_C.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Objective_C.dir/build: ../bin/Objective_C

.PHONY : CMakeFiles/Objective_C.dir/build

CMakeFiles/Objective_C.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Objective_C.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Objective_C.dir/clean

CMakeFiles/Objective_C.dir/depend:
	cd /home/alxhoff/git/GitHub/lecture_example_code/objective_c/1/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/alxhoff/git/GitHub/lecture_example_code/objective_c/1 /home/alxhoff/git/GitHub/lecture_example_code/objective_c/1 /home/alxhoff/git/GitHub/lecture_example_code/objective_c/1/build /home/alxhoff/git/GitHub/lecture_example_code/objective_c/1/build /home/alxhoff/git/GitHub/lecture_example_code/objective_c/1/build/CMakeFiles/Objective_C.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Objective_C.dir/depend


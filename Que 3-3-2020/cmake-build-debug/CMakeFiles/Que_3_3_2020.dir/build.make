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
CMAKE_COMMAND = /cygdrive/c/Users/benny/AppData/Local/JetBrains/CLion2020.2/cygwin_cmake/bin/cmake.exe

# The command to remove a file.
RM = /cygdrive/c/Users/benny/AppData/Local/JetBrains/CLion2020.2/cygwin_cmake/bin/cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/cygdrive/c/Users/benny/CLionProjects/Que 3-3-2020"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/cygdrive/c/Users/benny/CLionProjects/Que 3-3-2020/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Que_3_3_2020.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Que_3_3_2020.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Que_3_3_2020.dir/flags.make

CMakeFiles/Que_3_3_2020.dir/main.cpp.o: CMakeFiles/Que_3_3_2020.dir/flags.make
CMakeFiles/Que_3_3_2020.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/cygdrive/c/Users/benny/CLionProjects/Que 3-3-2020/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Que_3_3_2020.dir/main.cpp.o"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Que_3_3_2020.dir/main.cpp.o -c "/cygdrive/c/Users/benny/CLionProjects/Que 3-3-2020/main.cpp"

CMakeFiles/Que_3_3_2020.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Que_3_3_2020.dir/main.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/cygdrive/c/Users/benny/CLionProjects/Que 3-3-2020/main.cpp" > CMakeFiles/Que_3_3_2020.dir/main.cpp.i

CMakeFiles/Que_3_3_2020.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Que_3_3_2020.dir/main.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/cygdrive/c/Users/benny/CLionProjects/Que 3-3-2020/main.cpp" -o CMakeFiles/Que_3_3_2020.dir/main.cpp.s

# Object files for target Que_3_3_2020
Que_3_3_2020_OBJECTS = \
"CMakeFiles/Que_3_3_2020.dir/main.cpp.o"

# External object files for target Que_3_3_2020
Que_3_3_2020_EXTERNAL_OBJECTS =

Que_3_3_2020.exe: CMakeFiles/Que_3_3_2020.dir/main.cpp.o
Que_3_3_2020.exe: CMakeFiles/Que_3_3_2020.dir/build.make
Que_3_3_2020.exe: CMakeFiles/Que_3_3_2020.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/cygdrive/c/Users/benny/CLionProjects/Que 3-3-2020/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Que_3_3_2020.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Que_3_3_2020.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Que_3_3_2020.dir/build: Que_3_3_2020.exe

.PHONY : CMakeFiles/Que_3_3_2020.dir/build

CMakeFiles/Que_3_3_2020.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Que_3_3_2020.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Que_3_3_2020.dir/clean

CMakeFiles/Que_3_3_2020.dir/depend:
	cd "/cygdrive/c/Users/benny/CLionProjects/Que 3-3-2020/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/cygdrive/c/Users/benny/CLionProjects/Que 3-3-2020" "/cygdrive/c/Users/benny/CLionProjects/Que 3-3-2020" "/cygdrive/c/Users/benny/CLionProjects/Que 3-3-2020/cmake-build-debug" "/cygdrive/c/Users/benny/CLionProjects/Que 3-3-2020/cmake-build-debug" "/cygdrive/c/Users/benny/CLionProjects/Que 3-3-2020/cmake-build-debug/CMakeFiles/Que_3_3_2020.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Que_3_3_2020.dir/depend


# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_SOURCE_DIR = /home/erik/dev/rf1060r/baltech_sdk

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/erik/dev/rf1060r/baltech_sdk

# Include any dependencies generated for this target.
include appnotes/CMakeFiles/appnote_vhl.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include appnotes/CMakeFiles/appnote_vhl.dir/compiler_depend.make

# Include the progress variables for this target.
include appnotes/CMakeFiles/appnote_vhl.dir/progress.make

# Include the compile flags for this target's objects.
include appnotes/CMakeFiles/appnote_vhl.dir/flags.make

appnotes/CMakeFiles/appnote_vhl.dir/vhl/appnote_vhl.c.o: appnotes/CMakeFiles/appnote_vhl.dir/flags.make
appnotes/CMakeFiles/appnote_vhl.dir/vhl/appnote_vhl.c.o: appnotes/vhl/appnote_vhl.c
appnotes/CMakeFiles/appnote_vhl.dir/vhl/appnote_vhl.c.o: appnotes/CMakeFiles/appnote_vhl.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/erik/dev/rf1060r/baltech_sdk/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object appnotes/CMakeFiles/appnote_vhl.dir/vhl/appnote_vhl.c.o"
	cd /home/erik/dev/rf1060r/baltech_sdk/appnotes && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT appnotes/CMakeFiles/appnote_vhl.dir/vhl/appnote_vhl.c.o -MF CMakeFiles/appnote_vhl.dir/vhl/appnote_vhl.c.o.d -o CMakeFiles/appnote_vhl.dir/vhl/appnote_vhl.c.o -c /home/erik/dev/rf1060r/baltech_sdk/appnotes/vhl/appnote_vhl.c

appnotes/CMakeFiles/appnote_vhl.dir/vhl/appnote_vhl.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/appnote_vhl.dir/vhl/appnote_vhl.c.i"
	cd /home/erik/dev/rf1060r/baltech_sdk/appnotes && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/erik/dev/rf1060r/baltech_sdk/appnotes/vhl/appnote_vhl.c > CMakeFiles/appnote_vhl.dir/vhl/appnote_vhl.c.i

appnotes/CMakeFiles/appnote_vhl.dir/vhl/appnote_vhl.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/appnote_vhl.dir/vhl/appnote_vhl.c.s"
	cd /home/erik/dev/rf1060r/baltech_sdk/appnotes && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/erik/dev/rf1060r/baltech_sdk/appnotes/vhl/appnote_vhl.c -o CMakeFiles/appnote_vhl.dir/vhl/appnote_vhl.c.s

# Object files for target appnote_vhl
appnote_vhl_OBJECTS = \
"CMakeFiles/appnote_vhl.dir/vhl/appnote_vhl.c.o"

# External object files for target appnote_vhl
appnote_vhl_EXTERNAL_OBJECTS =

binaries/linux64/appnote_vhl: appnotes/CMakeFiles/appnote_vhl.dir/vhl/appnote_vhl.c.o
binaries/linux64/appnote_vhl: appnotes/CMakeFiles/appnote_vhl.dir/build.make
binaries/linux64/appnote_vhl: binaries/linux64/static-libs/libbaltech_api.a
binaries/linux64/appnote_vhl: binaries/linux64/libbrp_lib.so
binaries/linux64/appnote_vhl: appnotes/CMakeFiles/appnote_vhl.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/erik/dev/rf1060r/baltech_sdk/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable ../binaries/linux64/appnote_vhl"
	cd /home/erik/dev/rf1060r/baltech_sdk/appnotes && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/appnote_vhl.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
appnotes/CMakeFiles/appnote_vhl.dir/build: binaries/linux64/appnote_vhl
.PHONY : appnotes/CMakeFiles/appnote_vhl.dir/build

appnotes/CMakeFiles/appnote_vhl.dir/clean:
	cd /home/erik/dev/rf1060r/baltech_sdk/appnotes && $(CMAKE_COMMAND) -P CMakeFiles/appnote_vhl.dir/cmake_clean.cmake
.PHONY : appnotes/CMakeFiles/appnote_vhl.dir/clean

appnotes/CMakeFiles/appnote_vhl.dir/depend:
	cd /home/erik/dev/rf1060r/baltech_sdk && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/erik/dev/rf1060r/baltech_sdk /home/erik/dev/rf1060r/baltech_sdk/appnotes /home/erik/dev/rf1060r/baltech_sdk /home/erik/dev/rf1060r/baltech_sdk/appnotes /home/erik/dev/rf1060r/baltech_sdk/appnotes/CMakeFiles/appnote_vhl.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : appnotes/CMakeFiles/appnote_vhl.dir/depend


# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.24

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2022.3.2\bin\cmake\win\x64\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2022.3.2\bin\cmake\win\x64\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\91418\OneDrive\Demo0\ClionProj

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\91418\OneDrive\Demo0\ClionProj\build

# Include any dependencies generated for this target.
include CMakeFiles/mtlib.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/mtlib.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/mtlib.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/mtlib.dir/flags.make

CMakeFiles/mtlib.dir/src/myThreadfuc.cpp.obj: CMakeFiles/mtlib.dir/flags.make
CMakeFiles/mtlib.dir/src/myThreadfuc.cpp.obj: CMakeFiles/mtlib.dir/includes_CXX.rsp
CMakeFiles/mtlib.dir/src/myThreadfuc.cpp.obj: C:/Users/91418/OneDrive/Demo0/ClionProj/src/myThreadfuc.cpp
CMakeFiles/mtlib.dir/src/myThreadfuc.cpp.obj: CMakeFiles/mtlib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\91418\OneDrive\Demo0\ClionProj\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/mtlib.dir/src/myThreadfuc.cpp.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.2\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/mtlib.dir/src/myThreadfuc.cpp.obj -MF CMakeFiles\mtlib.dir\src\myThreadfuc.cpp.obj.d -o CMakeFiles\mtlib.dir\src\myThreadfuc.cpp.obj -c C:\Users\91418\OneDrive\Demo0\ClionProj\src\myThreadfuc.cpp

CMakeFiles/mtlib.dir/src/myThreadfuc.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mtlib.dir/src/myThreadfuc.cpp.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.2\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\91418\OneDrive\Demo0\ClionProj\src\myThreadfuc.cpp > CMakeFiles\mtlib.dir\src\myThreadfuc.cpp.i

CMakeFiles/mtlib.dir/src/myThreadfuc.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mtlib.dir/src/myThreadfuc.cpp.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.2\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\91418\OneDrive\Demo0\ClionProj\src\myThreadfuc.cpp -o CMakeFiles\mtlib.dir\src\myThreadfuc.cpp.s

# Object files for target mtlib
mtlib_OBJECTS = \
"CMakeFiles/mtlib.dir/src/myThreadfuc.cpp.obj"

# External object files for target mtlib
mtlib_EXTERNAL_OBJECTS =

/LIB/libmtlib.a: CMakeFiles/mtlib.dir/src/myThreadfuc.cpp.obj
/LIB/libmtlib.a: CMakeFiles/mtlib.dir/build.make
/LIB/libmtlib.a: CMakeFiles/mtlib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\91418\OneDrive\Demo0\ClionProj\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library \LIB\libmtlib.a"
	$(CMAKE_COMMAND) -P CMakeFiles\mtlib.dir\cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\mtlib.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/mtlib.dir/build: /LIB/libmtlib.a
.PHONY : CMakeFiles/mtlib.dir/build

CMakeFiles/mtlib.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\mtlib.dir\cmake_clean.cmake
.PHONY : CMakeFiles/mtlib.dir/clean

CMakeFiles/mtlib.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\91418\OneDrive\Demo0\ClionProj C:\Users\91418\OneDrive\Demo0\ClionProj C:\Users\91418\OneDrive\Demo0\ClionProj\build C:\Users\91418\OneDrive\Demo0\ClionProj\build C:\Users\91418\OneDrive\Demo0\ClionProj\build\CMakeFiles\mtlib.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/mtlib.dir/depend


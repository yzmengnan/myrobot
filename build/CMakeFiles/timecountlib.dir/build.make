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
include CMakeFiles/timecountlib.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/timecountlib.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/timecountlib.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/timecountlib.dir/flags.make

CMakeFiles/timecountlib.dir/src/TimerCounter.cpp.obj: CMakeFiles/timecountlib.dir/flags.make
CMakeFiles/timecountlib.dir/src/TimerCounter.cpp.obj: CMakeFiles/timecountlib.dir/includes_CXX.rsp
CMakeFiles/timecountlib.dir/src/TimerCounter.cpp.obj: C:/Users/91418/OneDrive/Demo0/ClionProj/src/TimerCounter.cpp
CMakeFiles/timecountlib.dir/src/TimerCounter.cpp.obj: CMakeFiles/timecountlib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\91418\OneDrive\Demo0\ClionProj\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/timecountlib.dir/src/TimerCounter.cpp.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.2\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/timecountlib.dir/src/TimerCounter.cpp.obj -MF CMakeFiles\timecountlib.dir\src\TimerCounter.cpp.obj.d -o CMakeFiles\timecountlib.dir\src\TimerCounter.cpp.obj -c C:\Users\91418\OneDrive\Demo0\ClionProj\src\TimerCounter.cpp

CMakeFiles/timecountlib.dir/src/TimerCounter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/timecountlib.dir/src/TimerCounter.cpp.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.2\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\91418\OneDrive\Demo0\ClionProj\src\TimerCounter.cpp > CMakeFiles\timecountlib.dir\src\TimerCounter.cpp.i

CMakeFiles/timecountlib.dir/src/TimerCounter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/timecountlib.dir/src/TimerCounter.cpp.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.2\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\91418\OneDrive\Demo0\ClionProj\src\TimerCounter.cpp -o CMakeFiles\timecountlib.dir\src\TimerCounter.cpp.s

# Object files for target timecountlib
timecountlib_OBJECTS = \
"CMakeFiles/timecountlib.dir/src/TimerCounter.cpp.obj"

# External object files for target timecountlib
timecountlib_EXTERNAL_OBJECTS =

/LIB/libtimecountlib.a: CMakeFiles/timecountlib.dir/src/TimerCounter.cpp.obj
/LIB/libtimecountlib.a: CMakeFiles/timecountlib.dir/build.make
/LIB/libtimecountlib.a: CMakeFiles/timecountlib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\91418\OneDrive\Demo0\ClionProj\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library \LIB\libtimecountlib.a"
	$(CMAKE_COMMAND) -P CMakeFiles\timecountlib.dir\cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\timecountlib.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/timecountlib.dir/build: /LIB/libtimecountlib.a
.PHONY : CMakeFiles/timecountlib.dir/build

CMakeFiles/timecountlib.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\timecountlib.dir\cmake_clean.cmake
.PHONY : CMakeFiles/timecountlib.dir/clean

CMakeFiles/timecountlib.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\91418\OneDrive\Demo0\ClionProj C:\Users\91418\OneDrive\Demo0\ClionProj C:\Users\91418\OneDrive\Demo0\ClionProj\build C:\Users\91418\OneDrive\Demo0\ClionProj\build C:\Users\91418\OneDrive\Demo0\ClionProj\build\CMakeFiles\timecountlib.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/timecountlib.dir/depend

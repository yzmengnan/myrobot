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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2022.3.3\bin\cmake\win\x64\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2022.3.3\bin\cmake\win\x64\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\LR\OneDrive\Demo0\ClionProj

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\LR\OneDrive\Demo0\ClionProj\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/driverlib.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/driverlib.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/driverlib.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/driverlib.dir/flags.make

CMakeFiles/driverlib.dir/src/Servo_DRIVE.cpp.obj: CMakeFiles/driverlib.dir/flags.make
CMakeFiles/driverlib.dir/src/Servo_DRIVE.cpp.obj: CMakeFiles/driverlib.dir/includes_CXX.rsp
CMakeFiles/driverlib.dir/src/Servo_DRIVE.cpp.obj: C:/Users/LR/OneDrive/Demo0/ClionProj/src/Servo_DRIVE.cpp
CMakeFiles/driverlib.dir/src/Servo_DRIVE.cpp.obj: CMakeFiles/driverlib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\LR\OneDrive\Demo0\ClionProj\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/driverlib.dir/src/Servo_DRIVE.cpp.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/driverlib.dir/src/Servo_DRIVE.cpp.obj -MF CMakeFiles\driverlib.dir\src\Servo_DRIVE.cpp.obj.d -o CMakeFiles\driverlib.dir\src\Servo_DRIVE.cpp.obj -c C:\Users\LR\OneDrive\Demo0\ClionProj\src\Servo_DRIVE.cpp

CMakeFiles/driverlib.dir/src/Servo_DRIVE.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/driverlib.dir/src/Servo_DRIVE.cpp.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\LR\OneDrive\Demo0\ClionProj\src\Servo_DRIVE.cpp > CMakeFiles\driverlib.dir\src\Servo_DRIVE.cpp.i

CMakeFiles/driverlib.dir/src/Servo_DRIVE.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/driverlib.dir/src/Servo_DRIVE.cpp.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\LR\OneDrive\Demo0\ClionProj\src\Servo_DRIVE.cpp -o CMakeFiles\driverlib.dir\src\Servo_DRIVE.cpp.s

# Object files for target driverlib
driverlib_OBJECTS = \
"CMakeFiles/driverlib.dir/src/Servo_DRIVE.cpp.obj"

# External object files for target driverlib
driverlib_EXTERNAL_OBJECTS =

C:/Users/LR/OneDrive/Demo0/ClionProj/lib/libdriverlib.a: CMakeFiles/driverlib.dir/src/Servo_DRIVE.cpp.obj
C:/Users/LR/OneDrive/Demo0/ClionProj/lib/libdriverlib.a: CMakeFiles/driverlib.dir/build.make
C:/Users/LR/OneDrive/Demo0/ClionProj/lib/libdriverlib.a: CMakeFiles/driverlib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\LR\OneDrive\Demo0\ClionProj\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library C:\Users\LR\OneDrive\Demo0\ClionProj\lib\libdriverlib.a"
	$(CMAKE_COMMAND) -P CMakeFiles\driverlib.dir\cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\driverlib.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/driverlib.dir/build: C:/Users/LR/OneDrive/Demo0/ClionProj/lib/libdriverlib.a
.PHONY : CMakeFiles/driverlib.dir/build

CMakeFiles/driverlib.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\driverlib.dir\cmake_clean.cmake
.PHONY : CMakeFiles/driverlib.dir/clean

CMakeFiles/driverlib.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\LR\OneDrive\Demo0\ClionProj C:\Users\LR\OneDrive\Demo0\ClionProj C:\Users\LR\OneDrive\Demo0\ClionProj\cmake-build-debug C:\Users\LR\OneDrive\Demo0\ClionProj\cmake-build-debug C:\Users\LR\OneDrive\Demo0\ClionProj\cmake-build-debug\CMakeFiles\driverlib.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/driverlib.dir/depend


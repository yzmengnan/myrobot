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
include CMakeFiles/Demo1.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Demo1.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Demo1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Demo1.dir/flags.make

CMakeFiles/Demo1.dir/demo1.cpp.obj: CMakeFiles/Demo1.dir/flags.make
CMakeFiles/Demo1.dir/demo1.cpp.obj: CMakeFiles/Demo1.dir/includes_CXX.rsp
CMakeFiles/Demo1.dir/demo1.cpp.obj: C:/Users/91418/OneDrive/Demo0/ClionProj/demo1.cpp
CMakeFiles/Demo1.dir/demo1.cpp.obj: CMakeFiles/Demo1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\91418\OneDrive\Demo0\ClionProj\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Demo1.dir/demo1.cpp.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.2\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Demo1.dir/demo1.cpp.obj -MF CMakeFiles\Demo1.dir\demo1.cpp.obj.d -o CMakeFiles\Demo1.dir\demo1.cpp.obj -c C:\Users\91418\OneDrive\Demo0\ClionProj\demo1.cpp

CMakeFiles/Demo1.dir/demo1.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Demo1.dir/demo1.cpp.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.2\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\91418\OneDrive\Demo0\ClionProj\demo1.cpp > CMakeFiles\Demo1.dir\demo1.cpp.i

CMakeFiles/Demo1.dir/demo1.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Demo1.dir/demo1.cpp.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.2\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\91418\OneDrive\Demo0\ClionProj\demo1.cpp -o CMakeFiles\Demo1.dir\demo1.cpp.s

# Object files for target Demo1
Demo1_OBJECTS = \
"CMakeFiles/Demo1.dir/demo1.cpp.obj"

# External object files for target Demo1
Demo1_EXTERNAL_OBJECTS =

Demo1.exe: CMakeFiles/Demo1.dir/demo1.cpp.obj
Demo1.exe: CMakeFiles/Demo1.dir/build.make
Demo1.exe: C:/Users/91418/OneDrive/Demo0/ClionProj/lib/libcomlib.a
Demo1.exe: C:/Users/91418/OneDrive/Demo0/ClionProj/lib/libdriverlib.a
Demo1.exe: C:/Users/91418/OneDrive/Demo0/ClionProj/lib/libdplib.a
Demo1.exe: C:/Users/91418/OneDrive/Demo0/ClionProj/lib/libmtlib.a
Demo1.exe: C:/Users/91418/OneDrive/Demo0/ClionProj/lib/libsocketlib.a
Demo1.exe: C:/Users/91418/OneDrive/Demo0/ClionProj/lib/libtimecountlib.a
Demo1.exe: C:/Users/91418/OneDrive/Demo0/ClionProj/lib/libdatarecordlib.a
Demo1.exe: C:/Users/91418/OneDrive/Demo0/ClionProj/lib/TcAdsDll.lib
Demo1.exe: CMakeFiles/Demo1.dir/linklibs.rsp
Demo1.exe: CMakeFiles/Demo1.dir/objects1.rsp
Demo1.exe: CMakeFiles/Demo1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\91418\OneDrive\Demo0\ClionProj\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Demo1.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Demo1.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Demo1.dir/build: Demo1.exe
.PHONY : CMakeFiles/Demo1.dir/build

CMakeFiles/Demo1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Demo1.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Demo1.dir/clean

CMakeFiles/Demo1.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\91418\OneDrive\Demo0\ClionProj C:\Users\91418\OneDrive\Demo0\ClionProj C:\Users\91418\OneDrive\Demo0\ClionProj\build C:\Users\91418\OneDrive\Demo0\ClionProj\build C:\Users\91418\OneDrive\Demo0\ClionProj\build\CMakeFiles\Demo1.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Demo1.dir/depend


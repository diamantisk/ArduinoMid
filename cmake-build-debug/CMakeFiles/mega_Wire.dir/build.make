# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.6

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files (x86)\JetBrains\CLion 2016.3\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files (x86)\JetBrains\CLion 2016.3\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\Angel Zaprianov\Documents\Arduino\ArduinoMid"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\Angel Zaprianov\Documents\Arduino\ArduinoMid\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/mega_Wire.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/mega_Wire.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/mega_Wire.dir/flags.make

CMakeFiles/mega_Wire.dir/C_/Program_Files_(x86)/Arduino/hardware/arduino/avr/libraries/Wire/src/Wire.cpp.obj: CMakeFiles/mega_Wire.dir/flags.make
CMakeFiles/mega_Wire.dir/C_/Program_Files_(x86)/Arduino/hardware/arduino/avr/libraries/Wire/src/Wire.cpp.obj: C:/Program\ Files\ (x86)/Arduino/hardware/arduino/avr/libraries/Wire/src/Wire.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Angel Zaprianov\Documents\Arduino\ArduinoMid\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/mega_Wire.dir/C_/Program_Files_(x86)/Arduino/hardware/arduino/avr/libraries/Wire/src/Wire.cpp.obj"
	C:\PROGRA~2\Arduino\hardware\tools\avr\bin\AVR-G_~1.EXE   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\mega_Wire.dir\C_\Program_Files_(x86)\Arduino\hardware\arduino\avr\libraries\Wire\src\Wire.cpp.obj -c "C:\Program Files (x86)\Arduino\hardware\arduino\avr\libraries\Wire\src\Wire.cpp"

CMakeFiles/mega_Wire.dir/C_/Program_Files_(x86)/Arduino/hardware/arduino/avr/libraries/Wire/src/Wire.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mega_Wire.dir/C_/Program_Files_(x86)/Arduino/hardware/arduino/avr/libraries/Wire/src/Wire.cpp.i"
	C:\PROGRA~2\Arduino\hardware\tools\avr\bin\AVR-G_~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Program Files (x86)\Arduino\hardware\arduino\avr\libraries\Wire\src\Wire.cpp" > CMakeFiles\mega_Wire.dir\C_\Program_Files_(x86)\Arduino\hardware\arduino\avr\libraries\Wire\src\Wire.cpp.i

CMakeFiles/mega_Wire.dir/C_/Program_Files_(x86)/Arduino/hardware/arduino/avr/libraries/Wire/src/Wire.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mega_Wire.dir/C_/Program_Files_(x86)/Arduino/hardware/arduino/avr/libraries/Wire/src/Wire.cpp.s"
	C:\PROGRA~2\Arduino\hardware\tools\avr\bin\AVR-G_~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Program Files (x86)\Arduino\hardware\arduino\avr\libraries\Wire\src\Wire.cpp" -o CMakeFiles\mega_Wire.dir\C_\Program_Files_(x86)\Arduino\hardware\arduino\avr\libraries\Wire\src\Wire.cpp.s

CMakeFiles/mega_Wire.dir/C_/Program_Files_(x86)/Arduino/hardware/arduino/avr/libraries/Wire/src/Wire.cpp.obj.requires:

.PHONY : CMakeFiles/mega_Wire.dir/C_/Program_Files_(x86)/Arduino/hardware/arduino/avr/libraries/Wire/src/Wire.cpp.obj.requires

CMakeFiles/mega_Wire.dir/C_/Program_Files_(x86)/Arduino/hardware/arduino/avr/libraries/Wire/src/Wire.cpp.obj.provides: CMakeFiles/mega_Wire.dir/C_/Program_Files_(x86)/Arduino/hardware/arduino/avr/libraries/Wire/src/Wire.cpp.obj.requires
	$(MAKE) -f CMakeFiles\mega_Wire.dir\build.make CMakeFiles/mega_Wire.dir/C_/Program_Files_(x86)/Arduino/hardware/arduino/avr/libraries/Wire/src/Wire.cpp.obj.provides.build
.PHONY : CMakeFiles/mega_Wire.dir/C_/Program_Files_(x86)/Arduino/hardware/arduino/avr/libraries/Wire/src/Wire.cpp.obj.provides

CMakeFiles/mega_Wire.dir/C_/Program_Files_(x86)/Arduino/hardware/arduino/avr/libraries/Wire/src/Wire.cpp.obj.provides.build: CMakeFiles/mega_Wire.dir/C_/Program_Files_(x86)/Arduino/hardware/arduino/avr/libraries/Wire/src/Wire.cpp.obj


CMakeFiles/mega_Wire.dir/C_/Program_Files_(x86)/Arduino/hardware/arduino/avr/libraries/Wire/src/utility/twi.c.obj: CMakeFiles/mega_Wire.dir/flags.make
CMakeFiles/mega_Wire.dir/C_/Program_Files_(x86)/Arduino/hardware/arduino/avr/libraries/Wire/src/utility/twi.c.obj: C:/Program\ Files\ (x86)/Arduino/hardware/arduino/avr/libraries/Wire/src/utility/twi.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Angel Zaprianov\Documents\Arduino\ArduinoMid\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/mega_Wire.dir/C_/Program_Files_(x86)/Arduino/hardware/arduino/avr/libraries/Wire/src/utility/twi.c.obj"
	C:\PROGRA~2\Arduino\hardware\tools\avr\bin\avr-gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\mega_Wire.dir\C_\Program_Files_(x86)\Arduino\hardware\arduino\avr\libraries\Wire\src\utility\twi.c.obj   -c "C:\Program Files (x86)\Arduino\hardware\arduino\avr\libraries\Wire\src\utility\twi.c"

CMakeFiles/mega_Wire.dir/C_/Program_Files_(x86)/Arduino/hardware/arduino/avr/libraries/Wire/src/utility/twi.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/mega_Wire.dir/C_/Program_Files_(x86)/Arduino/hardware/arduino/avr/libraries/Wire/src/utility/twi.c.i"
	C:\PROGRA~2\Arduino\hardware\tools\avr\bin\avr-gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Program Files (x86)\Arduino\hardware\arduino\avr\libraries\Wire\src\utility\twi.c" > CMakeFiles\mega_Wire.dir\C_\Program_Files_(x86)\Arduino\hardware\arduino\avr\libraries\Wire\src\utility\twi.c.i

CMakeFiles/mega_Wire.dir/C_/Program_Files_(x86)/Arduino/hardware/arduino/avr/libraries/Wire/src/utility/twi.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/mega_Wire.dir/C_/Program_Files_(x86)/Arduino/hardware/arduino/avr/libraries/Wire/src/utility/twi.c.s"
	C:\PROGRA~2\Arduino\hardware\tools\avr\bin\avr-gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Program Files (x86)\Arduino\hardware\arduino\avr\libraries\Wire\src\utility\twi.c" -o CMakeFiles\mega_Wire.dir\C_\Program_Files_(x86)\Arduino\hardware\arduino\avr\libraries\Wire\src\utility\twi.c.s

CMakeFiles/mega_Wire.dir/C_/Program_Files_(x86)/Arduino/hardware/arduino/avr/libraries/Wire/src/utility/twi.c.obj.requires:

.PHONY : CMakeFiles/mega_Wire.dir/C_/Program_Files_(x86)/Arduino/hardware/arduino/avr/libraries/Wire/src/utility/twi.c.obj.requires

CMakeFiles/mega_Wire.dir/C_/Program_Files_(x86)/Arduino/hardware/arduino/avr/libraries/Wire/src/utility/twi.c.obj.provides: CMakeFiles/mega_Wire.dir/C_/Program_Files_(x86)/Arduino/hardware/arduino/avr/libraries/Wire/src/utility/twi.c.obj.requires
	$(MAKE) -f CMakeFiles\mega_Wire.dir\build.make CMakeFiles/mega_Wire.dir/C_/Program_Files_(x86)/Arduino/hardware/arduino/avr/libraries/Wire/src/utility/twi.c.obj.provides.build
.PHONY : CMakeFiles/mega_Wire.dir/C_/Program_Files_(x86)/Arduino/hardware/arduino/avr/libraries/Wire/src/utility/twi.c.obj.provides

CMakeFiles/mega_Wire.dir/C_/Program_Files_(x86)/Arduino/hardware/arduino/avr/libraries/Wire/src/utility/twi.c.obj.provides.build: CMakeFiles/mega_Wire.dir/C_/Program_Files_(x86)/Arduino/hardware/arduino/avr/libraries/Wire/src/utility/twi.c.obj


# Object files for target mega_Wire
mega_Wire_OBJECTS = \
"CMakeFiles/mega_Wire.dir/C_/Program_Files_(x86)/Arduino/hardware/arduino/avr/libraries/Wire/src/Wire.cpp.obj" \
"CMakeFiles/mega_Wire.dir/C_/Program_Files_(x86)/Arduino/hardware/arduino/avr/libraries/Wire/src/utility/twi.c.obj"

# External object files for target mega_Wire
mega_Wire_EXTERNAL_OBJECTS =

libmega_Wire.a: CMakeFiles/mega_Wire.dir/C_/Program_Files_(x86)/Arduino/hardware/arduino/avr/libraries/Wire/src/Wire.cpp.obj
libmega_Wire.a: CMakeFiles/mega_Wire.dir/C_/Program_Files_(x86)/Arduino/hardware/arduino/avr/libraries/Wire/src/utility/twi.c.obj
libmega_Wire.a: CMakeFiles/mega_Wire.dir/build.make
libmega_Wire.a: CMakeFiles/mega_Wire.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\Angel Zaprianov\Documents\Arduino\ArduinoMid\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library libmega_Wire.a"
	$(CMAKE_COMMAND) -P CMakeFiles\mega_Wire.dir\cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\mega_Wire.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/mega_Wire.dir/build: libmega_Wire.a

.PHONY : CMakeFiles/mega_Wire.dir/build

CMakeFiles/mega_Wire.dir/requires: CMakeFiles/mega_Wire.dir/C_/Program_Files_(x86)/Arduino/hardware/arduino/avr/libraries/Wire/src/Wire.cpp.obj.requires
CMakeFiles/mega_Wire.dir/requires: CMakeFiles/mega_Wire.dir/C_/Program_Files_(x86)/Arduino/hardware/arduino/avr/libraries/Wire/src/utility/twi.c.obj.requires

.PHONY : CMakeFiles/mega_Wire.dir/requires

CMakeFiles/mega_Wire.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\mega_Wire.dir\cmake_clean.cmake
.PHONY : CMakeFiles/mega_Wire.dir/clean

CMakeFiles/mega_Wire.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\Angel Zaprianov\Documents\Arduino\ArduinoMid" "C:\Users\Angel Zaprianov\Documents\Arduino\ArduinoMid" "C:\Users\Angel Zaprianov\Documents\Arduino\ArduinoMid\cmake-build-debug" "C:\Users\Angel Zaprianov\Documents\Arduino\ArduinoMid\cmake-build-debug" "C:\Users\Angel Zaprianov\Documents\Arduino\ArduinoMid\cmake-build-debug\CMakeFiles\mega_Wire.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/mega_Wire.dir/depend


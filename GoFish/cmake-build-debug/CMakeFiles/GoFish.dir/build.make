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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/pulkitmahajan/Documents/C/GoFish

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/pulkitmahajan/Documents/C/GoFish/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/GoFish.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/GoFish.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/GoFish.dir/flags.make

CMakeFiles/GoFish.dir/main.cpp.o: CMakeFiles/GoFish.dir/flags.make
CMakeFiles/GoFish.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/pulkitmahajan/Documents/C/GoFish/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/GoFish.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/GoFish.dir/main.cpp.o -c /Users/pulkitmahajan/Documents/C/GoFish/main.cpp

CMakeFiles/GoFish.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GoFish.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/pulkitmahajan/Documents/C/GoFish/main.cpp > CMakeFiles/GoFish.dir/main.cpp.i

CMakeFiles/GoFish.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GoFish.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/pulkitmahajan/Documents/C/GoFish/main.cpp -o CMakeFiles/GoFish.dir/main.cpp.s

CMakeFiles/GoFish.dir/card.cpp.o: CMakeFiles/GoFish.dir/flags.make
CMakeFiles/GoFish.dir/card.cpp.o: ../card.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/pulkitmahajan/Documents/C/GoFish/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/GoFish.dir/card.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/GoFish.dir/card.cpp.o -c /Users/pulkitmahajan/Documents/C/GoFish/card.cpp

CMakeFiles/GoFish.dir/card.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GoFish.dir/card.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/pulkitmahajan/Documents/C/GoFish/card.cpp > CMakeFiles/GoFish.dir/card.cpp.i

CMakeFiles/GoFish.dir/card.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GoFish.dir/card.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/pulkitmahajan/Documents/C/GoFish/card.cpp -o CMakeFiles/GoFish.dir/card.cpp.s

CMakeFiles/GoFish.dir/deck.cpp.o: CMakeFiles/GoFish.dir/flags.make
CMakeFiles/GoFish.dir/deck.cpp.o: ../deck.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/pulkitmahajan/Documents/C/GoFish/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/GoFish.dir/deck.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/GoFish.dir/deck.cpp.o -c /Users/pulkitmahajan/Documents/C/GoFish/deck.cpp

CMakeFiles/GoFish.dir/deck.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GoFish.dir/deck.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/pulkitmahajan/Documents/C/GoFish/deck.cpp > CMakeFiles/GoFish.dir/deck.cpp.i

CMakeFiles/GoFish.dir/deck.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GoFish.dir/deck.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/pulkitmahajan/Documents/C/GoFish/deck.cpp -o CMakeFiles/GoFish.dir/deck.cpp.s

CMakeFiles/GoFish.dir/player.cpp.o: CMakeFiles/GoFish.dir/flags.make
CMakeFiles/GoFish.dir/player.cpp.o: ../player.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/pulkitmahajan/Documents/C/GoFish/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/GoFish.dir/player.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/GoFish.dir/player.cpp.o -c /Users/pulkitmahajan/Documents/C/GoFish/player.cpp

CMakeFiles/GoFish.dir/player.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GoFish.dir/player.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/pulkitmahajan/Documents/C/GoFish/player.cpp > CMakeFiles/GoFish.dir/player.cpp.i

CMakeFiles/GoFish.dir/player.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GoFish.dir/player.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/pulkitmahajan/Documents/C/GoFish/player.cpp -o CMakeFiles/GoFish.dir/player.cpp.s

# Object files for target GoFish
GoFish_OBJECTS = \
"CMakeFiles/GoFish.dir/main.cpp.o" \
"CMakeFiles/GoFish.dir/card.cpp.o" \
"CMakeFiles/GoFish.dir/deck.cpp.o" \
"CMakeFiles/GoFish.dir/player.cpp.o"

# External object files for target GoFish
GoFish_EXTERNAL_OBJECTS =

GoFish: CMakeFiles/GoFish.dir/main.cpp.o
GoFish: CMakeFiles/GoFish.dir/card.cpp.o
GoFish: CMakeFiles/GoFish.dir/deck.cpp.o
GoFish: CMakeFiles/GoFish.dir/player.cpp.o
GoFish: CMakeFiles/GoFish.dir/build.make
GoFish: CMakeFiles/GoFish.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/pulkitmahajan/Documents/C/GoFish/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable GoFish"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/GoFish.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/GoFish.dir/build: GoFish

.PHONY : CMakeFiles/GoFish.dir/build

CMakeFiles/GoFish.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/GoFish.dir/cmake_clean.cmake
.PHONY : CMakeFiles/GoFish.dir/clean

CMakeFiles/GoFish.dir/depend:
	cd /Users/pulkitmahajan/Documents/C/GoFish/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/pulkitmahajan/Documents/C/GoFish /Users/pulkitmahajan/Documents/C/GoFish /Users/pulkitmahajan/Documents/C/GoFish/cmake-build-debug /Users/pulkitmahajan/Documents/C/GoFish/cmake-build-debug /Users/pulkitmahajan/Documents/C/GoFish/cmake-build-debug/CMakeFiles/GoFish.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/GoFish.dir/depend


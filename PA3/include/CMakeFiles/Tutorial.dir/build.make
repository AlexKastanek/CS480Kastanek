# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = /home/alex/Documents/computer-graphics/PA3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/alex/Documents/computer-graphics/PA3/include

# Include any dependencies generated for this target.
include CMakeFiles/Tutorial.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Tutorial.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Tutorial.dir/flags.make

CMakeFiles/Tutorial.dir/src/imgui_widgets.cpp.o: CMakeFiles/Tutorial.dir/flags.make
CMakeFiles/Tutorial.dir/src/imgui_widgets.cpp.o: ../src/imgui_widgets.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alex/Documents/computer-graphics/PA3/include/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Tutorial.dir/src/imgui_widgets.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Tutorial.dir/src/imgui_widgets.cpp.o -c /home/alex/Documents/computer-graphics/PA3/src/imgui_widgets.cpp

CMakeFiles/Tutorial.dir/src/imgui_widgets.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Tutorial.dir/src/imgui_widgets.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alex/Documents/computer-graphics/PA3/src/imgui_widgets.cpp > CMakeFiles/Tutorial.dir/src/imgui_widgets.cpp.i

CMakeFiles/Tutorial.dir/src/imgui_widgets.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Tutorial.dir/src/imgui_widgets.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alex/Documents/computer-graphics/PA3/src/imgui_widgets.cpp -o CMakeFiles/Tutorial.dir/src/imgui_widgets.cpp.s

CMakeFiles/Tutorial.dir/src/imgui_widgets.cpp.o.requires:

.PHONY : CMakeFiles/Tutorial.dir/src/imgui_widgets.cpp.o.requires

CMakeFiles/Tutorial.dir/src/imgui_widgets.cpp.o.provides: CMakeFiles/Tutorial.dir/src/imgui_widgets.cpp.o.requires
	$(MAKE) -f CMakeFiles/Tutorial.dir/build.make CMakeFiles/Tutorial.dir/src/imgui_widgets.cpp.o.provides.build
.PHONY : CMakeFiles/Tutorial.dir/src/imgui_widgets.cpp.o.provides

CMakeFiles/Tutorial.dir/src/imgui_widgets.cpp.o.provides.build: CMakeFiles/Tutorial.dir/src/imgui_widgets.cpp.o


CMakeFiles/Tutorial.dir/src/main.cpp.o: CMakeFiles/Tutorial.dir/flags.make
CMakeFiles/Tutorial.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alex/Documents/computer-graphics/PA3/include/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Tutorial.dir/src/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Tutorial.dir/src/main.cpp.o -c /home/alex/Documents/computer-graphics/PA3/src/main.cpp

CMakeFiles/Tutorial.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Tutorial.dir/src/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alex/Documents/computer-graphics/PA3/src/main.cpp > CMakeFiles/Tutorial.dir/src/main.cpp.i

CMakeFiles/Tutorial.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Tutorial.dir/src/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alex/Documents/computer-graphics/PA3/src/main.cpp -o CMakeFiles/Tutorial.dir/src/main.cpp.s

CMakeFiles/Tutorial.dir/src/main.cpp.o.requires:

.PHONY : CMakeFiles/Tutorial.dir/src/main.cpp.o.requires

CMakeFiles/Tutorial.dir/src/main.cpp.o.provides: CMakeFiles/Tutorial.dir/src/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/Tutorial.dir/build.make CMakeFiles/Tutorial.dir/src/main.cpp.o.provides.build
.PHONY : CMakeFiles/Tutorial.dir/src/main.cpp.o.provides

CMakeFiles/Tutorial.dir/src/main.cpp.o.provides.build: CMakeFiles/Tutorial.dir/src/main.cpp.o


CMakeFiles/Tutorial.dir/src/shader.cpp.o: CMakeFiles/Tutorial.dir/flags.make
CMakeFiles/Tutorial.dir/src/shader.cpp.o: ../src/shader.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alex/Documents/computer-graphics/PA3/include/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Tutorial.dir/src/shader.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Tutorial.dir/src/shader.cpp.o -c /home/alex/Documents/computer-graphics/PA3/src/shader.cpp

CMakeFiles/Tutorial.dir/src/shader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Tutorial.dir/src/shader.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alex/Documents/computer-graphics/PA3/src/shader.cpp > CMakeFiles/Tutorial.dir/src/shader.cpp.i

CMakeFiles/Tutorial.dir/src/shader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Tutorial.dir/src/shader.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alex/Documents/computer-graphics/PA3/src/shader.cpp -o CMakeFiles/Tutorial.dir/src/shader.cpp.s

CMakeFiles/Tutorial.dir/src/shader.cpp.o.requires:

.PHONY : CMakeFiles/Tutorial.dir/src/shader.cpp.o.requires

CMakeFiles/Tutorial.dir/src/shader.cpp.o.provides: CMakeFiles/Tutorial.dir/src/shader.cpp.o.requires
	$(MAKE) -f CMakeFiles/Tutorial.dir/build.make CMakeFiles/Tutorial.dir/src/shader.cpp.o.provides.build
.PHONY : CMakeFiles/Tutorial.dir/src/shader.cpp.o.provides

CMakeFiles/Tutorial.dir/src/shader.cpp.o.provides.build: CMakeFiles/Tutorial.dir/src/shader.cpp.o


CMakeFiles/Tutorial.dir/src/engine.cpp.o: CMakeFiles/Tutorial.dir/flags.make
CMakeFiles/Tutorial.dir/src/engine.cpp.o: ../src/engine.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alex/Documents/computer-graphics/PA3/include/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Tutorial.dir/src/engine.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Tutorial.dir/src/engine.cpp.o -c /home/alex/Documents/computer-graphics/PA3/src/engine.cpp

CMakeFiles/Tutorial.dir/src/engine.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Tutorial.dir/src/engine.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alex/Documents/computer-graphics/PA3/src/engine.cpp > CMakeFiles/Tutorial.dir/src/engine.cpp.i

CMakeFiles/Tutorial.dir/src/engine.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Tutorial.dir/src/engine.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alex/Documents/computer-graphics/PA3/src/engine.cpp -o CMakeFiles/Tutorial.dir/src/engine.cpp.s

CMakeFiles/Tutorial.dir/src/engine.cpp.o.requires:

.PHONY : CMakeFiles/Tutorial.dir/src/engine.cpp.o.requires

CMakeFiles/Tutorial.dir/src/engine.cpp.o.provides: CMakeFiles/Tutorial.dir/src/engine.cpp.o.requires
	$(MAKE) -f CMakeFiles/Tutorial.dir/build.make CMakeFiles/Tutorial.dir/src/engine.cpp.o.provides.build
.PHONY : CMakeFiles/Tutorial.dir/src/engine.cpp.o.provides

CMakeFiles/Tutorial.dir/src/engine.cpp.o.provides.build: CMakeFiles/Tutorial.dir/src/engine.cpp.o


CMakeFiles/Tutorial.dir/src/moon.cpp.o: CMakeFiles/Tutorial.dir/flags.make
CMakeFiles/Tutorial.dir/src/moon.cpp.o: ../src/moon.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alex/Documents/computer-graphics/PA3/include/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Tutorial.dir/src/moon.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Tutorial.dir/src/moon.cpp.o -c /home/alex/Documents/computer-graphics/PA3/src/moon.cpp

CMakeFiles/Tutorial.dir/src/moon.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Tutorial.dir/src/moon.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alex/Documents/computer-graphics/PA3/src/moon.cpp > CMakeFiles/Tutorial.dir/src/moon.cpp.i

CMakeFiles/Tutorial.dir/src/moon.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Tutorial.dir/src/moon.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alex/Documents/computer-graphics/PA3/src/moon.cpp -o CMakeFiles/Tutorial.dir/src/moon.cpp.s

CMakeFiles/Tutorial.dir/src/moon.cpp.o.requires:

.PHONY : CMakeFiles/Tutorial.dir/src/moon.cpp.o.requires

CMakeFiles/Tutorial.dir/src/moon.cpp.o.provides: CMakeFiles/Tutorial.dir/src/moon.cpp.o.requires
	$(MAKE) -f CMakeFiles/Tutorial.dir/build.make CMakeFiles/Tutorial.dir/src/moon.cpp.o.provides.build
.PHONY : CMakeFiles/Tutorial.dir/src/moon.cpp.o.provides

CMakeFiles/Tutorial.dir/src/moon.cpp.o.provides.build: CMakeFiles/Tutorial.dir/src/moon.cpp.o


CMakeFiles/Tutorial.dir/src/planet.cpp.o: CMakeFiles/Tutorial.dir/flags.make
CMakeFiles/Tutorial.dir/src/planet.cpp.o: ../src/planet.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alex/Documents/computer-graphics/PA3/include/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Tutorial.dir/src/planet.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Tutorial.dir/src/planet.cpp.o -c /home/alex/Documents/computer-graphics/PA3/src/planet.cpp

CMakeFiles/Tutorial.dir/src/planet.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Tutorial.dir/src/planet.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alex/Documents/computer-graphics/PA3/src/planet.cpp > CMakeFiles/Tutorial.dir/src/planet.cpp.i

CMakeFiles/Tutorial.dir/src/planet.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Tutorial.dir/src/planet.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alex/Documents/computer-graphics/PA3/src/planet.cpp -o CMakeFiles/Tutorial.dir/src/planet.cpp.s

CMakeFiles/Tutorial.dir/src/planet.cpp.o.requires:

.PHONY : CMakeFiles/Tutorial.dir/src/planet.cpp.o.requires

CMakeFiles/Tutorial.dir/src/planet.cpp.o.provides: CMakeFiles/Tutorial.dir/src/planet.cpp.o.requires
	$(MAKE) -f CMakeFiles/Tutorial.dir/build.make CMakeFiles/Tutorial.dir/src/planet.cpp.o.provides.build
.PHONY : CMakeFiles/Tutorial.dir/src/planet.cpp.o.provides

CMakeFiles/Tutorial.dir/src/planet.cpp.o.provides.build: CMakeFiles/Tutorial.dir/src/planet.cpp.o


CMakeFiles/Tutorial.dir/src/imgui_demo.cpp.o: CMakeFiles/Tutorial.dir/flags.make
CMakeFiles/Tutorial.dir/src/imgui_demo.cpp.o: ../src/imgui_demo.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alex/Documents/computer-graphics/PA3/include/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/Tutorial.dir/src/imgui_demo.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Tutorial.dir/src/imgui_demo.cpp.o -c /home/alex/Documents/computer-graphics/PA3/src/imgui_demo.cpp

CMakeFiles/Tutorial.dir/src/imgui_demo.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Tutorial.dir/src/imgui_demo.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alex/Documents/computer-graphics/PA3/src/imgui_demo.cpp > CMakeFiles/Tutorial.dir/src/imgui_demo.cpp.i

CMakeFiles/Tutorial.dir/src/imgui_demo.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Tutorial.dir/src/imgui_demo.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alex/Documents/computer-graphics/PA3/src/imgui_demo.cpp -o CMakeFiles/Tutorial.dir/src/imgui_demo.cpp.s

CMakeFiles/Tutorial.dir/src/imgui_demo.cpp.o.requires:

.PHONY : CMakeFiles/Tutorial.dir/src/imgui_demo.cpp.o.requires

CMakeFiles/Tutorial.dir/src/imgui_demo.cpp.o.provides: CMakeFiles/Tutorial.dir/src/imgui_demo.cpp.o.requires
	$(MAKE) -f CMakeFiles/Tutorial.dir/build.make CMakeFiles/Tutorial.dir/src/imgui_demo.cpp.o.provides.build
.PHONY : CMakeFiles/Tutorial.dir/src/imgui_demo.cpp.o.provides

CMakeFiles/Tutorial.dir/src/imgui_demo.cpp.o.provides.build: CMakeFiles/Tutorial.dir/src/imgui_demo.cpp.o


CMakeFiles/Tutorial.dir/src/gui.cpp.o: CMakeFiles/Tutorial.dir/flags.make
CMakeFiles/Tutorial.dir/src/gui.cpp.o: ../src/gui.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alex/Documents/computer-graphics/PA3/include/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/Tutorial.dir/src/gui.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Tutorial.dir/src/gui.cpp.o -c /home/alex/Documents/computer-graphics/PA3/src/gui.cpp

CMakeFiles/Tutorial.dir/src/gui.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Tutorial.dir/src/gui.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alex/Documents/computer-graphics/PA3/src/gui.cpp > CMakeFiles/Tutorial.dir/src/gui.cpp.i

CMakeFiles/Tutorial.dir/src/gui.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Tutorial.dir/src/gui.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alex/Documents/computer-graphics/PA3/src/gui.cpp -o CMakeFiles/Tutorial.dir/src/gui.cpp.s

CMakeFiles/Tutorial.dir/src/gui.cpp.o.requires:

.PHONY : CMakeFiles/Tutorial.dir/src/gui.cpp.o.requires

CMakeFiles/Tutorial.dir/src/gui.cpp.o.provides: CMakeFiles/Tutorial.dir/src/gui.cpp.o.requires
	$(MAKE) -f CMakeFiles/Tutorial.dir/build.make CMakeFiles/Tutorial.dir/src/gui.cpp.o.provides.build
.PHONY : CMakeFiles/Tutorial.dir/src/gui.cpp.o.provides

CMakeFiles/Tutorial.dir/src/gui.cpp.o.provides.build: CMakeFiles/Tutorial.dir/src/gui.cpp.o


CMakeFiles/Tutorial.dir/src/object.cpp.o: CMakeFiles/Tutorial.dir/flags.make
CMakeFiles/Tutorial.dir/src/object.cpp.o: ../src/object.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alex/Documents/computer-graphics/PA3/include/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/Tutorial.dir/src/object.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Tutorial.dir/src/object.cpp.o -c /home/alex/Documents/computer-graphics/PA3/src/object.cpp

CMakeFiles/Tutorial.dir/src/object.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Tutorial.dir/src/object.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alex/Documents/computer-graphics/PA3/src/object.cpp > CMakeFiles/Tutorial.dir/src/object.cpp.i

CMakeFiles/Tutorial.dir/src/object.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Tutorial.dir/src/object.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alex/Documents/computer-graphics/PA3/src/object.cpp -o CMakeFiles/Tutorial.dir/src/object.cpp.s

CMakeFiles/Tutorial.dir/src/object.cpp.o.requires:

.PHONY : CMakeFiles/Tutorial.dir/src/object.cpp.o.requires

CMakeFiles/Tutorial.dir/src/object.cpp.o.provides: CMakeFiles/Tutorial.dir/src/object.cpp.o.requires
	$(MAKE) -f CMakeFiles/Tutorial.dir/build.make CMakeFiles/Tutorial.dir/src/object.cpp.o.provides.build
.PHONY : CMakeFiles/Tutorial.dir/src/object.cpp.o.provides

CMakeFiles/Tutorial.dir/src/object.cpp.o.provides.build: CMakeFiles/Tutorial.dir/src/object.cpp.o


CMakeFiles/Tutorial.dir/src/imgui_impl_sdl.cpp.o: CMakeFiles/Tutorial.dir/flags.make
CMakeFiles/Tutorial.dir/src/imgui_impl_sdl.cpp.o: ../src/imgui_impl_sdl.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alex/Documents/computer-graphics/PA3/include/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/Tutorial.dir/src/imgui_impl_sdl.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Tutorial.dir/src/imgui_impl_sdl.cpp.o -c /home/alex/Documents/computer-graphics/PA3/src/imgui_impl_sdl.cpp

CMakeFiles/Tutorial.dir/src/imgui_impl_sdl.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Tutorial.dir/src/imgui_impl_sdl.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alex/Documents/computer-graphics/PA3/src/imgui_impl_sdl.cpp > CMakeFiles/Tutorial.dir/src/imgui_impl_sdl.cpp.i

CMakeFiles/Tutorial.dir/src/imgui_impl_sdl.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Tutorial.dir/src/imgui_impl_sdl.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alex/Documents/computer-graphics/PA3/src/imgui_impl_sdl.cpp -o CMakeFiles/Tutorial.dir/src/imgui_impl_sdl.cpp.s

CMakeFiles/Tutorial.dir/src/imgui_impl_sdl.cpp.o.requires:

.PHONY : CMakeFiles/Tutorial.dir/src/imgui_impl_sdl.cpp.o.requires

CMakeFiles/Tutorial.dir/src/imgui_impl_sdl.cpp.o.provides: CMakeFiles/Tutorial.dir/src/imgui_impl_sdl.cpp.o.requires
	$(MAKE) -f CMakeFiles/Tutorial.dir/build.make CMakeFiles/Tutorial.dir/src/imgui_impl_sdl.cpp.o.provides.build
.PHONY : CMakeFiles/Tutorial.dir/src/imgui_impl_sdl.cpp.o.provides

CMakeFiles/Tutorial.dir/src/imgui_impl_sdl.cpp.o.provides.build: CMakeFiles/Tutorial.dir/src/imgui_impl_sdl.cpp.o


CMakeFiles/Tutorial.dir/src/imgui.cpp.o: CMakeFiles/Tutorial.dir/flags.make
CMakeFiles/Tutorial.dir/src/imgui.cpp.o: ../src/imgui.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alex/Documents/computer-graphics/PA3/include/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/Tutorial.dir/src/imgui.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Tutorial.dir/src/imgui.cpp.o -c /home/alex/Documents/computer-graphics/PA3/src/imgui.cpp

CMakeFiles/Tutorial.dir/src/imgui.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Tutorial.dir/src/imgui.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alex/Documents/computer-graphics/PA3/src/imgui.cpp > CMakeFiles/Tutorial.dir/src/imgui.cpp.i

CMakeFiles/Tutorial.dir/src/imgui.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Tutorial.dir/src/imgui.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alex/Documents/computer-graphics/PA3/src/imgui.cpp -o CMakeFiles/Tutorial.dir/src/imgui.cpp.s

CMakeFiles/Tutorial.dir/src/imgui.cpp.o.requires:

.PHONY : CMakeFiles/Tutorial.dir/src/imgui.cpp.o.requires

CMakeFiles/Tutorial.dir/src/imgui.cpp.o.provides: CMakeFiles/Tutorial.dir/src/imgui.cpp.o.requires
	$(MAKE) -f CMakeFiles/Tutorial.dir/build.make CMakeFiles/Tutorial.dir/src/imgui.cpp.o.provides.build
.PHONY : CMakeFiles/Tutorial.dir/src/imgui.cpp.o.provides

CMakeFiles/Tutorial.dir/src/imgui.cpp.o.provides.build: CMakeFiles/Tutorial.dir/src/imgui.cpp.o


CMakeFiles/Tutorial.dir/src/camera.cpp.o: CMakeFiles/Tutorial.dir/flags.make
CMakeFiles/Tutorial.dir/src/camera.cpp.o: ../src/camera.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alex/Documents/computer-graphics/PA3/include/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/Tutorial.dir/src/camera.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Tutorial.dir/src/camera.cpp.o -c /home/alex/Documents/computer-graphics/PA3/src/camera.cpp

CMakeFiles/Tutorial.dir/src/camera.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Tutorial.dir/src/camera.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alex/Documents/computer-graphics/PA3/src/camera.cpp > CMakeFiles/Tutorial.dir/src/camera.cpp.i

CMakeFiles/Tutorial.dir/src/camera.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Tutorial.dir/src/camera.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alex/Documents/computer-graphics/PA3/src/camera.cpp -o CMakeFiles/Tutorial.dir/src/camera.cpp.s

CMakeFiles/Tutorial.dir/src/camera.cpp.o.requires:

.PHONY : CMakeFiles/Tutorial.dir/src/camera.cpp.o.requires

CMakeFiles/Tutorial.dir/src/camera.cpp.o.provides: CMakeFiles/Tutorial.dir/src/camera.cpp.o.requires
	$(MAKE) -f CMakeFiles/Tutorial.dir/build.make CMakeFiles/Tutorial.dir/src/camera.cpp.o.provides.build
.PHONY : CMakeFiles/Tutorial.dir/src/camera.cpp.o.provides

CMakeFiles/Tutorial.dir/src/camera.cpp.o.provides.build: CMakeFiles/Tutorial.dir/src/camera.cpp.o


CMakeFiles/Tutorial.dir/src/graphics.cpp.o: CMakeFiles/Tutorial.dir/flags.make
CMakeFiles/Tutorial.dir/src/graphics.cpp.o: ../src/graphics.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alex/Documents/computer-graphics/PA3/include/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/Tutorial.dir/src/graphics.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Tutorial.dir/src/graphics.cpp.o -c /home/alex/Documents/computer-graphics/PA3/src/graphics.cpp

CMakeFiles/Tutorial.dir/src/graphics.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Tutorial.dir/src/graphics.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alex/Documents/computer-graphics/PA3/src/graphics.cpp > CMakeFiles/Tutorial.dir/src/graphics.cpp.i

CMakeFiles/Tutorial.dir/src/graphics.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Tutorial.dir/src/graphics.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alex/Documents/computer-graphics/PA3/src/graphics.cpp -o CMakeFiles/Tutorial.dir/src/graphics.cpp.s

CMakeFiles/Tutorial.dir/src/graphics.cpp.o.requires:

.PHONY : CMakeFiles/Tutorial.dir/src/graphics.cpp.o.requires

CMakeFiles/Tutorial.dir/src/graphics.cpp.o.provides: CMakeFiles/Tutorial.dir/src/graphics.cpp.o.requires
	$(MAKE) -f CMakeFiles/Tutorial.dir/build.make CMakeFiles/Tutorial.dir/src/graphics.cpp.o.provides.build
.PHONY : CMakeFiles/Tutorial.dir/src/graphics.cpp.o.provides

CMakeFiles/Tutorial.dir/src/graphics.cpp.o.provides.build: CMakeFiles/Tutorial.dir/src/graphics.cpp.o


CMakeFiles/Tutorial.dir/src/window.cpp.o: CMakeFiles/Tutorial.dir/flags.make
CMakeFiles/Tutorial.dir/src/window.cpp.o: ../src/window.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alex/Documents/computer-graphics/PA3/include/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object CMakeFiles/Tutorial.dir/src/window.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Tutorial.dir/src/window.cpp.o -c /home/alex/Documents/computer-graphics/PA3/src/window.cpp

CMakeFiles/Tutorial.dir/src/window.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Tutorial.dir/src/window.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alex/Documents/computer-graphics/PA3/src/window.cpp > CMakeFiles/Tutorial.dir/src/window.cpp.i

CMakeFiles/Tutorial.dir/src/window.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Tutorial.dir/src/window.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alex/Documents/computer-graphics/PA3/src/window.cpp -o CMakeFiles/Tutorial.dir/src/window.cpp.s

CMakeFiles/Tutorial.dir/src/window.cpp.o.requires:

.PHONY : CMakeFiles/Tutorial.dir/src/window.cpp.o.requires

CMakeFiles/Tutorial.dir/src/window.cpp.o.provides: CMakeFiles/Tutorial.dir/src/window.cpp.o.requires
	$(MAKE) -f CMakeFiles/Tutorial.dir/build.make CMakeFiles/Tutorial.dir/src/window.cpp.o.provides.build
.PHONY : CMakeFiles/Tutorial.dir/src/window.cpp.o.provides

CMakeFiles/Tutorial.dir/src/window.cpp.o.provides.build: CMakeFiles/Tutorial.dir/src/window.cpp.o


CMakeFiles/Tutorial.dir/src/imgui_draw.cpp.o: CMakeFiles/Tutorial.dir/flags.make
CMakeFiles/Tutorial.dir/src/imgui_draw.cpp.o: ../src/imgui_draw.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alex/Documents/computer-graphics/PA3/include/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building CXX object CMakeFiles/Tutorial.dir/src/imgui_draw.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Tutorial.dir/src/imgui_draw.cpp.o -c /home/alex/Documents/computer-graphics/PA3/src/imgui_draw.cpp

CMakeFiles/Tutorial.dir/src/imgui_draw.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Tutorial.dir/src/imgui_draw.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alex/Documents/computer-graphics/PA3/src/imgui_draw.cpp > CMakeFiles/Tutorial.dir/src/imgui_draw.cpp.i

CMakeFiles/Tutorial.dir/src/imgui_draw.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Tutorial.dir/src/imgui_draw.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alex/Documents/computer-graphics/PA3/src/imgui_draw.cpp -o CMakeFiles/Tutorial.dir/src/imgui_draw.cpp.s

CMakeFiles/Tutorial.dir/src/imgui_draw.cpp.o.requires:

.PHONY : CMakeFiles/Tutorial.dir/src/imgui_draw.cpp.o.requires

CMakeFiles/Tutorial.dir/src/imgui_draw.cpp.o.provides: CMakeFiles/Tutorial.dir/src/imgui_draw.cpp.o.requires
	$(MAKE) -f CMakeFiles/Tutorial.dir/build.make CMakeFiles/Tutorial.dir/src/imgui_draw.cpp.o.provides.build
.PHONY : CMakeFiles/Tutorial.dir/src/imgui_draw.cpp.o.provides

CMakeFiles/Tutorial.dir/src/imgui_draw.cpp.o.provides.build: CMakeFiles/Tutorial.dir/src/imgui_draw.cpp.o


CMakeFiles/Tutorial.dir/src/imgui_impl_opengl3.cpp.o: CMakeFiles/Tutorial.dir/flags.make
CMakeFiles/Tutorial.dir/src/imgui_impl_opengl3.cpp.o: ../src/imgui_impl_opengl3.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alex/Documents/computer-graphics/PA3/include/CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Building CXX object CMakeFiles/Tutorial.dir/src/imgui_impl_opengl3.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Tutorial.dir/src/imgui_impl_opengl3.cpp.o -c /home/alex/Documents/computer-graphics/PA3/src/imgui_impl_opengl3.cpp

CMakeFiles/Tutorial.dir/src/imgui_impl_opengl3.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Tutorial.dir/src/imgui_impl_opengl3.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alex/Documents/computer-graphics/PA3/src/imgui_impl_opengl3.cpp > CMakeFiles/Tutorial.dir/src/imgui_impl_opengl3.cpp.i

CMakeFiles/Tutorial.dir/src/imgui_impl_opengl3.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Tutorial.dir/src/imgui_impl_opengl3.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alex/Documents/computer-graphics/PA3/src/imgui_impl_opengl3.cpp -o CMakeFiles/Tutorial.dir/src/imgui_impl_opengl3.cpp.s

CMakeFiles/Tutorial.dir/src/imgui_impl_opengl3.cpp.o.requires:

.PHONY : CMakeFiles/Tutorial.dir/src/imgui_impl_opengl3.cpp.o.requires

CMakeFiles/Tutorial.dir/src/imgui_impl_opengl3.cpp.o.provides: CMakeFiles/Tutorial.dir/src/imgui_impl_opengl3.cpp.o.requires
	$(MAKE) -f CMakeFiles/Tutorial.dir/build.make CMakeFiles/Tutorial.dir/src/imgui_impl_opengl3.cpp.o.provides.build
.PHONY : CMakeFiles/Tutorial.dir/src/imgui_impl_opengl3.cpp.o.provides

CMakeFiles/Tutorial.dir/src/imgui_impl_opengl3.cpp.o.provides.build: CMakeFiles/Tutorial.dir/src/imgui_impl_opengl3.cpp.o


# Object files for target Tutorial
Tutorial_OBJECTS = \
"CMakeFiles/Tutorial.dir/src/imgui_widgets.cpp.o" \
"CMakeFiles/Tutorial.dir/src/main.cpp.o" \
"CMakeFiles/Tutorial.dir/src/shader.cpp.o" \
"CMakeFiles/Tutorial.dir/src/engine.cpp.o" \
"CMakeFiles/Tutorial.dir/src/moon.cpp.o" \
"CMakeFiles/Tutorial.dir/src/planet.cpp.o" \
"CMakeFiles/Tutorial.dir/src/imgui_demo.cpp.o" \
"CMakeFiles/Tutorial.dir/src/gui.cpp.o" \
"CMakeFiles/Tutorial.dir/src/object.cpp.o" \
"CMakeFiles/Tutorial.dir/src/imgui_impl_sdl.cpp.o" \
"CMakeFiles/Tutorial.dir/src/imgui.cpp.o" \
"CMakeFiles/Tutorial.dir/src/camera.cpp.o" \
"CMakeFiles/Tutorial.dir/src/graphics.cpp.o" \
"CMakeFiles/Tutorial.dir/src/window.cpp.o" \
"CMakeFiles/Tutorial.dir/src/imgui_draw.cpp.o" \
"CMakeFiles/Tutorial.dir/src/imgui_impl_opengl3.cpp.o"

# External object files for target Tutorial
Tutorial_EXTERNAL_OBJECTS =

Tutorial: CMakeFiles/Tutorial.dir/src/imgui_widgets.cpp.o
Tutorial: CMakeFiles/Tutorial.dir/src/main.cpp.o
Tutorial: CMakeFiles/Tutorial.dir/src/shader.cpp.o
Tutorial: CMakeFiles/Tutorial.dir/src/engine.cpp.o
Tutorial: CMakeFiles/Tutorial.dir/src/moon.cpp.o
Tutorial: CMakeFiles/Tutorial.dir/src/planet.cpp.o
Tutorial: CMakeFiles/Tutorial.dir/src/imgui_demo.cpp.o
Tutorial: CMakeFiles/Tutorial.dir/src/gui.cpp.o
Tutorial: CMakeFiles/Tutorial.dir/src/object.cpp.o
Tutorial: CMakeFiles/Tutorial.dir/src/imgui_impl_sdl.cpp.o
Tutorial: CMakeFiles/Tutorial.dir/src/imgui.cpp.o
Tutorial: CMakeFiles/Tutorial.dir/src/camera.cpp.o
Tutorial: CMakeFiles/Tutorial.dir/src/graphics.cpp.o
Tutorial: CMakeFiles/Tutorial.dir/src/window.cpp.o
Tutorial: CMakeFiles/Tutorial.dir/src/imgui_draw.cpp.o
Tutorial: CMakeFiles/Tutorial.dir/src/imgui_impl_opengl3.cpp.o
Tutorial: CMakeFiles/Tutorial.dir/build.make
Tutorial: /usr/lib/x86_64-linux-gnu/libGLEW.so
Tutorial: /usr/lib/x86_64-linux-gnu/libGLU.so
Tutorial: /usr/lib/x86_64-linux-gnu/libGL.so
Tutorial: /usr/lib/x86_64-linux-gnu/libSDL2main.a
Tutorial: /usr/lib/x86_64-linux-gnu/libSDL2.so
Tutorial: CMakeFiles/Tutorial.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/alex/Documents/computer-graphics/PA3/include/CMakeFiles --progress-num=$(CMAKE_PROGRESS_17) "Linking CXX executable Tutorial"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Tutorial.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Tutorial.dir/build: Tutorial

.PHONY : CMakeFiles/Tutorial.dir/build

CMakeFiles/Tutorial.dir/requires: CMakeFiles/Tutorial.dir/src/imgui_widgets.cpp.o.requires
CMakeFiles/Tutorial.dir/requires: CMakeFiles/Tutorial.dir/src/main.cpp.o.requires
CMakeFiles/Tutorial.dir/requires: CMakeFiles/Tutorial.dir/src/shader.cpp.o.requires
CMakeFiles/Tutorial.dir/requires: CMakeFiles/Tutorial.dir/src/engine.cpp.o.requires
CMakeFiles/Tutorial.dir/requires: CMakeFiles/Tutorial.dir/src/moon.cpp.o.requires
CMakeFiles/Tutorial.dir/requires: CMakeFiles/Tutorial.dir/src/planet.cpp.o.requires
CMakeFiles/Tutorial.dir/requires: CMakeFiles/Tutorial.dir/src/imgui_demo.cpp.o.requires
CMakeFiles/Tutorial.dir/requires: CMakeFiles/Tutorial.dir/src/gui.cpp.o.requires
CMakeFiles/Tutorial.dir/requires: CMakeFiles/Tutorial.dir/src/object.cpp.o.requires
CMakeFiles/Tutorial.dir/requires: CMakeFiles/Tutorial.dir/src/imgui_impl_sdl.cpp.o.requires
CMakeFiles/Tutorial.dir/requires: CMakeFiles/Tutorial.dir/src/imgui.cpp.o.requires
CMakeFiles/Tutorial.dir/requires: CMakeFiles/Tutorial.dir/src/camera.cpp.o.requires
CMakeFiles/Tutorial.dir/requires: CMakeFiles/Tutorial.dir/src/graphics.cpp.o.requires
CMakeFiles/Tutorial.dir/requires: CMakeFiles/Tutorial.dir/src/window.cpp.o.requires
CMakeFiles/Tutorial.dir/requires: CMakeFiles/Tutorial.dir/src/imgui_draw.cpp.o.requires
CMakeFiles/Tutorial.dir/requires: CMakeFiles/Tutorial.dir/src/imgui_impl_opengl3.cpp.o.requires

.PHONY : CMakeFiles/Tutorial.dir/requires

CMakeFiles/Tutorial.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Tutorial.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Tutorial.dir/clean

CMakeFiles/Tutorial.dir/depend:
	cd /home/alex/Documents/computer-graphics/PA3/include && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/alex/Documents/computer-graphics/PA3 /home/alex/Documents/computer-graphics/PA3 /home/alex/Documents/computer-graphics/PA3/include /home/alex/Documents/computer-graphics/PA3/include /home/alex/Documents/computer-graphics/PA3/include/CMakeFiles/Tutorial.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Tutorial.dir/depend


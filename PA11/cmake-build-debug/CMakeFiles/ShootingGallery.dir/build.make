# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_COMMAND = /home/mari/clion-2018.2.4/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/mari/clion-2018.2.4/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/mari/CS480Kastanek/PA11

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/mari/CS480Kastanek/PA11/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ShootingGallery.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ShootingGallery.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ShootingGallery.dir/flags.make

CMakeFiles/ShootingGallery.dir/src/bb.cpp.o: CMakeFiles/ShootingGallery.dir/flags.make
CMakeFiles/ShootingGallery.dir/src/bb.cpp.o: ../src/bb.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mari/CS480Kastanek/PA11/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ShootingGallery.dir/src/bb.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ShootingGallery.dir/src/bb.cpp.o -c /home/mari/CS480Kastanek/PA11/src/bb.cpp

CMakeFiles/ShootingGallery.dir/src/bb.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ShootingGallery.dir/src/bb.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mari/CS480Kastanek/PA11/src/bb.cpp > CMakeFiles/ShootingGallery.dir/src/bb.cpp.i

CMakeFiles/ShootingGallery.dir/src/bb.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ShootingGallery.dir/src/bb.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mari/CS480Kastanek/PA11/src/bb.cpp -o CMakeFiles/ShootingGallery.dir/src/bb.cpp.s

CMakeFiles/ShootingGallery.dir/src/camera.cpp.o: CMakeFiles/ShootingGallery.dir/flags.make
CMakeFiles/ShootingGallery.dir/src/camera.cpp.o: ../src/camera.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mari/CS480Kastanek/PA11/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/ShootingGallery.dir/src/camera.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ShootingGallery.dir/src/camera.cpp.o -c /home/mari/CS480Kastanek/PA11/src/camera.cpp

CMakeFiles/ShootingGallery.dir/src/camera.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ShootingGallery.dir/src/camera.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mari/CS480Kastanek/PA11/src/camera.cpp > CMakeFiles/ShootingGallery.dir/src/camera.cpp.i

CMakeFiles/ShootingGallery.dir/src/camera.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ShootingGallery.dir/src/camera.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mari/CS480Kastanek/PA11/src/camera.cpp -o CMakeFiles/ShootingGallery.dir/src/camera.cpp.s

CMakeFiles/ShootingGallery.dir/src/engine.cpp.o: CMakeFiles/ShootingGallery.dir/flags.make
CMakeFiles/ShootingGallery.dir/src/engine.cpp.o: ../src/engine.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mari/CS480Kastanek/PA11/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/ShootingGallery.dir/src/engine.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ShootingGallery.dir/src/engine.cpp.o -c /home/mari/CS480Kastanek/PA11/src/engine.cpp

CMakeFiles/ShootingGallery.dir/src/engine.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ShootingGallery.dir/src/engine.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mari/CS480Kastanek/PA11/src/engine.cpp > CMakeFiles/ShootingGallery.dir/src/engine.cpp.i

CMakeFiles/ShootingGallery.dir/src/engine.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ShootingGallery.dir/src/engine.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mari/CS480Kastanek/PA11/src/engine.cpp -o CMakeFiles/ShootingGallery.dir/src/engine.cpp.s

CMakeFiles/ShootingGallery.dir/src/graphics.cpp.o: CMakeFiles/ShootingGallery.dir/flags.make
CMakeFiles/ShootingGallery.dir/src/graphics.cpp.o: ../src/graphics.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mari/CS480Kastanek/PA11/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/ShootingGallery.dir/src/graphics.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ShootingGallery.dir/src/graphics.cpp.o -c /home/mari/CS480Kastanek/PA11/src/graphics.cpp

CMakeFiles/ShootingGallery.dir/src/graphics.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ShootingGallery.dir/src/graphics.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mari/CS480Kastanek/PA11/src/graphics.cpp > CMakeFiles/ShootingGallery.dir/src/graphics.cpp.i

CMakeFiles/ShootingGallery.dir/src/graphics.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ShootingGallery.dir/src/graphics.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mari/CS480Kastanek/PA11/src/graphics.cpp -o CMakeFiles/ShootingGallery.dir/src/graphics.cpp.s

CMakeFiles/ShootingGallery.dir/src/gui.cpp.o: CMakeFiles/ShootingGallery.dir/flags.make
CMakeFiles/ShootingGallery.dir/src/gui.cpp.o: ../src/gui.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mari/CS480Kastanek/PA11/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/ShootingGallery.dir/src/gui.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ShootingGallery.dir/src/gui.cpp.o -c /home/mari/CS480Kastanek/PA11/src/gui.cpp

CMakeFiles/ShootingGallery.dir/src/gui.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ShootingGallery.dir/src/gui.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mari/CS480Kastanek/PA11/src/gui.cpp > CMakeFiles/ShootingGallery.dir/src/gui.cpp.i

CMakeFiles/ShootingGallery.dir/src/gui.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ShootingGallery.dir/src/gui.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mari/CS480Kastanek/PA11/src/gui.cpp -o CMakeFiles/ShootingGallery.dir/src/gui.cpp.s

CMakeFiles/ShootingGallery.dir/src/gun.cpp.o: CMakeFiles/ShootingGallery.dir/flags.make
CMakeFiles/ShootingGallery.dir/src/gun.cpp.o: ../src/gun.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mari/CS480Kastanek/PA11/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/ShootingGallery.dir/src/gun.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ShootingGallery.dir/src/gun.cpp.o -c /home/mari/CS480Kastanek/PA11/src/gun.cpp

CMakeFiles/ShootingGallery.dir/src/gun.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ShootingGallery.dir/src/gun.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mari/CS480Kastanek/PA11/src/gun.cpp > CMakeFiles/ShootingGallery.dir/src/gun.cpp.i

CMakeFiles/ShootingGallery.dir/src/gun.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ShootingGallery.dir/src/gun.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mari/CS480Kastanek/PA11/src/gun.cpp -o CMakeFiles/ShootingGallery.dir/src/gun.cpp.s

CMakeFiles/ShootingGallery.dir/src/imgui.cpp.o: CMakeFiles/ShootingGallery.dir/flags.make
CMakeFiles/ShootingGallery.dir/src/imgui.cpp.o: ../src/imgui.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mari/CS480Kastanek/PA11/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/ShootingGallery.dir/src/imgui.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ShootingGallery.dir/src/imgui.cpp.o -c /home/mari/CS480Kastanek/PA11/src/imgui.cpp

CMakeFiles/ShootingGallery.dir/src/imgui.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ShootingGallery.dir/src/imgui.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mari/CS480Kastanek/PA11/src/imgui.cpp > CMakeFiles/ShootingGallery.dir/src/imgui.cpp.i

CMakeFiles/ShootingGallery.dir/src/imgui.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ShootingGallery.dir/src/imgui.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mari/CS480Kastanek/PA11/src/imgui.cpp -o CMakeFiles/ShootingGallery.dir/src/imgui.cpp.s

CMakeFiles/ShootingGallery.dir/src/imgui_demo.cpp.o: CMakeFiles/ShootingGallery.dir/flags.make
CMakeFiles/ShootingGallery.dir/src/imgui_demo.cpp.o: ../src/imgui_demo.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mari/CS480Kastanek/PA11/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/ShootingGallery.dir/src/imgui_demo.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ShootingGallery.dir/src/imgui_demo.cpp.o -c /home/mari/CS480Kastanek/PA11/src/imgui_demo.cpp

CMakeFiles/ShootingGallery.dir/src/imgui_demo.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ShootingGallery.dir/src/imgui_demo.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mari/CS480Kastanek/PA11/src/imgui_demo.cpp > CMakeFiles/ShootingGallery.dir/src/imgui_demo.cpp.i

CMakeFiles/ShootingGallery.dir/src/imgui_demo.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ShootingGallery.dir/src/imgui_demo.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mari/CS480Kastanek/PA11/src/imgui_demo.cpp -o CMakeFiles/ShootingGallery.dir/src/imgui_demo.cpp.s

CMakeFiles/ShootingGallery.dir/src/imgui_draw.cpp.o: CMakeFiles/ShootingGallery.dir/flags.make
CMakeFiles/ShootingGallery.dir/src/imgui_draw.cpp.o: ../src/imgui_draw.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mari/CS480Kastanek/PA11/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/ShootingGallery.dir/src/imgui_draw.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ShootingGallery.dir/src/imgui_draw.cpp.o -c /home/mari/CS480Kastanek/PA11/src/imgui_draw.cpp

CMakeFiles/ShootingGallery.dir/src/imgui_draw.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ShootingGallery.dir/src/imgui_draw.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mari/CS480Kastanek/PA11/src/imgui_draw.cpp > CMakeFiles/ShootingGallery.dir/src/imgui_draw.cpp.i

CMakeFiles/ShootingGallery.dir/src/imgui_draw.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ShootingGallery.dir/src/imgui_draw.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mari/CS480Kastanek/PA11/src/imgui_draw.cpp -o CMakeFiles/ShootingGallery.dir/src/imgui_draw.cpp.s

CMakeFiles/ShootingGallery.dir/src/imgui_impl_opengl3.cpp.o: CMakeFiles/ShootingGallery.dir/flags.make
CMakeFiles/ShootingGallery.dir/src/imgui_impl_opengl3.cpp.o: ../src/imgui_impl_opengl3.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mari/CS480Kastanek/PA11/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/ShootingGallery.dir/src/imgui_impl_opengl3.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ShootingGallery.dir/src/imgui_impl_opengl3.cpp.o -c /home/mari/CS480Kastanek/PA11/src/imgui_impl_opengl3.cpp

CMakeFiles/ShootingGallery.dir/src/imgui_impl_opengl3.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ShootingGallery.dir/src/imgui_impl_opengl3.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mari/CS480Kastanek/PA11/src/imgui_impl_opengl3.cpp > CMakeFiles/ShootingGallery.dir/src/imgui_impl_opengl3.cpp.i

CMakeFiles/ShootingGallery.dir/src/imgui_impl_opengl3.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ShootingGallery.dir/src/imgui_impl_opengl3.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mari/CS480Kastanek/PA11/src/imgui_impl_opengl3.cpp -o CMakeFiles/ShootingGallery.dir/src/imgui_impl_opengl3.cpp.s

CMakeFiles/ShootingGallery.dir/src/imgui_impl_sdl.cpp.o: CMakeFiles/ShootingGallery.dir/flags.make
CMakeFiles/ShootingGallery.dir/src/imgui_impl_sdl.cpp.o: ../src/imgui_impl_sdl.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mari/CS480Kastanek/PA11/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/ShootingGallery.dir/src/imgui_impl_sdl.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ShootingGallery.dir/src/imgui_impl_sdl.cpp.o -c /home/mari/CS480Kastanek/PA11/src/imgui_impl_sdl.cpp

CMakeFiles/ShootingGallery.dir/src/imgui_impl_sdl.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ShootingGallery.dir/src/imgui_impl_sdl.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mari/CS480Kastanek/PA11/src/imgui_impl_sdl.cpp > CMakeFiles/ShootingGallery.dir/src/imgui_impl_sdl.cpp.i

CMakeFiles/ShootingGallery.dir/src/imgui_impl_sdl.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ShootingGallery.dir/src/imgui_impl_sdl.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mari/CS480Kastanek/PA11/src/imgui_impl_sdl.cpp -o CMakeFiles/ShootingGallery.dir/src/imgui_impl_sdl.cpp.s

CMakeFiles/ShootingGallery.dir/src/imgui_widgets.cpp.o: CMakeFiles/ShootingGallery.dir/flags.make
CMakeFiles/ShootingGallery.dir/src/imgui_widgets.cpp.o: ../src/imgui_widgets.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mari/CS480Kastanek/PA11/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/ShootingGallery.dir/src/imgui_widgets.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ShootingGallery.dir/src/imgui_widgets.cpp.o -c /home/mari/CS480Kastanek/PA11/src/imgui_widgets.cpp

CMakeFiles/ShootingGallery.dir/src/imgui_widgets.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ShootingGallery.dir/src/imgui_widgets.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mari/CS480Kastanek/PA11/src/imgui_widgets.cpp > CMakeFiles/ShootingGallery.dir/src/imgui_widgets.cpp.i

CMakeFiles/ShootingGallery.dir/src/imgui_widgets.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ShootingGallery.dir/src/imgui_widgets.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mari/CS480Kastanek/PA11/src/imgui_widgets.cpp -o CMakeFiles/ShootingGallery.dir/src/imgui_widgets.cpp.s

CMakeFiles/ShootingGallery.dir/src/main.cpp.o: CMakeFiles/ShootingGallery.dir/flags.make
CMakeFiles/ShootingGallery.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mari/CS480Kastanek/PA11/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/ShootingGallery.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ShootingGallery.dir/src/main.cpp.o -c /home/mari/CS480Kastanek/PA11/src/main.cpp

CMakeFiles/ShootingGallery.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ShootingGallery.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mari/CS480Kastanek/PA11/src/main.cpp > CMakeFiles/ShootingGallery.dir/src/main.cpp.i

CMakeFiles/ShootingGallery.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ShootingGallery.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mari/CS480Kastanek/PA11/src/main.cpp -o CMakeFiles/ShootingGallery.dir/src/main.cpp.s

CMakeFiles/ShootingGallery.dir/src/model.cpp.o: CMakeFiles/ShootingGallery.dir/flags.make
CMakeFiles/ShootingGallery.dir/src/model.cpp.o: ../src/model.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mari/CS480Kastanek/PA11/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object CMakeFiles/ShootingGallery.dir/src/model.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ShootingGallery.dir/src/model.cpp.o -c /home/mari/CS480Kastanek/PA11/src/model.cpp

CMakeFiles/ShootingGallery.dir/src/model.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ShootingGallery.dir/src/model.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mari/CS480Kastanek/PA11/src/model.cpp > CMakeFiles/ShootingGallery.dir/src/model.cpp.i

CMakeFiles/ShootingGallery.dir/src/model.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ShootingGallery.dir/src/model.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mari/CS480Kastanek/PA11/src/model.cpp -o CMakeFiles/ShootingGallery.dir/src/model.cpp.s

CMakeFiles/ShootingGallery.dir/src/object.cpp.o: CMakeFiles/ShootingGallery.dir/flags.make
CMakeFiles/ShootingGallery.dir/src/object.cpp.o: ../src/object.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mari/CS480Kastanek/PA11/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building CXX object CMakeFiles/ShootingGallery.dir/src/object.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ShootingGallery.dir/src/object.cpp.o -c /home/mari/CS480Kastanek/PA11/src/object.cpp

CMakeFiles/ShootingGallery.dir/src/object.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ShootingGallery.dir/src/object.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mari/CS480Kastanek/PA11/src/object.cpp > CMakeFiles/ShootingGallery.dir/src/object.cpp.i

CMakeFiles/ShootingGallery.dir/src/object.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ShootingGallery.dir/src/object.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mari/CS480Kastanek/PA11/src/object.cpp -o CMakeFiles/ShootingGallery.dir/src/object.cpp.s

CMakeFiles/ShootingGallery.dir/src/obstacle.cpp.o: CMakeFiles/ShootingGallery.dir/flags.make
CMakeFiles/ShootingGallery.dir/src/obstacle.cpp.o: ../src/obstacle.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mari/CS480Kastanek/PA11/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Building CXX object CMakeFiles/ShootingGallery.dir/src/obstacle.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ShootingGallery.dir/src/obstacle.cpp.o -c /home/mari/CS480Kastanek/PA11/src/obstacle.cpp

CMakeFiles/ShootingGallery.dir/src/obstacle.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ShootingGallery.dir/src/obstacle.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mari/CS480Kastanek/PA11/src/obstacle.cpp > CMakeFiles/ShootingGallery.dir/src/obstacle.cpp.i

CMakeFiles/ShootingGallery.dir/src/obstacle.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ShootingGallery.dir/src/obstacle.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mari/CS480Kastanek/PA11/src/obstacle.cpp -o CMakeFiles/ShootingGallery.dir/src/obstacle.cpp.s

CMakeFiles/ShootingGallery.dir/src/physics.cpp.o: CMakeFiles/ShootingGallery.dir/flags.make
CMakeFiles/ShootingGallery.dir/src/physics.cpp.o: ../src/physics.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mari/CS480Kastanek/PA11/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_17) "Building CXX object CMakeFiles/ShootingGallery.dir/src/physics.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ShootingGallery.dir/src/physics.cpp.o -c /home/mari/CS480Kastanek/PA11/src/physics.cpp

CMakeFiles/ShootingGallery.dir/src/physics.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ShootingGallery.dir/src/physics.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mari/CS480Kastanek/PA11/src/physics.cpp > CMakeFiles/ShootingGallery.dir/src/physics.cpp.i

CMakeFiles/ShootingGallery.dir/src/physics.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ShootingGallery.dir/src/physics.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mari/CS480Kastanek/PA11/src/physics.cpp -o CMakeFiles/ShootingGallery.dir/src/physics.cpp.s

CMakeFiles/ShootingGallery.dir/src/physics_object.cpp.o: CMakeFiles/ShootingGallery.dir/flags.make
CMakeFiles/ShootingGallery.dir/src/physics_object.cpp.o: ../src/physics_object.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mari/CS480Kastanek/PA11/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_18) "Building CXX object CMakeFiles/ShootingGallery.dir/src/physics_object.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ShootingGallery.dir/src/physics_object.cpp.o -c /home/mari/CS480Kastanek/PA11/src/physics_object.cpp

CMakeFiles/ShootingGallery.dir/src/physics_object.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ShootingGallery.dir/src/physics_object.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mari/CS480Kastanek/PA11/src/physics_object.cpp > CMakeFiles/ShootingGallery.dir/src/physics_object.cpp.i

CMakeFiles/ShootingGallery.dir/src/physics_object.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ShootingGallery.dir/src/physics_object.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mari/CS480Kastanek/PA11/src/physics_object.cpp -o CMakeFiles/ShootingGallery.dir/src/physics_object.cpp.s

CMakeFiles/ShootingGallery.dir/src/shader.cpp.o: CMakeFiles/ShootingGallery.dir/flags.make
CMakeFiles/ShootingGallery.dir/src/shader.cpp.o: ../src/shader.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mari/CS480Kastanek/PA11/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_19) "Building CXX object CMakeFiles/ShootingGallery.dir/src/shader.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ShootingGallery.dir/src/shader.cpp.o -c /home/mari/CS480Kastanek/PA11/src/shader.cpp

CMakeFiles/ShootingGallery.dir/src/shader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ShootingGallery.dir/src/shader.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mari/CS480Kastanek/PA11/src/shader.cpp > CMakeFiles/ShootingGallery.dir/src/shader.cpp.i

CMakeFiles/ShootingGallery.dir/src/shader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ShootingGallery.dir/src/shader.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mari/CS480Kastanek/PA11/src/shader.cpp -o CMakeFiles/ShootingGallery.dir/src/shader.cpp.s

CMakeFiles/ShootingGallery.dir/src/sound.cpp.o: CMakeFiles/ShootingGallery.dir/flags.make
CMakeFiles/ShootingGallery.dir/src/sound.cpp.o: ../src/sound.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mari/CS480Kastanek/PA11/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_20) "Building CXX object CMakeFiles/ShootingGallery.dir/src/sound.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ShootingGallery.dir/src/sound.cpp.o -c /home/mari/CS480Kastanek/PA11/src/sound.cpp

CMakeFiles/ShootingGallery.dir/src/sound.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ShootingGallery.dir/src/sound.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mari/CS480Kastanek/PA11/src/sound.cpp > CMakeFiles/ShootingGallery.dir/src/sound.cpp.i

CMakeFiles/ShootingGallery.dir/src/sound.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ShootingGallery.dir/src/sound.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mari/CS480Kastanek/PA11/src/sound.cpp -o CMakeFiles/ShootingGallery.dir/src/sound.cpp.s

CMakeFiles/ShootingGallery.dir/src/texture.cpp.o: CMakeFiles/ShootingGallery.dir/flags.make
CMakeFiles/ShootingGallery.dir/src/texture.cpp.o: ../src/texture.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mari/CS480Kastanek/PA11/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_21) "Building CXX object CMakeFiles/ShootingGallery.dir/src/texture.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ShootingGallery.dir/src/texture.cpp.o -c /home/mari/CS480Kastanek/PA11/src/texture.cpp

CMakeFiles/ShootingGallery.dir/src/texture.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ShootingGallery.dir/src/texture.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mari/CS480Kastanek/PA11/src/texture.cpp > CMakeFiles/ShootingGallery.dir/src/texture.cpp.i

CMakeFiles/ShootingGallery.dir/src/texture.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ShootingGallery.dir/src/texture.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mari/CS480Kastanek/PA11/src/texture.cpp -o CMakeFiles/ShootingGallery.dir/src/texture.cpp.s

CMakeFiles/ShootingGallery.dir/src/trigger_object.cpp.o: CMakeFiles/ShootingGallery.dir/flags.make
CMakeFiles/ShootingGallery.dir/src/trigger_object.cpp.o: ../src/trigger_object.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mari/CS480Kastanek/PA11/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_22) "Building CXX object CMakeFiles/ShootingGallery.dir/src/trigger_object.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ShootingGallery.dir/src/trigger_object.cpp.o -c /home/mari/CS480Kastanek/PA11/src/trigger_object.cpp

CMakeFiles/ShootingGallery.dir/src/trigger_object.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ShootingGallery.dir/src/trigger_object.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mari/CS480Kastanek/PA11/src/trigger_object.cpp > CMakeFiles/ShootingGallery.dir/src/trigger_object.cpp.i

CMakeFiles/ShootingGallery.dir/src/trigger_object.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ShootingGallery.dir/src/trigger_object.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mari/CS480Kastanek/PA11/src/trigger_object.cpp -o CMakeFiles/ShootingGallery.dir/src/trigger_object.cpp.s

CMakeFiles/ShootingGallery.dir/src/window.cpp.o: CMakeFiles/ShootingGallery.dir/flags.make
CMakeFiles/ShootingGallery.dir/src/window.cpp.o: ../src/window.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mari/CS480Kastanek/PA11/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_23) "Building CXX object CMakeFiles/ShootingGallery.dir/src/window.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ShootingGallery.dir/src/window.cpp.o -c /home/mari/CS480Kastanek/PA11/src/window.cpp

CMakeFiles/ShootingGallery.dir/src/window.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ShootingGallery.dir/src/window.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mari/CS480Kastanek/PA11/src/window.cpp > CMakeFiles/ShootingGallery.dir/src/window.cpp.i

CMakeFiles/ShootingGallery.dir/src/window.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ShootingGallery.dir/src/window.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mari/CS480Kastanek/PA11/src/window.cpp -o CMakeFiles/ShootingGallery.dir/src/window.cpp.s

CMakeFiles/ShootingGallery.dir/src/world.cpp.o: CMakeFiles/ShootingGallery.dir/flags.make
CMakeFiles/ShootingGallery.dir/src/world.cpp.o: ../src/world.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mari/CS480Kastanek/PA11/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_24) "Building CXX object CMakeFiles/ShootingGallery.dir/src/world.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ShootingGallery.dir/src/world.cpp.o -c /home/mari/CS480Kastanek/PA11/src/world.cpp

CMakeFiles/ShootingGallery.dir/src/world.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ShootingGallery.dir/src/world.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mari/CS480Kastanek/PA11/src/world.cpp > CMakeFiles/ShootingGallery.dir/src/world.cpp.i

CMakeFiles/ShootingGallery.dir/src/world.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ShootingGallery.dir/src/world.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mari/CS480Kastanek/PA11/src/world.cpp -o CMakeFiles/ShootingGallery.dir/src/world.cpp.s

# Object files for target ShootingGallery
ShootingGallery_OBJECTS = \
"CMakeFiles/ShootingGallery.dir/src/bb.cpp.o" \
"CMakeFiles/ShootingGallery.dir/src/camera.cpp.o" \
"CMakeFiles/ShootingGallery.dir/src/engine.cpp.o" \
"CMakeFiles/ShootingGallery.dir/src/graphics.cpp.o" \
"CMakeFiles/ShootingGallery.dir/src/gui.cpp.o" \
"CMakeFiles/ShootingGallery.dir/src/gun.cpp.o" \
"CMakeFiles/ShootingGallery.dir/src/imgui.cpp.o" \
"CMakeFiles/ShootingGallery.dir/src/imgui_demo.cpp.o" \
"CMakeFiles/ShootingGallery.dir/src/imgui_draw.cpp.o" \
"CMakeFiles/ShootingGallery.dir/src/imgui_impl_opengl3.cpp.o" \
"CMakeFiles/ShootingGallery.dir/src/imgui_impl_sdl.cpp.o" \
"CMakeFiles/ShootingGallery.dir/src/imgui_widgets.cpp.o" \
"CMakeFiles/ShootingGallery.dir/src/main.cpp.o" \
"CMakeFiles/ShootingGallery.dir/src/model.cpp.o" \
"CMakeFiles/ShootingGallery.dir/src/object.cpp.o" \
"CMakeFiles/ShootingGallery.dir/src/obstacle.cpp.o" \
"CMakeFiles/ShootingGallery.dir/src/physics.cpp.o" \
"CMakeFiles/ShootingGallery.dir/src/physics_object.cpp.o" \
"CMakeFiles/ShootingGallery.dir/src/shader.cpp.o" \
"CMakeFiles/ShootingGallery.dir/src/sound.cpp.o" \
"CMakeFiles/ShootingGallery.dir/src/texture.cpp.o" \
"CMakeFiles/ShootingGallery.dir/src/trigger_object.cpp.o" \
"CMakeFiles/ShootingGallery.dir/src/window.cpp.o" \
"CMakeFiles/ShootingGallery.dir/src/world.cpp.o"

# External object files for target ShootingGallery
ShootingGallery_EXTERNAL_OBJECTS =

ShootingGallery: CMakeFiles/ShootingGallery.dir/src/bb.cpp.o
ShootingGallery: CMakeFiles/ShootingGallery.dir/src/camera.cpp.o
ShootingGallery: CMakeFiles/ShootingGallery.dir/src/engine.cpp.o
ShootingGallery: CMakeFiles/ShootingGallery.dir/src/graphics.cpp.o
ShootingGallery: CMakeFiles/ShootingGallery.dir/src/gui.cpp.o
ShootingGallery: CMakeFiles/ShootingGallery.dir/src/gun.cpp.o
ShootingGallery: CMakeFiles/ShootingGallery.dir/src/imgui.cpp.o
ShootingGallery: CMakeFiles/ShootingGallery.dir/src/imgui_demo.cpp.o
ShootingGallery: CMakeFiles/ShootingGallery.dir/src/imgui_draw.cpp.o
ShootingGallery: CMakeFiles/ShootingGallery.dir/src/imgui_impl_opengl3.cpp.o
ShootingGallery: CMakeFiles/ShootingGallery.dir/src/imgui_impl_sdl.cpp.o
ShootingGallery: CMakeFiles/ShootingGallery.dir/src/imgui_widgets.cpp.o
ShootingGallery: CMakeFiles/ShootingGallery.dir/src/main.cpp.o
ShootingGallery: CMakeFiles/ShootingGallery.dir/src/model.cpp.o
ShootingGallery: CMakeFiles/ShootingGallery.dir/src/object.cpp.o
ShootingGallery: CMakeFiles/ShootingGallery.dir/src/obstacle.cpp.o
ShootingGallery: CMakeFiles/ShootingGallery.dir/src/physics.cpp.o
ShootingGallery: CMakeFiles/ShootingGallery.dir/src/physics_object.cpp.o
ShootingGallery: CMakeFiles/ShootingGallery.dir/src/shader.cpp.o
ShootingGallery: CMakeFiles/ShootingGallery.dir/src/sound.cpp.o
ShootingGallery: CMakeFiles/ShootingGallery.dir/src/texture.cpp.o
ShootingGallery: CMakeFiles/ShootingGallery.dir/src/trigger_object.cpp.o
ShootingGallery: CMakeFiles/ShootingGallery.dir/src/window.cpp.o
ShootingGallery: CMakeFiles/ShootingGallery.dir/src/world.cpp.o
ShootingGallery: CMakeFiles/ShootingGallery.dir/build.make
ShootingGallery: /usr/lib/x86_64-linux-gnu/libGLEW.so
ShootingGallery: /usr/lib/x86_64-linux-gnu/libassimp.so
ShootingGallery: /usr/local/lib/libMagick++-7.Q16HDRI.so
ShootingGallery: /usr/lib/x86_64-linux-gnu/libGL.so
ShootingGallery: /usr/lib/x86_64-linux-gnu/libGLU.so
ShootingGallery: /usr/lib/x86_64-linux-gnu/libSDL2main.a
ShootingGallery: /usr/lib/x86_64-linux-gnu/libSDL2.so
ShootingGallery: /usr/local/lib/libMagick++-7.Q16HDRI.so
ShootingGallery: /usr/lib/x86_64-linux-gnu/libBulletDynamics.so
ShootingGallery: /usr/lib/x86_64-linux-gnu/libBulletCollision.so
ShootingGallery: /usr/lib/x86_64-linux-gnu/libLinearMath.so
ShootingGallery: /usr/lib/x86_64-linux-gnu/libBulletSoftBody.so
ShootingGallery: /usr/lib/x86_64-linux-gnu/libGL.so
ShootingGallery: /usr/lib/x86_64-linux-gnu/libGLU.so
ShootingGallery: /usr/lib/x86_64-linux-gnu/libSDL2main.a
ShootingGallery: /usr/lib/x86_64-linux-gnu/libSDL2.so
ShootingGallery: /usr/lib/x86_64-linux-gnu/libBulletDynamics.so
ShootingGallery: /usr/lib/x86_64-linux-gnu/libBulletCollision.so
ShootingGallery: /usr/lib/x86_64-linux-gnu/libLinearMath.so
ShootingGallery: /usr/lib/x86_64-linux-gnu/libBulletSoftBody.so
ShootingGallery: CMakeFiles/ShootingGallery.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/mari/CS480Kastanek/PA11/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_25) "Linking CXX executable ShootingGallery"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ShootingGallery.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ShootingGallery.dir/build: ShootingGallery

.PHONY : CMakeFiles/ShootingGallery.dir/build

CMakeFiles/ShootingGallery.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ShootingGallery.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ShootingGallery.dir/clean

CMakeFiles/ShootingGallery.dir/depend:
	cd /home/mari/CS480Kastanek/PA11/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mari/CS480Kastanek/PA11 /home/mari/CS480Kastanek/PA11 /home/mari/CS480Kastanek/PA11/cmake-build-debug /home/mari/CS480Kastanek/PA11/cmake-build-debug /home/mari/CS480Kastanek/PA11/cmake-build-debug/CMakeFiles/ShootingGallery.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ShootingGallery.dir/depend


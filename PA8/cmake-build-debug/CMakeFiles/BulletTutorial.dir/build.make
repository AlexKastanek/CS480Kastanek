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
CMAKE_SOURCE_DIR = /home/mari/CS480Kastanek/PA8

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/mari/CS480Kastanek/PA8/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/BulletTutorial.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/BulletTutorial.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/BulletTutorial.dir/flags.make

CMakeFiles/BulletTutorial.dir/src/ball.cpp.o: CMakeFiles/BulletTutorial.dir/flags.make
CMakeFiles/BulletTutorial.dir/src/ball.cpp.o: ../src/ball.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mari/CS480Kastanek/PA8/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/BulletTutorial.dir/src/ball.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/BulletTutorial.dir/src/ball.cpp.o -c /home/mari/CS480Kastanek/PA8/src/ball.cpp

CMakeFiles/BulletTutorial.dir/src/ball.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BulletTutorial.dir/src/ball.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mari/CS480Kastanek/PA8/src/ball.cpp > CMakeFiles/BulletTutorial.dir/src/ball.cpp.i

CMakeFiles/BulletTutorial.dir/src/ball.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BulletTutorial.dir/src/ball.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mari/CS480Kastanek/PA8/src/ball.cpp -o CMakeFiles/BulletTutorial.dir/src/ball.cpp.s

CMakeFiles/BulletTutorial.dir/src/board.cpp.o: CMakeFiles/BulletTutorial.dir/flags.make
CMakeFiles/BulletTutorial.dir/src/board.cpp.o: ../src/board.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mari/CS480Kastanek/PA8/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/BulletTutorial.dir/src/board.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/BulletTutorial.dir/src/board.cpp.o -c /home/mari/CS480Kastanek/PA8/src/board.cpp

CMakeFiles/BulletTutorial.dir/src/board.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BulletTutorial.dir/src/board.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mari/CS480Kastanek/PA8/src/board.cpp > CMakeFiles/BulletTutorial.dir/src/board.cpp.i

CMakeFiles/BulletTutorial.dir/src/board.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BulletTutorial.dir/src/board.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mari/CS480Kastanek/PA8/src/board.cpp -o CMakeFiles/BulletTutorial.dir/src/board.cpp.s

CMakeFiles/BulletTutorial.dir/src/camera.cpp.o: CMakeFiles/BulletTutorial.dir/flags.make
CMakeFiles/BulletTutorial.dir/src/camera.cpp.o: ../src/camera.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mari/CS480Kastanek/PA8/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/BulletTutorial.dir/src/camera.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/BulletTutorial.dir/src/camera.cpp.o -c /home/mari/CS480Kastanek/PA8/src/camera.cpp

CMakeFiles/BulletTutorial.dir/src/camera.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BulletTutorial.dir/src/camera.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mari/CS480Kastanek/PA8/src/camera.cpp > CMakeFiles/BulletTutorial.dir/src/camera.cpp.i

CMakeFiles/BulletTutorial.dir/src/camera.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BulletTutorial.dir/src/camera.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mari/CS480Kastanek/PA8/src/camera.cpp -o CMakeFiles/BulletTutorial.dir/src/camera.cpp.s

CMakeFiles/BulletTutorial.dir/src/cylinder.cpp.o: CMakeFiles/BulletTutorial.dir/flags.make
CMakeFiles/BulletTutorial.dir/src/cylinder.cpp.o: ../src/cylinder.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mari/CS480Kastanek/PA8/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/BulletTutorial.dir/src/cylinder.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/BulletTutorial.dir/src/cylinder.cpp.o -c /home/mari/CS480Kastanek/PA8/src/cylinder.cpp

CMakeFiles/BulletTutorial.dir/src/cylinder.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BulletTutorial.dir/src/cylinder.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mari/CS480Kastanek/PA8/src/cylinder.cpp > CMakeFiles/BulletTutorial.dir/src/cylinder.cpp.i

CMakeFiles/BulletTutorial.dir/src/cylinder.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BulletTutorial.dir/src/cylinder.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mari/CS480Kastanek/PA8/src/cylinder.cpp -o CMakeFiles/BulletTutorial.dir/src/cylinder.cpp.s

CMakeFiles/BulletTutorial.dir/src/engine.cpp.o: CMakeFiles/BulletTutorial.dir/flags.make
CMakeFiles/BulletTutorial.dir/src/engine.cpp.o: ../src/engine.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mari/CS480Kastanek/PA8/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/BulletTutorial.dir/src/engine.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/BulletTutorial.dir/src/engine.cpp.o -c /home/mari/CS480Kastanek/PA8/src/engine.cpp

CMakeFiles/BulletTutorial.dir/src/engine.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BulletTutorial.dir/src/engine.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mari/CS480Kastanek/PA8/src/engine.cpp > CMakeFiles/BulletTutorial.dir/src/engine.cpp.i

CMakeFiles/BulletTutorial.dir/src/engine.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BulletTutorial.dir/src/engine.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mari/CS480Kastanek/PA8/src/engine.cpp -o CMakeFiles/BulletTutorial.dir/src/engine.cpp.s

CMakeFiles/BulletTutorial.dir/src/flipper.cpp.o: CMakeFiles/BulletTutorial.dir/flags.make
CMakeFiles/BulletTutorial.dir/src/flipper.cpp.o: ../src/flipper.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mari/CS480Kastanek/PA8/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/BulletTutorial.dir/src/flipper.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/BulletTutorial.dir/src/flipper.cpp.o -c /home/mari/CS480Kastanek/PA8/src/flipper.cpp

CMakeFiles/BulletTutorial.dir/src/flipper.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BulletTutorial.dir/src/flipper.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mari/CS480Kastanek/PA8/src/flipper.cpp > CMakeFiles/BulletTutorial.dir/src/flipper.cpp.i

CMakeFiles/BulletTutorial.dir/src/flipper.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BulletTutorial.dir/src/flipper.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mari/CS480Kastanek/PA8/src/flipper.cpp -o CMakeFiles/BulletTutorial.dir/src/flipper.cpp.s

CMakeFiles/BulletTutorial.dir/src/graphics.cpp.o: CMakeFiles/BulletTutorial.dir/flags.make
CMakeFiles/BulletTutorial.dir/src/graphics.cpp.o: ../src/graphics.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mari/CS480Kastanek/PA8/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/BulletTutorial.dir/src/graphics.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/BulletTutorial.dir/src/graphics.cpp.o -c /home/mari/CS480Kastanek/PA8/src/graphics.cpp

CMakeFiles/BulletTutorial.dir/src/graphics.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BulletTutorial.dir/src/graphics.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mari/CS480Kastanek/PA8/src/graphics.cpp > CMakeFiles/BulletTutorial.dir/src/graphics.cpp.i

CMakeFiles/BulletTutorial.dir/src/graphics.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BulletTutorial.dir/src/graphics.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mari/CS480Kastanek/PA8/src/graphics.cpp -o CMakeFiles/BulletTutorial.dir/src/graphics.cpp.s

CMakeFiles/BulletTutorial.dir/src/gui.cpp.o: CMakeFiles/BulletTutorial.dir/flags.make
CMakeFiles/BulletTutorial.dir/src/gui.cpp.o: ../src/gui.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mari/CS480Kastanek/PA8/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/BulletTutorial.dir/src/gui.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/BulletTutorial.dir/src/gui.cpp.o -c /home/mari/CS480Kastanek/PA8/src/gui.cpp

CMakeFiles/BulletTutorial.dir/src/gui.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BulletTutorial.dir/src/gui.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mari/CS480Kastanek/PA8/src/gui.cpp > CMakeFiles/BulletTutorial.dir/src/gui.cpp.i

CMakeFiles/BulletTutorial.dir/src/gui.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BulletTutorial.dir/src/gui.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mari/CS480Kastanek/PA8/src/gui.cpp -o CMakeFiles/BulletTutorial.dir/src/gui.cpp.s

CMakeFiles/BulletTutorial.dir/src/imgui.cpp.o: CMakeFiles/BulletTutorial.dir/flags.make
CMakeFiles/BulletTutorial.dir/src/imgui.cpp.o: ../src/imgui.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mari/CS480Kastanek/PA8/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/BulletTutorial.dir/src/imgui.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/BulletTutorial.dir/src/imgui.cpp.o -c /home/mari/CS480Kastanek/PA8/src/imgui.cpp

CMakeFiles/BulletTutorial.dir/src/imgui.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BulletTutorial.dir/src/imgui.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mari/CS480Kastanek/PA8/src/imgui.cpp > CMakeFiles/BulletTutorial.dir/src/imgui.cpp.i

CMakeFiles/BulletTutorial.dir/src/imgui.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BulletTutorial.dir/src/imgui.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mari/CS480Kastanek/PA8/src/imgui.cpp -o CMakeFiles/BulletTutorial.dir/src/imgui.cpp.s

CMakeFiles/BulletTutorial.dir/src/imgui_demo.cpp.o: CMakeFiles/BulletTutorial.dir/flags.make
CMakeFiles/BulletTutorial.dir/src/imgui_demo.cpp.o: ../src/imgui_demo.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mari/CS480Kastanek/PA8/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/BulletTutorial.dir/src/imgui_demo.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/BulletTutorial.dir/src/imgui_demo.cpp.o -c /home/mari/CS480Kastanek/PA8/src/imgui_demo.cpp

CMakeFiles/BulletTutorial.dir/src/imgui_demo.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BulletTutorial.dir/src/imgui_demo.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mari/CS480Kastanek/PA8/src/imgui_demo.cpp > CMakeFiles/BulletTutorial.dir/src/imgui_demo.cpp.i

CMakeFiles/BulletTutorial.dir/src/imgui_demo.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BulletTutorial.dir/src/imgui_demo.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mari/CS480Kastanek/PA8/src/imgui_demo.cpp -o CMakeFiles/BulletTutorial.dir/src/imgui_demo.cpp.s

CMakeFiles/BulletTutorial.dir/src/imgui_draw.cpp.o: CMakeFiles/BulletTutorial.dir/flags.make
CMakeFiles/BulletTutorial.dir/src/imgui_draw.cpp.o: ../src/imgui_draw.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mari/CS480Kastanek/PA8/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/BulletTutorial.dir/src/imgui_draw.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/BulletTutorial.dir/src/imgui_draw.cpp.o -c /home/mari/CS480Kastanek/PA8/src/imgui_draw.cpp

CMakeFiles/BulletTutorial.dir/src/imgui_draw.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BulletTutorial.dir/src/imgui_draw.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mari/CS480Kastanek/PA8/src/imgui_draw.cpp > CMakeFiles/BulletTutorial.dir/src/imgui_draw.cpp.i

CMakeFiles/BulletTutorial.dir/src/imgui_draw.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BulletTutorial.dir/src/imgui_draw.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mari/CS480Kastanek/PA8/src/imgui_draw.cpp -o CMakeFiles/BulletTutorial.dir/src/imgui_draw.cpp.s

CMakeFiles/BulletTutorial.dir/src/imgui_impl_opengl3.cpp.o: CMakeFiles/BulletTutorial.dir/flags.make
CMakeFiles/BulletTutorial.dir/src/imgui_impl_opengl3.cpp.o: ../src/imgui_impl_opengl3.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mari/CS480Kastanek/PA8/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/BulletTutorial.dir/src/imgui_impl_opengl3.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/BulletTutorial.dir/src/imgui_impl_opengl3.cpp.o -c /home/mari/CS480Kastanek/PA8/src/imgui_impl_opengl3.cpp

CMakeFiles/BulletTutorial.dir/src/imgui_impl_opengl3.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BulletTutorial.dir/src/imgui_impl_opengl3.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mari/CS480Kastanek/PA8/src/imgui_impl_opengl3.cpp > CMakeFiles/BulletTutorial.dir/src/imgui_impl_opengl3.cpp.i

CMakeFiles/BulletTutorial.dir/src/imgui_impl_opengl3.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BulletTutorial.dir/src/imgui_impl_opengl3.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mari/CS480Kastanek/PA8/src/imgui_impl_opengl3.cpp -o CMakeFiles/BulletTutorial.dir/src/imgui_impl_opengl3.cpp.s

CMakeFiles/BulletTutorial.dir/src/imgui_impl_sdl.cpp.o: CMakeFiles/BulletTutorial.dir/flags.make
CMakeFiles/BulletTutorial.dir/src/imgui_impl_sdl.cpp.o: ../src/imgui_impl_sdl.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mari/CS480Kastanek/PA8/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/BulletTutorial.dir/src/imgui_impl_sdl.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/BulletTutorial.dir/src/imgui_impl_sdl.cpp.o -c /home/mari/CS480Kastanek/PA8/src/imgui_impl_sdl.cpp

CMakeFiles/BulletTutorial.dir/src/imgui_impl_sdl.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BulletTutorial.dir/src/imgui_impl_sdl.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mari/CS480Kastanek/PA8/src/imgui_impl_sdl.cpp > CMakeFiles/BulletTutorial.dir/src/imgui_impl_sdl.cpp.i

CMakeFiles/BulletTutorial.dir/src/imgui_impl_sdl.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BulletTutorial.dir/src/imgui_impl_sdl.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mari/CS480Kastanek/PA8/src/imgui_impl_sdl.cpp -o CMakeFiles/BulletTutorial.dir/src/imgui_impl_sdl.cpp.s

CMakeFiles/BulletTutorial.dir/src/imgui_widgets.cpp.o: CMakeFiles/BulletTutorial.dir/flags.make
CMakeFiles/BulletTutorial.dir/src/imgui_widgets.cpp.o: ../src/imgui_widgets.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mari/CS480Kastanek/PA8/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object CMakeFiles/BulletTutorial.dir/src/imgui_widgets.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/BulletTutorial.dir/src/imgui_widgets.cpp.o -c /home/mari/CS480Kastanek/PA8/src/imgui_widgets.cpp

CMakeFiles/BulletTutorial.dir/src/imgui_widgets.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BulletTutorial.dir/src/imgui_widgets.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mari/CS480Kastanek/PA8/src/imgui_widgets.cpp > CMakeFiles/BulletTutorial.dir/src/imgui_widgets.cpp.i

CMakeFiles/BulletTutorial.dir/src/imgui_widgets.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BulletTutorial.dir/src/imgui_widgets.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mari/CS480Kastanek/PA8/src/imgui_widgets.cpp -o CMakeFiles/BulletTutorial.dir/src/imgui_widgets.cpp.s

CMakeFiles/BulletTutorial.dir/src/main.cpp.o: CMakeFiles/BulletTutorial.dir/flags.make
CMakeFiles/BulletTutorial.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mari/CS480Kastanek/PA8/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building CXX object CMakeFiles/BulletTutorial.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/BulletTutorial.dir/src/main.cpp.o -c /home/mari/CS480Kastanek/PA8/src/main.cpp

CMakeFiles/BulletTutorial.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BulletTutorial.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mari/CS480Kastanek/PA8/src/main.cpp > CMakeFiles/BulletTutorial.dir/src/main.cpp.i

CMakeFiles/BulletTutorial.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BulletTutorial.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mari/CS480Kastanek/PA8/src/main.cpp -o CMakeFiles/BulletTutorial.dir/src/main.cpp.s

CMakeFiles/BulletTutorial.dir/src/model.cpp.o: CMakeFiles/BulletTutorial.dir/flags.make
CMakeFiles/BulletTutorial.dir/src/model.cpp.o: ../src/model.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mari/CS480Kastanek/PA8/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Building CXX object CMakeFiles/BulletTutorial.dir/src/model.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/BulletTutorial.dir/src/model.cpp.o -c /home/mari/CS480Kastanek/PA8/src/model.cpp

CMakeFiles/BulletTutorial.dir/src/model.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BulletTutorial.dir/src/model.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mari/CS480Kastanek/PA8/src/model.cpp > CMakeFiles/BulletTutorial.dir/src/model.cpp.i

CMakeFiles/BulletTutorial.dir/src/model.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BulletTutorial.dir/src/model.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mari/CS480Kastanek/PA8/src/model.cpp -o CMakeFiles/BulletTutorial.dir/src/model.cpp.s

CMakeFiles/BulletTutorial.dir/src/object.cpp.o: CMakeFiles/BulletTutorial.dir/flags.make
CMakeFiles/BulletTutorial.dir/src/object.cpp.o: ../src/object.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mari/CS480Kastanek/PA8/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_17) "Building CXX object CMakeFiles/BulletTutorial.dir/src/object.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/BulletTutorial.dir/src/object.cpp.o -c /home/mari/CS480Kastanek/PA8/src/object.cpp

CMakeFiles/BulletTutorial.dir/src/object.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BulletTutorial.dir/src/object.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mari/CS480Kastanek/PA8/src/object.cpp > CMakeFiles/BulletTutorial.dir/src/object.cpp.i

CMakeFiles/BulletTutorial.dir/src/object.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BulletTutorial.dir/src/object.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mari/CS480Kastanek/PA8/src/object.cpp -o CMakeFiles/BulletTutorial.dir/src/object.cpp.s

CMakeFiles/BulletTutorial.dir/src/physics.cpp.o: CMakeFiles/BulletTutorial.dir/flags.make
CMakeFiles/BulletTutorial.dir/src/physics.cpp.o: ../src/physics.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mari/CS480Kastanek/PA8/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_18) "Building CXX object CMakeFiles/BulletTutorial.dir/src/physics.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/BulletTutorial.dir/src/physics.cpp.o -c /home/mari/CS480Kastanek/PA8/src/physics.cpp

CMakeFiles/BulletTutorial.dir/src/physics.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BulletTutorial.dir/src/physics.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mari/CS480Kastanek/PA8/src/physics.cpp > CMakeFiles/BulletTutorial.dir/src/physics.cpp.i

CMakeFiles/BulletTutorial.dir/src/physics.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BulletTutorial.dir/src/physics.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mari/CS480Kastanek/PA8/src/physics.cpp -o CMakeFiles/BulletTutorial.dir/src/physics.cpp.s

CMakeFiles/BulletTutorial.dir/src/physics_object.cpp.o: CMakeFiles/BulletTutorial.dir/flags.make
CMakeFiles/BulletTutorial.dir/src/physics_object.cpp.o: ../src/physics_object.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mari/CS480Kastanek/PA8/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_19) "Building CXX object CMakeFiles/BulletTutorial.dir/src/physics_object.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/BulletTutorial.dir/src/physics_object.cpp.o -c /home/mari/CS480Kastanek/PA8/src/physics_object.cpp

CMakeFiles/BulletTutorial.dir/src/physics_object.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BulletTutorial.dir/src/physics_object.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mari/CS480Kastanek/PA8/src/physics_object.cpp > CMakeFiles/BulletTutorial.dir/src/physics_object.cpp.i

CMakeFiles/BulletTutorial.dir/src/physics_object.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BulletTutorial.dir/src/physics_object.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mari/CS480Kastanek/PA8/src/physics_object.cpp -o CMakeFiles/BulletTutorial.dir/src/physics_object.cpp.s

CMakeFiles/BulletTutorial.dir/src/shader.cpp.o: CMakeFiles/BulletTutorial.dir/flags.make
CMakeFiles/BulletTutorial.dir/src/shader.cpp.o: ../src/shader.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mari/CS480Kastanek/PA8/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_20) "Building CXX object CMakeFiles/BulletTutorial.dir/src/shader.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/BulletTutorial.dir/src/shader.cpp.o -c /home/mari/CS480Kastanek/PA8/src/shader.cpp

CMakeFiles/BulletTutorial.dir/src/shader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BulletTutorial.dir/src/shader.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mari/CS480Kastanek/PA8/src/shader.cpp > CMakeFiles/BulletTutorial.dir/src/shader.cpp.i

CMakeFiles/BulletTutorial.dir/src/shader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BulletTutorial.dir/src/shader.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mari/CS480Kastanek/PA8/src/shader.cpp -o CMakeFiles/BulletTutorial.dir/src/shader.cpp.s

CMakeFiles/BulletTutorial.dir/src/texture.cpp.o: CMakeFiles/BulletTutorial.dir/flags.make
CMakeFiles/BulletTutorial.dir/src/texture.cpp.o: ../src/texture.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mari/CS480Kastanek/PA8/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_21) "Building CXX object CMakeFiles/BulletTutorial.dir/src/texture.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/BulletTutorial.dir/src/texture.cpp.o -c /home/mari/CS480Kastanek/PA8/src/texture.cpp

CMakeFiles/BulletTutorial.dir/src/texture.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BulletTutorial.dir/src/texture.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mari/CS480Kastanek/PA8/src/texture.cpp > CMakeFiles/BulletTutorial.dir/src/texture.cpp.i

CMakeFiles/BulletTutorial.dir/src/texture.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BulletTutorial.dir/src/texture.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mari/CS480Kastanek/PA8/src/texture.cpp -o CMakeFiles/BulletTutorial.dir/src/texture.cpp.s

CMakeFiles/BulletTutorial.dir/src/window.cpp.o: CMakeFiles/BulletTutorial.dir/flags.make
CMakeFiles/BulletTutorial.dir/src/window.cpp.o: ../src/window.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mari/CS480Kastanek/PA8/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_22) "Building CXX object CMakeFiles/BulletTutorial.dir/src/window.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/BulletTutorial.dir/src/window.cpp.o -c /home/mari/CS480Kastanek/PA8/src/window.cpp

CMakeFiles/BulletTutorial.dir/src/window.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BulletTutorial.dir/src/window.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mari/CS480Kastanek/PA8/src/window.cpp > CMakeFiles/BulletTutorial.dir/src/window.cpp.i

CMakeFiles/BulletTutorial.dir/src/window.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BulletTutorial.dir/src/window.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mari/CS480Kastanek/PA8/src/window.cpp -o CMakeFiles/BulletTutorial.dir/src/window.cpp.s

CMakeFiles/BulletTutorial.dir/src/world.cpp.o: CMakeFiles/BulletTutorial.dir/flags.make
CMakeFiles/BulletTutorial.dir/src/world.cpp.o: ../src/world.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mari/CS480Kastanek/PA8/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_23) "Building CXX object CMakeFiles/BulletTutorial.dir/src/world.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/BulletTutorial.dir/src/world.cpp.o -c /home/mari/CS480Kastanek/PA8/src/world.cpp

CMakeFiles/BulletTutorial.dir/src/world.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BulletTutorial.dir/src/world.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mari/CS480Kastanek/PA8/src/world.cpp > CMakeFiles/BulletTutorial.dir/src/world.cpp.i

CMakeFiles/BulletTutorial.dir/src/world.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BulletTutorial.dir/src/world.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mari/CS480Kastanek/PA8/src/world.cpp -o CMakeFiles/BulletTutorial.dir/src/world.cpp.s

# Object files for target BulletTutorial
BulletTutorial_OBJECTS = \
"CMakeFiles/BulletTutorial.dir/src/ball.cpp.o" \
"CMakeFiles/BulletTutorial.dir/src/board.cpp.o" \
"CMakeFiles/BulletTutorial.dir/src/camera.cpp.o" \
"CMakeFiles/BulletTutorial.dir/src/cylinder.cpp.o" \
"CMakeFiles/BulletTutorial.dir/src/engine.cpp.o" \
"CMakeFiles/BulletTutorial.dir/src/flipper.cpp.o" \
"CMakeFiles/BulletTutorial.dir/src/graphics.cpp.o" \
"CMakeFiles/BulletTutorial.dir/src/gui.cpp.o" \
"CMakeFiles/BulletTutorial.dir/src/imgui.cpp.o" \
"CMakeFiles/BulletTutorial.dir/src/imgui_demo.cpp.o" \
"CMakeFiles/BulletTutorial.dir/src/imgui_draw.cpp.o" \
"CMakeFiles/BulletTutorial.dir/src/imgui_impl_opengl3.cpp.o" \
"CMakeFiles/BulletTutorial.dir/src/imgui_impl_sdl.cpp.o" \
"CMakeFiles/BulletTutorial.dir/src/imgui_widgets.cpp.o" \
"CMakeFiles/BulletTutorial.dir/src/main.cpp.o" \
"CMakeFiles/BulletTutorial.dir/src/model.cpp.o" \
"CMakeFiles/BulletTutorial.dir/src/object.cpp.o" \
"CMakeFiles/BulletTutorial.dir/src/physics.cpp.o" \
"CMakeFiles/BulletTutorial.dir/src/physics_object.cpp.o" \
"CMakeFiles/BulletTutorial.dir/src/shader.cpp.o" \
"CMakeFiles/BulletTutorial.dir/src/texture.cpp.o" \
"CMakeFiles/BulletTutorial.dir/src/window.cpp.o" \
"CMakeFiles/BulletTutorial.dir/src/world.cpp.o"

# External object files for target BulletTutorial
BulletTutorial_EXTERNAL_OBJECTS =

BulletTutorial: CMakeFiles/BulletTutorial.dir/src/ball.cpp.o
BulletTutorial: CMakeFiles/BulletTutorial.dir/src/board.cpp.o
BulletTutorial: CMakeFiles/BulletTutorial.dir/src/camera.cpp.o
BulletTutorial: CMakeFiles/BulletTutorial.dir/src/cylinder.cpp.o
BulletTutorial: CMakeFiles/BulletTutorial.dir/src/engine.cpp.o
BulletTutorial: CMakeFiles/BulletTutorial.dir/src/flipper.cpp.o
BulletTutorial: CMakeFiles/BulletTutorial.dir/src/graphics.cpp.o
BulletTutorial: CMakeFiles/BulletTutorial.dir/src/gui.cpp.o
BulletTutorial: CMakeFiles/BulletTutorial.dir/src/imgui.cpp.o
BulletTutorial: CMakeFiles/BulletTutorial.dir/src/imgui_demo.cpp.o
BulletTutorial: CMakeFiles/BulletTutorial.dir/src/imgui_draw.cpp.o
BulletTutorial: CMakeFiles/BulletTutorial.dir/src/imgui_impl_opengl3.cpp.o
BulletTutorial: CMakeFiles/BulletTutorial.dir/src/imgui_impl_sdl.cpp.o
BulletTutorial: CMakeFiles/BulletTutorial.dir/src/imgui_widgets.cpp.o
BulletTutorial: CMakeFiles/BulletTutorial.dir/src/main.cpp.o
BulletTutorial: CMakeFiles/BulletTutorial.dir/src/model.cpp.o
BulletTutorial: CMakeFiles/BulletTutorial.dir/src/object.cpp.o
BulletTutorial: CMakeFiles/BulletTutorial.dir/src/physics.cpp.o
BulletTutorial: CMakeFiles/BulletTutorial.dir/src/physics_object.cpp.o
BulletTutorial: CMakeFiles/BulletTutorial.dir/src/shader.cpp.o
BulletTutorial: CMakeFiles/BulletTutorial.dir/src/texture.cpp.o
BulletTutorial: CMakeFiles/BulletTutorial.dir/src/window.cpp.o
BulletTutorial: CMakeFiles/BulletTutorial.dir/src/world.cpp.o
BulletTutorial: CMakeFiles/BulletTutorial.dir/build.make
BulletTutorial: /usr/lib/x86_64-linux-gnu/libGLEW.so
BulletTutorial: /usr/lib/x86_64-linux-gnu/libassimp.so
BulletTutorial: /usr/local/lib/libMagick++-7.Q16HDRI.so
BulletTutorial: /usr/lib/x86_64-linux-gnu/libGL.so
BulletTutorial: /usr/lib/x86_64-linux-gnu/libGLU.so
BulletTutorial: /usr/lib/x86_64-linux-gnu/libSDL2main.a
BulletTutorial: /usr/lib/x86_64-linux-gnu/libSDL2.so
BulletTutorial: /usr/local/lib/libMagick++-7.Q16HDRI.so
BulletTutorial: /usr/lib/x86_64-linux-gnu/libBulletDynamics.so
BulletTutorial: /usr/lib/x86_64-linux-gnu/libBulletCollision.so
BulletTutorial: /usr/lib/x86_64-linux-gnu/libLinearMath.so
BulletTutorial: /usr/lib/x86_64-linux-gnu/libBulletSoftBody.so
BulletTutorial: /usr/lib/x86_64-linux-gnu/libGL.so
BulletTutorial: /usr/lib/x86_64-linux-gnu/libGLU.so
BulletTutorial: /usr/lib/x86_64-linux-gnu/libSDL2main.a
BulletTutorial: /usr/lib/x86_64-linux-gnu/libSDL2.so
BulletTutorial: /usr/lib/x86_64-linux-gnu/libBulletDynamics.so
BulletTutorial: /usr/lib/x86_64-linux-gnu/libBulletCollision.so
BulletTutorial: /usr/lib/x86_64-linux-gnu/libLinearMath.so
BulletTutorial: /usr/lib/x86_64-linux-gnu/libBulletSoftBody.so
BulletTutorial: CMakeFiles/BulletTutorial.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/mari/CS480Kastanek/PA8/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_24) "Linking CXX executable BulletTutorial"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/BulletTutorial.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/BulletTutorial.dir/build: BulletTutorial

.PHONY : CMakeFiles/BulletTutorial.dir/build

CMakeFiles/BulletTutorial.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/BulletTutorial.dir/cmake_clean.cmake
.PHONY : CMakeFiles/BulletTutorial.dir/clean

CMakeFiles/BulletTutorial.dir/depend:
	cd /home/mari/CS480Kastanek/PA8/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mari/CS480Kastanek/PA8 /home/mari/CS480Kastanek/PA8 /home/mari/CS480Kastanek/PA8/cmake-build-debug /home/mari/CS480Kastanek/PA8/cmake-build-debug /home/mari/CS480Kastanek/PA8/cmake-build-debug/CMakeFiles/BulletTutorial.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/BulletTutorial.dir/depend


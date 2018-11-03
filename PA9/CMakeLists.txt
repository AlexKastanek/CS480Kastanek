cmake_minimum_required(VERSION 3.12)
project(PA9)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(PA9
        include/ball.h
        include/board.h
        include/camera.h
        include/cylinder.h
        include/engine.h
        include/flipper.h
        include/graphics.h
        include/graphics_headers.h
        include/gui.h
        include/imconfig.h
        include/imgui.h
        include/imgui_impl_opengl3.h
        include/imgui_impl_sdl.h
        include/imgui_internal.h
        include/imstb_rectpack.h
        include/imstb_textedit.h
        include/imstb_truetype.h
        include/model.h
        include/object.h
        include/physics.h
        include/physics_object.h
        include/shader.h
        include/texture.h
        include/window.h
        include/world.h
        src/ball.cpp
        src/board.cpp
        src/camera.cpp
        src/cylinder.cpp
        src/engine.cpp
        src/flipper.cpp
        src/graphics.cpp
        src/gui.cpp
        src/imgui.cpp
        src/imgui_demo.cpp
        src/imgui_draw.cpp
        src/imgui_impl_opengl3.cpp
        src/imgui_impl_sdl.cpp
        src/imgui_widgets.cpp
        src/main.cpp
        src/model.cpp
        src/object.cpp
        src/physics.cpp
        src/physics_object.cpp
        src/shader.cpp
        src/texture.cpp
        src/window.cpp
        src/world.cpp)

cmake_minimum_required(VERSION 3.12)
project(PA6)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(PA6
        assets/board.mtl
        assets/board.obj
        assets/dragon.obj
        include/camera.h
        include/engine.h
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
        include/moon.h
        include/object.h
        include/planet.h
        include/shader.h
        include/window.h
        src/camera.cpp
        src/engine.cpp
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
        src/moon.cpp
        src/object.cpp
        src/planet.cpp
        src/shader.cpp
        src/window.cpp
        README.md src/Texture.cpp include/Texture.h)

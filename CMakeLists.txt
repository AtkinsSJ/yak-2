cmake_minimum_required(VERSION 3.16)

project(yak CXX)
include_directories(${PROJECT_SOURCE_DIR}/src)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake/sdl2)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)

set(SOURCE_FILES
        src/main.cpp
        src/Entity.cpp
        src/Game.cpp
        src/MenuScene.cpp
        src/Scene.cpp
        src/Graphics/Renderer.cpp
        src/Graphics/Text.cpp
        src/Graphics/Texture.cpp
        )

add_executable(yak ${SOURCE_FILES})
target_link_libraries(yak SDL2::Main SDL2::Image SDL2::TTF)

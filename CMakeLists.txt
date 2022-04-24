cmake_minimum_required(VERSION 3.16)
project(yak CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories(${PROJECT_SOURCE_DIR}/src)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake/sdl2)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)

set(CMAKE_SKIP_BUILD_RPATH FALSE)
set(CMAKE_BUILD_WITH_INSTALL_RPATH FALSE)
# See slide 100 of the following ppt :^)
# https://crascit.com/wp-content/uploads/2019/09/Deep-CMake-For-Library-Authors-Craig-Scott-CppCon-2019.pdf
if (NOT APPLE)
    set(CMAKE_INSTALL_RPATH $ORIGIN)
endif ()
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)

add_compile_options(-Wall)
add_compile_options(-Wextra)
add_compile_options(-Wno-address-of-packed-member)
add_compile_options(-Wcast-align)
add_compile_options(-Wcast-qual)
add_compile_options(-Wno-deprecated-copy)
add_compile_options(-Wduplicated-cond)
add_compile_options(-Wno-expansion-to-defined)
add_compile_options(-Wformat=2)
add_compile_options(-Wimplicit-fallthrough)
add_compile_options(-Wno-literal-suffix)
add_compile_options(-Wlogical-op)
add_compile_options(-Wmisleading-indentation)
add_compile_options(-Wmissing-declarations)
add_compile_options(-Wno-nonnull-compare)
add_compile_options(-Wnon-virtual-dtor)
add_compile_options(-Wno-unknown-warning-option)
add_compile_options(-Wundef)
add_compile_options(-Wunused)
add_compile_options(-Wno-user-defined-literals)
add_compile_options(-Wwrite-strings)
add_compile_options(-fno-exceptions)

# Lagom!
# FIXME: It would be nicer to use AK's move() and forward() but I couldn't figure out how to disable the stdlib's ones
#        without also disabling headers that are needed by AK. (`#include <new>` in particular)
add_compile_definitions(AK_DONT_REPLACE_STD=1)
include(FetchContent)
include(cmake/FetchLagom.cmake)

set(SOURCE_FILES
        src/main.cpp
        src/Entity.cpp
        src/MenuScene.cpp
        src/YakPunk/Assets.cpp
        src/YakPunk/Game.cpp
        src/YakPunk/Graphics/Font.cpp
        src/YakPunk/Graphics/Text.cpp
        src/YakPunk/Graphics/Texture.cpp
        src/YakPunk/Scene.cpp
        )

add_executable(yak ${SOURCE_FILES})
target_link_libraries(yak SDL2::Main SDL2::Image SDL2::TTF Lagom::Core Lagom::Main)

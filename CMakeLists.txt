cmake_minimum_required(VERSION 3.16)

project(yak CXX)
include_directories(${PROJECT_SOURCE_DIR}/src)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS})

add_executable(yak src/main.cpp)
target_link_libraries(yak ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})

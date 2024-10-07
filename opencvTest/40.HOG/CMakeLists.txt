cmake_minimum_required(VERSION 3.10)
project(HOG)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(HOG main.cpp)
target_link_libraries(HOG ${OpenCV_LIBS})

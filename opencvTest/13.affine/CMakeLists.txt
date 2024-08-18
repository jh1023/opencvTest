cmake_minimum_required(VERSION 3.10)
project(affine)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(affine main.cpp)
target_link_libraries(affine ${OpenCV_LIBS})

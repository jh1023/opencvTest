cmake_minimum_required(VERSION 3.10)
project(Movementconversion)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(Movementconversion main.cpp)
target_link_libraries(Movementconversion ${OpenCV_LIBS})

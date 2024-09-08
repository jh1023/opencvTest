cmake_minimum_required(VERSION 3.10)
project(OTSU)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(OTSU main.cpp)
target_link_libraries(OTSU ${OpenCV_LIBS})

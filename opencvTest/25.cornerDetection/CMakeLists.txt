cmake_minimum_required(VERSION 3.10)
project(cornerDetection)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(cornerDetection main.cpp)
target_link_libraries(cornerDetection ${OpenCV_LIBS})

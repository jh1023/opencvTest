cmake_minimum_required(VERSION 3.10)
project(BilinearInterpolation)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(BilinearInterpolation main.cpp)
target_link_libraries(BilinearInterpolation ${OpenCV_LIBS})

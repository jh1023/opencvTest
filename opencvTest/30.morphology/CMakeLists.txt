cmake_minimum_required(VERSION 3.10)
project(morphology)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(morphology main.cpp)
target_link_libraries(morphology ${OpenCV_LIBS})

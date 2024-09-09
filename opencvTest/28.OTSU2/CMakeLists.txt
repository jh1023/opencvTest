cmake_minimum_required(VERSION 3.10)
project(OTSU2)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(OTSU2 main.cpp)
target_link_libraries(OTSU2 ${OpenCV_LIBS})

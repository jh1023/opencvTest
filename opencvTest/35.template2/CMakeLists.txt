cmake_minimum_required(VERSION 3.10)
project(template2)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(template2 main.cpp)
target_link_libraries(template2 ${OpenCV_LIBS})

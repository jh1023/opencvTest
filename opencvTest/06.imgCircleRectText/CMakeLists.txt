#이미지 원,사각형,텍스트 넣기
cmake_minimum_required(VERSION 3.10)
project(imgCircleRectText)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(imgCircleRectText main.cpp)
target_link_libraries(imgCircleRectText ${OpenCV_LIBS})

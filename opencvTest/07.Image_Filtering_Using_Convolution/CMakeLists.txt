#OpenCV에서 컨볼루션을 사용한 이미지 필터링
cmake_minimum_required(VERSION 3.10)
project(imgFilterConv)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(imgFilterConv main.cpp)
target_link_libraries(imgFilterConv ${OpenCV_LIBS})

cmake_minimum_required(VERSION 3.16)
project(sobel)

set(CMAKE_CXX_STANDARD 14)
find_package(OpenCV REQUIRED)

add_executable(sobel main.cpp sobel.cpp)
target_link_libraries(sobel ${OpenCV_LIBS})

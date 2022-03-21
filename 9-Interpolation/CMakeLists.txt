cmake_minimum_required(VERSION 3.16)
project(interpolation)

set(CMAKE_CXX_STANDARD 14)
find_package(OpenCV REQUIRED)

add_executable(interpolation main.cpp interpolation.cpp)
target_link_libraries(interpolation ${OpenCV_LIBS})

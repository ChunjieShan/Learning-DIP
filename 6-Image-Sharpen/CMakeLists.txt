cmake_minimum_required(VERSION 3.16)
project(sharpen)

set(CMAKE_CXX_STANDARD 14)
find_package(OpenCV REQUIRED)

add_executable(sharpen main.cpp sharpen.cpp)
target_link_libraries(sharpen ${OpenCV_LIBS})

cmake_minimum_required(VERSION 3.16)
project(equal_hist)

set(CMAKE_CXX_STANDARD 14)
find_package(OpenCV REQUIRED)

add_executable(equal_hist main.cpp equal_hist.cpp histogram.cpp)
target_link_libraries(equal_hist ${OpenCV_LIBS})

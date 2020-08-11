cmake_minimum_required(VERSION 3.18.1)
project(adaptive-cruise-control)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES src/main.cc src/pid.cc src/vehicle.cc src/acc.cc)
add_executable(ACC ${SOURCE_FILES})
target_include_directories(ACC PRIVATE include)

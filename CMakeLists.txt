cmake_minimum_required(VERSION 3.10)

project(dpcpp)

set(CMAKE_CXX_STANDARD 14)

find_package(Boost REQUIRED)
include_directories(${Boost_INCLUDE_DIR})

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/catch2)
add_subdirectory(src)

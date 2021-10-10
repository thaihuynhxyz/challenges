cmake_minimum_required(VERSION 3.16)
project(hacker_rank)

set(CMAKE_CXX_STANDARD 14)

include_directories(${CMAKE_INCLUDE_PATH} include)

add_subdirectory(src/hacker_rank)
add_subdirectory(src/leet_code)
add_subdirectory(src/codility)
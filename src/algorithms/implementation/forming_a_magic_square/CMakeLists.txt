cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 14)

install(DIRECTORY "." # source directory
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR} # target directory
        FILES_MATCHING # install only matched files
        PATTERN "*.txt" # select header files
        )

add_executable(forming_a_magic_square main.cpp)
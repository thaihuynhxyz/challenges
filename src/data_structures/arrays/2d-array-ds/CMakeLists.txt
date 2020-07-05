cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 14)

add_executable(2d_array_ds main.cpp)

#install(FILES tensor.hpp numeric/numeric.hpp array.hpp data/ndarray.hpp signal/iir.cpp extension/array_ext.hpp DESTINATION ${ETENSOR_INSTALL_INCLUDE_DIR})
install(DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/" # source directory
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR} # target directory
        FILES_MATCHING # install only matched files
        PATTERN "*.txt" # select header files
        )
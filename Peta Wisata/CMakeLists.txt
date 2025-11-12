cmake_minimum_required(VERSION 3.10)

project(PETA_WISATA LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


add_executable(PETA_WISATA
    src/main.cpp
    src/djikstraAlgorithm.cpp
    src/mergeSort.cpp
    src/gotoXY.cpp
)

target_include_directories(PETA_WISATA PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)
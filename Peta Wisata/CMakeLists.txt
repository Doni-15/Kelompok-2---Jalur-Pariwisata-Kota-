cmake_minimum_required(VERSION 3.10)

project(PETA_WISATA)


add_executable(PETA_WISATA
    src/main.cpp
    src/djikstraAlgorithm.cpp
    src/loadGraph.cpp
    src/mergeSort.cpp
)

target_include_directories(PETA_WISATA PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)
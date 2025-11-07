cmake_minimum_required(VERSION 3.10)

project(PETA_WISATA)

file(GLOB_RECURSE SOURCES "src/*.cpp")
add_executable(PETA_WISATA ${SOURCES})

target_include_directories(PETA_WISATA PUBLIC "src")
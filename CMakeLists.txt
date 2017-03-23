cmake_minimum_required(VERSION 3.6)
project(TugasBesarSTD)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp document.h document.cpp tags.cpp tags.h)
add_executable(TugasBesarSTD ${SOURCE_FILES})
cmake_minimum_required(VERSION 3.14)
project(Image)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wconversion -Wextra -pedantic")

add_executable(Image main.cpp GraphFromImage.cpp GraphFromImage.h ParcoursEnProfondeur.h)
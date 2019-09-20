cmake_minimum_required(VERSION 3.14)
project(Actor)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wconversion -Wextra -pedantic")

add_executable(Actor main.cpp GraphUsingAdjacencyLists.cpp GraphUsingAdjacencyLists.h SymbolGraph.h Util.cpp Util.h)
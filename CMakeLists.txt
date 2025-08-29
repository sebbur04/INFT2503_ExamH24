cmake_minimum_required(VERSION 3.10) #Obligatorisk med Cmake versjon 3, ikke 4
project(Oblig1)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -Wall -Wextra") #Obligatorisk i emnet og ha følgende advarseltegn

add_executable(oppA Oblig1/oblig1a.cpp)
add_executable(oppB Oblig1/oblig1b.cpp)
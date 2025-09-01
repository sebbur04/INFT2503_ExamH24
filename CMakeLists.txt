cmake_minimum_required(VERSION 3.10) #Obligatorisk med Cmake versjon 3, ikke 4
project(Oblig2)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -Wall -Wextra") #Obligatorisk i emnet og ha følgende advarseltegn

add_executable(opp1 Oblig2/opp1.cpp)
add_executable(opp4 Oblig2/opp4.cpp)
add_executable(opp5 Oblig2/opp5.cpp)
add_executable(opp6 Oblig2/opp6.cpp)
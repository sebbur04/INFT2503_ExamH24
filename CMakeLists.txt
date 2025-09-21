cmake_minimum_required(VERSION 3.10) #Obligatorisk med Cmake versjon 3, ikke 4
project(Oblig3)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -Wall -Wextra") #Obligatorisk i emnet og ha følgende advarseltegn

add_executable(opp1 Oblig3/opp1.cpp)
add_executable(opp2 Oblig3/opp2.cpp)
add_executable(opp3 Oblig3/opp3.cpp)
add_executable(opp4 Oblig3/opp4.cpp)

cmake_minimum_required(VERSION 3.10) #Obligatorisk med Cmake versjon 3, ikke 4
project(Oblig8)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -Wall -Wextra") #Obligatorisk i emnet og ha følgende advarseltegn

add_executable(opp5 Oblig8/opp5.cpp)
add_executable(opp6 Oblig8/opp6.cpp)
add_executable(opp7 Oblig8/opp7.cpp)
add_executable(opp8 Oblig8/opp8.cpp)
add_executable(opp9 Oblig8/opp9.cpp)



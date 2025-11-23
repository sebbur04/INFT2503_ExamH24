cmake_minimum_required(VERSION 3.10) #Obligatorisk med Cmake versjon 3, ikke 4
project(ExamH24)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -Wall -Wextra") #Obligatorisk i emnet og ha følgende advarseltegn

add_executable(opp5 ExamH24/opp5.cpp)
add_executable(opp6 ExamH24/opp6.cpp)
add_executable(opp7 ExamH24/opp7.cpp)
add_executable(opp8 ExamH24/opp8.cpp)
add_executable(opp9 ExamH24/opp9.cpp)



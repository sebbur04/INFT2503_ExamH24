//
// Created by sebas on 30/10/2025.
//

#include <iostream>
using namespace std;

// Lager en template med to typer: T1 og T2
template <typename T1, typename T2>
class Pair {
public:
    T1 first;
    T2 second;

    Pair(const T1& a, const T2& b) : first(a), second(b) {}

    // Forenkler ved å bruke operator overloading fra OBLIG7 med addisjon og større enn operatorer på mine klasser
    // Returnerer et nytt Pair som er summen av to Pair-objekter
    Pair operator+(const Pair& other) const {
        return Pair(first + other.first, second + other.second);
    }

    // Sammenligner summen av verdiene i to Pair-objekter
    bool operator>(const Pair& other) const {
        return (first + second) > (other.first + other.second);
    }
};

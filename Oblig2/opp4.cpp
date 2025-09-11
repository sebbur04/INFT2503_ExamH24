//
// Created by Sebastian E Burmo on 21/08/2025.


#include <iostream>
#include <fstream>
using namespace std;

int main() {
    int a = 5;
    int &b = a; //Kan ikke ha en referanse uten at den referer til en ting.
    int *c;
    c = &b;
    a = b + *c; // a og b er ikke pointers, kan ikke definere en ting som ikke er en pointer
    b = 2; //&b peker til addressen til variablen, siden den er en konstant er den ikke modifierbar

    return 0;
}

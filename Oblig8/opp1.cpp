//
// Created on 30/10/2025.

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// Lager en template med typename T
template <typename T>

//funksjonstemplate som finner ut om to verdier er like
bool equal(T a, T b) {
    cout << "Generic" << endl;
    return a == b;
}

// Funksjonen skal kunne brukes for beregnede desimaltallsverdie
bool equal(double a, double b) {
    // Toleranse for sammenligning av desimaltall er mindre enn 0.00001
    double TOL = 0.00001;
    cout << "Specialized: ";
    cout << fixed << setprecision(6); // Viser 6 desimaler
    cout << " a: " << a << " b: " << b << endl;
    return abs(a - b) < TOL;
}

// Program som prøver både template-utgaven og spesialutgaven
int main() {
    cout << "Denne vil resultere i 1 , da begge stringene er like (c++ og c++)" << endl;
    cout << "String:" << equal(string("c++"), string("c++")) << endl;
    cout << "------------------------------------------------------" << endl;


    cout << "Denne vil resultere i 0 , da begge stringene er ulike (c++ og c--)" << endl;
    cout << "String:" << equal(string("c++"), string("c--")) << endl;
    cout << "------------------------------------------------------" << endl;


    cout << "Denne vil resultere i 0 , da begge integrene er ulike (1 og 2)" << endl;
    cout << "Integer:" << equal(1, 2) << endl;
    cout << "------------------------------------------------------" << endl;


    cout << "Denne vil resultere i 1 , da begge integrene er like (10 og 10)" << endl;
    cout << "Integer:" << equal(10, 10) << endl;
    cout << "------------------------------------------------------" << endl;


    cout << "Denne vil resultere i 1 , da begge desimaltallene er innenfor toleranse " << endl;
    cout << "Double: " << equal(0.5123456, 0.5123456) << endl;
    cout << "------------------------------------------------------" << endl;


    cout << "Denne vil resultere i 0 , da begge desimaltallene er utenfor toleranse " << endl;
    cout << "Double:" << equal(0.5122456, 0.5123456) << endl;
    return 0;
}
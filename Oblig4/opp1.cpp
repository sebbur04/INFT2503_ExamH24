//
// Created by Sebastian E Burmo on 25/09/2025
// Oppgave 1 - Vektor operasjoner


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    cout << "Oppgave 1" << endl;
    // Creata a vector with double with 5 default values in the vector
    vector<double> vec{1,2,3,4,5};

    // Use front() and back() to print the first and last element in the vector
    cout << "Første element: " << vec.front() << endl;
    cout << "Siste element: " << vec.back() << endl;

    vec.emplace(vec.begin() , 6); // Change value from  1 to 6 for the first value in the vector

    cout << "Etter emplace, første element: " << vec.front() << endl; //Print the first value aftr emplace change of the vector

    // Searched for value 2 in the vector and print it if found, error if not
    double value = 4; //Added a hardcoded entry for which value I would like to find
    auto it = find(vec.begin(), vec.end(), value);
    if (it != vec.end()) {
        cout << "Fant verdi: " << *it << endl;
    } else {
        cout << "Fant ikke verdien: " << value << endl;
    }
}

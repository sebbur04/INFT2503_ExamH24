//
// Created by Sebastian E Burmo on 25/09/2025
// Oppgave 1 - Vektor operasjoner


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    cout << "Oppgave 1" << endl;

    vector<int> vec{1,2, 3, 4, 5};

    cout << "Første element: " << vec.front() << endl;
    cout << "Siste element: " << vec.back() << endl;

    vec.emplace(vec.begin() + 1, 6);

    cout << "Etter emplace, første element: " << vec.front() << endl;

    auto it = find(vec.begin(), vec.end(), 6.6);
    if (it != vec.end()) {
        cout << "Fant verdi: " << *it << endl;
    }

    return 0;
}

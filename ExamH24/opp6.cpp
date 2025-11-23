//Oppgave 6 (10% Løsning)

#include <iostream>

using namespace std;

class Fahrenheit {
public:
    static double to_kelvin(double value) {
        return (value - 32) / 1.8 + 273.15;
    }
};

class Celsius {
public:
    static double to_kelvin(double value) {
        return value + 273.15;
    }
};

class Kelvin {
public:
    static double to_kelvin(double value) {
        // LF boks 1
        return value; // Kelvin til Kelvin er ingen endring
    }
};

template<typename T> // LF Boks 2
class Temperature {
public:
    double kelvin;

    Temperature(double value) {
        kelvin = T::to_kelvin(value); // LF Boks 3
    }

    friend ostream& operator<<(ostream& os, const Temperature<T>& temperature) {
        os << temperature.kelvin << " K (kelvins)"; // LF Boks 4: denne delen (temperature.kelvin)
        return os;
    }
};

int main() {
    cout << Temperature<Fahrenheit>(10.4) << endl;
    cout << Temperature<Celsius>(10.4) << endl;
    cout << Temperature<Kelvin>(10.4) << endl;

    return 0;
}
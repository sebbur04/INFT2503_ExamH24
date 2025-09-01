//
// Created by Sebastian E Burmo on 21/08/2025.


#include <iostream>
#include <fstream>
using namespace std;

// Funksjonsdeklarasjon MÅ være utenfor main()
void read_temperatures(double temperatures[], int length);

int main() {

    cout << "---------------------------------------" << endl;
    cout << "Oppgave B - Med filinnlesing av temperaturer " << endl;

    //Må lage intervall som jeg kan bruke for å telle opp antall
    const int length = 5;
    int tempunder_10 = 0;
    int tempbetween_10_and_20 = 0;
    int tempover_20 = 0;
    double temperatures[length];

    read_temperatures(temperatures, length);

    for (int i = 0; i < length; i++) // Bruker "length" ikke "lenght"
    {
        cout << "Temperatur nr " << i + 1 << ": " << temperatures[i] << endl;

        //Gjenbruke fra oppgave A, men endre til temperatures[i]
        if (temperatures[i] < 10) //Temperatur under 10
            tempunder_10++;

        else if (temperatures[i] >= 10 && temperatures[i] <= 20) // Temperatur mellom 10 og 20
            tempbetween_10_and_20++;

        else
            tempover_20++; //Hvis ingen av tilfellene over stemmer er temperaturen over 20
    }

    //Utskrift på likt format som oppgaven
    cout << "Antall under 10 er " << tempunder_10 << endl;
    cout << "Antall mellom 10 og 20 er " << tempbetween_10_and_20 << endl;
    cout << "Antall over 20 er " << tempover_20 << endl;

    return 0;
}

// Her plasserer du koden i funksjonen, vi sier at vi definerer funksjonen
void read_temperatures(double temperatures[], int length) {
    ifstream file("/Users/sebastian.burmo/Movies/temperatures.txt"); //Relativ path til filen som skal leses inn

    if (!file.is_open()) {
        cerr << "Error opening temperatures.txt" << endl;
        exit(1);
    }

    for (int i = 0; i < length; i++) {
        double temperature;
        file >> temperature;
        temperatures[i] = temperature;
    }

    file.close();
}
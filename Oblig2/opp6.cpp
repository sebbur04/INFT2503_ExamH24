#include <iostream>
using namespace std;

// Finner summen av elementene i en tabell
int find_sum(const int *table, int length) {
    int sum = 0;
    // Her går man i gjennom alle elementene og summerer dem
    for (int i = 0; i < length; i++) {
        sum += *(table + i);
    }
    return sum;
}

int main() {
    const int table_length = 20; // Antall elementer i tabellen
    int table[table_length]; // Oppretter tabellen

    // Fyller tabellen med tallene 1 til 20
    for (int i = 0; i < table_length; i++) {
        table[i] = i + 1;
    }

    cout << "Summen av de 10 første: " << find_sum(table, 10) << endl;
    cout << "Summen av de 5 neste: " << find_sum(&table[10], 5) << endl;
    cout << "Summen av de 5 siste: " << find_sum(table + 15, 5) << endl;

    return 0;
}

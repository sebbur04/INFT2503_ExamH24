//
// Created by Sebastian E Burmo on 01/09/2025.
//

#include <iostream>
#include <array>
#include <vector>
using namespace std;

int main() {
    // Lage en tabell
    {
        const int table_length = 20;
        int table[table_length];

        for (int i = 0; i < table_length; i++)
        {
            // *(table + i) = i + 1;
            table[i] = i + 1;
        }

        cout << "Sum 10 første: " << find_sum(table, 10) << endl;
        cout << "Sum 5 neste: " << find_sum(&table[10], 5) << endl;
        cout << "Sum 5 siste: " << find_sum(table + 15, 5) << endl;

        return 0;
    }
        int find_sum(const int *table, int length)
    {
        int sum = 0;
        for (int i = 0; i < length; i++) {
            sum+= *(table + i);

            return sum;
        }
    }
}
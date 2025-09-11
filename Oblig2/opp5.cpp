//
// Created by Sebastian E Burmo on 01/09/2025.
//
#include <iostream>
int main() {

        std::cout << "Oppgave 5" << std::endl;
        std::cout << "----------------" << std::endl;
        double number;
        double *p = &number; //Definerer peker som peker på number
        double &ref = number;  //Definerer referanse som refererer til number

        // Vis tre måter å få tilordnet verdi til number på.

        //A - Definerer number direkte
        number = 5;
        std::cout << number << std::endl;

       // B - Bruker pekeren til å endre verdien til number
        *p = 2.0;
        std::cout << number << std::endl;

        // C - Bruker referansen til å endre verdien til number
        ref = 150.0;
        std::cout << number << std::endl;

        return 0;
}

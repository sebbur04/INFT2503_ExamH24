//Oppgave 1
#include <iostream>

using namespace std;

// Oppgave 1 - DEL A
int main()
{
    //Kopierer følgende verdier fra øvingen
    int i = 3;
    int j = 5;
    int *p = &i; //pekeren P peker på adressen til i
    int *q = &j; //pekeren q peker på adressen til j

    cout << "i: Addresse: " << &i << " Innholder følgende verdi: " << i << endl; //Addressen peker til verdien 3 i i
    cout << "j: Addresse: " << &j << " Innholder følgende verdi: " << j << endl; //Addressen peker til verdien 5 i j
    cout << "p: Addresse: " << p << " Innholder følgende verdi: " << *p << endl; //Pekkeren p referer til adressen til i, og verdien 3
    cout << "q: Addresse: " << q << " Innholder følgende verdi: " << *q << endl; //Pekkeren q referer til adressen til j, og verdien 5

// Oppgave 1 - DEL B (Utvidelse av kode)
    cout << "-------- Del B -----------" << endl;
    /*
Koden som er skissert i oppgave 1b skal gjøre følgende:
*p = 7;      // Setter verdien på adressen p peker til (i)
*q += 4;   // Legger til 4 på verdien på adressen q peker til (j)
*q = *p + 1; // Setter verdien på adressen q peker til (j) til verdien på adressen p peker til (i) + 1
p = q;      // Setter pekeren p til å peke på samme adresse som q (j)
//--> Nå vil begge pekerene peker på j som nå er 8

*/

    *p = 7;
    *q += 4;
    *q = *p + 1;
    p = q;
    cout << *p << " " << *q << endl; //(Begge peker til j som er 8)
    //Utskrift: 8 8
    return 0;
}
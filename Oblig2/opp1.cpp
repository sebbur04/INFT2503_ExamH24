//Oppgave 1
#include <iostream>

using namespace std;

// Oppgave 1 - DEL A
int main(void)
{
    //Kopierer følgende verdier fra øvingen
    int i = 3;
    int j = 5;
    int *p = &i; //pekeren P peker på adressen til i
    int *q = &j; //pekeren q peker på adressen til j

    cout << "i: Addresse: " << &i << " Verdi: " << i << endl; //Addressen peker til verdien 3 i i
    cout << "j: Addresse: " << &j << " Verdi: " << j << endl; //Addressen peker til verdien 5 i j
    cout << "p: Addresse: " << p << " Verdi: " << *p << endl; //Pekkeren p referer til adressen til i, og verdien 3
    cout << "q: Addresse: " << q << " Verdi: " << *q << endl; //Pekkeren q referer til adressen til j, og verdien 5

// Oppgave 1 - DEL B (Utvidelse av kode)

    return 0;
}
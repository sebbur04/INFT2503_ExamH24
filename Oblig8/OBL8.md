# Øving 8 - Templates

## Oppgave 1
Lag en funksjonstemplate som finner ut om to verdier er like (for eksempel: ```template <typename Type> bool equal(Type a, Type b) {...}```). Du kan anta at sammenlikningsoperatorene er implementert for den aktuelle datatypen.

Lag en spesialutgave for ```double``` (for eksempel: ```bool equal(double a, double b) {...}```). Denne funksjonen skal kunne brukes for beregnede desimaltallsverdier. Anta at to slike verdier betraktes som like dersom forskjellen mellom dem er mindre enn for eksempel ```0.00001```.

Lag et lite program som prøver både template-utgaven og spesialutgaven. Sjekk at riktig utgave blir brukt ved å legge inn utskrift-setninger inni funksjonene. Du vil kanskje trenge å skrive ut ```double``` med mer enn 6 desimaler, bruk i tilfelle manipulatoren ```setprecision()```.

## Oppgave 2 
Du skal lage en template-klasse for par. De to elementene som inngår i et par kan være av forskjellig type. Klassen skal tilby følgende:

1) En konstruktør som tar begge elementene som argumenter.


2) En operator for å legge sammen to par. Den skal lages ved elementvis summering, se eksemplet nedenfor.


3) En operator for å finne ut om et par er større enn et annet par. Her skal du sammenligne summen av elementene i hvert enkelt par, se eksemplet nedenfor.


Forutsett at det du måtte trenge av ytterligere versjoner av operatorene ```+``` og ```>``` eksisterer. Hvilke forutsetninger gjør du?



Klassetemplaten skal kunne brukes i følgende:

```cpp
int main() {
Pair<double, int> p1(3.5, 14);
Pair<double, int> p2(2.1, 7);
cout << "p1: " << p1.first << ", " << p1.second << endl;
cout << "p2: " << p2.first << ", " << p2.second << endl;

if (p1 > p2)
cout << "p1 er størst" << endl;
else
cout << "p2 er størst" << endl;

auto sum = p1 + p2;
cout << "Sum: " << sum.first << ", " << sum.second << endl;
}

/* Utskrift:
p1: 3.5, 14
p2: 2.1, 7
p1 er størst
Sum: 5.6, 21
*/
```
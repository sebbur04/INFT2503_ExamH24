# Øving 3: Objektorientert programmering i C++
## Oppgave 1
Rett opp feilene i følgende klasse:

````
const double pi = 3.141592;

class Circle {
public:
circle(double radius_);
int get_area() const;
double get_circumference() const;
private double radius;
}

// ==> Implementasjon av klassen Circle

public Circle::Circle(double radius_) : radius_(radius) {}

int Circle::get_area() {
return pi * radius * radius;
}

Circle::get_circumference() const {
circumference = 2.0 * pi * radius;
return circumference;
}
````
## Oppgave 2
Følgende klientprogram bruker klassen fra oppgave 1. Fyll ut det som mangler (merket med /*---*/):

````
#include <iostream>

using namespace std;

int main() {
/*---*/ circle(5);

/*---*/ area = circle.get_area();
cout << "Arealet er lik " /*---*/ endl;

double circumference = /*---*/.get_circumference();
cout << "Omkretsen er lik " << circumference << endl;
}
````

## Oppgave 3
Lag en klasse Commodity i henhold til følgende klassediagram:

Pris uten moms (engelsk: sales tax) skal lagres i objektet. Det er denne prisen som get_price() returnerer.

I tillegg skal funksjonene ````get_price()```` og ````get_price_with_sales_tax()```` ta antall enheter som argument og regne ut prisen for så mange enheter henholdsvis uten og med moms. Du kan sette momsen som en global konstant (på samme måte som pi i oppgave 1).

Klassen skal virke med følgende testklient:

````
#include "commodity.hpp"
#include <iostream>
#include <string>

using namespace std;

int main() {
const double quantity = 2.5;
Commodity commodity("Norvegia", 123, 73.50);

cout << "Varenavn: " << commodity.get_name() << ", varenr: " << commodity.get_id()
<< " Pris pr enhet: " << commodity.get_price() << endl;

cout << "Kilopris: " << commodity.get_price() << endl;
cout << "Prisen for " << quantity << " kg er " << commodity.get_price(quantity)
<< " uten moms" << endl;
cout << "Prisen for " << quantity << " kg er " << commodity.get_price_with_sales_tax(quantity)
<< " med moms" << endl;

commodity.set_price(79.60);
cout << "Ny kilopris: " << commodity.get_price() << endl;
cout << "Prisen for " << quantity << " kg er " << commodity.get_price(quantity)
<< " uten moms" << endl;
cout << "Prisen for " << quantity << " kg er " << commodity.get_price_with_sales_tax(quantity)
<< " med moms" << endl;
}

/* Utskrift:
Varenavn: Norvegia, varenr: 123 Pris pr enhet: 73.5
Kilopris: 73.5
Prisen for 2.5 kg er 183.75 uten moms
Prisen for 2.5 kg er 229.688 med moms
Ny kilopris: 79.6
Prisen for 2.5 kg er 199 uten moms
Prisen for 2.5 kg er 248.75 med moms
*/
````

## Oppgave 4
Du skal i denne oppgaven få øvelse i å bruke klassen string. Lag et helt enkelt program som gjør følgende:

a) Les inn tre ord fra brukeren. Kall variablene word1, word2 og word3.

b) Lag en streng der du skjøter sammen disse med mellomrom mellom og punktum til slutt. Kall variabelen sentence. Skriv ut.

c) Skriv ut lengden til hvert enkelt ord, og lengden til setningen som helhet.

d) Lag en kopi av sentence. Kall kopien sentence2.

e) Bytt ut tegn nr 10-12 i sentence2 med x’er. Tegnene nummereres fra og med 0. Husk å kontrollere at dette er gyldige posisjoner! Skriv ut sentence og sentence2.

f) Lagre de fem første tegnene i sentence i objektet sentence_start. Skriv ut sentence og sentence_start. (Husk kontroll av gyldige posisjoner)

g) Finn ut om sentence inneholder ordet "hallo". Skriv ut resultatet.

h) Finn alle forekomster i sentence av strengen "er". Skriv ut resultatet.
# Øving 2: Pekere
Besvarelse i MD-fil for tekstoppgave 2 og 3
## Oppgave 2 - Teorioppgave
Hva vil skje hvis du skriver:

````c++
char *line = nullptr;   // eller char *line = 0;
strcpy(line, "Dette er en tekst");
````
Hvis man kjører dette skriptet, så vil vi få en tilsvarende hendelse som i leksjonen, med at vi har en peker som ikke peker på noe. strcpy  vil prøve  å kopiere stringen innhold til minneområdet til line. Siden line er en nullptr, vil strcpy prøve å skrive på minneadresse 0  i systemet

Programmet vil ikke skrive til et tilfeldig sted, I praksis vil programmet krasje med en segmentation fault eller tilsvarende, fordi OS beskytter adresse 0.



## Oppgave 3 - Teorioppgave
Finn ting som kan gå galt i følgende programbit:
Feil er kommentert inline i koden
````c++
char text[5]; //Kan bare innholde 4 tegn + nullterminator
char *pointer = text;
char search_for = 'e'; 
cin >> text; //Hvis brukeren skriver inn mer enn 4 tegn, vil det føre til buffer overflow
while (*pointer != search_for) { //Om e ikke finnes i strengen, vil ikke while løkken stoppe
*pointer = search_for;
pointer++;
} // Løkken stopper om den finner e, hvis ikke kræsjer programmet
````

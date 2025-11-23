# INFT2503 Eksamen Høst 2024 LF

## Oppgave 8 
Lag funksjonen parallell_transform() som returnerer en ny tabell avhengig av tabellene i første og andre argumentet, og funksjonen i tredje argumentet. Utregningene skal skje i parallell. Du kan bruke thread::hardware_concurrency() for å finne antall CPU kjerner som er tilgjengelig. Følgende kildekode:

```cpp
vector<int> a = {1, 2, 3, 4, 5};
vector<int> b = {2, 3, 4, 5, 6};
 auto result = parallell_transform(a, b, [](int a_element, int b_element) { 
  return a_element + b_element; 
});
 for (auto &e : result)
 cout << e << ' ';
 cout << endl;
 result = parallell_transform(a, b, [](int a_element, int b_element) {   return a_element * b_element; 
}); for (auto &e : result)   cout << e << ' '; cout << endl;

```

## Oppgave 9
Lag nødvendige klasser og funksjoner slik at følgende kildekode:

```cpp

```
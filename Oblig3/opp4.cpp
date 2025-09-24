//
// Created by Sebastian E Burmo on 21/08/2025.
//
// Oppgave 4

#include <iostream>
using namespace std;

int main() {
    // A) Les inn tre ord fra brukeren
    string word1, word2, word3;
    cout << "Skriv inn 3 ord med mellomrom: ";
    cin >> word1 >> word2 >> word3; //Cin leser inn data fra terminalen

    // B) Lag en setning med mellomrom og punktum
    string sentence = word1 + " " + word2 + " " + word3 + "."; //Skiller de tre setningene med mellomrom
    cout << "Setning: " << sentence << endl;

    // C) Skriv ut lengdene på setningene der word brukes som definisjon på  en enkelt setning
    cout << "Lengde word1: " << word1.length() << endl;
    cout << "Lengde word2: " << word2.length() << endl;
    cout << "Lengde word3: " << word3.length() << endl;
    cout << "Lengde sentence: " << sentence.length() << endl;

    // D) Lag en kopi av sentence
    string sentence2 = sentence; //Kopierer sentence til sentence2

    // E) Bytt ut tegn 10-12 med x'er (hvis gyldige posisjoner)
    for(size_t i = 9; i < 12; i++){
        if(i > sentence2.length()) break;
        sentence2[i] = 'x'; //Sette inn x'er
    }

    cout << "Sentence: " << sentence << endl;
    cout << "Sentence2: " << sentence2 << endl << endl;
    ;

    // F) Lagre de fem første tegnene i sentence i objektet sentence_start. Skriv ut sentence og sentence_start. (Husk kontroll av gyldige posisjoner)

    auto sentence_start = (sentence.length() > 5) ?
    sentence.substr(0, 5) : sentence.substr(0, sentence.length());
    cout << "Sentence: " << sentence << endl;
    cout << "Sentence_start: " << sentence_start << endl << endl;

    // G) Sjekk om sentence inneholder "hallo"
    if (sentence.find("hallo") != string::npos) {
        cout << "Setningen inneholder 'hallo'" << endl;
    } else {
        cout << "Setningen inneholder ikke 'hallo'" << endl;
    }

    // H) Finn alle forekomster av "er"
    int count = 0;
    size_t finder = sentence.find("er"); //Leter etter "er"
    while(finder != string::npos){
        count++;
        finder = sentence.find("er", finder+1);
    }

    cout << "'er' forekommer: " << count << " ganger" << endl;

    return 0;
}

//Oppgave 5 (10% Løsning)

#include <iostream>
#include <vector>
#include <thread>

using namespace std;

int main() {


    vector<thread> threads;

    for (int a = -1; a < 9; ++a) {

        threads.emplace_back([b = a + 1]() { //[b = a + 1]
            cout << b;
        });
    }

    for (thread& t : threads) //thread&
        t.join(); // t.join();

    cout << endl;

    return 0;
}
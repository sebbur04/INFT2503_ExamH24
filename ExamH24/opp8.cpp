// Oppgave 8 - (20% Løsning)

#include <iostream>
#include <vector>
#include <thread>
#include <functional>

using namespace std;

vector<int> parallel_transform(const vector<int> &a, const vector<int> &b, function<int(int, int)> func) {
    vector<int> result(a.size());
    vector<thread> threads;
    size_t n_threads = thread::hardware_concurrency();

    for (size_t t = 0; t < n_threads; ++t) {
        threads.emplace_back([t, n_threads, &a, &b, &result, &func]() {
            for (size_t i = t; i < a.size(); i += n_threads)
                result[i] = func(a[i], b[i]);
        });
    }

    for (auto &thread : threads)
        thread.join();

    return result;
}

int main() {
    vector<int> a = {1, 2, 3, 4, 5};
    vector<int> b = {2, 3, 4, 5, 6};

    auto result = parallel_transform(a, b, [](int a_element, int b_element) {
        return a_element + b_element;
    });

    for (auto &e : result)
        cout << e << " ";
    cout << endl;

    result = parallel_transform(a, b, [](int a_element, int b_element) {
        return a_element * b_element;
    });

    for (auto &e : result)
        cout << e << " ";
    cout << endl;

    return 0;
}
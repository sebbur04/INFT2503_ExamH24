//
// Created by Sebastian E Burmo on 21/11/2025.
//

#include <iostream>
#include <vector>
#include <functional>

using namespace std;

// Find Helper
template<typename Pred>
struct FindHelper {
    Pred pred;

    int* operator()(vector<int>& vec) {
        for (auto& e : vec)
            if (pred(e)) return &e;
        return nullptr;
    }
};

// Reduce Helper
template<typename Func>
struct ReduceHelper {
    Func func;
    int init;

    int operator()(vector<int>& vec) {
        int result = init;
        for (auto& e : vec)
            result = func(result, e);
        return result;
    }
};

// Find function
template<typename Pred>
FindHelper<Pred> Find(Pred pred) {
    return {pred};
}

// Reduce function
template<typename Func>
ReduceHelper<Func> Reduce(Func func, int init) {
    return {func, init};
}

// Pipe operators
template<typename Pred>
int* operator|(vector<int>& vec, FindHelper<Pred> h) { return h(vec); }

template<typename Func>
int operator|(vector<int>& vec, ReduceHelper<Func> h) { return h(vec); }

int main() {
    vector<int> vec = {1, 2, 3};

    cout << *(vec | Find([](int value) { return value > 1; })) << endl;
    cout << (vec | Find([](int value) { return value == 5; })) << endl;
    cout << (vec | Reduce([](int previous_value, int current_value) {
        return previous_value + current_value;
    }, 0)) << endl;
    cout << (vec | Reduce([](int previous_value, int current_value) {
        return previous_value + 2 * current_value;
    }, 5)) << endl;

    return 0;
}
#include <iostream>
#include <vector>
#include <memory>
#include <functional>

using namespace std;

class Object {
public:
    virtual ~Object() {}
    virtual function<double(double)> area_function() const = 0;
};

class Square : public Object {
public:
    double side_length;

    Square(double side_length) : side_length(side_length) {}

    function<double(double)> area_function() const override {
        return [this](double) {
            return side_length * side_length;
        };
    }
};

class Circle : public Object {
public:
    double radius;

    Circle(double radius) : radius(radius) {}

    function<double(double)> area_function() const override {
        return [this](double) {
            return 3.14 * radius * radius;
        };
    }
};

int main() {
    vector<unique_ptr<Object>> objects;

    objects.emplace_back(new Square(2));
    objects.emplace_back(new Circle(2));

    for (auto &object : objects)
        cout << object->area_function()(2.) << endl;

    return 0;
}
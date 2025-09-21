//
// Created by Sebastian E Burmo on 21/08/2025.
#include <iostream>
using namespace std;


// Oppgave 1 - Rett opp feilene i følgende klasse:
int main()
{
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

    return 0;
}
//
// Created by Sebastian E Burmo on 21/08/2025.
#include <iostream>
using namespace std;

// Oppgave 1 - Rett opp feilene i følgende klasse:

const double pi = 3.141592;

//Selve objekten skal ikke ligge i main, men blir kallet opp i main, for å verfisere at det fungerer

    class Circle {

    public:
        Circle(double radius_);
        int get_area() const;
        double get_circumference() const;

    private:
        double radius;
    };

    // ==> Implementasjon av klassen Circle

    Circle::Circle(double radius_) : radius(radius_) {} //Skal ikke være public, skrivefeil i radius

    int Circle::get_area() const {
        return pi * radius * radius;
    }

    double Circle::get_circumference() const {//Må legge til double

        double circumference = 2.0 * pi * radius; //Må legge til double
        return circumference;

    }


//Bruker en main og bruker klassen for å sjekke om objektene ovenfor fungerer som de skal
// Selve konstruktøren skal ikke ligge i main
 int main () {

        Circle circle (10); //Definere radius i sirklen

        double circumference = circle.get_circumference(); // Finne omkretsen

        cout << "Ved a kalle opp circumference far vi opp omkretsen til sirkel med radius pa 10cm" << circumference << endl;

     return 0;
 }
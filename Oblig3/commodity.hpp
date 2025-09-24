//
// Created by Sebastian E Burmo on 21/08/2025.
//
//Header++ fil for opp3.cpp - Klassedeklarasjon for Commodity
#include <string>
#pragma once
using namespace std;

//Definisjon av klassen Commodity i henhold til klassediagrammet
class Commodity {
public:
    Commodity(const string &name_, int id_, double price_);
    const string &get_name() const;
    int get_id() const;
    double get_price() const;
    double get_price(double quantity) const;
    double get_price_with_sales_tax() const;
    double get_price_with_sales_tax(double quantity) const;
    void set_price(double new_price);
private:
    string name;
    int id;
    double price;
};

//Metoder for å implementere klassen Commodity sin funksjonlitet
Commodity::Commodity(const string &name_, int id_, double price_) : name(name_), id(id_), price(price_){};

const string &Commodity::get_name() const {
    return name;
}

int Commodity::get_id() const {
    return id;
}

double Commodity::get_price() const {
    return price;
}

double Commodity::get_price(double quantity) const {
    return price * quantity;
}

double Commodity::get_price_with_sales_tax() const {
    return price * 1.25; //Legger til moms 25%
}

double Commodity::get_price_with_sales_tax(double quantity) const {
    return price * 1.25 * quantity; //Legger til moms 25%
}

void Commodity::set_price(double new_price) {
    price = new_price;
}
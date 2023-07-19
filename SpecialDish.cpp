#include "SpecialDish.h"
#include <iostream>

SpecialDish::SpecialDish(std::string name, double price, double special)
    : Dish(name, price), special(special) {}

double SpecialDish::getNetPrice() const {
    return getPrice() * special;
}

void SpecialDish::output() const {
    Dish::output();
    std::cout << "，特价：" << special;
}
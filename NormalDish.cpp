#include "NormalDish.h"
#include <iostream>

NormalDish::NormalDish(std::string name, double price, double discount)
    : Dish(name, price), discount(discount) {}

double NormalDish::getNetPrice() const {
    return getPrice();
}

void NormalDish::output() const {
    Dish::output();
    //std::cout << "，折扣：" << discount;
}
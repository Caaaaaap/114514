#include "OverseaDish.h"
#include <iostream>

OverseaDish::OverseaDish(std::string name, double price, double tariff)
    : Dish(name, price), tariff(tariff) {}

double OverseaDish::getNetPrice() const {
    return getPrice() + tariff;
}

void OverseaDish::output() const {
    Dish::output();
    std::cout << "，关税：" << tariff;
}
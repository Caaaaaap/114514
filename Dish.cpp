#include "Dish.h"
#include <iostream>

Dish::Dish(std::string name, double price) : name(name), price(price), totalRating(0), ratingCount(0) {}

std::string Dish::getName() const {
    return name;
}

double Dish::getPrice() const {
    return price;
}

double Dish::getAverageRating() const {
    if (ratingCount == 0) {
        return 0;
    }
    return totalRating / ratingCount;
}

void Dish::updateRating(double rating) {
    totalRating += rating;
    ratingCount++;
}

void Dish::setPrice(double price) {
    this->price = price;
}

double Dish::getNetPrice() const {
    return price;
}

void Dish::output() const {
    std::cout << "菜品名称：" << name << "，价格：" << price;
}
#ifndef NORMALDISH_H
#define NORMALDISH_H

#include "Dish.h"

class NormalDish : public Dish {
private:
    double discount;

public:
    NormalDish(std::string name, double price, double discount);
    double getNetPrice() const override;
    void output() const override;
};

#endif
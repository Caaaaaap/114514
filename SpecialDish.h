#ifndef SPECIALDISH_H
#define SPECIALDISH_H

#include "Dish.h"

class SpecialDish : public Dish {
private:
    double special;

public:
    SpecialDish(std::string name, double price, double special);
    double getNetPrice() const override;
    void output() const override;
};

#endif
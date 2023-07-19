#ifndef OVERSEADISH_H
#define OVERSEADISH_H

#include "Dish.h"

class OverseaDish : public Dish {
private:
    double tariff;

public:
    OverseaDish(std::string name, double price, double tariff);
    double getNetPrice() const override;
    void output() const override;
};

#endif
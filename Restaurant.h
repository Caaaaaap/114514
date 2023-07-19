#ifndef RESTAURANT_H
#define RESTAURANT_H

#include <vector>
#include "Dish.h"

class Restaurant {
private:
    std::vector<Dish*> menu;
    double totalIncome;
    double TotalIncome;

public:
    Restaurant();
    ~Restaurant();
    void addDish(Dish* dish);
    void removeDish(const std::string& dishName);
    void modifyPrice(const std::string& dishName, double newPrice);
    void showMenuWithRatings() const;
    void showMenu() const;
    void showTotalIncome() const;
    void showAverageRating() const;
    void customerInterface();
    void ownerInterface();
    void saveData() const;
    void loadData();
};

#endif
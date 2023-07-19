#ifndef DISH_H
#define DISH_H

#include <string>

class Dish {
private:
    std::string name;
    double price;
    double totalRating; // 总评分
    int ratingCount;    // 评分次数

public:
    Dish(std::string name, double price);

    std::string getName() const;
    double getPrice() const;
    double getAverageRating() const; // 获取平均评分
    void updateRating(double rating); // 更新评分
    void setPrice(double price);
    virtual double getNetPrice() const;
    virtual void output() const;
};

#endif
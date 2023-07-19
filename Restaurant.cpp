#include "Restaurant.h"
#include "NormalDish.h"
#include "OverseaDish.h"
#include "SpecialDish.h"
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

Restaurant::Restaurant() : totalIncome(0) {}

Restaurant::~Restaurant() {
    for (Dish* dish : menu) {
        delete dish;
    }
}

void Restaurant::addDish(Dish* dish) {
    menu.push_back(dish);
}

void Restaurant::removeDish(const std::string& dishName) {
    auto it = find_if(menu.begin(), menu.end(), [dishName](const Dish* dish) {
        return dish->getName() == dishName;
    });

    if (it != menu.end()) {
        delete *it;
        menu.erase(it);
        cout << "成功删除菜品：" << dishName << endl;
    } else {
        cout << "菜品：" << dishName << " 不存在，删除失败！" << endl;
    }
}

void Restaurant::modifyPrice(const std::string& dishName, double newPrice) {
    auto it = find_if(menu.begin(), menu.end(), [dishName](const Dish* dish) {
        return dish->getName() == dishName;
    });

    if (it != menu.end()) {
        (*it)->setPrice(newPrice);
        cout << "成功修改菜品：" << dishName << " 的价格为：" << newPrice << "元" << endl;
    } else {
        cout << "菜品：" << dishName << " 不存在，修改价格失败！" << endl;
    }
}

void Restaurant::showMenuWithRatings() const {
    cout << "菜单如下：" << endl;
    for (const Dish* dish : menu) {
        dish->output();
        if (dish->getAverageRating() != 0) {
            cout << "，评分：" << dish->getAverageRating() << "分";
        } else {
            cout << "，暂无评分";
        }
        cout << endl;
    }
}

void Restaurant::showMenu() const {
    cout << "菜单如下：" << endl;
    for (const Dish* dish : menu) {
        dish->output();
        cout << endl;
    }
}

void Restaurant::showTotalIncome() const {
    cout << "当前总收入为：" << TotalIncome << "元" << endl;
}

void Restaurant::showAverageRating() const {
    int totalRating = 0;
    int numRatedDishes = 0;

    for (const Dish* dish : menu) {
        if (dish->getAverageRating() != 0) {
            totalRating += dish->getAverageRating();
            numRatedDishes++;
        }
    }

    if (numRatedDishes > 0) {
        double averageRating = static_cast<double>(totalRating) / numRatedDishes;
        cout << "当前菜品平均评分为：" << averageRating << "分" << endl;
    } else {
        cout << "当前暂无菜品评分" << endl;
    }
}

void Restaurant::customerInterface() {
    while (true) {
        cout << "欢迎来到餐厅！请选择功能：" << endl;
        cout << "1. 查看菜单并显示菜品当前评分" << endl;
        cout << "2. 点菜系统" << endl;
        cout << "3. 给菜品评分" << endl;
        cout << "0. 返回主页面" << endl;

        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                showMenuWithRatings();
                break;
            case 2: {
                cout << "请输入菜品名称以点菜，输入0结束点菜：" << endl;
                string dishName;
                double totalCost = 0;
                while (true) {
                    cin >> dishName;
                    if (dishName == "0") {
                        break;
                    }

                    auto it = find_if(menu.begin(), menu.end(), [dishName](const Dish* dish) {
                        return dish->getName() == dishName;
                    });

                    if (it != menu.end()) {
                        totalCost += (*it)->getNetPrice();
                        cout << "成功点菜：" << dishName << "，价格：" << (*it)->getNetPrice() << "元" << endl;
                    } else {
                        cout << "菜品：" << dishName << " 不存在，点菜失败！" << endl;
                    }
                }
                cout << "您一共消费了：" << totalCost << "元" << endl;
                TotalIncome+=totalCost;
                break;
            }
            case 3: {
                cout << "请输入菜品名称以评分（0-10），输入0结束评分：" << endl;
                string dishName;
                double rating;
                while (true) {
                    cin >> dishName;
                    if (dishName == "0") {
                        break;
                    }

                    auto it = find_if(menu.begin(), menu.end(), [dishName](const Dish* dish) {
                        return dish->getName() == dishName;
                    });

                    if (it != menu.end()) {
                        cout << "请输入评分（0-10）：" << endl;
                        cin >> rating;
                        if (rating >= 0 && rating <= 10) {
                            (*it)->updateRating(rating);
                            cout << "成功给菜品：" << dishName << " 评分：" << rating << "分" << endl;
                        } else {
                            cout << "评分范围错误，请重新输入！" << endl;
                        }
                    } else {
                        cout << "菜品：" << dishName << " 不存在，评分失败！" << endl;
                    }
                }
                break;
            }
            case 0:
                return;
            default:
                cout << "无效输入！请重试！" << endl;
                break;
        }
    }
}

void Restaurant::ownerInterface() {
    while (true) {
        cout << "欢迎来到商家界面！请选择功能：" << endl;
        cout << "1. 增加菜品" << endl;
        cout << "2. 删除菜品" << endl;
        cout << "3. 修改菜品价格" << endl;
        cout << "4. 显示当前全部收入" << endl;
        cout << "5. 查看所有菜品评价分数平均数" << endl;
        cout << "0. 返回主页面" << endl;

        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "请输入菜品名称：" << endl;
                string dishName;
                cin >> dishName;
                cout << "请输入菜品价格：" << endl;
                double price;
                cin >> price;
                cout << "请选择菜品类型（1-普通菜品，2-特价菜品，3-海外菜品）：" << endl;
                int type;
                cin >> type;
                if (type == 1) {
                    double discount=1;
                    addDish(new NormalDish(dishName, price, discount));
                } else if (type == 2) {
                    cout << "请输入特价折扣（0-1之间）：" << endl;
                    double special;
                    cin >> special;
                    addDish(new SpecialDish(dishName, price, special));
                } else if (type == 3) {
                    cout << "请输入关税：" << endl;
                    double tariff;
                    cin >> tariff;
                    addDish(new OverseaDish(dishName, price, tariff));
                } else {
                    cout << "无效输入！请重试！" << endl;
                }
                cout << "成功增加菜品：" << dishName << "，价格：" << price << "元" << endl;
                break;
            }
            case 2: {
                cout << "请输入菜品名称：" << endl;
                string dishName;
                cin >> dishName;
                removeDish(dishName);
                break;
            }
            case 3: {
                cout << "请输入菜品名称：" << endl;
                string dishName;
                cin >> dishName;
                cout << "请输入新的价格：" << endl;
                double newPrice;
                cin >> newPrice;
                modifyPrice(dishName, newPrice);
                break;
            }
            case 4:
                showTotalIncome();
                break;
            case 5:
                showAverageRating();
                break;
            case 0:
                return;
            default:
                cout << "无效输入！请重试！" << endl;
                break;
        }
    }
}

void Restaurant::saveData() const {
    ofstream out("restaurant_data.txt");
    if (out) {
        out << menu.size() << endl;
        for (const Dish* dish : menu) {
            out << dish->getName() << " " << dish->getPrice() << " " << dish->getAverageRating() << endl;
        }
        out << totalIncome << endl;
        out.close();
    } else {
        cout << "保存数据失败！" << endl;
    }
}

void Restaurant::loadData() {
    ifstream in("restaurant_data.txt");
    if (in) {
        int numDishes;
        in >> numDishes;
        in.ignore();

        for (int i = 0; i < numDishes; i++) {
            std::string name;
            double price;
            double rating;

            in >> name >> price >> rating;
            in.ignore();

            addDish(new Dish(name, price));
            menu.back()->updateRating(rating);
        }

        in >> totalIncome;
        in.close();
    } else {
        cout << "加载数据失败！" << endl;
    }
}

#include <iostream>
#include <windows.h>
#include "Restaurant.h"

using namespace std;

char menu() {
    cout << "========== 欢迎使用餐厅管理系统 ==========" << endl;
    cout << "请选择身份进入系统：" << endl;
    cout << "1. 客户" << endl;
    cout << "2. 商家" << endl;
    cout << "0. 退出系统" << endl;
    cout << "=========================================" << endl;
    cout << "请输入功能选项：";
    char choice;
    cin >> choice;
    return choice;
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    Restaurant restaurant;
    restaurant.loadData();

    while (true) {
        char choice = menu();

        if (choice == '0') {
            restaurant.saveData();
            cout << "再见！" << endl;
            break;
        } else if (choice == '1') {
            restaurant.customerInterface();
        } else if (choice == '2') {
            restaurant.ownerInterface();
        } else {
            cout << "无效输入！请重试！" << endl;
        }
    }

    return 0;
}

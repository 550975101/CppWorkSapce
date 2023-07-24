//
// Created by 封心 on 2022/6/13.
//
#include <iostream>

using namespace std;

int add(int x, int y) {
    return x + y;
}

double add(double x, double y) {
    return x + y;
}

int main() {
    cout << add(0, 1) << endl;
    cout << add(1.1, 1.2) << endl;
    return 0;
}

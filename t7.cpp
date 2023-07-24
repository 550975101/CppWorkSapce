//
// Created by 封心 on 2022/6/13.
//
#include <iostream>

using namespace std;

// 函数声明
int max(int num1, int num2);

int main() {
    int num1 = 2222;
    int num2 = 2;
    cout << max(num1, num2) << endl;
}

int max(int num1, int num2) {
    int result;
    if (num1 > num2) {
        result = num1;
    } else if (num1 < num2) {
        result = num2;
    } else {
        result = num1;
    }
    return result;
}

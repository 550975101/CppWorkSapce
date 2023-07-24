//
// Created by 封心 on 2022/6/13.
//
#include <iostream>

using namespace std;

// 函数声明
void swap(int *num1, int *num2);


int main() {
    int num1 = 1;
    int num2 = 2;
    swap(num1, num2);
    cout << num1 << endl;
}

void swap(int *num1, int *num2) {
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

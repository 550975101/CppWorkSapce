//
// Created by 封心 on 2022/6/13.
//
#include <iostream>

using namespace std;

// 变量声明
extern int a, b;
extern int c;
extern float f;

// 函数声明
int func();

int main() {
    int i = func();
    cout << i << endl;
}

// 函数定义
int func()
{
    return 0;
}

//
// Created by 封心 on 2022/6/13.
//
#include <iostream>

using namespace std;

//在 C++ 中，有两种简单的定义常量的方式：
//使用 #define 预处理器。
//使用 const 关键字。

#define LENGTH 10
#define WIDTH 5
#define NEWLINE '\n'

int main() {
    string greeting = "hello , runoob";
    cout << greeting;
    cout << "\n";
    string greeting2 = "hello, \n"
                       "runoob";
    cout << greeting2 << endl;

    int area;
    area = LENGTH * WIDTH;
    cout << area;
    cout << NEWLINE;


    const float pai = 3.14159265358979323846;
    cout << pai;
    return 0;
}

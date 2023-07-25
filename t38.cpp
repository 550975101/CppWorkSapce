//
// Created by 封心 on 2023/7/25.
//
#include "iostream"

using namespace std;

int main() {
    int a = 10;

    int *p;

    p = &a;

    cout << *p << endl;

    //在32位操作系统下，指针是占4个字节空间大小 不管什么类型
    //在64位操作系统下，指针是占8个字节空间大小 不管什么类型
    cout << sizeof(p) << endl;
    cout << sizeof(char *) << endl;
    cout << sizeof(double *) << endl;
    cout << sizeof(double *) << endl;
}

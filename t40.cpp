//
// Created by 封心 on 2023/7/25.
//
#include "iostream"

using namespace std;

int main() {

    //指针变量p指向内存地址编号为0x1100的空间
    int *p = (int *) 0x1100;
    //访问野指针报错
    cout << *p << endl;

    return 0;
}

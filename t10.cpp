//
// Created by 封心 on 2022/6/14.
//
#include <iostream>

using namespace std;

//引用不是新定义一个变量，而是给已存在变量取了一个别名，编译器不会为引用变量开辟内存空间，它和它
//引用的变量共用同一块内存空间。
//类型& 引用变量名(对象名) = 引用实体；

//引用在定义时必须初始化
//一个变量可以有多个引用
int swap(int *a, int *b) {
    return 0;
}

int main() {
    int a = 1;
    //相当于给a起了一个别名为b  int是b的类型
    int &b = a;
    //cout << a << endl;
    //cout << b << endl;
    //b = 3;
    //cout << b << endl;
    //cout << a << endl;

    //引用在定义时必须初始化
    //正确示例
    int z = 10;
    int &x = z;
    //错误示例
    //int c = 10;
    //int &v;
    //b = a;

    //一个变量可以有多个引用
    int n = 10;
    int &m = n;
    int &d = n;
    int &f = n;

    //引用一旦引用了一个实体，就不能再引用其他实体
    int r = 10;
    cout << &r << endl;
    auto y = &r;
    cout << y << endl;
    int u = 20;
    *y = u;
    cout << r << endl;
    cout << &y << endl;
    return 0;
}

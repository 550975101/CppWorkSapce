//
// Created by 封心 on 2023/7/20.
//
#include "iostream"

using namespace std;

class Box {
public:
    static int objectCount;

    Box(double l = 2.0, double b = 2.0, double h = 2.0) {
        cout << "Constructor called ." << endl;
        length = l;
        breadth = b;
        height = h;
        objectCount++;
    }

    double Volume() {
        return length * breadth * height;
    }

    static int getCount() {
        return objectCount;
    }

private:
    //长度
    double length;
    //宽度
    double breadth;
    //高度
    double height;
};

int Box::objectCount = 0;

int main() {

    // 在创建对象之前输出对象的总数
    cout << "Inital Stage Count: " << Box::getCount() << endl;

    Box Box1(3.3, 1.2, 1.5);    // 声明 box1
    Box Box2(8.5, 6.0, 2.0);    // 声明 box2

    // 在创建对象之后输出对象的总数
    cout << "Final Stage Count: " << Box::getCount() << endl;

    return 0;
}
//
// Created by 封心 on 2023/7/24.
//
#include "iostream"

using namespace std;

class Box {
public:
    Box(double l = 2.0, double b = 2.0, double h = 2.0) {
        cout << "Construct called." << endl;
        length = l;
        breadth = b;
        height = h;
    }

    double Volume() {
        return length * breadth * height;
    }

private:
    double length;
    double breadth;
    double height;
};

int main() {
    Box box1(3.3, 1.2, 1.5);
    Box box2(8.5, 6.0, 2.0);
    Box *ptrBox;

    //保存第一个地址
    ptrBox = &box1;
    //现在尝试用成员运算符号来访问成员
    cout << "Volume of Box1: " << ptrBox->Volume() << endl;

    //保存第二个地址
    ptrBox = &box2;
    //现在尝试用成员运算符号来访问成员
    cout << "Volume of Box2: " << ptrBox->Volume() << endl;
    return 0;
}

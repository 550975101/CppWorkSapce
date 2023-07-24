//
// Created by 封心 on 2023/7/13.
//

#include "iostream"
#include "cstring"

using namespace std;

class Box {
public:
    double length;         // 长度
    double breadth;        // 宽度
    double height;         // 高度
    double getVolume() const;

    void setLength(double len);

    void setBreadth(double br);

    void setHeight(double hei);
};

double Box::getVolume() const {
    return length * breadth * height;
}

void Box::setLength(double len) {
    length = len;
}

void Box::setBreadth(double bre) {
    breadth = bre;
}

void Box::setHeight(double hei) {
    height = hei;
}

int main() {
    //声明Box1 类型为Box
    Box box1;
    // 声明 Box2，类型为 Box
    Box box2;
    // 用于存储体积
    double volume = 0.0;


}
//
// Created by 封心 on 2023/7/24.
//
#include "iostream"

using namespace std;

class Shape {
protected:
    int width, height;
public:
    Shape(int a = 0, int b = 0) {
        width = a;
        height = b;
    }

    virtual int area() {
        cout << "Parent class area: " << endl;
        return 0;
    }
};

class Rectangle : public Shape {
public:
    Rectangle(int a = 0, int b = 0) : Shape(a, b) {

    }

    int area() {
        cout << "Rectangle class area: " << endl;
        return (width * height);
    }
};

class Triangle : public Shape {
public:
    Triangle(int a = 0, int b = 0) : Shape(a, b) {

    }

    int area() {
        cout << "Triangle class area: " << endl;
        return (width * height / 2);
    }
};

int main() {
    Shape *shape;
    Rectangle rec(10, 7);
    Triangle tri(10, 5);

    //储存矩形的地址
    shape = &rec;
    //调用矩形的求面积函数area
    shape->area();
    //储存三角形的地址
    shape = &tri;
    //调用求三角形面积函数 area
    shape->area();
}

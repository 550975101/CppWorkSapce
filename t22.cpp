//
// Created by 封心 on 2023/7/20.
//
#include "iostream"

using namespace std;

// 基类 Shape
class Shape {
public:
    void setWidth(int w) {
        width = w;
    };

    void setHeight(int h) {
        height = h;
    }

protected:
    int width;
    int height;
};

class PainCost {
public:
    int getCost(int area) {
        return area * 70;
    }
};

//派生类
class Rectangle : public Shape, public PainCost {
public:
    int getArea() {
        return (width * height);
    }
};

int main() {
    Rectangle rect;
    rect.setWidth(5);
    rect.setHeight(7);

    int area = rect.getArea();
    //输出对象的面积
    cout << "Total area: " << rect.getArea() << endl;
    // 输出总花费
    cout << "Total paint cost: $" << rect.getCost(area) << endl;
    return 0;
}
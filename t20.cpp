//
// Created by 封心 on 2023/7/18.
//
#include "iostream"

using namespace std;

class Line {
public:
    void setLength(double len);

    double getLength();

    // 这是构造函数声明
    Line();

    ~Line();

private:
    double length;
};

Line::Line() {
    cout << "Object is being created" << endl;
}

void Line::setLength(double len) {
    length = len;
}

double Line::getLength() {
    return length;
}

Line::~Line() {
    cout << "Object is being deleted" << endl;
}

int main() {
    Line line;

    //设置长度
    line.setLength(6.0);
    cout << "Length of line: " << line.getLength() << endl;
}
//
// Created by 封心 on 2023/7/13.
//
class Box {
public:
    double length;
    double breadth;
    double height;

    double getVolume() const;
    //成员函数可以定义在类定义内部，
    // 或者单独使用范围解析运算符 :: 来定义。
    // 在类定义中定义的成员函数把函数声明为内联的，即便没有使用 inline 标识符。
    // 所以您可以按照如下方式定义 getVolume() 函数：
    //double getVolume(void)
    //{
    //    return length * breadth * height;
    //}
};

double Box::getVolume() const {
    return length * breadth * height;
}
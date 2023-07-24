//
// Created by 封心 on 2023/7/24.
//
#include "iostream"

using namespace std;

namespace A {
    int a = 100;
    //嵌套一个命名空间B
    namespace B {
        int a = 20;
    }
}
//定义一个全局变量
int a = 200;

int main(int argc, char *argv[]) {
    // A::a =100
    cout << "A::a = " << A::a << endl;
    //A::B::a =20
    cout << "A::B::a = " << A::B::a << endl;
    //a=200
    cout << "a = " << a << endl;
    //::a=200
    cout << "::a = " << ::a << endl;

    using namespace A;
    // Reference to 'a' is ambiguous // 命名空间冲突，编译期错误
    //cout << "a = " << a << endl;

    cout << "::a = " << ::a << endl;

    int a = 30;
    cout << "a = " << a << endl;
    cout << "::a = " << ::a << endl;



    //即：全局变量 a 表达为 ::a，用于当有同名的局部变量时来区别两者。
    using namespace A;
    // a =30 当有本地同名变量后，优先使用本地，冲突解除
    cout << "a = " << a << endl;
    //::a =200
    cout << "::a = " << ::a << endl;
}

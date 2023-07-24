//
// Created by 封心 on 2023/7/21.
//
#include "iostream"

using namespace std;

class PrintData {
public:
    void print(int i) {
        cout << "整数: " << i << endl;
    }

    void print(double f) {
        cout << "浮点数: " << f << endl;
    }

    void print(char c[]) {
        cout << "字符串为: " << c << endl;
    }
};

int main() {
    PrintData printData;

    //输出整数
    printData.print(5);
    //输出浮点数
    printData.print(500.263);
    //输出字符串
    char c[] = "hello C++";
    printData.print(c);
}
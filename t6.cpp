//
// Created by 封心 on 2022/6/13.
//
#include <iostream>

using namespace std;

//修饰符 signed、unsigned、long 和 short 可应用于整型，
// signed 和 unsigned 可应用于字符型，long 可应用于双精度型。
//修饰符 signed 和 unsigned 也可以作为 long 或 short 修饰符的前缀。例如：unsigned long int。
//C++ 允许使用速记符号来声明无符号短整数或无符号长整数。
// 您可以不写 int，只写单词 unsigned、short 或 long，int 是隐含的。例如，下面的两个语句都声明了无符号整型变量。
int main() {
    //有符号短整数
    short int i;
    //无符号短整数
    short unsigned int j;

    j = 50000;
    i = j;
    cout << i << " " << j;
    return 0;
}


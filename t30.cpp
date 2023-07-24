//
// Created by 封心 on 2023/7/24.
//
#include "iostream"

using namespace std;

class Box {
public:
    Box() {
        cout << "调用构造函数" << endl;
    }

    ~Box() {
        cout << "调用析造函数" << endl;
    }
};

int main() {
    // 初始化为 null 的指针
    double *pvalue = NULL;
    //为变量申请内存
    //pvalue = new double;
    //如果自由存储区已被用完，可能无法成功分配内存。所以建议检查 new 运算符是否返回 NULL 指针，并采取以下适当的操作：
    if (!(pvalue = new double)) {
        cout << "Error: out of memory." << endl;
        exit(1);
    }
    //malloc() 函数在 C 语言中就出现了，在 C++ 中仍然存在，但建议尽量不要使用 malloc() 函数。
    // new 与 malloc() 函数相比，其主要的优点是，new 不只是分配了内存，它还创建了对象。
    //在任何时候，当您觉得某个已经动态分配内存的变量不再需要使用时，您可以使用 delete 操作符释放它所占用的内存

    // 在分配的地址存储值
    *pvalue = 29494.99;
    cout << "Value of pvalue: " << *pvalue << endl;

    delete pvalue;
    // 初始化为 null 的指针
    char *cpvalue = NULL;
    // 为变量请求内存
    cpvalue = new char[20];

    delete[]   cpvalue;

    Box *myBoxArray = new Box[4];
    //尝试不写[] 发现不会被删除
    //必须加[] 才能删除
    //不加[] 不打印析构函数内容
    delete[] myBoxArray;
}

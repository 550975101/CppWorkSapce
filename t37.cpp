//
// Created by 封心 on 2023/7/25.
//
// 演示多线程的CPP程序
// 使用三个不同的可调用对象
#include "iostream"
#include "thread"

using namespace std;

void foo(int Z) {
    for (int i = 0; i < Z; ++i) {
        cout << "线程使用函数指针作为可调用参数\n";
    }
}

//可调用对象
class thread_obj {
public:
    void operator()(int x) {
        for (int i = 0; i < x; ++i) {
            cout << "线程使用函数对象作为可调用参数\n";
        }
    }
};

int main() {
    cout << "独立运行1、2、3、"
            "独立运行" << endl;
    //函数指针
    thread th1(foo, 3);

    //函数对象
    thread th2(thread_obj(), 3);

    //定义lambda表达式
    auto f = [](int x) {
        for (int i = 0; i < x; ++i) {
            cout << "线程使用 lambda 表达式作为可调用参数\n";
        }
    };

    //线程通过使用lambda表达式作为可调用的参数
    thread th3(f, 3);

    //等待线程完成
    //等待线程t1完成
    th1.join();
    //等待线程t2完成
    th2.join();
    //等待线程t3完成
    th3.join();
    return 0;
}
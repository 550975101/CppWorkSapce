//
// Created by 封心 on 2022/6/14.
//
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <list>
#include <map>
#include <fstream>

using namespace std;

//在语法概念上引用就是一个别名，没有独立空间，和其引用实体共用同一块空间。

void fun_test1() {
    vector<int> vec;//定义了vec向量(vector为一个类)
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(6);
    //vec.pop_back();
    //cout << vec.size() << endl;
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << endl;
    }
    //也可以用迭代器遍历向量表
    auto itor = vec.begin();
    //cout << *itor << endl;
    for (; itor != vec.end(); itor++) {
        cout << *itor << endl;
    }
}

void fun_test2() {
    list<int> list1;
    list1.push_back(1);
    list1.push_back(2);
    list1.push_back(3);
    list1.push_back(4);
    //这种方法不可以访问
    //for (int i = 0; i < list1.size(); ++i) {
    //    cout << list1[i] << endl;
    //}
    auto iterator = list1.begin();
    for (; iterator != list1.end(); iterator++) {
        cout << *iterator << endl;
    }
}

void fun_test3() {
    map<string, string> map1;
    pair<string, string> p1("张三", "1");
    pair<string, string> p2("张三", "1");
    map1.insert(p1);
    map1.insert(p2);

    cout << map1["张三"] << endl;
    auto iterator = map1.begin();
    for (; iterator != map1.end(); iterator++) {
        cout << iterator->first << endl;
        cout << iterator->second << endl;
    }
}

void fun_test4() {
    double x, y;
    cout << "请输入坐标" << endl;
    cin >> x >> y;
    if (abs(x) <= 2 && abs(y) <= 2) {
        cout << 1 << endl;
    } else {
        cout << 0 << endl;
    }
}

void fun_test5() {
    int a;
    cout << sizeof(a) << endl;
    //之前求数组变量个数也用到过
    int balance[5] = {100, 2, 3, 17, 50};
    int sizeb = sizeof(balance) / sizeof(balance[0]);
    cout << sizeb << endl;
}

void fun_test6() {
    fstream my_file;
    // write,清空再写入
    my_file.open(R"(D:\software\JetBrains\CWorkSpace\1.txt)", ios::out);
    if (my_file.is_open()) {
        my_file << "Hello \n";
        my_file << "你好 is second line\\ \n";
        my_file.close();
    }
    my_file.open(R"(D:\software\JetBrains\CWorkSpace\2.txt)", ios::app);  // append,追加
    if (my_file.is_open()) {
        for (int i = 0; i < 1000000000; ++i) {
            my_file << "Hello \n";
        }
        my_file.close();
    }

    //my_file.open(R"(D:\software\JetBrains\CWorkSpace\2.txt)", ios::in);
    //if (my_file.is_open()) {
    //    string line;
    //    while (getline(my_file, line)) {
    //        cout << line << endl;
    //    }
    //    my_file.close();
    //}
}

int main() {
    fun_test6();
    return 0;
}

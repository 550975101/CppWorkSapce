//
// Created by 封心 on 2022/6/14.
//
#include <iostream>

using namespace std;

//上面提到，引用类型必须和引用实体是同种类型的。
// 但是仅仅是同种类型，还不能保证能够引用成功，这儿我们还要注意可否可以修改的问题。

//这里的a，b，d都是常量，常量是不可以被修改的，
// 但是如果你用int&ra等这样来引用a的话，那么引用的这个a是可以被修改的，因此会出问题。

int &add(int a, int b) {
    int c = a + b;
    return c;
}

int main() {

    const int a = 10;

    //该语句会编译时会出错，a为常量
    //int &ra = a;
    const int &ra = a;

    //该语句会编译出错，b为常量
    //int &b = 10;

    const int &b = 10;

    double d = 12.34;
    //该语句编译会出错，类型不同
    //int &rd = d;

    const int &rd = d;
    //cout << rd << endl;


    //将不可修改的量用可读可写的量来引用是不可以的，
    //但是反过来是可以的，将可读可写的量用只可读的量来引用是可以的。
    int z = 10;
    const double &vz = z;
    //cout << vz;

    int &ans = add(1, 2);
    cout << ans << endl;
    return 0;
}

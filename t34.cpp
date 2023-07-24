//
// Created by 封心 on 2023/7/24.
//
#include "iostream"

#define DEBUG
#define MKSTR(x) #x


using namespace std;
//预处理
#define PI 3.1415926
//参数宏
#define MIN(a, b)(a<b?a:b)

int main() {
    cout << "Value of PI :" << PI << endl;

    int i, j;
    i = 100;
    j = 30;
    cout << "较小值的为: " << MIN(i, j) << endl;
#ifdef DEBUG
    cerr << "Trace: Inside main function" << endl;
#endif

#if 0
    /*这是注释部分*/
    cout<<MKSTR(HELLLO C++)<<endl;
#endif
    cout << "The minimum is " << MIN(i, j) << endl;
#ifdef DEBUG
    cerr << "Trace: Coming out of main function" << endl;
#endif
    cout << "Value of __LINE__: " << __LINE__ << endl;
    cout << "Value of __FILE__: " << __FILE__ << endl;
    cout << "Value of __DATE__: " << __DATE__ << endl;
    cout << "Value of __TIME__: " << __TIME__ << endl;

}


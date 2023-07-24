//
// Created by 封心 on 2023/7/14.
//
#include "iostream"
#include "ctime"
#include "string"

using namespace std;

int main() {
    //基于当前系统的当前日期/时间
    time_t now = time(nullptr);
    //把now转成字符串
    char *dt = ctime(&now);
    cout << "本地日期和时间: " << dt << endl;

    //把now转换成tm结构
    tm *gmtm = gmtime(&now);

    dt = asctime(gmtm);

    cout << "UTC 日期和时间" << dt << endl;

    tm *ltm = localtime(&now);
    // 输出 tm 结构的各个组成部分
    cout << "年: " << 1900 + ltm->tm_year << endl;
    cout << "月: " << 1 + ltm->tm_mon << endl;
    cout << "日: " << ltm->tm_mday << endl;
    cout << "时间: " << ltm->tm_hour << ":";
    cout << ltm->tm_min << ":";
    cout << ltm->tm_sec << endl;

    string dateStr = "2023-07-14";
    tm time = {};
}


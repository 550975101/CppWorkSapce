//
// Created by 封心 on 2023/7/24.
//
#include "iostream"
#include <csignal>
#include <unistd.h>

using namespace std;

void signalHandler(int signum) {
    cout << "Interrupt signal (" << signum << "received.\n";
    //清理并关闭
    //终止程序
    exit(signum);
}

int main() {
    int i = 0;
    //注册信号 sigint和信号处理器程序
    signal(SIGINT, signalHandler);
    while (++i) {
        cout << "Going to sleep..." << endl;
        if (i==3) {
            raise(SIGINT);
        }
        sleep(1);
    }
    return 0;
}

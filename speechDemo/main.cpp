//
// Created by 封心 on 2023/7/25.
//
#include <ctime>
#include "iostream"
#include "speechManager.h"

using namespace std;

int main() {
    //添加随机种子
    srand((unsigned int) time(NULL));
    SpeechManager sm;
    //用来存储用户的选项
    int choice = 0;
    while (true) {
        sm.show_menu();
        cout << "请输入您的选择" << endl;
        cin >> choice;
        switch (choice) {
            //开始比赛
            case 1:
                sm.startSpeech();
                break;
                //查看记录
            case 2:
                sm.showRecord();
                break;
                //清空记录
            case 3:
                sm.clearRecord();
                break;
                //退出系统
            case 0:
                sm.exitSystem();
                break;
            default:
                //清屏
                system("cls");
                break;
        }
    }
    system("pause");
    return 0;
}

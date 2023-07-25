//
// Created by 封心 on 2023/7/25.
//
#include "speechManager.h"
#include "string"

SpeechManager::SpeechManager() {
    //初始化容器和属性
    this->initSpeech();
    //创建12名选手
    this->createSpeaker();

}

SpeechManager::~SpeechManager() {

}

void SpeechManager::exitSystem() {
    cout << "欢迎下次使用" << endl;
    system("pause");
    exit(0);
}

void SpeechManager::initSpeech() {
    //容器都置为空
    this->v1.clear();
    this->v2.clear();
    this->vVictory.clear();
    this->m_Speaker.clear();

    //初始化比赛轮数
    this->m_index = 1;
}

void SpeechManager::createSpeaker() {
    string nameSeed = "ABCDEFGHIJKL";
    for (int i = 0; i < nameSeed.size(); ++i) {
        string name = "选手";
        name += nameSeed[i];
        Speaker sp;
        sp.m_Name = name;
        for (int j = 0; j < 2; ++j) {
            sp.m_score[i] = 0;
        }
        //12名选手编号
        this->v1.push_back(i + 10001);
        //选手编号以及对应的选手 放入map容器中
        this->m_Speaker.insert(make_pair(i + 10001, sp));
    }
}

void SpeechManager::show_menu() {
    cout << "****************************************************" << endl;
    cout << "*****************欢迎参加演讲比赛**********************" << endl;
    cout << "*****************1.开始演讲比赛***********************" << endl;
    cout << "*****************2.查看往届记录***********************" << endl;
    cout << "*****************3.清除比赛记录***********************" << endl;
    cout << "*****************4.退出比赛程序***********************" << endl;
    cout << "****************************************************" << endl;
    cout << endl;
}
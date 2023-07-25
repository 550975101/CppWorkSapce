//
// Created by 封心 on 2023/7/25.
//
#pragma once

#include "Speaker.h"
#include "iostream"
#include "vector"
#include "map"

using namespace std;

#ifndef CWORKSPACE_SPEECHMANAGER_H
#define CWORKSPACE_SPEECHMANAGER_H

#endif //CWORKSPACE_SPEECHMANAGER_H

class SpeechManager {

public:
    //构造函数
    SpeechManager();

    //展示菜单
    void show_menu();

    //退出系统
    void exitSystem();

    //析构函数
    ~SpeechManager();

    //初始化容器和属性的操作
    void initSpeech();

    //初始化创建12名选手
    void createSpeaker();

    //开始比赛
    void startSpeech();

    //抽签
    void speechDraw();

    //比赛
    void speechContest();

    //比赛选手 容器 12人
    vector<int> v1;
    //第一轮晋级容器 6人
    vector<int> v2;
    //胜利前三名容器 3人
    vector<int> vVictory;
    //存放编号以及对应的具体选手 容器
    map<int, Speaker> m_Speaker;
    //记录比赛轮数
    int m_index;
};
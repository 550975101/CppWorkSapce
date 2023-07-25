//
// Created by 封心 on 2023/7/25.
//
#include <algorithm>
#include <deque>
#include <numeric>
#include <fstream>
#include "speechManager.h"
#include "string"
#include "iostream"

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
    exit(0);
    system("pause");
}

void SpeechManager::initSpeech() {
    //容器都置为空
    this->v1.clear();
    this->v2.clear();
    this->vVictory.clear();
    this->m_Speaker.clear();

    //初始化比赛轮数
    this->m_index = 1;
    //初始化容器记录
    this->m_Record.clear();
}

void SpeechManager::createSpeaker() {
    string nameSeed = "ABCDEFGHIJKL";
    for (int i = 0; i < nameSeed.size(); i++) {
        string name = "选手";
        name += nameSeed[i];
        //创建具体选手
        Speaker sp;
        sp.m_Name = name;
        for (int j = 0; j < 2; j++) {
            sp.m_score[j] = 0;
        }
        //12名选手编号
        this->v1.push_back(i + 10001);
        //选手编号以及对应的选手 放入map容器中
        this->m_Speaker.insert(make_pair(i + 10001, sp));
    }
}

void SpeechManager::speechDraw() {
    cout << "第<<" << this->m_index << ">>轮比赛选手正在抽签" << endl;
    cout << "---------------------------------------" << endl;
    cout << "抽签后演讲顺序如下： " << endl;
    if (this->m_index == 1) {
        random_shuffle(v1.begin(), v1.end());
        for (auto it = v1.begin(); it != v1.end(); it++) {
            cout << *it << " ";
        }
        cout << endl;
    } else {
        random_shuffle(v2.begin(), v2.end());
        for (auto it = v2.begin(); it != v2.end(); it++) {
            cout << *it << " ";
        }
        cout << endl;
    }
    cout << "---------------------------------------" << endl;
    system("pause");
    cout << endl;
}

void SpeechManager::speechContest() {
    cout << "第<<" << this->m_index << ">>轮比赛正式开始： " << endl;
    //临时容器保存key分数 value选手编号
    multimap<double, int, greater<double>> groupScore;
    //记录人员数，6为一组
    int num = 0;
    vector<int> v_Src;
    if (this->m_index == 1) {
        v_Src = v1;
    } else {
        v_Src = v2;
    }
    //遍历所有参赛选手
    for (vector<int>::iterator it = v_Src.begin(); it != v_Src.end(); it++) {
        num++;
        //评委打分
        deque<double> d;
        for (int i = 0; i < 10; i++) {
            double score = (rand() % 401 + 600) / 10.f;
            cout << score << " ";
            d.push_back(score);
        }
        //排序
        sort(d.begin(), d.end(), greater<double>());
        //去掉最高分
        d.pop_front();
        //去掉最低分
        d.pop_back();
        //获取总分
        double sum = accumulate(d.begin(), d.end(), 0.0f);
        //获取平均分
        double avg = sum / (double) d.size();

//        cout << "编号: " << *it << " 选手: " << this->m_Speaker[*it].m_Name << " 获取平均分为: " << avg << endl;
        this->m_Speaker[*it].m_score[this->m_index - 1] = avg;
        groupScore.insert(make_pair(avg, *it));
        if (num % 6 == 0) {
            cout << "第" << num / 6 << "小组比赛名次: " << endl;
            for (multimap<double, int, greater<double>>::iterator it = groupScore.begin();
                 it != groupScore.end(); it++) {
                cout << "编号: " << it->second << " 姓名: " << this->m_Speaker[it->second].m_Name << " 成绩: "
                     << this->m_Speaker[it->second].m_score[this->m_index - 1] << endl;
            }
            int count = 0;
            //去前三名
            for (multimap<double, int, greater<double>>::iterator it = groupScore.begin();
                 it != groupScore.end() && count < 3; it++, count++) {
                if (this->m_index == 1) {
                    v2.push_back((*it).second);
                } else {
                    vVictory.push_back((*it).second);
                }
            }
            groupScore.clear();
            cout << endl;
        }
    }
    cout << "第<<" << this->m_index << ">>轮比赛正式完成： " << endl;
    system("pause");
}

void SpeechManager::showScore() {
    cout << "第" << this->m_index << "轮晋级选手信息如下: " << endl;
    vector<int> v;
    if (this->m_index == 1) {
        v = v2;
    } else {
        v = vVictory;
    }
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        cout << "选手编号: " << *it << "姓名: " << m_Speaker[*it].m_Name << " 得分: "
             << m_Speaker[*it].m_score[this->m_index - 1] << endl;
    }
    cout << endl;
    system("pause");
    system("cls");
    this->show_menu();
}

void SpeechManager::saveRecord() {
    ofstream ofs;
    //用输出的方式打开文件  写文件
    ofs.open("speech.csv", ios::out | ios::app);
    //将每个人数据写入文件中
    for (vector<int>::iterator it = vVictory.begin(); it != vVictory.end(); it++) {
        ofs << *it << "," << m_Speaker[*it].m_score[1] << ",";
    }
    ofs << endl;
    //关闭文件
    ofs.close();
    cout << "记录已保存" << endl;
}

void SpeechManager::loadRecord() {
    //输入流对象 读取文件
    ifstream ifs("speech.csv", ios::in);
    if (!ifs.is_open()) {
        this->fileIsEmpty = true;
        cout << "文件不存在!" << endl;
        ifs.close();
        return;
    }
    char ch;
    ifs >> ch;
    if (ifs.eof()) {
        cout << "文件为空!" << endl;
        this->fileIsEmpty = true;
        ifs.close();
        return;
    }

    //文件不为空
    this->fileIsEmpty = false;

    ifs.putback(ch);

    string data;

    int index = 0;
    while (ifs >> data) {
        cout << data << endl;

        vector<string> v;
        int pos = 0;
        int start = 0;
        while (true) {
            //从0开始查找
            pos = data.find(",", start);
            if (pos == -1) {
                //找不到break
                break;
            }
            //找到了 进行分割 参数1起始位置 参数2截取长度
            string temp = data.substr(start, pos - start);
            v.push_back(temp);
            start = pos + 1;
        }
        this->m_Record.insert(make_pair(index, v));
        index++;
    }
    ifs.close();
//    for (map<int, vector<string>>::iterator it = m_Record.begin(); it != m_Record.end(); it++) {
//        cout << it->first << "冠军编号" << it->second[0] << " 分数: " << it->second[1] << endl;
//    }
}

void SpeechManager::showRecord() {
    for (int i = 0; i < this->m_Record.size(); i++) {
        cout << "第" << i + 1 << "届 "
             << "冠军编号： " << this->m_Record[i][0] << "得分: " << this->m_Record[i][1] << " "
             << "亚军编号： " << this->m_Record[i][2] << "得分: " << this->m_Record[i][3] << " "
             << "季军编号： " << this->m_Record[i][4] << "得分: " << this->m_Record[i][5] << endl;
    }
    system("pause");
    system("cls");
}

//开始比赛
void SpeechManager::startSpeech() {
    //第一轮比赛
    //1、抽签
    this->speechDraw();
    //2、比赛
    this->speechContest();
    //3、显示晋级结果
    this->showScore();
    //4、第二轮比赛
    this->m_index++;
    //1、抽签
    this->speechDraw();
    //2、比赛
    this->speechContest();
    //3、显示比赛最终结果
    this->showScore();
    //4、保存分数
    this->saveRecord();

    //重置比赛
    this->initSpeech();
    //创建选手
    this->createSpeaker();
    //获取往届记录
    this->loadRecord();
    cout << "本届比赛完毕" << endl;
    system("pause");
    system("cls");
}

void SpeechManager::show_menu() {
    cout << "****************************************************" << endl;
    cout << "*****************欢迎参加演讲比赛**********************" << endl;
    cout << "*****************1.开始演讲比赛***********************" << endl;
    cout << "*****************2.查看往届记录***********************" << endl;
    cout << "*****************3.清除比赛记录***********************" << endl;
    cout << "*****************0.退出比赛程序***********************" << endl;
    cout << "****************************************************" << endl;
    cout << endl;
}
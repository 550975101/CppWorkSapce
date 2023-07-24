//
// Created by 封心 on 2023/7/24.
//
#include <fstream>
#include "iostream"

using namespace std;

int main() {
    char data[100];
    ofstream outfile;
    // 以写模式打开文件
    outfile.open("afile.dat");
    cout << "Writing to the file" << endl;
    cout << "Enter your name: ";
    cin.getline(data, 100);
    //向文件中写入用户输入的数据
    outfile << data << endl;
    cin >> data;
    cin.ignore();

    //再次向文件中写入用户输入的数据
    outfile << data << endl;

    //关闭打开的文件
    outfile.close();

    // 以读模式打开文件
    ifstream inFile;
    inFile.open("afile.dat");
    cout << "Reading from the file" << endl;
    inFile >> data;
    // 在屏幕上写入数据
    cout << data << endl;
    // 再次从文件读取数据，并显示它
    inFile >> data;
    cout << data << endl;
    //关闭打开的文件
    inFile.close();

}

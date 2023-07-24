//
// Created by 封心 on 2023/7/13.
//
#include "iostream"
#include "cstring"

using namespace std;

void printBook(struct Books book);

struct Books {
    char title[50];
    char author[50];
    char subject[100];
    int book_id;
};

int main() {
    Books book1{};
    Books book2{};

    //BooK1 详述
    strcpy(book1.title, "C++教程");
    strcpy(book1.author, "Runoob");
    strcpy(book1.subject, "编程语言");
    book1.book_id = 12345;

    //BooK1 详述
    strcpy(book2.title, "CSS 教程");
    strcpy(book2.author, "Runoob");
    strcpy(book2.subject, "前端技术");
    book2.book_id = 12345;
    // 输出 Book1 信息
    printBook(book1);

    // 输出 Book2 信息
    printBook(book2);
}

void printBook(struct Books book) {
    cout << "书标题 : " << book.title << endl;
    cout << "书作者 : " << book.author << endl;
    cout << "书类目 : " << book.subject << endl;
    cout << "书 ID : " << book.book_id << endl;
};
//
// Created by 封心 on 2023/7/24.
//
#include "iostream"

using namespace std;

struct MyException : public exception {
    [[nodiscard]] const char *what() const noexcept override {
        return "C++ Exception";
    }
};

int main() {
    try {
        throw MyException();
    } catch (MyException &e) {
        cout << "MyException caught" << endl;
        cout << e.what() << endl;
    } catch (exception &exception) {

    }
}

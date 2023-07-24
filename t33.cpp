//
// Created by 封心 on 2023/7/24.
//
#include "iostream"
#include "vector"

using namespace std;

template<class T>
class Stack {
private:
    vector<T> elems;
public:
    //入栈
    void push(T const &);

    //出栈
    void pop();

    //返回栈顶元素
    T top() const;

    //如果为空则返回空值
    bool empty() const {
        return elems.empty();
    }
};

template<class T>
void Stack<T>::push(T const &elem) {
    elems.push_back(elem);
}

template<class T>
void Stack<T>::pop() {
    if (elems.empty()) {
        throw out_of_range("Stack<>::pop(): empty stack");
    }
    // 删除最后一个元素
    elems.pop_back();
}

template<class T>
T Stack<T>::top() const {
    if (elems.empty()) {
        throw out_of_range("Stack<>::top: empty stack");
    }
    // 返回最后一个元素的副本
    return elems.back();
}


int main() {
    try {
        //int 类型的栈
        Stack<int> inStack;
        //string类型的栈
        Stack<string> stringStack;
        //操作int类型的栈
        inStack.push(7);
        cout << inStack.top() << endl;

        //操作string类型的栈
        stringStack.push("hello");
        cout << stringStack.top() << endl;
        stringStack.pop();
        stringStack.pop();
    } catch (exception const &ex) {
        cerr << "Exception: " << ex.what() << endl;
        return -1;
    }
}

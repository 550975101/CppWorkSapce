//
// Created by 封心 on 2023/7/21.
//

#include "iostream"

using namespace std;
const int SIZE = 10;

class SafeArray {
private:
    int arr[SIZE];
public:
    SafeArray() {
        for (int i = 0; i < SIZE; ++i) {
            arr[i] = i;
        }
    }

    int &operator[](int i) {
        if (i >= SIZE) {
            cout << "索引操作最大值" << endl;
            return arr[0];
        }
        return arr[i];
    }
};

int main() {
    SafeArray array;
    cout << "A[2]的值为: " << array[2] << endl;
    cout << "A[5]的值为: " << array[5] << endl;
    cout << "A[12]的值为: " << array[12] << endl;
}
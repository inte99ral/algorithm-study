#include <algorithm>
#include <cstdarg>
#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;

int func1() {
}

int main() {
  {
    // 벡터 복사
    // vector<string> sVec1 = {"1.c", "2.h", "3.a", "4.r"};
    // cout << "[";
    // for (string s : sVec1) cout << s << ", ";
    // cout << "\b\b] \n";

    // vector<string> sVec2 = {"", "", "", ""};

    // cout << "[5]: " << sVec2.size() << endl;

    // copy(sVec1.begin() + 2, sVec1.end(), sVec2.begin());

    // cout << "[6]: " << sVec2.size() << endl;

    // cout << "[";
    // for (string s : sVec2) cout << s << ", ";
    // cout << "\b\b] \n";
  }

  string input = "";

  int arr1[8] = {0, 1, 2, 3, 4, 5, 6, 7};
  int arr2[3][3];

  for (int y = 0; y < 0; y++) {
    for (int x = 0; x < 0; x++) {
      cout << arr2[y][x] << ", ";
    }
    cout << "\b\b\n";
  }

  // copy((int*)arr1, (int*)arr1 + 8, (int*)arr2);  // 사이즈가 안맞아도 복사 가능

  // func1(arr2, sizeof(arr2) / sizeof(arr2[0]), "arr2");  // 사이즈가 안맞아도 복사 가능

  // // copy(arr1, arr1 + 25, arr2);
  // // copy(&arr1[0][0], &arr1[0][0] + 4, &arr2[0][0]);

  // copy((int*)arr1, (int*)arr1 + 4, (int*)arr2);

  // // cout << "arr1 TYPE:" << typeid(arr1).name() << " V: " << arr1 << endl;
  // // cout << "arr1 TYPE:" << typeid(&arr1[0][0]).name() << " V: " << &arr1[0][0] << endl;

  // cout << "arr1: " << typeid(arr1).name() << endl;
  // cout << "arr2: " << typeid(arr2).name() << endl;

  // copy((int*)arr3, (int*)arr3 + 4, (int*)arr2);  // 메모리 복사로 동적할당된 배열과 정적할당된 배열간의 깊은 복사를 할 수 있다.

  // arr2[0][2] = 67;

  // func1((int*)arr1, 20);

  // func1((int*)arr2, 20);

  return 0;
}

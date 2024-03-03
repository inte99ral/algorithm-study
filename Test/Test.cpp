#include <algorithm>
#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;

int func1(int arr[], int N) {
  cout << "fnc1: " << typeid(arr).name() << " - N: " << N << endl;
  for (int n = 0; n < N; n++) cout << arr[n] << ' ';
  cout << '\b' << endl;
  return 0;
}

int main() {
  string input = "";

  int arr1[5] = {10, 11, 12, 13, 14};
  int arr2[2];

  copy((int*)arr1, (int*)arr1 + 2, (int*)arr2);

  func1(arr2, 2);

  // int arr1[5][5] = {{10, 11, 12, 13, 14}, {20, 21, 22, 23, 24}};
  // int arr2[5][5] = {};

  // int** arr3 = new int*[5];

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

  // delete arr3;

  return 0;
}

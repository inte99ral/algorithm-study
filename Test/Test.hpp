#ifndef TEST_HPP
#define TEST_HPP

#include <cstdarg>
#include <iostream>
#include <queue>
#include <typeinfo>

using namespace std;

class ArrayParameter {
 private:
  int a;
  void printArrRecur(int* arr, queue<int> arrData);

 public:
  void printArr(int* arr, ...);

  template <typename T, size_t N>
  void idCheck(T (&arr)[N]) {
    cout << "=====TYPE: " << typeid(arr).name() << "=====\n";

    cout << "[";
    for (int n = 0; n < N; n++) {
      cout << *((T*)arr + n) << ", ";
    }
    cout << "\b\b] \n";
  };
};

#endif
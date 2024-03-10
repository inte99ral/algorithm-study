#ifndef TEST_HPP
#define TEST_HPP

#include <cstdarg>
#include <iostream>
#include <queue>
#include <regex>
#include <typeinfo>

using namespace std;

class ArrayParameter {
 private:
  int a;
  void printArrRecur(int* arr, queue<int> arrData);

 public:
  void printArr(int* arr, ...);

  template <typename T, size_t N>
  void idCheck(T (&arr)[N]);
};

template <typename T, size_t N>
void ArrayParameter::idCheck(T (&arr)[N]) {
  string typeName = typeid(arr).name();

  regex regExp("A[0-9]+_", regex::optimize);

  sregex_token_iterator iter(typeName.begin(), typeName.end(), regExp), end;

  while (iter != end) {
    cout << stoi(((string)*iter).substr(1, ((string)*iter++).size() - 2)) << endl;
  }
}

#endif
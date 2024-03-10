#ifndef TEST_HPP
#define TEST_HPP

#include <cstdarg>
#include <deque>
#include <iostream>
#include <regex>
#include <typeinfo>

using namespace std;

// Prototype Declaration ==========

class ArrayTool {
 private:
  void printRecur(int* arr, deque<int> arrData);

 public:
  template <typename T, size_t N>
  void print(T (&arr)[N]);
};

// Implements Definition ==========

template <typename T, size_t N>
void ArrayTool::print(T (&arr)[N]) {
  deque<int> arrData;
  string arrType = typeid(arr).name();
  regex regExp("A[0-9]+_", regex::optimize);

  sregex_token_iterator iter(arrType.begin(), arrType.end(), regExp), end;

  while (iter != end) {
    string token = (string)*iter++;
    arrData.push_back(stoi(token.substr(1, token.size() - 2)));
  }

  printRecur((int*)arr, arrData);
}

#endif
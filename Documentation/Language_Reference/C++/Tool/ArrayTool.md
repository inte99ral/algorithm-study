# CmdTool

## 선언부

```cpp
#ifndef ARRAY_TOOL_HPP
#define ARRAY_TOOL_HPP

#include <windows.h>

#include <deque>
#include <iostream>
#include <regex>
#include <typeinfo>

// Prototype Declaration ====================
// ArrayTool ======================
class ArrayTool {
 private:
  int defaultTextColor = 15;
  void printRecur(int* arr, std::deque<int> arrData);

 public:
  template <typename T, size_t N>
  void print(T (&arr)[N]);
};

// Implements Definition ====================
// ArrayTool ======================
template <typename T, size_t N>
void ArrayTool::print(T (&arr)[N]) {
  std::deque<int> arrData;
  std::string arrType = typeid(arr).name();
  std::regex regExp("A[0-9]+_", std::regex::optimize);

  std::sregex_token_iterator iter(arrType.begin(), arrType.end(), regExp), end;

  while (iter != end) {
    std::string token = (std::string)*iter++;
    arrData.push_back(std::stoi(token.substr(1, token.size() - 2)));
  }

  printRecur((int*)arr, arrData);
  std::cout << "\b\b  " << std::endl;
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}

#endif
```

## 구현부

```cpp
#include "ArrayTool.hpp"

// Implements Definition ====================
// ArrayTool ======================
void ArrayTool::printRecur(int* arr, std::deque<int> arrData) {
  if (arrData.size() == 0) std::cout << *arr << ", ";
  else {
    int N = arrData.front();
    arrData.pop_front();
    int gap = 1;
    for (int i : arrData) gap *= i;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), arrData.size());
    std::cout << "[";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ArrayTool::defaultTextColor);

    for (int n = 0; n < N; n++) {
      printRecur(arr, arrData);
      arr += gap;
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), arrData.size());
    std::cout << "\b\b], ";
  }
}
```

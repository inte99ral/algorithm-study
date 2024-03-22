#ifndef ARRAY_TOOL_HPP
#define ARRAY_TOOL_HPP

#include <deque>
#include <iostream>
#include <regex>
#include <typeinfo>

// Prototype Declaration ====================
// ArrayTool ===========================
class ArrayTool {
 private:
  void printRecur(int* arr, std::deque<int> arrData);

 public:
  template <typename T, size_t N>
  void print(T (&arr)[N]);
};

// Implements Definition ====================
// ArrayTool ===========================
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
}
#endif
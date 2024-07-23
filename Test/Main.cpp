#include <bits/stdc++.h>

using namespace std;

// # Prototype Declaration ====================
class ArrayTool {
/*
  // Requires these conditions
  #include <deque>
  #include <iostream>
  #include <regex>
  #include <typeinfo>
*/

 private:
  void printRecur(int* arr, std::deque<int> arrData) {
    if (arrData.size() == 0) std::cout << "\033[0m" << *arr << ", ";
    else {
      int N = arrData.front();
      arrData.pop_front();
      int gap = 1;
      int color = 31 + (arrData.size() % 6);
      for (int i : arrData) gap *= i;
      std::cout << "\033[" << color << "m[";

      for (int n = 0; n < N; n++) {
        printRecur(arr, arrData);
        arr += gap;
      }
      std::cout << "\033[" << color << "m\b\b]\033[0m, ";
    }
  }

 public:
  template <typename T, size_t N>
  void print(T (&arr)[N]) {
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
};

// # Implements Definition ====================
// ## Main
int main() {
  int a[2][2][2] = {{{1, 9}, {2, 8}}, {{3, 7}, {4, 6}}};

  ArrayTool at;
  at.print(a);

  return 0;
}
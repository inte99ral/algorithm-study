#include "ArrayTool.hpp"

//# Prototype Declaration ====================
//# ArrayTool ===========================
void ArrayTool::printRecur(int* arr, std::deque<int> arrData) {


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
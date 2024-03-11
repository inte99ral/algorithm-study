#include "Test.hpp"

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
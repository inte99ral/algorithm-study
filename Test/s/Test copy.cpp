#include "Test.hpp"

using namespace std;

void ArrayParameter::printArr(int* arr, ...) {
  queue<int> argQue;
  va_list ap;
  va_start(ap, arr);
  for (int arg = va_arg(ap, int); arg != 0; arg = va_arg(ap, int)) argQue.push(arg);

  cout << "[--SAFETY--  ";
  // printArrRecur(arr, argQue);
  cout << "\b\b] \n";

  return;
}

void ArrayParameter::printArrRecur(int* arr, queue<int> arrData) {
  if (arrData.empty()) {
    cout << *arr << ", ";
  }
  else {
  }
}

// template <typename T>
// void ArrayParameter::idCheck(T arr) {
//   cout << "[" << typeid(arr).name() << "]" << endl;
// }

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

// template <size_t N>
// void ArrayParameter::idCheck(int (&arr)[N]) {
//   cout << "WORK" << endl;
//   // cout << "=====TYPE: " << typeid(arr).name() << "=====\n";

//   // cout << "[";
//   // for (int n = 0; n < N; n++) {
//   //   cout << *((T*)arr + n) << ", ";
//   // }
//   // cout << "\b\b] \n";
// };
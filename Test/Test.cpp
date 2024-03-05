#include "Test.hpp"

using namespace std;

void arrayParameter::printArr(int* arr, ...) {
  vector<int> argVec;
  va_list ap;
  va_start(ap, arr);
  for (int arg = va_arg(ap, int); arg != 0; arg = va_arg(ap, int)) argVec.push_back(arg);

  for (int i = 0; i < argVec[0]; i++) {
    cout << *arr + i << ", ";
  }

  cout << "\b\b  \n";
  return;
}

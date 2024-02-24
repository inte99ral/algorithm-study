/**
 * 가변 인자 (Variable argument)
 */
#include <cstdarg>
#include <iostream>
#include <typeinfo>

using namespace std;

void func(int args, ...) {
  va_list list;

  va_start(list, args);  // 마지막 고정인수

  for (int i = 0; i < args; i++) {
    int temp = va_arg(list, int);
    cout << temp << endl;
  }

  va_end(list);
}

int main() {
  func(4, 'c', 'g', 'x', '\0');

  int arr1[2][3] = {{1, 2, 3}, {4, 5, 6}};
  int arr2[3] = {1, 2, 3};
  int arr3 = 1;

  cout << typeid(arr1).name() << endl;
  cout << typeid(arr2).name() << endl;
  cout << typeid(arr3).name() << endl;

  return 0;
}
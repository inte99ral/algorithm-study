/**
 * 가변 인자 (Variable argument)
 */
#include <cstdarg>
#include <iostream>

using namespace std;

void func(int args, ...) {
  va_list list;

  va_start(list, args);

  for (int i = 0; i < args; i++) {
    int temp = va_arg(list, int);
    cout << temp << endl;
  }

  va_end(list);
}

int main() {
  func(4, 'c', 'g', 'x', '\0');

  return 0;
}
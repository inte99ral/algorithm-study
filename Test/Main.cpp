// #include <iostream>
// #include <string>
// #include <vector>

#include "Test.hpp"

#define VERSION 3.1f

using namespace std;

int main() {
  cout << "[VERSION]: " << VERSION << '\n';

  int iArr[2][2][2][2] = {{{{1, 2}, {3, 4}}, {{5, 6}, {7, 8}}}, {}};

  ArrayTool at;
  at.print(iArr);

  return 0;
}

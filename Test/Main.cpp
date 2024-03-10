// #include <iostream>
// #include <string>
// #include <vector>

#include "Test.hpp"

#define VERSION 3.1f

using namespace std;

int main() {
  cout << "[VERSION]: " << VERSION << '\n';

  int iArr[2][2][30] = {{{1, 2}, {3, 4}}, {{5, 6}, {7, 8}}};

  ArrayTool at;
  at.print(iArr);

  // int iArr[2][2][20] = {{{1, 2}, {3, 4}}, {{5, 6}, {7, 8}}};
  // string temp = typeid(iArr).name();
  // cout << temp << endl;

  // char cArr[2][2][2] = {{{'1', '2'}, {'3', '4'}}, {{'5', '6'}, {'7', '8'}}};
  // cout << typeid(typeid(cArr).name()).name() << endl;

  // string sArr[2][2][2] = {{{"1", "2"}, {"3", "4"}}, {{"5", "6"}, {"7", "8"}}};
  // cout << typeid(sArr).name() << endl;

  // regex regExp1("A[0-9]+", regex::optimize);

  // cregex_token_iterator iter(cArr, cArr + 15, regExp1), end;

  // while (iter != end) {
  //   cout << ((string)(*iter++)).back() - '0' + 1000 << '\n';
  // }

  return 0;
}

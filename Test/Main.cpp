#include <iostream>
#include <regex>
#include <string>
#include <typeinfo>
#include <vector>

#define VERSION 3.1f

using namespace std;

int main() {
  cout << "[VERSION]: " << VERSION << '\n';

  char test[] = "A5_A7_A8";

  int iArr[2][2][20] = {{{1, 2}, {3, 4}}, {{5, 6}, {7, 8}}};
  string temp = typeid(iArr).name();
  cout << temp << endl;

  char cArr[2][2][2] = {{{'1', '2'}, {'3', '4'}}, {{'5', '6'}, {'7', '8'}}};
  cout << typeid(typeid(cArr).name()).name() << endl;

  string sArr[2][2][2] = {{{"1", "2"}, {"3", "4"}}, {{"5", "6"}, {"7", "8"}}};
  cout << typeid(sArr).name() << endl;

  // regex regExp1("A[0-9]+", regex::optimize);

  // cregex_token_iterator iter(cArr, cArr + 15, regExp1), end;

  // while (iter != end) {
  //   cout << ((string)(*iter++)).back() - '0' + 1000 << '\n';
  // }

  return 0;
}

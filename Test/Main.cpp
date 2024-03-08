#include <iostream>
#include <regex>
#include <typeinfo>
#include <vector>

#define VERSION 3.1f

using namespace std;

int main() {
  cout << "[VERSION]: " << VERSION << '\n';

  char cArr[] = "db-123-456-789-log.txt";

  regex regExp1("[0-9]+", regex::optimize);
  regex regExp2("db-\\d*-log\\.txt");

  cout << (string)cArr << " : " << sizeof(cArr) / sizeof(char) << " : " << boolalpha << regex_match(&cArr[0], &cArr[14], regExp2) << '\n';

  cregex_token_iterator iter(cArr, cArr + 15, regExp1), end;

  while (iter != end) {
    cout << stoi(*iter++) << '\n'
  }

  return 0;
}

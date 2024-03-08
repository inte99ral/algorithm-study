#include <iostream>
#include <regex>
#include <vector>

using namespace std;

int main() {
  char cArr[] = "db-123-log.txt";

  regex regExp1("[0-9]+");
  regex regExp2("db-\\d*-log\\.txt");

  cout << (string)cArr << " : " << sizeof(cArr) / sizeof(char) << " : " << boolalpha << regex_match(&cArr[0], &cArr[14], regExp2) << '\n';

  return 0;
}

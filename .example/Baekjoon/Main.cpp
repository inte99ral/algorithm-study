#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  freopen(".example\\Baekjoon\\input.txt", "rt", stdin); // -- 로컬 input.txt 입력 코드

  string x;
  getline(cin, x);
  cout << x;
  return 0;
}
#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  freopen("Problem\\Solved\\Baekjoon\\Bronze\\5\\BJ_1000\\info\\input.txt", "rt", stdin);

  int A, B;
  cin >> A >> B;
  cout << A + B;
  return 0;
}
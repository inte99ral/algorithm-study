#include <iostream>
#include <string>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  freopen("Problem\\Failed\\Baekjoon\\Silver\\4\\BJ_1244\\input.txt", "rt", stdin); // -- 로컬 input.txt 입력 코드

  int N;
  int *arr;
  int iArr[10] = {0, 0, 1};

  cin >> N;
  arr = new int[N];

  for(int i : iArr) {
    cout << i << ' ';
  }
  cout << '\n';

  return 0;
}
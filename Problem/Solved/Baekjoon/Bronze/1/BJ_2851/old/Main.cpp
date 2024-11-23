#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  freopen("Problem\\Solved\\Baekjoon\\Bronze\\1\\BJ_2851\\question\\input.txt", "rt", stdin);

  int answer = 0;

  for(int i = 0; i < 10; i++) {
    int input;
    cin >> input;
    if(abs(answer - 100) < abs(answer + input - 100)) break;
    answer += input;
  }

  cout << answer;

  return 0;
}
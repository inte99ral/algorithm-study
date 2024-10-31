#include <iostream>

using namespace std;

int main() {
  freopen("Problem\\Solved\\Baekjoon\\Bronze\\2\\BJ_2292\\.input.txt", "rt", stdin);

  int N = 0;
  int answer = 1;
  cin >> N;
  while(N > 3 * (answer * (answer - 1)) + 1) answer++;
  cout << answer;
  return 0;
}
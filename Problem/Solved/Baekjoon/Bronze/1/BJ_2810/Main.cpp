#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  freopen("Problem\\Solved\\Baekjoon\\Bronze\\1\\BJ_2810\\question\\input.txt", "rt", stdin);

  int answer;
  int N;
  string input;

  cin >> N;
  cin >> input;

  answer = N + 1;
  for(int n = 0; n < N; n++) {
    if(input.at(n) == 'L') {
      answer--;
      n++;
    }
  }

  cout << (answer == N + 1? N : answer);

  return 0;
}
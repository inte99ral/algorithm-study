#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  freopen("Problem\\Solved\\Baekjoon\\Bronze\\2\\BJ_2292\\question\\input.txt","rt", stdin); // -- 로컬

  int N;
  int answer;

  cin >> N;

  answer = 1;
  while(N > 3 * (answer * (answer - 1)) + 1) answer++; // 등차수열의 합
  cout << answer;

  return 0;
}
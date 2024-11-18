#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#define SET_IO(INPUT_PATH) freopen(INPUT_PATH, "rt", stdin)
#else
#define SET_IO(INPUT_PATH) std::ios::sync_with_stdio(false); std::cin.tie(nullptr); cout.tie(nullptr)
#endif

using namespace std;

int main() {
  SET_IO("Problem\\Solved\\Baekjoon\\Silver\\5\\BJ_2563\\_INPUT_.txt");

  int answer;
  int N;
  int matrix[101][101] = {};

  cin >> N;

  answer = N * 100;

  for (int n = 0; n < N; n++) {
    int X, Y;
    cin >> X >> Y;
    for (int x = X; x < X + 10; x++) {
      for (int y = Y; y < Y + 10; y++) {
        if (matrix[x][y]) answer--;
        matrix[x][y] = true;
      }
    }
  }

  cout << answer;
  return 0;
}
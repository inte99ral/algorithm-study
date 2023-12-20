#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  freopen("Problem\\Failed\\Baekjoon\\Silver\\5\\BJ_2563\\question\\input.txt", "rt", stdin);

  bool matrix[101][101] = {false,};
  int N;
  int answer = 0;

  cin >> N;
  for (int i = 0; i < N; i++) {
    int xCoord, yCoord;

    cin >> xCoord >> yCoord;
    for (int x = xCoord; x < xCoord + 10; x++) {
      for (int y = yCoord; y < yCoord + 10; matrix[x][y++] = true) {
        if (!matrix[x][y]) answer++;
      }
    }
  }

  cout << answer << '\n';
  return 0;
}
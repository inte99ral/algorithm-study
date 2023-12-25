/**
 * 2차원 배열 형성 후, 데이터를 모두 입력받고 사방향에 빈 곳이 있는 지 체크
 */
#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  freopen("Problem\\Solved\\Baekjoon\\Silver\\4\\BJ_2567\\question\\input.txt", "rt", stdin); // -- input.txt
  int answer = 0;

  int N;
  bool (*matrix)[101] = new (bool[101][101])();

  cin >> N;
  for(;N--;) {
    int X;
    int Y;

    cin >> X >> Y;

    for(int y = Y; y < Y + 10; y++)
      for(int x = X; x < X + 10; x++)
        matrix[y][x] = true;
  }

  for(int y = 0; y < 101; y++) {
    for(int x = 0; x < 101; x++) {
      if(matrix[y][x]) {
        if(!matrix[y - 1][x]) answer++;
        if(!matrix[y][x - 1]) answer++;
        if(!matrix[y + 1][x]) answer++;
        if(!matrix[y][x + 1]) answer++;
      }
    }
  }

  delete[] matrix;

  cout << answer;
  return 0;
}
/**
 * 서로소 알고리즘 사용
 * 데이터를 집어 넣으면서 8방향 주변에 연결되어 있는 배열을 확인
 * 각 배열 안에는 연결되어있는 다른 배열 중 가장 작은 좌표값을 가지고 있다.
 * 결국, 데이터를 다 집어넣고 난 이후에는 배열 값 == 본인 좌표값 인 배열의 수가 연결되어있는 섬의 수이다.
 */
#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  freopen("Problem\\Solved\\Baekjoon\\Silver\\2\\BJ_4963\\question\\input.txt", "rt", stdin);
  
  const int dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
  const int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

  while(true) {
    int W, H;
    cin >> W >> H;

    if(W == 0) return 0;

    int matrix[H + 2][W + 2] = {};
    int answer = 0;

    for(int h = 1; h <= H; h++) {
      for(int w = 1; w <= W; w++) {
        cin >> matrix[h][w];

        if(!matrix[h][w]) continue;

        matrix[h][w] = h * (W + 2) + w;

        for(int i = 0; i < 8; i++) {

          if(matrix[h + dy[i]][w + dx[i]] == 0) continue;

          int y = h + dy[i];
          int x = w + dx[i];

          while(matrix[y][x] != y * (W + 2) + x) {
            int temp = matrix[y][x];
            y = temp / (W + 2);
            x = temp % (W + 2);
          }

          if(matrix[y][x] < matrix[h][w]) matrix[matrix[h][w] / (W + 2)][matrix[h][w] % (W + 2)] = matrix[y][x];
          else matrix[y][x] = matrix[h][w];
        }
      }
    }

    for(int h = 1; h <= H; h++) for(int w = 1; w <= W; w++) if(matrix[h][w] == h * (W + 2) + w) answer++;
    cout << answer << '\n';
  }

  return 0;
}
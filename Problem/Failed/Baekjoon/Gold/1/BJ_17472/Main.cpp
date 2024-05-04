#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  freopen("Problem\\Failed\\Baekjoon\\Gold\\1\\BJ_17472\\question\\input.txt", "rt", stdin);

  const int dy[4] = {-1, 0, 0, 1};
  const int dx[4] = {0, -1, 1, 0};

  int N;
  int M;
  int** matrix;

  cin >> N >> M;

  matrix = new int*[N + 2]();
  matrix[0] = new int[M + 2]();

  for (int n = 1; n < N + 1; n++) {
    matrix[n] = new int[M + 2]();

    for (int m = 1; m < M + 1; m++) {
      cin >> matrix[n][m];
      if(matrix[n][m] == 0) continue;

      matrix[n][m] = (n * (M + 2)) + m;

      for (int i = 0; i < 2; i++) {
        int y = n + dy[i];
        int x = m + dx[i];
        if (matrix[y][x] == 0) continue;

        while ((y != matrix[y][x] / (M + 2)) || (x != matrix[y][x] % (M + 2))) {
          y = matrix[y][x] / (M + 2);
          x = matrix[y][x] % (M + 2);
        }

        if (matrix[matrix[n][m] / (M + 2)][matrix[n][m] % (M + 2)] < matrix[y][x]) matrix[y][x] = matrix[matrix[n][m] / (M + 2)][matrix[n][m] % (M + 2)];
        else matrix[matrix[n][m] / (M + 2)][matrix[n][m] % (M + 2)] = matrix[y][x];
      }
    }
  }

  matrix[N + 1] = new int[M + 2]();

  // goto ACT_0;
  { // ACT_0
    int count = 0;

    for (int n = 1; n < N + 1; n++) {
      for (int m = 1; m < M + 1; m++) {
        if (matrix[n][m] == 0) continue;
        if ((n == matrix[n][m] / (M + 2)) && (m == matrix[n][m] % (M + 2))) continue;
      }
    }

  }
  ACT_0:



  // goto TEST_0;
  { //_TEST_0
    for (int n = 0; n < N + 2; n++) {
      for (int m = 0; m < M + 2; m++) {
        if (matrix[n][m] == 0) {
          cout << "-- ";
          continue;
        }

        cout.width(2);
        cout.fill('-');
        cout << matrix[n][m] << " ";
      }
      cout << "\b \n";
    }
  }
  TEST_0:

  delete[] matrix;
  return 0;
}
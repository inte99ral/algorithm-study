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

  for (int n = 1; n < N + 2; n++) {
    matrix[n] = new int[M + 2]();
    for (int m = 1; m < M + 2; m++) {
      int temp;
      cin >> temp;
      goto ACT_1;
      { //_ACT_1 서로소 알고리즘
        if (int i = 0; i < 2; i++) {
          if(matrix[n + dy[i]][m + dx[i]] != 0) {

          }
        }
      }
      ACT_1:
      matrix[n][m] = temp;
    }
  }

  goto TEST_0;
  { //_TEST_0
    for (int n = 0; n < N; n++) {
      for (int m = 0; m < M; m++) {
        cout << matrix[n][m] << ", ";
      }
      cout << "\b\b  \n";
    }
  }
  TEST_0:

  delete[] matrix;
  return 0;
}
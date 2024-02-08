#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  freopen("Problem\\Failed\\Baekjoon\\Gold\\5\\BJ_15686\\question\\input.txt", "rt", stdin);

  int N;
  int M;
  vector<vector<int>> matrix;

  vector<vector<int>> cVec;  // chicken vector
  vector<vector<int>> hVec;  // house vector

  cin >> N >> M;

  for (int y = 0; y < N; y++) {
    vector<int> tempVec;
    for (int x = 0; x < N; x++) {
      int tempInt;
      cin >> tempInt;
      tempVec.push_back(tempInt);
      if (tempInt == 1) {
        continue;
      }
      else if (tempInt == 2) {
        continue;
      }
    }
    matrix.push_back(tempVec);
  }

  if (N == 0) return;

  // for (int y = 0; y < N; y++) {
  //   for (int x = 0; x < N; x++)
  //     cout << matrix[y][x] << ' ';
  //   cout << endl;
  // }

  return 0;
}
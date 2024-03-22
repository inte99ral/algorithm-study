#include <iostream>
#include <vector>

using namespace std;

const int dy[4] = {-1, 0, 0, 1};
const int dx[4] = {0, -1, 1, 0};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  freopen("Problem\\Failed\\Baekjoon\\Gold\\5\\BJ_7576\\question\\input.txt", "rt", stdin);

  int M;
  int N;
  cin >> M >> N;

  vector<vector<int>> matrix(N + 2, vector<int>(M + 2, -1));
  vector<pair<int, int>> ripeTmt;
  int unripeTmt = 0;
  int count = 0;
  bool isRipen = true;

  for(int n = 0; n < N; n++) {
    for(int m = 0; m < M; m++) {
      int temp;
      cin >> temp;
      switch(temp) {
        case 1:
          ripeTmt.push_back({n + 1, m + 1});
          break;
        case 0:
          unripeTmt++;
          break;
      }
      matrix[n + 1][m + 1] = temp;
    }
  }

  while(isRipen) {
    isRipen = false;
    for(int i = ripeTmt.size() - 1; i >= 0; i--) {
      for(int j = 0; j < 4; j++) {
        int y = ripeTmt[i].first + dy[j];
        int x = ripeTmt[i].second + dx[j];
        if(matrix[y][x] == 0) {
          matrix[y][x] = 1;
          isRipen = true;
          ripeTmt.push_back({y, x});
          unripeTmt--;
        }
      }
    }

    if(isRipen) count++;
  }

  cout << (unripeTmt ? -1 : count) << endl;


  return 0;
}
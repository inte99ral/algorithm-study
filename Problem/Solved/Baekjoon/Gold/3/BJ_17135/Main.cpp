#include <array>
#include <cstdlib>
#include <deque>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  freopen("Problem\\Failed\\Baekjoon\\Gold\\3\\BJ_17135\\question\\input.txt", "rt", stdin);
  int answer = 0;
  int N, M, D;
  cin >> N >> M >> D;

  vector<array<int, 3>> enemy;

  for (int n = 0; n < N; n++) {
    for (int m = 0; m < M; m++) {
      int temp;
      cin >> temp;
      if (temp == 1) {
        enemy.push_back({n, m, true});
      }
    }
  }

  int origin[M] = {};
  int select[3] = {};

  for (int i = 0; i < M; i++) {
    origin[i] = i;
  }
  deque<pair<int, int>> task{{0, 0}};  // data, size;

  while (!task.empty()) {
    const int data = task.back().first;
    const int size = task.back().second;
    task.pop_back();

    if (size == 3) {
      vector tempEnemy = enemy;
      int count = 0;
      int y = N;

      while (!tempEnemy.empty()) {
        for (int x : select) {
          int minLen = D;
          int minIdx = -1;
          int minLeft = M;
          for (int i = tempEnemy.size() - 1; i >= 0; i--) {
            int l = abs(tempEnemy[i][0] - y) + abs(tempEnemy[i][1] - x);
            if (l < minLen || (l == minLen && tempEnemy[i][1] < minLeft)) {
              minLen = l;
              minIdx = i;
              minLeft = tempEnemy[i][1];
            }
          }

          if (minIdx != -1) tempEnemy[minIdx][2] = false;
        }

        y--;

        for (int i = tempEnemy.size() - 1; i >= 0; i--) {
          if (!tempEnemy[i][2]) {
            tempEnemy.erase(tempEnemy.begin() + i);
            count++;
            continue;
          }

          if (tempEnemy[i][0] == y) {
            tempEnemy.erase(tempEnemy.begin() + i);
            continue;
          }
        }
      }

      if (answer < count) answer = count;

      continue;
    }

    if (data == M) {
      continue;
    }

    task.push_back({data + 1, size});
    select[size] = origin[data];
    task.push_back({data + 1, size + 1});
  }

  cout << answer << endl;

  return 0;
}
// #include <cstdlib>
#include <array>
#include <deque>
#include <iostream>
#include <vector>
// #include <bits/stdc++.h>

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

  {  // DFS Permutation
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
        {  // TODO
          vector tempEnemy = enemy;
          int count = 0;
          int y = N;

          while (!tempEnemy.empty()) {
            for (int x : select) {
              {  // 적들 중 사정거리 안에 들고 가장 가까운 적 조준
                int minLen = D + 1;
                int minIdx = -1;
                for (int i = tempEnemy.size() - 1; i >= 0; i--) {
                  int l = abs(tempEnemy[i][0] - y) + abs(tempEnemy[i][1] - x);
                  if (l <= minLen) {
                    minLen = l;
                    minIdx = i;
                  }
                }

                tempEnemy[minIdx][2] = false;
              }
            }

            // 사수 한 칸 위로
            y--;

            {  // 사격이 종료되면 맞은 적은 제거
              for (int i = tempEnemy.size() - 1; i >= 0; i--) {
                {  // TEST 3
                   // cout << "loop!" << endl;
                }
                if (!tempEnemy[i][2]) {
                  tempEnemy.erase(tempEnemy.begin() + i);
                  count++;
                  cout << "what?\n";
                  continue;
                }
                if (tempEnemy[i][0] == y) {
                  tempEnemy.erase(tempEnemy.begin() + i);
                  continue;
                }
              }
            }

            {  // TEST 3
               // cout << "loop!" << endl;
            }
          }

          if (answer < count) answer = count;

          {  // TEST 2
            for (int i : select) {
              cout << i << ", ";
            }
            cout << "\b\b = " << count << "\n";
          }
        }

        {  // TEST 1
           // for (int i : select) {
           //   cout << i << ", ";
           // }
           // cout << "\b\b  \n";
        }

        continue;
      }

      if (data == M) {
        continue;
      }

      task.push_back({data + 1, size});
      select[size] = origin[data];
      task.push_back({data + 1, size + 1});
    }
  }

  cout << answer << endl;

  return 0;
}
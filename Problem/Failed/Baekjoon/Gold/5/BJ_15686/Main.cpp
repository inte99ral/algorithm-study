#include <iostream>
#include <vector>
#include <deque>
#include <cstdlib>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  freopen("Problem\\Failed\\Baekjoon\\Gold\\5\\BJ_15686\\question\\input.txt", "rt", stdin);

  int N;
  int M;
  // vector<vector<int>> matrix;

  vector<vector<int>> cVecs;  // chicken vector
  vector<vector<int>> hVecs;  // house vector

  cin >> N >> M;

  for (int y = 0; y < N; y++) {
    vector<int> tempVec;
    for (int x = 0; x < N; x++) {
      int tempInt;
      cin >> tempInt;
      // tempVec.push_back(tempInt);
      if (tempInt == 1) {
        hVecs.push_back({y, x});
        continue;
      }
      else if (tempInt == 2) {
        cVecs.push_back({y, x});
        continue;
      }
    }
    // matrix.push_back(tempVec);
  }

  // ========== DFS ==========
  int minLen = hVecs.size() * N * 2;
  vector<vector<int>> select(M, {0, 0});
  deque<pair<int, int>> task = {{0, -1}};

  while(!task.empty()) {
    const int size = task.back().first;
    const int prev = task.back().second;
    task.pop_back();

    if(prev != -1) {
      select[size - 1] = cVecs[prev];
    }

    if(size == M) {
      { // test
        // cout << "[";
        // for(const auto& a1 : select) {
        //   cout << "[";
        //   for(const auto& a2 : a1) {
        //     cout << a2 << ", ";
        //   }
        //   cout << "\b\b], ";
        // }
        // cout << "\b\b] \n";
      }
      
      { // Calc city chicken len
        int len = 0;
        for(vector<int> hVec : hVecs) {
          int min = N * 2;

          for(vector<int> cVec : select) {
            int len = abs(hVec[0] - cVec[0]) + abs(hVec[1] - cVec[1]);
            // cout << len << endl;
            min = (len < min) ? len : min;
          }

          len += min; 
        }
        minLen = (len < minLen) ? len : minLen;
      }
      
      continue;
    }

    for(int i = cVecs.size() - 1; i > prev; i--) {
      task.push_back({size + 1, i});
    }
  }

  cout << minLen << endl;
  return 0;
}
#include <iostream>
#include <vector>

using namespace std;

void combRecur(int N, int R, vector<vector<int>> origin, vector<vector<int>> select, int memory, int count);

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
        hVec.push_back({x, y});
        continue;
      }
      else if (tempInt == 2) {
        cVec.push_back({x, y});
        continue;
      }
    }
    matrix.push_back(tempVec);
  }

  combRecur(cVec.size(), M, cVec, {}, -1, 0);

  return 0;
}

void combRecur(int N, int R, vector<vector<int>> origin, vector<vector<int>> select, int memory, int count) {
  if (count == R) {
    for (vector<int> v : select) cout << "[" << v[0] << ", " << v[1] << "]\n";
    cout << endl;
    return;
  }

  for (int i = memory + 1; i < origin.size(); i++) {
    select.push_back(origin[i]);
    combRecur(N, R, origin, select, i, count + 1);
    select.pop_back();
  }
  return;
}


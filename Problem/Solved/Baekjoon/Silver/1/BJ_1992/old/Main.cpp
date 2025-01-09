#include <iostream>
#include <vector>

using namespace std;

string quadTree(vector<vector<bool>> &matrix, int X, int Y, int L);

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  freopen("Problem\\Solved\\Baekjoon\\Silver\\1\\BJ_1992\\question\\input.txt", "rt", stdin);
  
  int N;
  vector<vector<bool>> matrix;

  cin >> N;
  cin.ignore();

  for(int y = 0; y < N; y++) {
    vector<bool> v;
    char rawInput[N + 1];
    cin.getline(rawInput, N + 1);

    for(int n = 0; n < N; n++) v.push_back(rawInput[n] == '1');
    matrix.push_back(v);
  }

  cout << quadTree(matrix, 0, 0, N);
  return 0;
}

string quadTree(vector<vector<bool>> &matrix, int X, int Y, int L) {
  if(L == 1) return matrix[Y][X]? "1" : "0";
  string UL = quadTree(matrix, X, Y, (L >> 1));
  string UR = quadTree(matrix, X + (L >> 1), Y, (L >> 1));
  string DL = quadTree(matrix, X, Y + (L >> 1), (L >> 1));
  string DR = quadTree(matrix, X + (L >> 1), Y + (L >> 1), (L >> 1));
  
  if((UL.length() == 1) && (UL == UR) && (UL == DL) && (UL == DR)) return UL;
  return '(' + UL + UR + DL + DR + ')';
}
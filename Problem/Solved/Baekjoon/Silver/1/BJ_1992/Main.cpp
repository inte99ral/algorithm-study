#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#define SET_IO(INPUT_DATA) std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);std::ifstream fs(INPUT_DATA);std::cin.rdbuf(fs.is_open()?((std::istream*)&fs)->rdbuf():((std::istream*)new std::stringstream(INPUT_DATA))->rdbuf())
#else
#define SET_IO(INPUT_PATH) std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr)
#endif

using namespace std;

string quadTree(int Y, int X, int L, vector<vector<char>>* matrix);

int main() {
  SET_IO("_INPUT_.txt");

  int N;
  vector<vector<char>> matrix;

  cin >> N;
  cin.ignore();
  matrix = vector<vector<char>>(N, vector<char>(N, 0));

  for (int y = 0; y < N; y++) {
    for (int x = 0; x < N; x++) cin.get(matrix[y][x]);
    cin.ignore();
  }

  cout << quadTree(0, 0, N, &matrix);
  return 0;
}

string quadTree(int Y, int X, int L, vector<vector<char>>* matrixRef) {
  if (L == 1) {
    return string(1, (*matrixRef)[Y][X]);
  }

  string LU = quadTree(Y, X, L >> 1, matrixRef);
  string RU = quadTree(Y, X + (L >> 1), L >> 1, matrixRef);
  string LD = quadTree(Y + (L >> 1), X, L >> 1, matrixRef);
  string RD = quadTree(Y + (L >> 1), X + (L >> 1), L >> 1, matrixRef);
  string full = LU + RU + LD + RD;

  if ((full.length() == 4) && (LU == RU) && (RU == LD) && (LD == RD)) {
    return LU;
  }

  return '(' + full + ')';
}
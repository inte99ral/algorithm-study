#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#define SET_IO(INPUT_DATA) std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);std::ifstream fs(INPUT_DATA);std::cin.rdbuf(fs.is_open()?((std::istream*)&fs)->rdbuf():((std::istream*)new std::stringstream(INPUT_DATA))->rdbuf())
#else
#define SET_IO(INPUT_PATH) std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr)
#endif


using namespace std;

int main() {
  SET_IO("_INPUT_.txt");

  for(int X, Y; cin >> X >> Y;) {
    if (X == 0) break;

    vector<vector<int>> matrix(Y, vector<int>(X, -1));

    for (int y = 0; y < Y; y++) {
      for (int x = 0; x < X; x++) {
        cout << matrix[y][x] << " ";
      }
      cout << "\n";
    }

  }
  return 0;
}
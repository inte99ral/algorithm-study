#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#define SET_IO(INPUT_DATA) std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);std::ifstream fs(INPUT_DATA);std::cin.rdbuf(fs.is_open()?((std::istream*)&fs)->rdbuf():((std::istream*)new std::stringstream(INPUT_DATA))->rdbuf())
#else
#define SET_IO(INPUT_PATH) std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr)
#endif

int main() {
  SET_IO("_INPUT_.txt");
  
  int N;
  int R;
  int* data;
  int size;

  cin >> N;
  cin >> R;
  data = new int[R]();
  size = 0;

  while (data[0] < N) {
    if (size == R) {
      for (int r = 0; r < R; r++) cout << data[r] + 1 << ' ';
      cout << '\n';

      size--;
      data[size]++;

      continue;
    }

    if (data[size] == N) {
      data[size] = 0;
      size--;
      data[size]++;
      continue;
    }

    if ((size == 0) || (data[size - 1] < data[size])) size++;
    else data[size]++;
  }
  
  delete[] data;
}
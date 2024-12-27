#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#define SET_IO(INPUT_DATA) std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);std::ifstream fs(INPUT_DATA);std::cin.rdbuf(fs.is_open()?((std::istream*)&fs)->rdbuf():((std::istream*)new std::stringstream(INPUT_DATA))->rdbuf())
#else
#define SET_IO(INPUT_PATH) std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr)
#endif


using namespace std;

int main() {
  SET_IO("_INPUT_.txt");

  int N;
  int R;
  set<int> iSet;
  int* origin;
  int* select;
  int* data;
  int size;

  cin >> N;
  cin >> R;
  
  for (int n = 0; n < N; n++) {
    int temp;
    cin >> temp;
    iSet.insert(temp);
  }
  origin = new int[iSet.size()];
  copy(iSet.begin(), iSet.end(), origin);
  N = iSet.size();

  select = new int[R]();
  data = new int[R]();
  size = 0;

  while (data[0] < N) {
    if (size == R) {
      for (int r = 0; r < R; r++) cout << select[r] << ' ';
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

    select[size] = origin[data[size]];
    size++;
  }

  return 0;
}
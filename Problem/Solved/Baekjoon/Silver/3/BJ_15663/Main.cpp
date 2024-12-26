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
  int* origin;
  int* select;
  int* data;
  int size;

  cin >> N;
  cin >> R;
  
  origin = new int[N]();
  for (int n = 0; n < N; n++) cin >> origin[n];
  sort(origin, origin + N);

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

    bool isDuplicated = (data[size] != 0) && (origin[data[size] - 1] == origin[data[size]]);
    bool isOk = !isDuplicated;

    for (int r = 0; r < size; r++) {
      // * 나와 중복되는 값이 바로 앞 인덱스에 있다면, 그 값이 선택된 이후에만 선택이 가능하다.

      if (data[r] == data[size]) {
        isOk = false;
        continue;
      }

      if ((isDuplicated) && (data[r] == data[size] - 1)) {
        isOk = true;
      }
    }

    if (isOk) {
      select[size] = origin[data[size]];
      size++;
    }
    else {
      data[size]++;
    }
  }

  delete[] origin;
  delete[] select;
  delete[] data;
  return 0;
}
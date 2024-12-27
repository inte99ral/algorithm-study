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
  
  origin = new int[N];
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

    // * 순서상 현재 값 인덱스보다 뒤의 인덱스 값이 있다면 선택불가
    if ((size != 0) && (data[size] <= data[size - 1])) {
      data[size]++;
      continue;
    }

    // * 중복되는 값은 더 앞에 있는 중복값이 나온 적이 없으면 선택불가
    if ((data[size] != 0) && (origin[data[size] - 1] == origin[data[size]])) {
      bool isOk = false;

      for (int r = 0; r < size; r++) {
        if (data[r] == data[size] - 1) {
          isOk = true;
          break;
        }
      }

      if (!isOk) {
        data[size]++;
        continue;
      }
    }

    select[size] = origin[data[size]];
    size++;
  }

  delete[] origin;
  delete[] select;
  delete[] data;

  return 0;
}
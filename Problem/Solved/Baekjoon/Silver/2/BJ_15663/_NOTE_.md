# <img alt="s2" src="https://d2gd6pc034wcta.cloudfront.net/tier/9.svg" width="16" /> [BJ 15663：N과 M (9)](https://www.acmicpc.net/problem/15663)：오답노트

## 힌트

- ~~순열을 구하되 겹치는 값들은 순서를 고려하여야 합니다.~~

## 정답

### C++：2024-12-23：인라인 풀이

- | 메모리  | 시간 | 코드 길이 |
  | :-----: | :--: | :-------: |
  | 2020 KB | 4 ms |   984 B   |

- while 루프 구조로 풀었습니다.
- isDuplicated 논리 값으로 본인이 중복되는 값인지 확인합니다.
- sort 소팅과정을 거쳤기 때문에 나와 중복되는 값이 바로 origin 배열에서 바로 앞의 인덱스에 있다면 이 값은 중복되는 값임을 의미합니다.
- origin 배열에서 바로 앞의 인덱스가 select 배열에 선택된 이후에만 선택이 가능하도록 하여 순서를 유지시킵니다.

```cpp
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
```

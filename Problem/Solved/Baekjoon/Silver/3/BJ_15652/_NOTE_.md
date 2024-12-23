# <img alt="s3" src="https://d2gd6pc034wcta.cloudfront.net/tier/8.svg" width="16" /> BJ 15652：N과 M (4)：오답노트

## 힌트

- ~~수학적으로 중복 조합을 구현해주세요.~~

## 정답

### C++：2024-12-23：인라인 풀이

- | 메모리  | 시간 | 코드 길이 |
  | :-----: | :--: | :-------: |
  | 2020 KB | 4 ms |   984 B   |

- while 루프 구조로 풀었습니다.

```cpp
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
  data = new int[N]();
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

    if ((size == 0) || (data[size - 1] <= data[size])) size++;
    else data[size]++;
  }

  delete[] data;
}
```

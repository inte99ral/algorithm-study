# <img alt="s3" src="https://d2gd6pc034wcta.cloudfront.net/tier/8.svg" width="16" /> [BJ 15656：N과 M (7)](https://www.acmicpc.net/problem/15656)：오답노트

## 힌트

- ~~수학적으로 중복 순열을 구현해주세요.~~
- ~~원본 배열과 선택된 배열을 저장하여 출력합니다.~~

## 정답

### C++：2024-12-24：인라인 풀이

- | 메모리  |  시간  | 코드 길이 |
  | :-----: | :----: | :-------: |
  | 2020 KB | 428 ms |  1154 B   |

- while 루프 구조로 풀었습니다.

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

    select[size] = origin[data[size]];
    size++;
  }

  delete[] origin;
  delete[] select;
  delete[] data;
  return 0;
}
```

# <img alt="s2" src="https://d2gd6pc034wcta.cloudfront.net/tier/9.svg" width="16" /> [BJ 15664：N과 M (10)：오답노트](https://www.acmicpc.net/problem/15664)

## 힌트

- ~~조합을 구하되 겹치는 값들은 순서를 고려하여야 합니다.~~

## 정답

### C++：2024-12-27：인라인 풀이

- | 메모리  | 시간 | 코드 길이 |
  | :-----: | :--: | :-------: |
  | 2020 KB | 0 ms |  1575 B   |

- while 루프 구조로 풀었습니다.
- `isOk` 논리 값이 현재 `origin` 원본 배열의 `data[size]` 번째 인덱스 값을 `select` 배열의 값으로 선택해도 되는 지를 결정합니다.
- 원소들의 순서가 역전되지 않도록 하는 조합의 기본적인 검증 외에, `origin` 에 중복되는 값을 가진 원소의 경우는 반드시 자신과 같은 값을 가졌으면서도 앞선 `origin` 순번의 원소가 존재할 때에만 선택가능해야 합니다.
- `origin` 배열은 sort 소팅과정을 거쳤기 때문에 나와 중복되는 값이 바로 `origin` 배열에서 바로 앞의 인덱스에 있다면 이 값은 중복되는 값임을 의미합니다.

  > ```cpp
  >   origin[data[size] - 1] == origin[data[size]]
  > ```

- origin 배열에서 바로 앞의 `data[size] - 1` 인덱스가 select 배열에 선택된 이후에만 선택이 가능하도록 하여 순서를 유지시킵니다.

  > ```cpp
  > for (int r = 0; r < size; r++) {
  >   if (data[r] == data[size] - 1) {
  >     isOk = true;
  >     break;
  >   }
  > }
  >
  > if (!isOk) {
  >   data[size]++;
  >   continue;
  > }
  >
  > ```

- 코드는 다음과 같습니다.

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
```

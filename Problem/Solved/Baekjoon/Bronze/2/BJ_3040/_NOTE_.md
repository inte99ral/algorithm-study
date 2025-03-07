# <img alt="b2" src="https://d2gd6pc034wcta.cloudfront.net/tier/4.svg" width="16" /> [BJ 3040](https://www.acmicpc.net/problem/3040)：공주와 일곱 난쟁이：오답노트

## 힌트

- ~~지식의 저주를 조심할 것~~
- ~~어차피 2명만 뽑는 게 확정이니 그냥 for 루프 두 번 돌면 됩니다~~

## 정답

### C++：2024-10-26：인라인 조합

- | 메모리  | 시간 | 코드 길이 |
  | :-----: | :--: | :-------: |
  | 2020 KB | 0 ms |   544 B   |

- 지식의 저주에 안걸린 시절의 풀이답게 단순합니다.
- 2개 밖에 안 뽑을 조합이라면 신경 쓸 필요 없이 for 루프 돌면 그만입니다.

```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
  vector<int> origin(9);

  int sum = 0;
  int gap = 0;

  for (int i = 0; i < 9; i++) {
    cin >> origin[i];
  }

  for (int i : origin) sum += i;
  gap = sum - 100;

  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < i; j++) {
      if (j == i) continue;
      if (origin[i] + origin[j] == gap) {
        origin.erase(origin.begin() + j);
        origin.erase(origin.begin() + i - 1);
        break;
      }
    }
  }

  for (int i : origin) cout << i << "\n";

  return 0;
}
```

### C++：2025-03-06：인라인 조합

- | 메모리  | 시간 | 코드 길이 |
  | :-----: | :--: | :-------: |
  | 2020 KB | 0 ms |  1442 B   |

- 지식의 저주에 걸린 풀이입니다.
- 기여코 nCr 를 할 줄 안다고 꺼드럭 거리는 것을 볼 수 있습니다.
- 이러지 맙시다.

```cpp
/**
 * BJ_3040
 * @see "https://www.acmicpc.net/problem/3040"
 * @version 2025-03-06
 */
#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
  #define SET_IO(INPUT_DATA) \
    std::ios::sync_with_stdio(false); \
    std::cin.tie(nullptr); \
    std::cout.tie(nullptr); \
    std::istream* IO_S = (std::filesystem::exists(INPUT_DATA)) \
      ? (std::istream*) new std::ifstream(INPUT_DATA) \
      : (std::istream*) new std::stringstream(INPUT_DATA); \
    std::streambuf* IO_BACKUP = std::cin.rdbuf(IO_S->rdbuf())

  #define UNSET_IO() \
    std::cin.rdbuf(IO_BACKUP); \
    delete IO_S

#else
  #define SET_IO(INPUT_DATA) \
    std::ios::sync_with_stdio(false); \
    std::cin.tie(nullptr); \
    std::cout.tie(nullptr)

  #define UNSET_IO() ((void) 0)
#endif

using namespace std;

int main() {
  SET_IO("_INPUT_.txt");
  int count = 0;
  int origin[9] = {};
  int data[2] = {};
  int size = 0;

  for (int i = 0; i < 9; i++) {
    cin >> origin[i];
    count += origin[i];
  }

  count -= 100;

  while (data[0] != 9) {
    if (size == 2) {
      if (count == origin[data[0]] + origin[data[1]]) break;
      size--;
      data[size]++;
      continue;
    }

    if (data[size] == 9) {
      data[size] = 0;
      size--;
      data[size]++;
      continue;
    }

    if ((size > 0) && (data[size] <= data[size - 1])) {
      data[size]++;
      continue;
    }

    size++;
  }

  for (int i = 0; i < 9; i++) {
    if ((i == data[0]) || (i == data[1])) continue;
    cout << origin[i] << "\n";
  }

  UNSET_IO();
  return 0;
}
```

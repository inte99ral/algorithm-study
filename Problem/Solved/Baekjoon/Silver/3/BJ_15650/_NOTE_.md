# <img alt="s3" src="https://d2gd6pc034wcta.cloudfront.net/tier/8.svg" width="16" /> BJ 15650：N과 M (2)：오답노트

## 힌트

- ~~수학적으로 조합을 구하면 되는 문제입니다.~~

## 정답

### C++：2024-01-01：재귀함수 & 스택

- | 메모리  | 시간 | 코드 길이 |
  | :-----: | :--: | :-------: |
  | 2024 KB | 0 ms |   843 B   |

- 재귀함수와 스택을 이용해서 조합을 구했습니다.

```cpp
#include <iostream>
#include <vector>

using namespace std;

void comb(int N, int R);
void combRecur(vector<int> origin, vector<int> fixed, int N, int R, int selected, int length);

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  freopen("Problem\\Solved\\Baekjoon\\Silver\\3\\BJ_15650\\question\\input.txt", "rt", stdin);

  int N, M;
  cin >> N >> M;

  comb(N, M);
  return 0;
}

void comb(int N, int R) {
  vector<int> origin;
  vector<int> fixed;
  for(int n = 1; n <= N; n++) origin.push_back(n);
  combRecur(origin, fixed, N, R, -1, 0);
}

void combRecur(vector<int> origin, vector<int> fixed, int N, int R, int selected, int length) {
  if(length == R) {
    for(int i : fixed) cout << i << ' ';
    cout << '\n';
    return;
  }

  for(int n = selected + 1; n < N; n++) {
    fixed.push_back(origin.at(n));
    combRecur(origin, fixed, N, R, n, length + 1);
    fixed.pop_back();
  }
}
```

### C++：2024-12-23：인라인 While 루프

- | 메모리  | 시간 | 코드 길이 |
  | :-----: | :--: | :-------: |
  | 2020 KB | 0 ms |   988 B   |

- 단순한 문제라 함수를 만들지 않고 인라인 코드로 구현했습니다.

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
```

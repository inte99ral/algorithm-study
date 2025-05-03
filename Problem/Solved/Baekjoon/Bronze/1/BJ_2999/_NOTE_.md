# <img alt="b1" src="https://d2gd6pc034wcta.cloudfront.net/tier/5.svg" width="16" /> [BJ 2999](https://www.acmicpc.net/problem/2999)：비밀 이메일：오답노트

## 힌트

## 정답

### C++：2025-05-04：배열

- | 메모리  | 시간 | 코드 길이 |
  | :-----: | :--: | :-------: |
  | 2036 KB | 0 ms |  1081 B   |

- N = C \* R 이고 `R <= C` 이므로 R은 N의 제곱근보다는 작다.

```cpp
#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
  #define SET_IO(INPUT_DATA) \
    std::ios::sync_with_stdio(false); \
    std::cin.tie(nullptr); \
    std::cout.tie(nullptr); \
    std::istream *IO_S = (std::filesystem::exists(INPUT_DATA)) \
      ? (std::istream*) new std::ifstream(INPUT_DATA) \
      : (std::istream*) new std::stringstream(INPUT_DATA); \
    std::streambuf *IO_BACKUP = std::cin.rdbuf(IO_S->rdbuf())
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

int main(int argc, char* argv[]) {
  SET_IO("_INPUT_.txt");

  string message;
  int N, R, C;

  cin >> message;
  N = message.size();
  R = sqrt(N);
  C = 1;

  while (R > 0) {
    if (N % R == 0) {
      C = N / R;
      break;
    }
    R--;
  }

  for (int r = 0; r < R; r++) {
    for (int c = 0; c < C; c++) {
      cout << message.at((c * R) + r);
    }
  }

  UNSET_IO();
  return 0;
}
```

# <img alt="s1" src="https://d2gd6pc034wcta.cloudfront.net/tier/10.svg" width="16" /> [BJ 1629](https://www.acmicpc.net/problem/1629)：곱셈：오답노트

- ~~나머지 연산자는 분배공식을 적용할 수 있다.~~
- ~~거듭제곱처럼 좌항 우항이 같다면 분할정복하여 2<sup>n</sup> 의 n 번만 연산하면 된다.~~
- ~~제곱 계산 전, 나머지 연산을 해두지 않는다면 10^9 + 7 이상의 값의 세제곱은 long long 범위마저 초과한다.~~

## 오답

### C++：2024-10-26：2의 제곱수로 논리상 분할정복

- | 메모리 |   시간   | 코드 길이 |
  | :----: | :------: | :-------: |
  |   -    | 시간초과 |     -     |

- 우습게 봤다가 박살났습니다.
- 분할정복은 캐치했으나 나머지 정리는 캐치하지 못했습니다.
- 수학 공부가 필요한 이유...

```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  freopen("Problem\\Unsolved\\Baekjoon\\Silver\\1\\BJ_1629\\question\\input.txt", "rt", stdin);

  int A, B, C;
  int answer;

  answer = A % C;

  for (int b = 0; b < B; b++) {
    if (b * 2 < B) {
      answer *= answer;
      answer %= C;
    }
  }

  cout << answer;

  return 0;
}
```

### C++：2024-10-26：나머지 정리 적용

- |  메모리  | 시간 | 코드 길이 |
  | :------: | :--: | :-------: |
  | 오답처리 |  -   |   552 B   |

- 전체적으로 로직 자체는 정답과 비슷합니다.
- 허나, `for (int i = B - isOdd; i > 1; i /= 2)` for 루프는 완전히 어긋난 실수입니다. B가 14 였다고 가정하면 14 -> 7 -> 3 -> 1 순으로 나머지는 버리고 몫만 가지고 가게 됩니다.
- 홀수부 분할정리 연산은 for 루프가 끝난 뒤, 맨 마지막만 하는 것이 아니라 매 분할정리 분기에서 2분할 때 나머지가 발생한다면 그때마다 해줘야 합니다.

```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  // freopen("Problem\\Unsolved\\Baekjoon\\Silver\\1\\BJ_1629\\question\\input.txt", "rt", stdin);

  int A, B, C;
  long long answer;
  bool isOdd;

  cin >> A >> B >> C;
  answer = A % C;
  isOdd = (B % 2 != 0);

  for (int i = B - isOdd; i > 1; i /= 2) {
    answer *= answer;
    answer %= C;
  }

  if (B != 1 && isOdd) {
    answer *= A;
    answer %= C;
  }

  cout << answer;

  return 0;
}
```

## 정답

### C++：2024-10-26：재귀함수 사용

- | 메모리  | 시간 | 코드 길이 |
  | :-----: | :--: | :-------: |
  | 2020 KB | 0 ms |   552 B   |

- 재귀함수를 이용하여 깔끔하게 정리하였습니다.
- 수학적으로 나머지 정리를 사용하여 연산을 나누었습니다.
- 제곱되는 경우를 분할정리를 통하여 복잡도를 logN 으로 줄였습니다.
- 분할하는 분기마다 생길 수 있는 홀수 상황에서 나머지 처리를 적용하였습니다.

```cpp
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

long long longMod(long long A, long long B, long long C) {
  if (B <= 1) {
    return (B == 0) ? (1 % C) : (A % C);
  }

  if (B % 2 == 0) {
    long long temp = longMod(A, B / 2, C) % C;
    return (temp * temp) % C;
  }
  else {
    long long temp = longMod(A, (B - 1) / 2, C) % C;
    return (((temp * temp) % C) * (A % C)) % C;
  }
}

int main() {
  SET_IO("_INPUT_.txt");

  long long A, B, C;
  cin >> A >> B >> C;
  cout << longMod(A, B, C) << endl;

  UNSET_IO();
  return 0;
}
```

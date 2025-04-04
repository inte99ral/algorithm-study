# <img alt="s3" src="https://d2gd6pc034wcta.cloudfront.net/tier/8.svg" width="16" /> [BJ 11726](https://www.acmicpc.net/problem/11726)：2×n 타일링：오답노트

## 힌트

- ~~수학적인 감각 필요~~
- ~~점화식~~

## 오답

### C++：2025-04-04：순열과 조합

- | 메모리 |   시간   | 코드 길이 |
  | :----: | :------: | :-------: |
  |   -    | 시간초과 |     -     |

- 순열과 조합으로 풀 수 있는 문제라고 판단했습니다.
- N 이다 라고 했을때, x C y 계산을 해야한다고 생각하면
  - N 이 짝수이면 y 가 카운터 i 가 될꺼고 i 은 최대 N 이었을것, 또한 2씩 올라가야합니다.
  - 1칸을 차지하는 세로블럭 1개의 수 V = i
  - 2칸을 차지하는 가로블럭 2개 묶음의 수 H = (N - i) / 2
  - H(n, r) = C(n + r - 1, r) = C(H + V, H)
- 위의 생각대로 for 루프를 돌면 모든 경우의 수를 체크해 볼 수 있습니다.
- 하지만 위의 방법은 치명적으로 느리며, 이 문제는 이 방법을 요구하지 않았던 것 입니다.

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

int main(int argc, char* argv[]) {
  SET_IO("_INPUT_.txt");

  int N;
  int answer;

  cin >> N;
  answer = 0;

  { // * TASK 0: 루프 연산
    for (int i = N % 2; i <= N; i += 2) {
      int count = 0;
      int H = (N - i) / 2;
      int V = i;

      if (H == 0) {
        count = 1;
      }
      else {
        vector<int> data(H, 0);
        int size = 0;

        { // * TASK 0.0: 조합계산
          while (data[0] != H + V) {
            if (size == H) {
              count++;
              count %= 10007;
              cout << " - ";
              for (int i : data) {
                cout << i << ", ";
              }
              cout << "\b\b \n";
              size--;
              data[size]++;
              continue;
            }

            if (data[size] == H + V) {
              data[size] = 0;
              size--;
              data[size]++;
              continue;
            }

            if ((size != 0) && (data[size - 1] >= data[size])) {
              data[size]++;
              continue;
            }

            size++;
          }
        }

      }

      { // * LOG 00: 조합식 확인
        cout << H << " + " << V << " 에서 " << H << " 개를 뽑는 경우의 수: " << count << "\n\n";
      }

      answer += count;
      answer %= 10007;
    }
  }

  cout << "정답: " << answer;
  UNSET_IO();
  return 0;
}
```

## 정답

### C++：2025-04-04：점화식

- | 메모리  | 시간 | 코드 길이 |
  | :-----: | :--: | :-------: |
  | 2024 KB | 0 ms |  1008 B   |

- 위 문제는 DP(Dynamic Programming, 동적계획법)을 이해하는 가에 대한 것 이었습니다.
- DP 란 최적화 이론의 한 기술이며, 특정 범위까지의 값을 구하기 위해서 그것과 다른 범위까지의 값을 이용하여 효율적으로 값을 구하는 알고리즘 설계 기법입니다.
- 수학 교육과정에서 점화식과 수열에 해당하는 풀이법입니다.
- DP 를 적용해서 풀면 오답과 같이 직접 경우를 시뮬레이션하지 않고도 경우의 수만 따로 구해낼 수 있습니다. 방법은 다음과 같습니다.

&nbsp; x \* 2 크기 직사각형을 1 \* 2 또는 2 \* 1 타일로 채우는 모든 경우의 수를 출력하는 함수 f(x) 이 있다고 가정합시다.

&nbsp; 이제 임의의 값 N 에 대하여 f(N - 1), f(N - 2) 과 f(N) 의 관계를 생각해 볼 수 있습니다.

&nbsp; x \* 2 직사각형을 1 \* 2 또는 2 \* 1 타일로 빈틈없이 채우는 방법은 1 \* 2 타일 하나를 세워서 넣는 방법과 2 \* 1 타일 두 개를 가로로 포개서 넣는 방법 뿐 입니다. 이 외의 방법은 존재하지 않습니다.

&nbsp; 이제 x \* 2 직사각형의 한 쪽 끝을 한번 상상해 봅시다. 끝을 채우는 방법은 두 가지 방법 외의 방법은 없기 때문에 모든 경우의 수 f(N) 은 (맨 끝을 수직으로 1 \* 2 타일 하나로 넣은 경우의 수) + (맨 끝을 수평으로 2 \* 1 타일 두 개로 넣은 경우의 수) 라고 나눠서 생각해 볼 수 있습니다.

&nbsp; 맨 끝을 수직으로 1 \* 2 타일 하나로 넣은 경우의 수를 생각해보세요. 1 \* 2 타일을 세워넣고 남은 공간은 (N - 1) \* 2 크기입니다. 따라서 이에 대한 경우의 수는 (N - 1) \* 2 직사각형을 채우는 경우의 수 f(N - 1) 과 같습니다.

&nbsp; 맨 끝을 수평으로 2 \* 1 타일 두 개로 넣은 경우의 수를 생각해보세요. 2 \* 1 타일을 포개어넣고 남은 공간은 (N - 2) \* 2 크기입니다. 따라서 이는 f(N - 2) 과 같습니다.

&nbsp; 그렇기 때문에 다음의 점화식이 성립된다는 것을 알 수 있습니다.

<div align="center">

`f(N) = f(N - 2) + f(N - 1)`

</div>

&nbsp; 여기서 이미 f(1) 은 세로 타일 하나 뿐이므로 1, f(2) 가 가로와 세로의 경우를 보아 2 임은 명확합니다.

- 이것을 다음과 같이 풀이할 수 있습니다.

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

int main(int argc, char* argv[]) {
  SET_IO("_INPUT_.txt");

  int N;
  int* arr;

  cin >> N;
  arr = new int[N + 1]();

  for (int n = 0; n <= N; n++) {
    if (n <= 2) {
      arr[n] = n;
      continue;
    }

    arr[n] = (arr[n - 2] + arr[n - 1]) % 10007;
  }

  cout << arr[N];

  UNSET_IO();
  return 0;
}
```

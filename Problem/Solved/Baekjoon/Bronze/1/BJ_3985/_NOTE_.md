# <img alt="b1" src="https://d2gd6pc034wcta.cloudfront.net/tier/5.svg" width="16" /> [3985](https://www.acmicpc.net/problem/3985)：롤 케이크：오답노트

## 힌트

- ~~직접 구현하는게 제일 빠른 단순 코딩 문제~~

## 정답

### C++：2025-09-08：직접 구현

- | 메모리  | 시간 | 코드 길이 |
  | :-----: | :--: | :-------: |
  | 2024 KB | 0 ms |  1352 B   |

- 직접 구현

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

int main() {
    SET_IO("_INPUT_.txt");

    int L;
    int N;

    int emaxNum = 0; // * expected
    int emaxCnt = -1;
    int maxNum = 0;
    int maxCnt = -1;

    cin >> L >> N;

    int *arr = new int[L + 1]();

    for (int n = 1; n <= N; n++) {
        int P;
        int K;
        int cnt = 0;

        cin >> P >> K;

        if (emaxCnt < K - P + 1) {
            emaxCnt = K - P + 1;
            emaxNum = n;
        }

        for (int i = P; i <= K; i++) {
            if (arr[i] == 0) {
                arr[i] = n;
                cnt++;
            }
        }

        if (maxCnt < cnt) {
            maxCnt = cnt;
            maxNum = n;
        }
    }

    cout << emaxNum << "\n";
    cout << maxNum << "\n";

    delete[] arr;
    UNSET_IO();
    return 0;
}
```

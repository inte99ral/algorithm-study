# <img alt="b2" src="https://d2gd6pc034wcta.cloudfront.net/tier/4.svg" width="16" /> [BJ 8320](https://www.acmicpc.net/problem/8320)：직사각형을 만드는 방법：오답노트

## 힌트

-   ~~제곱근~~

## 정답

### C++：2025-09-19：제곱근 풀이

-   | 메모리  | 시간 | 코드 길이 |
    | :-----: | :--: | :-------: |
    | 2032 KB | 0 ms |   243 B   |

-   제곱근 기준으로 1씩 빼가면서 나머지 값이 0 인 시점을 찾았습니다.

```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
    // freopen("_INPUT_.txt", "rt", stdin);
    int answer = 0;
    int N;
    cin >> N;

    for (int n = 1; n <= N; n++) for (int i = floor(sqrt(n)); i > 0; i--) if (n % i == 0) answer++;
    cout << answer;

    return 0;
}
```

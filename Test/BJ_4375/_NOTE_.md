# <img alt="『티어』" src="https://d2gd6pc034wcta.cloudfront.net/tier/『티어』.svg" width="16" /> [BJ 『문제코드』](https://www.acmicpc.net/problem/『문제코드』)：『문제제목』：오답노트

## 힌트

-   ~ ~볼 힌트~~
-   ~~숨길 힌트~~

## 오답

### C++：2025-10-30：힘으로 해결 시도

-   | 메모리 |   시간   | 코드 길이 |
    | :----: | :------: | :-------: |
    |   -    | 시간초과 |   384 B   |

-   무지성 1 ... 1111 나눠보기 시도 -> 타임아웃

```cpp
#include <bits/stdc++.h>
using namespace std;
int main() {
    // --------------------------------

    freopen("_INPUT_.txt", "rt", stdin); // <-- LOCAL INPUT

    // --------------------------------
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    long long temp;
    while(cin >> temp) {
        int cnt = 1;
        long long one = 1;
        while (one % temp != 0) {
            one = (one * 10) + 1;
            cnt++;
        }

        cout << cnt << "\n";
    }
    return 0;
}
```

## 정답

### 『LANGUAGE_TYPE_02』：xxxx-xx-xx：『ANNOTATION_COMMENT』

-   | 메모리  | 시간 | 코드 길이 |
    | :-----: | :--: | :-------: |
    | 2024 KB | 0 ms |   843 B   |

-   방법 찾음

```『LANGUAGE_TYPE_02』
    『CODE_LINE』
```

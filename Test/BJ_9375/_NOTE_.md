# <img alt="s3" src="https://d2gd6pc034wcta.cloudfront.net/tier/8.svg" width="16" /> [BJ 9375](https://www.acmicpc.net/problem/9375)：패션왕 신해빈：오답노트

## 힌트

-   ~~맵 카운팅~~

## 정답

### C++：2025-10-10：카운팅

-   | 메모리  | 시간 | 코드 길이 |
    | :-----: | :--: | :-------: |
    | 2028 KB | 0 ms |   590 B   |

-   카운팅과 맵

```cpp
#include <bits/stdc++.h>
using namespace std;
int T, N, ans;
string temp;
unordered_map<string, int> iMap;
int main() {
    freopen("input.txt", "rt", stdin); // <- local input

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> N;
        ans = 1;
        iMap.clear();
        for (int n = 0; n < N; n++) {
            cin >> temp >> temp;
            iMap[temp]++;
        }

        for (auto p : iMap) {
            ans *= p.second + 1;
        }
        cout << ans - 1 << "\n";
    }

    return 0;
}
```

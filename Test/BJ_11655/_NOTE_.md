# <img alt="b2" src="https://d2gd6pc034wcta.cloudfront.net/tier/4.svg" width="16" /> [BJ 11655](https://www.acmicpc.net/problem/11655)：ROT13：오답노트

## 힌트

-   ~ ~볼 힌트~~
-   ~~숨길 힌트~~

## 정답

### C++：2025-10-09：카운팅

-   | 메모리  | 시간 | 코드 길이 |
    | :-----: | :--: | :-------: |
    | 2024 KB | 0 ms |   843 B   |

-   방법 찾음

```cpp
#include <bits/stdc++.h>
using namespace std;
string str = "";
string ans = "";
int main() {
    freopen("input.txt", "rt", stdin); // <- local input
    getline(cin, str);
    for (char c : str) {
        if (0 <= (c - 'a') && (c - 'a') <= 26) c = 'a' + ((c - 'a' + 13) % 26);
        else if (0 <= (c - 'A') && (c - 'A') <= 26)  = 'A' + ((c - 'A' + 13) % 26);
        ans += c;
    }
    cout << ans;
    return 0;
}
```

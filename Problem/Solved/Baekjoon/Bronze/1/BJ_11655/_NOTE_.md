# <img alt="b1" src="https://d2gd6pc034wcta.cloudfront.net/tier/5.svg" width="16" /> [BJ 11655](https://www.acmicpc.net/problem/11655)：ROT13：오답노트

## 정답

### C++：2025-10-09：아스키 코드

-   | 메모리  | 시간 | 코드 길이 |
    | :-----: | :--: | :-------: |
    | 2024 KB | 0 ms |   412 B   |

-   아스키 코드 값과 해당 범위의 나머지 값으로 계산

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

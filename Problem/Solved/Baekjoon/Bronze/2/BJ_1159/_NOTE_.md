# <img alt="b2" src="https://d2gd6pc034wcta.cloudfront.net/tier/4.svg" width="16" /> [BJ 1159](https://www.acmicpc.net/problem/1159)：농구 경기：오답노트

## 힌트

-   ~~A=65, a=97~~

## 정답

### C++：2025-10-09：카운팅

-   | 메모리  | 시간 | 코드 길이 |
    | :-----: | :--: | :-------: |
    | 2024 KB | 0 ms |   428 B   |

-   숫자에 맞춘 배열로 카운팅하기

```cpp
#include <bits/stdc++.h>

using namespace std;
int N;
int alpCnt[26] = {};
bool isPredaja = true;

int main() {
    freopen("input.txt", "rt", stdin); // <- local input
    cin >> N;

    while(N--) {
        string name;
        cin >> name;
        alpCnt[name[0] - 'a']++;
    }

    for (int i = 0; i < 26; i++) {
        if (alpCnt[i] > 4) {
            cout << (char)('a' + i);
            isPredaja = false;
        }
    }

    if (isPredaja) cout << "PREDAJA";
    return 0;
}
```

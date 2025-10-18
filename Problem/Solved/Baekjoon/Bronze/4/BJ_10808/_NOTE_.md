# <img alt="b4" src="https://d2gd6pc034wcta.cloudfront.net/tier/2.svg" width="16" /> [BJ 10808](https://www.acmicpc.net/problem/10808)：알파벳 개수：오답노트

## 힌트

-   ~~'a' == 97~~

## 정답

### C++：2025-10-07：카운팅

-   | 메모리  | 시간 | 코드 길이 |
    | :-----: | :--: | :-------: |
    | 2024 KB | 0 ms |   306 B   |

-   카운팅과 배열

```cpp
#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("input.txt", "rt", stdin); // <-- local input
    string str;
    vector<int> v(26);
    cin >> str;
    for (char c : str) v[c - 'a']++;
    for (int i : v) cout << i << " ";
    return 0;
}
```

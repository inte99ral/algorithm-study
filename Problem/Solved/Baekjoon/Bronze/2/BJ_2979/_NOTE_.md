# <img alt="b2" src="https://d2gd6pc034wcta.cloudfront.net/tier/4.svg" width="16" /> [BJ 2979](https://www.acmicpc.net/problem/2979)：트럭 주차：오답노트

## 정답

### C++：2025-10-08：배열 구현

-   | 메모리  | 시간 | 코드 길이 |
    | :-----: | :--: | :-------: |
    | 2020 KB | 0 ms |   589 B   |

-   배열구현

```cpp
#include <bits/stdc++.h>
using namespace std;
int ans, A, B, C;
int a[101];
int main() {


    freopen("input.txt", "rt", stdin); // <-- local input


    cin >> A >> B >> C;
    B *= 2;
    C *= 3;

    for (int i = 0; i < 3; i++) {
        int in, out;
        cin >> in >> out;
        for (int j = in; j < out; j++) a[j]++;
    }

    ans = 0;
    for (int i = 0; i < 101; i++) {
        switch (a[i]) {
        case 1:
            ans += A;
            break;
        case 2:
            ans += B;
            break;
        case 3:
            ans += C;
            break;
        }
    }
    cout << ans;
    return 0;
}
```

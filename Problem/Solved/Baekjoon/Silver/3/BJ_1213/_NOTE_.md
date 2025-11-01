# <img alt="s3" src="https://d2gd6pc034wcta.cloudfront.net/tier/8.svg" width="16" /> [BJ 1213](https://www.acmicpc.net/problem/1213)：팰린드롬 만들기：오답노트

## 정답

### C++：2025-10-10：카운팅 배열

-   | 메모리  | 시간 | 코드 길이 |
    | :-----: | :--: | :-------: |
    | 2024 KB | 0 ms |   779 B   |

-   알파벳을 배열로 수를 센 뒤에 재배열
-   홀수개가 1개 이상일 경우 좌우 대칭 불가능 파악

```cpp
#include <bits/stdc++.h>
using namespace std;
string str;
int oddAlp = -1;
vector<int> v = vector<int>(26);
int main() {
    freopen("input.txt", "rt", stdin); // <- local input

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> str;
    for (char c : str) {
        v[c - 'A']++;
    }
    str = "";

    for (int i = 0; i < 26; i++) {
        if(v[i] % 2 != 0) {
            if (oddAlp != -1) {
                cout << "I'm Sorry Hansoo";
                exit(0);
            }
            oddAlp = i;
            v[i]--;
        }
        v[i] /= 2;
        while(v[i]--) {
            str += (i + 'A');
        }
    }

    string strRev = str;
    reverse(strRev.begin(), strRev.end());
    if (oddAlp != -1) str += char(oddAlp + 'A');
    str += strRev;
    cout << str;

    return 0;
}
```

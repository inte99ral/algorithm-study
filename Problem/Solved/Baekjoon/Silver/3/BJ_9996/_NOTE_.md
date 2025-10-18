# <img alt="s3" src="https://d2gd6pc034wcta.cloudfront.net/tier/8.svg" width="16" /> [BJ 9996](https://www.acmicpc.net/problem/9996)：한국이 그리울 땐 서버에 접속하지：오답노트

## 힌트

-   ~~split 과 substr 함수 꼭 잊지 않기~~

## 정답

### C++：2025-10-10：prefix suffix split

-   | 메모리  | 시간 | 코드 길이 |
    | :-----: | :--: | :-------: |
    | 2024 KB | 0 ms |   590 B   |

-   split 과 substr 함수 꼭 잊지 않기

```cpp
#include <bits/stdc++.h>
using namespace std;
int N;
int astIdx;
string pattern;
string prefix;
string suffix;
string temp;

int main() {


    freopen("input.txt", "rt", stdin); // <- local input


    cin >> N >> pattern;
    astIdx = pattern.find('*');
    prefix = pattern.substr(0, astIdx);
    suffix = pattern.substr(astIdx + 1, pattern.size());

    for (int n = 0; n < N; n++) {
        cin >> temp;
        if ((temp.size() >= (prefix.size() + suffix.size())) && (temp.substr(0, prefix.size()) == prefix) && (temp.substr(temp.size() - suffix.size()) == suffix)) cout << "DA\n";
        else cout << "NE\n";
    }
    return 0;
}
```

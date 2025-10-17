# <img alt="b3" src="https://d2gd6pc034wcta.cloudfront.net/tier/3.svg" width="16" /> [BJ 10988](https://www.acmicpc.net/problem/10988)：팰린드롬인지 확인하기：오답노트

## 힌트

-   ~ ~볼 힌트~~
-   ~~숨길 힌트~~

## 오답

### 『LANGUAGE_TYPE_01』：xxxx-xx-xx：『ANNOTATION_COMMENT』

-   | 메모리 |   시간   | 코드 길이 |
    | :----: | :------: | :-------: |
    |   -    | 시간초과 |     -     |

-   |  메모리  | 시간 | 코드 길이 |
    | :------: | :--: | :-------: |
    | 오답처리 |  -   |   552 B   |

-   반례 못찾음

```『LANGUAGE_TYPE_01』
    『CODE_LINE』
```

## 정답

### C++：2025-10-08：양끝부터 한칸씩 비교

-   | 메모리  | 시간 | 코드 길이 |
    | :-----: | :--: | :-------: |
    | 2024 KB | 0 ms |   843 B   |

-   방법 찾음

```cpp
#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("input.txt", "rt", stdin); // <- local input
    string str;
    cin >> str;
    int strSize = str.size() - 1;
    int halfSize = str.size() / 2;
    for (int i = 0; i < halfSize; i++) {
        if (str[i] != str[strSize - i]) {
            cout << 0;
            exit(0);
        }
    }
    cout << 1;
    return 0;
}
```

### C++：2025-10-08：뒤집어서 바로 비교

-   | 메모리  | 시간 | 코드 길이 |
    | :-----: | :--: | :-------: |
    | 2024 KB | 0 ms |   - B   |

-   단순하고 간편한 로직.
-   뒤집고 뒤집은 것과 같은지 확인하기.

```cpp
#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("input.txt", "rt", stdin); // <- local input
    string str;
    string temp;
    cin >> str;
    temp = str;
    reverse(temp.begin(), temp.end());
    cout << (str == temp);
    return 0;
}
```

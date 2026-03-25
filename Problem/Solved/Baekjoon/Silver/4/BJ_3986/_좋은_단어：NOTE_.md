# <img alt="s4" src="https://d2gd6pc034wcta.cloudfront.net/tier/7.svg" width="16" /> [BJ 3986](https://www.acmicpc.net/problem/3986)：좋은 단어：오답노트

## 힌트

-   ~~문제에서 짝짓기나 폭발제거면 스택을 떠올려보자~~
-   ~~어차피 매칭되는 글자 간의 거리가 짧은 것이 가장 효율적~~

## 오답

## 정답

### C++：2025-10-19：스택

-   | 메모리  | 시간 | 코드 길이 |
    | :-----: | :--: | :-------: |
    | 2392 KB | 0 ms |   547 B   |

-   스택 자료구조에 같은 알파벳을 만나면 스택에서 빼주고 다를 경우 스택에 추가.
-   다 끝났을 경우 스택이 empty 가 아니라면 묶음으로 정리하는 것이 불가능하다는 검증. (괄호를 열고 닫는 것처럼 빨리 같은 알파벳끼리 묶을 수 있을 때 바로 묶는 것이 최대 효율 방법이기 때문에 이 방법이 한 통할 경우 어차피 묶음 정리가 불가능함.)
-   참고로 stack 컨테이너 어답터는 !empty() 가 보증되지 않았다면 top() 호출시 에러가 나므로 확인이 먼저되야 합니다.

```cpp
#include <bits/stdc++.h>
using namespace std;
int main() {


    freopen("_INPUT_.txt", "rt", stdin); // <- LOCAL INPUT


    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int ans = 0;
    int N;
    string str;
    stack<char> st;

    cin >> N;
    while(N--) {
        cin >> str;
        st = stack<char>();
        for (char c : str) {
            // * 하나씩 집어넣을 때, 스택 맨 위와 동일하면 둘 다 제거, 다를 경우 스택에 추가
            if (!st.empty() && st.top() == c) st.pop();
            else st.push(c);
        }
        if (st.empty()) ans++;
    }

    cout << ans;
    return 0;
}
```

### C++：2026-03-06：스택

-   | 메모리  | 시간 | 코드 길이 |
    | :-----: | :--: | :-------: |
    | 2392 KB | 0 ms |   556 B   |

-   과거와 동일한 풀이법 채용

```cpp
#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("_INPUT_.txt", "rt", stdin); // LOCAL INPUT <<================================

    int N;
    string str;
    int ans = 0;
    
    cin >> N;

    for (int n = 0; n < N; n++) {
        cin >> str;
        stack<char> cStk;
        
        for (char c : str) {
            if (cStk.empty() || cStk.top() != c) {
                cStk.push(c);
                continue;
            }

            cStk.pop();
        }

        if (cStk.empty()) ans++;
    }

    cout << ans;
    return 0;
}
```

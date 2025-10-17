# <img alt="s3" src="https://d2gd6pc034wcta.cloudfront.net/tier/8.svg" width="16" /> [BJ 2559](https://www.acmicpc.net/problem/2559)：수열：오답노트

## 힌트

-   ~ ~제발 종료조건 설계를 잊지 말자~~

## 오답

### C++：2025-10-10：과다 출력 오버헤드

-   | 메모리 |   시간   | 코드 길이 |
    | :----: | :------: | :-------: |
    |   -    | 시간초과 |     -     |

-   들어오는 값을 vector 와 unordered_map 에 집어넣음
-   O(1) + O(logN) 만큼의 찾는 연산은 빠르나, 출력값이 너무 많은걸 감안하지 못함

```c++
#include <bits/stdc++.h>
using namespace std;
int N, M;
string temp;
unordered_map<string, int> sm;
vector<string> iv;
int main() {
    freopen("input.txt", "rt", stdin); // <- local input

    cin >> N >> M;
    iv = vector<string>(N + 1);
    for (int n = 1; n <= N; n++) {
        cin >> temp;
        sm[temp] = n;
        iv[n] = temp;
    }

    for (int m = 0; m < M; m++) {
        cin >> temp;
        if (temp[0] <= '9') {
            cout << iv[stoi(temp)] << "\n";
        }
        else {
            cout << sm[temp] << "\n";
        }
    }
    return 0;
}
```

## 정답

### C++：2025-10-10：속도 최적화

20664 84 C++17 / 수정 563

-   |  메모리  | 시간  | 코드 길이 |
    | :------: | :---: | :-------: |
    | 20664 KB | 84 ms |   563 B   |

-   `stoi(str)` 보단 `atoi(str.c_str())` 을 사용하기. 더 빠르고 안전하며 int return 이 보장됨(불가능할시 0 리턴)
-   `ios_base::sync_with_stdio(false);` `cin.tie(nullptr);` `cout.tie(nullptr);` 잊지 말기. 이렇게 출력이 많은 문제에선 속도가 2배 이상 빨라짐

```c++
#include <bits/stdc++.h>
using namespace std;
int N, M;
string temp;
unordered_map<string, int> sm;
vector<string> iv;
int main() {
    freopen("input.txt", "rt", stdin); // <- local input

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N >> M;
    iv = vector<string>(N + 1);

    for(int n = 0; n < N; n++) {
        cin >> temp;
        sm[temp] = n + 1;
        iv[n + 1] = temp;
    }

    for (int m = 0; m < M; m++) {
        cin >> temp;
        if (temp[0] <= '9') cout << iv[atoi(temp.c_str())] << "\n";
        else cout << sm[temp] << "\n";
    }
    return 0;
}
```

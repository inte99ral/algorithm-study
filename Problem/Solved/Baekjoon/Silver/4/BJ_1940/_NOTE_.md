# <img alt="s4" src="https://d2gd6pc034wcta.cloudfront.net/tier/7.svg" width="16" /> [BJ 1940](https://www.acmicpc.net/problem/1940)：주몽：오답노트

## 오답

### C++：2025-10-11：쓸때없이 DP

-   |   메모리   | 시간 | 코드 길이 |
    | :--------: | :--: | :-------: |
    | 메모리초과 |  -   |   904 B   |

-   2차원 배열에 N 번의 연산 이후에 가로 세로 열에 합이 구해지도록 했으나, DP 를 요구하는 문제가 아니었기 때문에 메모리를 초과하였다.

```cpp
#include <bits/stdc++.h>

using namespace std;
int ans = 0;
int N;
int M;
int temp;
vector<vector<int>> matrix;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    matrix = vector<vector<int>>(N, vector<int>(N));
    for (int n = 0; n < N; n++) {
        cin >> temp;
        for (int i = 0; i < N; i++) {
            if (i == n) continue;
            if (matrix[n][i] == 0) {
                matrix[n][i] = -temp;
            }
            else {
                matrix[n][i] = temp - matrix[n][i];
                if(matrix[n][i] == M) ans++;
            }

            if (matrix[i][n] == 0) {
                matrix[i][n] = -temp;
            }
            else {
                matrix[i][n] = temp - matrix[i][n];
                if(matrix[i][n] == M) ans++;
            }
        }
    }

    cout << (ans / 2);

    return 0;
}
```

## 정답

### C++：2025-10-11：정공법 풀이

-   | 메모리  |  시간  | 코드 길이 |
    | :-----: | :----: | :-------: |
    | 2200 KB | 112 ms |   463 B   |

-   얌전하게 조합 받아서 풀이

```cpp
#include <bits/stdc++.h>

using namespace std;
int ans = 0;
int N;
int M;
vector<int> v;

int main() {


    freopen("input.txt", "rt", stdin); // <- local input


    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    v = vector<int>(N);
    for (int n = 0; n < N; n++) {
        cin >> v[n];
    }

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (v[i] + v[j] == M) ans++;
        }
    }

    cout << ans;
    return 0;
}
```

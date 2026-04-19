# <img alt="s1" src="https://d2gd6pc034wcta.cloudfront.net/tier/10.svg" width="16" /> [BJ 2178](https://www.acmicpc.net/problem/2178)：미로 탐색：오답노트

## 목차

-   [BJ 2178：미로 탐색：오답노트](#-bj-2178미로-탐색오답노트)
    -   [목차](#목차)
    -   [힌트](#힌트)
    -   [오답](#오답)
        -   [C++：2026-03-08：DFS](#c2026-03-08dfs)
        -   [C++：2026-03-23：BFS](#c2026-03-23bfs)
    -   [정답](#정답)
        -   [C++：2026-04-16：BFS visited 누적합](#c2026-04-16bfs-visited-누적합)

## 힌트

-   ~~그래프 문제에서 사이클을 체크안하는 것은 자살행위와 같다.~~
-   ~~센스있게 누적된 거리를 구하는 visited 누적합~~

## 오답

### C++：2026-03-08：DFS

-   | 메모리 |   시간   | 코드 길이 |
    | :----: | :------: | :-------: |
    |   -    | 시간초과 |     1303 B     |

-   최단 거리 탐색에 DFS 는 최악이라는 점을 잊지 말 것

```cpp
#include <bits/stdc++.h>
using namespace std;

int ans, N, M;
vector<vector<bool>> matrix;

void recurDfs(int y, int x, int depth) {
    if (depth > ans) {
        return;
    }

    if ((y == N - 1) && (x == M - 1)) {
        ans = min(ans, depth);
        return;
    }

    if ((y > 0) && matrix[y - 1][x]) {
        matrix[y - 1][x] = 0;
        recurDfs(y - 1, x, depth + 1);
        matrix[y - 1][x] = 1;
    }
    if ((y < N - 1) && matrix[y + 1][x]) {
        matrix[y + 1][x] = 0;
        recurDfs(y + 1, x, depth + 1);
        matrix[y + 1][x] = 1;
    }
    if ((x > 0) && matrix[y][x - 1]) {
        matrix[y][x - 1] = 0;
        recurDfs(y, x - 1, depth + 1);
        matrix[y][x - 1] = 1;
    }
    if ((x < M - 1) && matrix[y][x + 1]) {
        matrix[y][x + 1] = 0;
        recurDfs(y, x + 1, depth + 1);
        matrix[y][x + 1] = 1;
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("_INPUT_.txt", "rt", stdin); // LOCAL INPUT <<================

    ans = INT_MAX;
    cin >> N >> M;
    matrix = vector<vector<bool>>(N, vector<bool>(M));

    for (int n = 0; n < N; n++) {
        string temp;
        cin >> temp;
        for (int m = 0; m < M; m++) {
            matrix[n][m] = (temp.at(m) == '1');
        }
    }

    recurDfs(0, 0, 1);

    cout << ans;
    
    return 0;
}
```

### C++：2026-03-23：BFS

-   |   메모리   | 시간 | 코드 길이 |
    | :--------: | :--: | :-------: |
    | 메모리초과 |  -   |   1303 B   |

-   사이클 체크를 잊었다. 저수준에서는 발각이 되지 않았기 때문. 큐에서는 계속 사이클이 돌고 있는 와중에 정답에 도달하면 while 조건에 걸렸기 때문에 낭비되고 있는 자원을 캐치하지 못했음.
-   또한, 누적합을 사용하면 따로 저장할 필요도 없었음에도 굳이 저런 방법을 선택한 것은 미스였음.

```cpp
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    // freopen("_INPUT_.txt", "rt", stdin); // LOCAL INPUT <<================

    int N, M;
    vector<vector<bool>> matrix;
    queue<vector<int>> vQue;
    int dy[4] = {-1, 0, 1, 0};
    int dx[4] = {0, 1, 0, -1};

    cin >> N >> M;
    matrix = vector<vector<bool>>(N, vector<bool>(M));

    for (int n = 0; n < N; n++) {
        string temp;
        cin >> temp;
        for (int m = 0; m < M; m++) {
            matrix[n][m] = (temp.at(m) == '1');
        }
    }

    vQue.push({0, 0, 1});

    while ((vQue.front()[0] != N - 1) || (vQue.front()[1] != M - 1)) {
        int y = vQue.front()[0];
        int x = vQue.front()[1];
        int d = vQue.front()[2];
        vQue.pop();
        for (int i = 0; i < 4; i++) {
            if ((0 <= y + dy[i]) && (y + dy[i] < N) && (0 <= x + dx[i]) && (x + dx[i] < M) && matrix[y + dy[i]][x + dx[i]]) {
                vQue.push({y + dy[i], x + dx[i], d + 1});
                matrix[y][x] = 0;
            }
        }
    }

    cout << vQue.front()[2];
    return 0;
}
```

## 정답

### C++：2026-04-16：BFS visited 누적합

-   | 메모리  | 시간 | 코드 길이 |
    | :-----: | :--: | :-------: |
    | 2040 KB | 0 ms |   969 B   |

-   사방탐색 사용
-   static 배열 사용
-   오답 풀이와 알고리즘은 비슷하나 int visited 누적합 사용
-   귀찮게 현재 위치의 깊이를 별도로 계산할 필요가 없다는 것이 좋음. 트리 관련 알고리즘 팁이므로 알고있으면 좋음

```cpp
#include <bits/stdc++.h>
using namespace std;
const int max_n = 104;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int n, m, a[max_n][max_n], visited[max_n][max_n], y, x;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("_INPUT_.txt", "rt", stdin); // <<=================

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string temp;
        cin >> temp;
        for (int j = 0; j < m; j++) {
            a[i][j] = temp.at(j) - '0';
        }
    }

    queue<pair<int, int>> q;
    visited[0][0] = 1;
    q.emplace(0, 0);

    while (!q.empty()) {
        auto [y, x] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++){
            int iy = y + dy[i];
            int ix = x + dx[i];

            if(iy < 0 || iy >= n  || ix < 0 || ix >= m || a[iy][ix] == 0 || visited[iy][ix]) continue;
            visited[iy][ix] = visited[y][x] + 1;
            q.emplace(iy, ix);
        }
    }

    cout << visited[n - 1][m - 1];
    return 0;
}
```

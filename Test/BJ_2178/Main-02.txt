// 메모리 초과
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
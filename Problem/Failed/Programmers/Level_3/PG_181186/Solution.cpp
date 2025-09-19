#ifndef SOLUTION
#define SOLUTION

#include <bits/stdc++.h>

using namespace std;

vector<vector<bool>> matrix;
int answer;
int len;

// deque<string> debugDq;

void dfs(int y, int x) {
    if (y >= 3) {
        answer = (answer + 1) % 1000000007;

        // for (string str : debugDq) {
        //     cout << str << ", ";
        // }
        // cout << "\n";

        return;
    }

    if (x >= len) {
        dfs(y + 1, 0);
        return;
    }

    if (matrix[y][x]) {
        dfs(y, x + 1);
        return;
    }

    // ⌈⌊⌋⌉|—

    // * |
    if ((y + 2 < 3) && !matrix[y][x] && !matrix[y + 1][x] && !matrix[y + 2][x]) {
        matrix[y][x] = true;
        matrix[y + 1][x] = true;
        matrix[y + 2][x] = true;

        // debugDq.emplace_back("V");
        dfs(y, x + 1);
        // debugDq.pop_back();

        matrix[y][x] = false;
        matrix[y + 1][x] = false;
        matrix[y + 2][x] = false;
    }

    // * —
    if ((x + 2 < len) && !matrix[y][x] && !matrix[y][x + 1] && !matrix[y][x + 2]) {
        matrix[y][x] = true;
        matrix[y][x + 1] = true;
        matrix[y][x + 2] = true;

        // debugDq.emplace_back("H");
        dfs(y, x + 3);
        // debugDq.pop_back();

        matrix[y][x] = false;
        matrix[y][x + 1] = false;
        matrix[y][x + 2] = false;
    }

    // * ⌋
    if ((x - 1 >= 0) && (y + 1 < 3) && !matrix[y][x] && !matrix[y + 1][x] && !matrix[y + 1][x - 1]) {
        matrix[y][x] = true;
        matrix[y + 1][x] = true;
        matrix[y + 1][x - 1] = true;

        // debugDq.emplace_back("RD");
        dfs(y, x + 1);
        // debugDq.pop_back();

        matrix[y][x] = false;
        matrix[y + 1][x] = false;
        matrix[y + 1][x - 1] = false;
    }

    if ((x + 1 < len) && (y + 1 < 3)) {
        // * ⌊
        if (!matrix[y][x] && !matrix[y + 1][x] && !matrix[y + 1][x + 1]) {
            matrix[y][x] = true;
            matrix[y + 1][x] = true;
            matrix[y + 1][x + 1] = true;

            // debugDq.emplace_back("LD");
            dfs(y, x + 1);
            // debugDq.pop_back();

            matrix[y][x] = false;
            matrix[y + 1][x] = false;
            matrix[y + 1][x + 1] = false;
        }

        // * ⌈
        if (!matrix[y][x] && !matrix[y + 1][x] && !matrix[y][x + 1]) {
            matrix[y][x] = true;
            matrix[y + 1][x] = true;
            matrix[y][x + 1] = true;

            // debugDq.emplace_back("LU");
            dfs(y, x + 2);
            // debugDq.pop_back();

            matrix[y][x] = false;
            matrix[y + 1][x] = false;
            matrix[y][x + 1] = false;
        }

        // * ⌉
        if (!matrix[y][x] && !matrix[y][x + 1] && !matrix[y + 1][x + 1]) {
            matrix[y][x] = true;
            matrix[y][x + 1] = true;
            matrix[y + 1][x + 1] = true;

            // debugDq.emplace_back("RU");
            dfs(y, x + 2);
            // debugDq.pop_back();

            matrix[y][x] = false;
            matrix[y][x + 1] = false;
            matrix[y + 1][x + 1] = false;
        }
    }

    return;
}

int solution(int n) {
    len = n;
    answer = 0;
    matrix = vector<vector<bool>>(3, vector<bool>(n));

    {   // * TEST 01
        // for (auto &v : matrix) {
        //     for (int i : v) {
        //         cout << i << " ";
        //     }
        //     cout << "\n";
        // }

        // return 01;
    }

    dfs(0, 0);
    return answer;
}


#endif
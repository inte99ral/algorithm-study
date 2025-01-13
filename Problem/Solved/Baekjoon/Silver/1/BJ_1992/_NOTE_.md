# <img alt="s1" src="https://d2gd6pc034wcta.cloudfront.net/tier/10.svg" width="16" /> [BJ 1992：쿼드트리](https://www.acmicpc.net/problem/1992)：오답노트

## 힌트

- ~-~볼 힌트~~
- ~~숨길 힌트~~

## 정답

2024.01.17 -> 2025-01-09

### Java：2024-01-17：재귀적 풀이

- |  메모리  |  시간  | 코드 길이 |
  | :------: | :----: | :-------: |
  | 14512 KB | 132 ms |  1309 B   |

- String 을 리턴하는 재귀함수 quadtree 를 이용해서 풀었습니다.

```java
import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.io.IOException;


public class Main {
  public static void main(String args[]) throws IOException, NumberFormatException {
    Main mainInstance = new Main();
    System.setIn(new FileInputStream("question/input.txt"));

    int N;
    boolean matrix[][];

    {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

      N = Integer.parseInt(br.readLine());
      matrix = new boolean[N][N];

      for(int y = 0; y < N; y++) {
        String rawInput = br.readLine();
        for(int x = 0; x < N; x++) matrix[y][x] = rawInput.charAt(x) == '1';
      }

      br.close();
    }


    System.out.println(mainInstance.quadTree(matrix, 0, 0, N));
    return;
  }

  public String quadTree(boolean[][] matrix, int Y, int X, int L) {
    if(L == 1) return matrix[Y][X]? "1" : "0";
    String UL = quadTree(matrix, Y, X, L >> 1);
    String UR = quadTree(matrix, Y, X + (L >> 1), L >> 1);
    String DL = quadTree(matrix, Y + (L >> 1), X, L >> 1);
    String DR = quadTree(matrix, Y + (L >> 1), X + (L >> 1), L >> 1);

    // Compress
    if((UL.length() == 1) && (UL == UR) && (UL == DL) && (UL == DR)) return UL;

    return new StringBuilder().append('(').append(UL).append(UR).append(DL).append(DR).append(')').toString();
  }
}
```

### C++：2024-01-17：재귀적 풀이

- | 메모리  | 시간 | 코드 길이 |
  | :-----: | :--: | :-------: |
  | 2156 KB | 0 ms |  1031 B   |

- String 을 리턴하는 재귀함수 quadtree 를 이용해서 풀었습니다.

```cpp
#include <iostream>
#include <vector>

using namespace std;

string quadTree(vector<vector<bool>> &matrix, int X, int Y, int L);

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  freopen("Problem\\Solved\\Baekjoon\\Silver\\1\\BJ_1992\\question\\input.txt", "rt", stdin);

  int N;
  vector<vector<bool>> matrix;

  cin >> N;
  cin.ignore();

  for(int y = 0; y < N; y++) {
    vector<bool> v;
    char rawInput[N + 1];
    cin.getline(rawInput, N + 1);

    for(int n = 0; n < N; n++) v.push_back(rawInput[n] == '1');
    matrix.push_back(v);
  }

  cout << quadTree(matrix, 0, 0, N);
  return 0;
}

string quadTree(vector<vector<bool>> &matrix, int X, int Y, int L) {
  if(L == 1) return matrix[Y][X]? "1" : "0";
  string UL = quadTree(matrix, X, Y, (L >> 1));
  string UR = quadTree(matrix, X + (L >> 1), Y, (L >> 1));
  string DL = quadTree(matrix, X, Y + (L >> 1), (L >> 1));
  string DR = quadTree(matrix, X + (L >> 1), Y + (L >> 1), (L >> 1));

  if((UL.length() == 1) && (UL == UR) && (UL == DL) && (UL == DR)) return UL;
  return '(' + UL + UR + DL + DR + ')';
}
```

### C++：2025-01-09：재귀적 풀이

- | 메모리  | 시간 | 코드 길이 |
  | :-----: | :--: | :-------: |
  | 2156 KB | 0 ms |  1369 B   |

- String 을 리턴하는 재귀함수 quadtree 를 이용해서 풀었습니다.
- 대신 matrix 를 bool 이 아니라 char 로 만들어봤는데 이 과정에서 이전보다 해맨 부분이 있습니다.

```cpp
#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#define SET_IO(INPUT_DATA) std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);std::ifstream fs(INPUT_DATA);std::cin.rdbuf(fs.is_open()?((std::istream*)&fs)->rdbuf():((std::istream*)new std::stringstream(INPUT_DATA))->rdbuf())
#else
#define SET_IO(INPUT_PATH) std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr)
#endif

using namespace std;

string quadTree(int Y, int X, int L, vector<vector<char>>* matrix);

int main() {
  SET_IO("_INPUT_.txt");

  int N;
  vector<vector<char>> matrix;

  cin >> N;
  cin.ignore();
  matrix = vector<vector<char>>(N, vector<char>(N, 0));

  for (int y = 0; y < N; y++) {
    for (int x = 0; x < N; x++) cin.get(matrix[y][x]);
    cin.ignore();
  }

  cout << quadTree(0, 0, N, &matrix);
  return 0;
}

string quadTree(int Y, int X, int L, vector<vector<char>>* matrixRef) {
  if (L == 1) {
    return string(1, (*matrixRef)[Y][X]);
  }

  string LU = quadTree(Y, X, L >> 1, matrixRef);
  string RU = quadTree(Y, X + (L >> 1), L >> 1, matrixRef);
  string LD = quadTree(Y + (L >> 1), X, L >> 1, matrixRef);
  string RD = quadTree(Y + (L >> 1), X + (L >> 1), L >> 1, matrixRef);
  string full = LU + RU + LD + RD;

  if ((full.length() == 4) && (LU == RU) && (RU == LD) && (LD == RD)) {
    return LU;
  }

  return '(' + full + ')';
}
```

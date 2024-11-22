# BJ 2567：색종이 2：오답노트

1. 나머지 연산자는 분배공식을 적용할 수 있다.
2. 거듭제곱 관련 연산은 분할 정복으로 풀지 않는다면 시간이 초과한다.
3. int 세제곱은 long long 이어도 범위가 초과한다.

## 오답

### Java：2023-12-24

```java
import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

  private static final int MATRIX_SIZE = 101;
  private static final int PAPER_SIZE = 10;

  public static void main(String[] args) throws IOException, NumberFormatException {
    System.setIn(new FileInputStream("question/input.txt"));

    BufferedReader br;
    boolean[][] matrix = new boolean[MATRIX_SIZE][MATRIX_SIZE];
    int answer = 0;

    {
      br = new BufferedReader(new InputStreamReader(System.in));
      int N = Integer.parseInt(br.readLine());

      for(;N-- > 0;) {
        String[] XY = br.readLine().split(" ");
        int X = Integer.parseInt(XY[0]);
        int Y = Integer.parseInt(XY[1]);
        for(int y = Y; y < Y + PAPER_SIZE; y++) for(int x = X; x < X + PAPER_SIZE; x++) matrix[y][x] = true;
      }

      br.close();
    }

    for(int y = 0; y < MATRIX_SIZE; y++) {
      for(int x = 0; x < MATRIX_SIZE; x++) {
        if(matrix[x][y]) {
          if (!matrix[x - 1][y]) answer++;
          if (!matrix[x + 1][y]) answer++;
          if (!matrix[x][y - 1]) answer++;
          if (!matrix[x][y + 1]) answer++;
        }
      }
    }

    System.out.println(answer);
    return;
  }
}
```

<hr />

### C++：2023-12-24

- 2차원 배열 형성 후, 데이터를 모두 입력받고 사방향에 빈 곳이 있는 지 체크

```cpp
#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  freopen("Problem\\Solved\\Baekjoon\\Silver\\4\\BJ_2567\\question\\input.txt", "rt", stdin); // -- input.txt
  int answer = 0;

  int N;
  bool (*matrix)[101] = new (bool[101][101])();

  cin >> N;
  for(;N--;) {
    int X;
    int Y;

    cin >> X >> Y;

    for(int y = Y; y < Y + 10; y++)
      for(int x = X; x < X + 10; x++)
        matrix[y][x] = true;
  }

  for(int y = 0; y < 101; y++) {
    for(int x = 0; x < 101; x++) {
      if(matrix[y][x]) {
        if(!matrix[y - 1][x]) answer++;
        if(!matrix[y][x - 1]) answer++;
        if(!matrix[y + 1][x]) answer++;
        if(!matrix[y][x + 1]) answer++;
      }
    }
  }

  delete[] matrix;

  cout << answer;
  return 0;
}
```

<hr />

### C++：2024-11-22

```cpp
#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#define SET_IO(INPUT_PATH) freopen(INPUT_PATH, "rt", stdin)
#else
#define SET_IO(INPUT_PATH) std::ios::sync_with_stdio(false); std::cin.tie(nullptr); cout.tie(nullptr)
#endif

using namespace std;

int dy[4] = {-1, 0, 0, 1};
int dx[4] = {0, -1, 1, 0};

int main() {
  SET_IO("_INPUT_.txt");

  int answer = 0;
  int N = 0;
  bool matrix[102][102] = {};

  cin >> N;
  for (int n = 0; n < N; n++) {
    int X, Y;
    cin >> X >> Y;

    for (int y = Y; y < Y + 10; y++) {
      for (int x = X; x < X + 10; x++) {
        matrix[y + 1][x + 1] = true;
      }
    }
  }

  for (int y = 0; y < 102; y++) {
    for (int x = 0; x < 102; x++) {
      if (matrix[y][x]) {
        for (int i = 0; i < 4; i++) {
          if (!matrix[y + dy[i]][x + dx[i]]) answer++;
        }
      }
    }
  }

  cout << answer;
  return 0;
}
```

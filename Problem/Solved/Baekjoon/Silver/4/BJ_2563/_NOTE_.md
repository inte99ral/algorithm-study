# BJ 2563：색종이：오답노트

## 오답

### <LANGUAGE_TYPE>：xxxx-xx-xx：<ANNOTATION_COMMENT>

## 정답

### Java：2023-12-24

```java
import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class Main {
  public static void main(String[] args) throws IOException, NumberFormatException {
    System.setIn(new FileInputStream("question/input.txt"));
    BufferedReader br;
    StringTokenizer st;

    int N;
    int answer = 0;
    boolean[][] matrix = new boolean[101][101];

    {
      br = new BufferedReader(new InputStreamReader(System.in));
      N = Integer.parseInt(br.readLine());

      for(int n = 0; n < N; n++) {
        int xCoord;
        int yCoord;

        st = new StringTokenizer(br.readLine());
        xCoord = Integer.parseInt(st.nextToken());
        yCoord = Integer.parseInt(st.nextToken());

        for(int y = yCoord; y < yCoord + 10; y++) {
          for(int x = xCoord; x < xCoord + 10; x++) {
            if(!matrix[y][x]) {
              matrix[y][x] = true;
              answer++;
            }
          }
        }
      }

      br.close();
    }

    System.out.println(answer);
  }
}
```

### C++：2023-12-24

```cpp
#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  freopen("Problem\\Solved\\Baekjoon\\Silver\\5\\BJ_2563\\question\\input.txt", "rt", stdin);

  bool matrix[101][101] = {false,};
  int N;
  int answer = 0;

  cin >> N;
  for (int n = 0; n < N; n++) {
    int xCoord, yCoord;

    cin >> xCoord >> yCoord;
    for (int x = xCoord; x < xCoord + 10; x++) {
      for (int y = yCoord; y < yCoord + 10; matrix[x][y++] = true) {
        if (!matrix[x][y]) answer++;
      }
    }
  }

  cout << answer << '\n';
  return 0;
}
```

### C++：2024-11-22

- 가산하던 이전 풀이와 다르게 차감하는 방향으로 풀이함

```cpp
#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#define SET_IO(INPUT_PATH) freopen(INPUT_PATH, "rt", stdin)
#else
#define SET_IO(INPUT_PATH) std::ios::sync_with_stdio(false); std::cin.tie(nullptr); cout.tie(nullptr)
#endif

using namespace std;

int main() {
  SET_IO("Problem\\Solved\\Baekjoon\\Silver\\5\\BJ_2563\\_INPUT_.txt");

  int answer;
  int N;
  int matrix[101][101] = {};

  cin >> N;

  answer = N * 100;

  for (int n = 0; n < N; n++) {
    int X, Y;
    cin >> X >> Y;
    for (int x = X; x < X + 10; x++) {
      for (int y = Y; y < Y + 10; y++) {
        if (matrix[x][y]) answer--;
        matrix[x][y] = true;
      }
    }
  }

  cout << answer;
  return 0;
}
```

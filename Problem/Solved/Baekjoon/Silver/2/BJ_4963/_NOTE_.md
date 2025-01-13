# <img alt="s2" src="https://d2gd6pc034wcta.cloudfront.net/tier/9.svg" width="16" /> [BJ 4963：N과 M (12)](https://www.acmicpc.net/problem/4963)：오답노트

## 힌트

- ~-~sd~~

## 정답

### C++：2024-01-02：서로소 알고리즘

- | 메모리  | 시간 | 코드 길이 |
  | :-----: | :--: | :-------: |
  | 2020 KB | 0 ms |  1583 B   |

- 서로소 알고리즘을 사용하였습니다.
  - 빈 칸이면 continue, 빈 칸이 아니라면 다음의 계산을 합니다.
  - 모든 칸은 (y \* x) + x 라는 고유값을 가지고 있습니다.
  - 데이터를 집어 넣으면서 동시에 8방향 주변에 연결되어 있는 칸들을 확인합니다.
  - 주변 칸이 빈 칸이면 continue, 빈 칸이 아니라면 다음의 계산을 합니다.
  - 칸의 값 == 본인 좌표값이 나올 때까지 계속 좌표를 타고 들어갑니다.
  - 도달했다면 현재 중심 값 (y \* x) + x 와 비교하여 더 작은 값을 중심값으로 바꿉니다. 이는 두 섬이 이번 칸으로 인하여 하나로 연결되는 경우에서 더 작은 값을 섬의 대표 값으로 만들기 위함입니다.
  - 이 과정을 거치면 하나의 섬인 모든 칸은 좌표를 따라가면 한 점으로 반드시 모이게 됩니다. 즉, 데이터를 다 집어넣고 나면 배열 값 == 본인 좌표값 인 배열의 수가 연결되어있는 섬의 수가 되는 것 입니다.

<br />

- 장점은 입력을 넣은 즉시 계산이 끝났으므로 메모리 소모도 적고 연산도 빠르다는 점입니다.
- 단점으론 좌표값과의 매칭과 최소값 기준을 맞추는 서로소 알고리즘 적용과정에 수많은 실수와 시행착오 때문에 구현에 쓸때없이 시간이 너무 많이 소모되었습니다.

```cpp
#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  freopen("Problem\\Solved\\Baekjoon\\Silver\\2\\BJ_4963\\question\\input.txt", "rt", stdin);

  const int dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
  const int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

  while(true) {
    int W, H;
    cin >> W >> H;

    if(W == 0) break;

    int matrix[H + 2][W + 2] = {};
    int answer = 0;

    for(int h = 1; h <= H; h++) {
      for(int w = 1; w <= W; w++) {
        cin >> matrix[h][w];

        if(!matrix[h][w]) continue;

        matrix[h][w] = h * (W + 2) + w;

        for(int i = 0; i < 8; i++) {

          if(matrix[h + dy[i]][w + dx[i]] == 0) continue;

          int y = h + dy[i];
          int x = w + dx[i];

          while(matrix[y][x] != y * (W + 2) + x) {
            int temp = matrix[y][x];
            y = temp / (W + 2);
            x = temp % (W + 2);
          }

          if(matrix[y][x] < matrix[h][w]) matrix[matrix[h][w] / (W + 2)][matrix[h][w] % (W + 2)] = matrix[y][x];
          else matrix[y][x] = matrix[h][w];
        }
      }
    }

    for(int h = 1; h <= H; h++) for(int w = 1; w <= W; w++) if(matrix[h][w] == h * (W + 2) + w) answer++;
    cout << answer << '\n';
  }

  return 0;
}
```

### Java：2024-01-02：서로소 알고리즘

- |  메모리  |  시간  | 코드 길이 |
  | :------: | :----: | :-------: |
  | 13852 KB | 124 ms |  1910 B   |

- C++ 와 동일한 풀이를 하였습니다.

```java
import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
  final static int[] dy = {-1, -1, -1, 0, 0, 1, 1, 1};
  final static int[] dx = {-1, 0, 1, -1, 1, -1, 0, 1};

  public static void main(String[] args) throws IOException, NumberFormatException {
    System.setIn(new FileInputStream("question\\input.txt"));
    {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      StringTokenizer st;

      String input = br.readLine();
      while(input.charAt(0) != '0') {
        int answer = 0;
        int W;
        int H;
        int[][] matrix;

        st = new StringTokenizer(input);
        W = Integer.parseInt(st.nextToken());
        H = Integer.parseInt(st.nextToken());
        matrix = new int[H + 2][W + 2];

        for(int h = 1; h <= H; h++) {
          st = new StringTokenizer(br.readLine());
          for(int w = 1; w <= W; w++) {
            matrix[h][w] = Integer.parseInt(st.nextToken());

            if(matrix[h][w] == 0) continue;

            matrix[h][w] = h * (W + 2) + w; // 본인 좌표값 할당

            for(int i = 0; i < 8; i++) {
              int y = h + dy[i];
              int x = w + dx[i];

              if(matrix[y][x] == 0) continue;

              while(matrix[y][x] != y * (W + 2) + x) {
                int temp = matrix[y][x];
                y = temp / (W + 2);
                x = temp % (W + 2);
              }

              if(matrix[h][w] < matrix[y][x]) matrix[y][x] = matrix[h][w];
              else matrix[matrix[h][w] / (W + 2)][matrix[h][w] % (W + 2)] = matrix[y][x];
            }
          }
        }

        for(int h = 1; h <= H; h++) for(int w = 1; w <= W; w++) if(matrix[h][w] == h * (W + 2) + w) answer++;
        System.out.println(answer);
        input = br.readLine();
      }

      br.close();
    }

    return;
  }
}
```

### Java：2024-01-02：DFS 알고리즘

- |  메모리  |  시간  | 코드 길이 |
  | :------: | :----: | :-------: |
  | 13824 KB | 136 ms |  2186 B   |

- 데이터 다 받고 나서 DFS로 연결된 모든 섬을 matrix 에서 삭제해버렸습니다.

```java
import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	private static BufferedReader br;
	private static StringTokenizer st;
	private static int w;
	private static int h;
	private static int[] dy = {-1, -1, -1, 0, 0, 1, 1, 1};
	private static int[] dx = {-1, 0, 1, -1, 1, -1, 0, 1};
	private static int[][] matrix;

	public static void main(String[] args) throws Exception {
		System.setIn(new FileInputStream("question\\input.txt"));
		br = new BufferedReader(new InputStreamReader(System.in));

		st = new StringTokenizer(br.readLine());

		w = Integer.parseInt(st.nextToken());
		h = Integer.parseInt(st.nextToken());
		int result = 0;

		while((w != 0) && (h != 0)) {
			matrix = new int[h][w];
			for(int y = 0; y < h; y++) {
				st = new StringTokenizer(br.readLine());
				for(int x = 0; x < w; x++) {
					matrix[y][x] = st.nextToken().equals("1")? 1 : 0;
				}
			}

			for(int y = 0; y < h; y++) {
				for(int x = 0; x < w; x++) {
					if(matrix[y][x] == 1) {
						result++;
						connectionCheck(y, x);
					}
				}
			}

			// output
			System.out.println(result);

			// init
			st = new StringTokenizer(br.readLine());
			w = Integer.parseInt(st.nextToken());
			h = Integer.parseInt(st.nextToken());
			result = 0;
		}

		return;
	}

	public static void connectionCheck(int y, int x) {
		for(int i = 0; i < 8; i++) {
			int Y = y + dy[i];
			int X = x + dx[i];
			if((0 <= Y) && (Y < h) && (0 <= X) && (X < w) && (matrix[Y][X] == 1)) {
				matrix[Y][X] = 2;
				connectionCheck(Y, X);
			}
		}
	}
}

```

### C++：2025-01-09：DFS 알고리즘

- | 메모리  | 시간 | 코드 길이 |
  | :-----: | :--: | :-------: |
  | 2156 KB | 0 ms |  1797 B   |

- 데이터 다 받고 나서 재귀함수가 아니라 while 로 DFS를 구현한 뒤에, 연결된 모든 섬을 count 로 값을 변환하였습니다.
- 8방향 파악에 out of index 가 되지 않도록 가로 세로 + 2 배열로 만들었습니다.
- 간 섬을 또 가거나 연산하기 않도록 visited 배열을 추가로 만들었습니다.

```cpp
#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#define SET_IO(INPUT_DATA) std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);std::ifstream fs(INPUT_DATA);std::cin.rdbuf(fs.is_open()?((std::istream*)&fs)->rdbuf():((std::istream*)new std::stringstream(INPUT_DATA))->rdbuf())
#else
#define SET_IO(INPUT_PATH) std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr)
#endif

using namespace std;

int main() {
  SET_IO("_INPUT_.txt");

  for(int X, Y; cin >> X >> Y;) {
    if (X == 0) break;

    int count = 0;
    int dy[9] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
    int dx[9] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};
    vector<vector<int>> matrix(Y + 2, vector<int>(X + 2));
    vector<vector<bool>> visited(Y + 2, vector<bool>(X + 2));

    for (int y = 1; y < Y + 1; y++) {
      for (int x = 1; x < X + 1; x++) {
        cin >> matrix[y][x];
      }
    }

    for (int y = 1; y < Y + 1; y++) {
      for (int x = 1; x < X + 1; x++) {
        if (matrix[y][x] == 0) continue;
        if (visited[y][x] == true) continue;

        count++;

        stack<pair<int, int>> task;
        task.emplace(y, x);

        while (!task.empty()) {
          int currY = task.top().first;
          int currX = task.top().second;
          task.pop();

          matrix[currY][currX] = count;
          visited[currY][currX] = true;

          for (int i = 0; i < 9; i++) {
            int nextY = currY + dy[i];
            int nextX = currX + dx[i];

            if (matrix[nextY][nextX] == 0) continue;
            if (visited[nextY][nextX]) continue;

            matrix[nextY][nextX] = count;
            visited[nextY][nextX] = true;

            task.emplace(nextY, nextX);
          }
        }
      }
    }

    cout << count << "\n";
  }

  return 0;
}
```

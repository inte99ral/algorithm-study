# <img alt="g5" src="https://d2gd6pc034wcta.cloudfront.net/tier/11.svg" width="16" /> [BJ 15686：치킨 배달](https://www.acmicpc.net/problem/15686)：오답노트

## 힌트

- ~-~복잡한 알고리즘보다 브루트포스가 훨씬 빠른 경우가 있다.~~
- ~-~순열과 조합 구현을 익혔다면 쉽게 풀 수 있다.~~

## 정답

### Java：2022-04-05：재귀적 방법의 조합과 최단경로

- |  메모리  |  시간  | 코드 길이 |
  | :------: | :----: | :-------: |
  | 75320 KB | 444 ms |  2501 B   |

- matrix 에서 치킨집과 가정집의 좌표를 얻어 chicken 과 house 라는 배열에 저장합니다.
- distance 라는 2차원 배열을 만듭니다.
  - Y 축은 치킨집, X 축은 가정집으로 값은 치킨집-가정집 사이의 거리로 채웁니다. 이제 첫번째 치킨집과 세번째 가정집 간의 거리를 매번 안구해도 `distance[1][3]` 으로 바로 얻을 수 있습니다.
- minChickenDistance 라는 함수를 만듭니다.
  - 재귀함수로써 minChickenDistance 를 다시 호출하며 조합을 구합니다.
  - 조합을 다 고른 시점에선 chickenDistance 함수를 호출합니다.
- removeChicken 이라는 함수를 만듭니다.
  - 조합의 선택을 위하여 제거된 치킨집은 distance 배열에서 거리를 Integer.MAX_VALUE 로 던져버립니다.
- chickenDistance 라는 함수를 만듭니다.
  - 2차원 배열 distance 로 부터 가장 짧은 값들의 합을 가져옵니다.

<br />

- 아이디어 자체는 재밌는데 몇 번 치킨집을 선택할 지 아는 시점에서 removeChicken 같은 연산을 할 이유가 없었습니다. 그냥 선택할 치킨집의 번호를 가지고 있는 배열만 있었어도 됬었습니다.
- 최단 경로 풀이 같은 느낌으로 풀고 싶었지만 이번 문제 같은 경우는 치킨집-가정집 간의 거리 연산이 워낙 단순하기 때문에 브루트 포스가 훨씬 빨랐습니다.

```java
import java.io.FileInputStream;
import java.util.ArrayList;
import java.util.Scanner;

public class Main {
  private static int N;
	private static int M;
	private static int minDistance;

	private static ArrayList<int[]> chicken = new ArrayList<>();
	private static ArrayList<int[]> house = new ArrayList<>();
	private static int[][] distance;
	private static Scanner sc;

	public static void main(String[] args) throws Exception {
		sc = new Scanner(new FileInputStream("input.txt"));

		N = sc.nextInt();
		M = sc.nextInt();

		int chickenCnt = 0;
		int houseCnt = 0;

		for(int y = 0; y < N; y++) {
			for(int x = 0; x < N; x++) {
				int curr = sc.nextInt();
				if(curr == 1) house.add(new int[] {y, x});
				if(curr == 2) chicken.add(new int[] {y, x});
			}
		}

		chickenCnt = chicken.size();
		houseCnt = house.size();

		distance = new int[house.size()][chicken.size()];
		for(int y = 0; y < house.size(); y++) {
			for(int x = 0; x < chicken.size(); x++) {
				distance[y][x] = Math.abs(house.get(y)[0] - chicken.get(x)[0]) + Math.abs(house.get(y)[1] - chicken.get(x)[1]);
			}
		}
		System.out.println(minChickenDistance(distance, chickenCnt, chickenCnt - M, 0, 0));
	}

	public static int minChickenDistance(int[][] distance, int n, int r, int cnt, int idx) {
		if(cnt == r) {
			return chickenDistance(distance);
		}

		int result = Integer.MAX_VALUE;

		for(int i = idx; i < n; i++) {
			int curr = minChickenDistance(removeChicken(distance, i), n, r, cnt + 1, i + 1);
			if(curr < result) result = curr;
		}

		return result;
	}

	public static int chickenDistance(int[][] distance) {
		int result = 0;
		for(int[] dArr : distance) {
			int min = Integer.MAX_VALUE;
			for(int d : dArr) {
				if(min > d) min = d;
			}
			result += min;
		}
		return result;
	}

	public static int[][] removeChicken(int[][] distance, int i) {
		int Y = distance.length;
		int X = distance[0].length;
		int[][] newDistance = new int[Y][X];

		for(int y = 0; y < Y; y++) {
			for(int x = 0; x < X; x++) {
				if(x == i) newDistance[y][x] = Integer.MAX_VALUE;
				else newDistance[y][x] = distance[y][x];
			}
		}

		return newDistance;
	}
}
```

### C++：2024-03-22：DFS 방법의 조합

- | 메모리  | 시간  | 코드 길이 |
  | :-----: | :---: | :-------: |
  | 2024 KB | 44 ms |  1593 B   |

- task 을 이용해서 DFS 방법으로 조합을 구현하였습니다.
  - 재귀함수의 알고리즘에 연산의 순서를 맡기지 않고, 연산정보를 stack 에 계속 넣게되습니다. stack 구조는 쌓인 순서의 가장 위부터, 가장 최근에 들어온 값을 가장 먼저 읽기 때문에 해당 방향의 연산의 깊숙한 끝까지 들어가고 나서야 그 다음 순서의 연산정보를 읽습니다.
- 이전 풀이는 반드시 최대가 되는 값에 INT_MAX 를 사용하였으나 이번엔 명백한 최댓값을 잡아 보았습니다.
  - 치킨 거리는 `N * N` 크기의 matrix 좌표의 양 끝 단 이상 멀어질 수 없기 때문에 `N * 2` 보다는 클 수 없습니다.
  - 치킨 거리의 총합, 변수 minLen 의 값은 `hVecs.size() * N * 2` 이상 클 수 없습니다.
- 연산이 다 끝나면 가장 작은 치킨거리의 합 minLen 을 출력합니다.

```cpp
#include <iostream>
#include <vector>
#include <deque>
#include <cstdlib>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  freopen("Problem\\Failed\\Baekjoon\\Gold\\5\\BJ_15686\\question\\input.txt", "rt", stdin);

  int N;
  int M;

  vector<vector<int>> cVecs;  // chicken vector
  vector<vector<int>> hVecs;  // house vector

  cin >> N >> M;

  for (int y = 0; y < N; y++) {
    vector<int> tempVec;
    for (int x = 0; x < N; x++) {
      int tempInt;
      cin >> tempInt;
      // tempVec.push_back(tempInt);
      if (tempInt == 1) {
        hVecs.push_back({y, x});
        continue;
      }
      else if (tempInt == 2) {
        cVecs.push_back({y, x});
        continue;
      }
    }
    // matrix.push_back(tempVec);
  }

  // ========== DFS ==========
  int minLen = hVecs.size() * N * 2;
  vector<vector<int>> select(M, {0, 0});
  deque<pair<int, int>> task = {{0, -1}};

  while(!task.empty()) {
    const int size = task.back().first;
    const int prev = task.back().second;
    task.pop_back();

    if(prev != -1) {
      select[size - 1] = cVecs[prev];
    }

    if(size == M) {

      { // Calc city chicken len
        int len = 0;
        for(vector<int> hVec : hVecs) {
          int min = N * 2;

          for(vector<int> cVec : select) {
            int len = abs(hVec[0] - cVec[0]) + abs(hVec[1] - cVec[1]);
            // cout << len << endl;
            min = (len < min) ? len : min;
          }

          len += min;
        }
        minLen = (len < minLen) ? len : minLen;
      }

      continue;
    }

    for(int i = cVecs.size() - 1; i > prev; i--) {
      task.push_back({size + 1, i});
    }
  }

  cout << minLen << endl;
  return 0;
}
```

### C++：2025-01-13：인라인 While 조합

- | 메모리  | 시간  | 코드 길이 |
  | :-----: | :---: | :-------: |
  | 2024 KB | 44 ms |  1593 B   |

- 브루트 포스가 가장 빠르고 편한 문제입니다.
- 잔에러가 없도록 단순한 논리로 while 을 사용하여 조합을 만들었습니다.
- 최대값도 단순하게 INT_MAX 썼습니다.
- 조합을 하나 찾으면 치킨거리를 바로 구해서 전부 sum 변수에 더한 뒤에 `answer = min(answer, sum);` 로 answer 에 가장 작은 치킨거리가 남도록 합니다.

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

  int answer = INT_MAX;
  int N;
  int M;

  vector<pair<int, int>> chicken;
  vector<pair<int, int>> house;

  vector<int> data;
  int size;

  { // * 초기화
    cin >> N;
    cin >> M;

    for (int y = 0; y < N; y++) {
      for (int x = 0; x < N; x++) {
        int temp;
        cin >> temp;

        switch (temp) {
        case 1:
          house.emplace_back(y, x);
          break;
        case 2:
          chicken.emplace_back(y, x);
          break;
        default:
          break;
        }
      }
    }

    data = vector<int>(M, 0);
    size = 0;
  }

  { // * 조합
    while (data[0] != (int) chicken.size()) {
      if (size == M) {
        { // * 치킨 거리 체크
          int sum = 0;
          for (int h = 0; h < (int) house.size(); h++) {
            int distance = INT_MAX;
            for (int m = 0; m < M; m++) {
              distance = min(distance, abs(house[h].first - chicken[data[m]].first) + abs(house[h].second - chicken[data[m]].second));
            }
            sum += distance;
          }

          answer = min(answer, sum);
        }

        size--;
        data[size]++;
        continue;
      }

      if (data[size] == (int) chicken.size()) {
        data[size] = 0;
        size--;
        data[size]++;
        continue;
      }

      if ((size != 0) && (data[size - 1] >= data[size])) {
        data[size]++;
        continue;
      }

      size++;
    }
  }
  cout << answer;
  return 0;
}
```

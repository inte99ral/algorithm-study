# <img alt="s3" src="https://d2gd6pc034wcta.cloudfront.net/tier/8.svg" width="16" /> BJ 15649：N과 M (1)：오답노트

## 힌트

- ~~수학적으로 순열 구현 방법을 이해해야 합니다.~~

## 정답

### Java：2023-12-29：Swap

- Swap 을 이용해서 순열을 구했습니다.

```java
import java.io.FileInputStream;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) throws Exception {
    int N;
    int M;
    int[] iArr;

    {
      Scanner sc = new Scanner(new FileInputStream("question/input.txt"));
      N = sc.nextInt();
      M = sc.nextInt();
      sc.close();
    }

		iArr = new int[N];
		for(int i = 0; i < N; i++) iArr[i] = i + 1;
		perm(iArr, 0, N, M);
	}

	public static void perm(int[] input, int depth, int n, int r) {
    if(depth == r) {
			System.out.println(Arrays.toString(Arrays.copyOfRange(input, 0, r)).replaceAll("[\\[\\,\\]]", ""));
			return;
		}
		for(int i = 0; i < n; i++) {
			swap(input, depth, i);
			perm(input, depth + 1, n, r);
			swap(input, depth, i);
		}
	}

	public static void swap(int[] input, int x, int y) {
		int temp = input[x];
		input[x] = input[y];
		input[y] = temp;
	}
}
```

### C++：2023-12-29：Recursive

- 재귀적 함수를 이용하여 순열을 구했습니다.

```cpp
#include <iostream>
#include <vector>

using namespace std;

void perm(vector<int> origin, int N, int M);
void permRecur(vector<int> origin, vector<int> fixed, int N, int M, int select, int length);

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  freopen("Problem\\Failed\\Baekjoon\\Silver\\3\\BJ_15649\\question\\input.txt", "rt", stdin);

  int N, M;
  vector<int> iVec;

  cin >> N >> M;
  for(int n = 0; n < N; n++) iVec.push_back(n + 1);
  perm(iVec, N, M);

  return 0;
}

void perm(vector<int> origin, int N, int M) {
  vector<int> fixed(M);
  permRecur(origin, fixed, N, M, 0, 0);
}

void permRecur(vector<int> origin, vector<int> fixed, int N, int M, int select, int length) {
  if(length == M) {
    for(int f : fixed) cout << f << ' ';
    cout << '\n';
    return;
  }

  for(int n = 0; n < N; n++) {
    if((select >> n) & 1) continue;
    fixed[length] = origin[n];
    permRecur(origin, fixed, N, M, select | (1 << n), length + 1);
  }
}
```

### C++：2024-12-20：Inline While Loop

- 직관적이진 않으나 while 루프만으로도 구할 수 있습니다.

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

  int N, M;
  int* data;
  int size;
  bool isSelect;

  cin >> N >> M;
  data = new int[M]();
  size = 0;
  isSelect = false;

  while (data[0] < N) {
    if (size == M) {
      for (int m = 0; m < M; m++) cout << data[m] + 1 << ' ';
      cout << '\n';

      size--;
      data[size]++;
      continue;
    }

    if (data[size] == N) {
      data[size] = 0;
      size--;
      data[size]++;
      continue;
    }

    isSelect = false;
    for (int s = 0; s < size; s++) {
      if (data[s] == data[size]) {
        isSelect = true;
        break;
      }
    }

    if(!isSelect) size++;
    else data[size]++;
  }

  delete[] data;
  return 0;
}
```

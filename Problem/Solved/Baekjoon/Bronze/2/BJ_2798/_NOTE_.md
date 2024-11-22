# BJ 2798：블랙잭：오답노트

## 정답

### Java：2023-12-26

```java
import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
  public static void main(String[] args) throws IOException, NumberFormatException{
    System.setIn(new FileInputStream("question/input.txt"));
    int answer = 0;
    int N;
    int M;
    int[] card;

    {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      String[] rawInput = br.readLine().split(" ");
      N = Integer.parseInt(rawInput[0]);
      M = Integer.parseInt(rawInput[1]);
      card = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
      br.close();
    }

    for(int i = 0; i < N - 2; i++) {
      if(card[i] > M) continue;
      for(int j = i + 1; j < N - 1; j++) {
        if(card[i] + card[j] > M) continue;
        for(int k = j + 1; k < N; k++) {
          if(card[i] + card[j] + card[k] > M) continue;
          if(card[i] + card[j] + card[k] < answer) continue;
          answer = card[i] + card[j] + card[k];
        }
      }
    }

    System.out.println(answer);
    return;
  }
}
```

### C++：2023-12-26

```cpp
#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  freopen("Problem\\Failed\\Baekjoon\\Bronze\\2\\BJ_2798\\question\\input.txt", "rt", stdin);

  int N;
  int M;
  int *card;
  int answer = 0;

  cin >> N >> M;

  card = new int[N];

  for(int n = 0; n < N; n++) cin >> card[n];

  for(int i = 0; i < N - 2; i++) {
    if(card[i] > M) continue;
    for(int j = i + 1; j < N - 1; j++) {
      if((card[i] + card[j]) > M) continue;
      for(int k = j + 1; k < N; k++) {
        if((card[i] + card[j] + card[k]) > M) continue;
        if((card[i] + card[j] + card[k]) < answer) continue;
        answer = card[i] + card[j] + card[k];
      }
    }
  }

  cout << answer;
  return 0;
}
```

### C++：2024-11-22

- 과거의 풀이에 비해 변수명이나 백트래킹 같은 세세함을 놓쳤다. 반성할 것

```cpp
#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#define SET_IO(INPUT_PATH) freopen(INPUT_PATH, "rt", stdin)
#else
#define SET_IO(INPUT_PATH) std::ios::sync_with_stdio(false); std::cin.tie(nullptr); cout.tie(nullptr)
#endif

using namespace std;

int main() {
  SET_IO("_INPUT_.txt");

  int N, M;
  int answer;
  int *iArr;

  cin >> N >> M;
  answer = 0;
  iArr = new int[N]();

  for (int n = 0; n < N; n++) {
    cin >> iArr[n];
  }

  for (int i = 0; i < N - 2; i++) {
    for (int j = i + 1; j < N - 1; j++) {
      for (int k = j + 1; k < N; k++) {
        int temp = iArr[i] + iArr[j] + iArr[k];
        if (answer < temp && temp <= M) answer = temp;
      }
    }
  }

  cout << answer;
  return 0;
}
```

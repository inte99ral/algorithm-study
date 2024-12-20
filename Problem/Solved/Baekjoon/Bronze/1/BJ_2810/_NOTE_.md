# <img alt="b1" src="https://d2gd6pc034wcta.cloudfront.net/tier/5.svg" width="16" /> BJ 2810：컵홀더：오답노트

## 힌트

- ~~모든 좌석이 S 싱글 좌석일 경우 컵홀더는 좌석 수 N에 대하여 N + 1 입니다.~~
- ~~커플 좌석 L 한 세트 마다 컵홀더 수는 N + 1 에서 줄어듭니다.~~

## 정답

### Java：2023-12-27

- 모든 좌석이 S 싱글 좌석일 경우 컵홀더는 좌석 수 N에 대하여 N + 1 입니다.
- 커플 좌석 L 한 세트 마다 컵홀더 수는 N + 1 에서 줄어듭니다.
- 문장 중에서 L 수를 센 후에 N - (count > 0? count / 2 - 1 : 0) 계산을 하면 됩니다.

```java
import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

  public static void main(String[] args) throws IOException, NumberFormatException {
    System.setIn(new FileInputStream("question/input.txt"));
    int N;
    int count = 0;
    String seat;

    {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      N = Integer.parseInt(br.readLine());
      seat = br.readLine();
      br.close();
    }

    for(int i = 0; i < N; i++) if(seat.charAt(i) == 'L') count++;

    System.out.println(N - (count > 0? count / 2 - 1 : 0));
  }
}
```

### C++：2023-12-27

- Java 풀이와 비슷하나

  1. 결국 최종값이 N+1 일때만 N, 나머지는 커플석 수 만큼 차감하면 된다.
  2. 커플석은 반드시 둘이 붙어서 나온다.

  두 논리에 따라 L 수를 세지않고 n 에 대한 루프에서 나오면 바로 answer--;n++; 을 시도한 뒤 answer가 N+1 인지만 확인하였습니다.

```cpp
#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  freopen("Problem\\Solved\\Baekjoon\\Bronze\\1\\BJ_2810\\question\\input.txt", "rt", stdin);

  int answer;
  int N;
  string input;

  cin >> N;
  cin >> input;

  answer = N + 1;
  for(int n = 0; n < N; n++) {
    if(input.at(n) == 'L') {
      answer--;
      n++;
    }
  }

  cout << (answer == N + 1? N : answer);

  return 0;
}
```

### C++：2024-12-20

- 더 단순해 졌습니다. 어차피 `전체 좌석 수 N`과 `N + 1에서 부터 차감한 컵홀더 수` 중에서 작은 것이 정답입니다.
- 따라서 정답은 min(holder, N); 이 될 것 입니다.

```cpp
#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#define SET_IO(INPUT_PATH) ios_base::sync_with_stdio(false);cout.tie(nullptr);cin.tie(nullptr);freopen(INPUT_PATH, "rt", stdin)
#else
#define SET_IO(INPUT_PATH) ios_base::sync_with_stdio(false);cout.tie(nullptr);cin.tie(nullptr)
#endif

using namespace std;

int main() {
  SET_IO("_INPUT_.txt");

  int N;
  string seat;
  int holder;

  cin >> N;
  cin >> seat;
  holder = N + 1;

  for (int n = 0; n < N; n++) {
    if (seat[n] == 'S') continue;
    holder--;
    n++;
  }

  cout << min(holder, N);
  return 0;
}
```

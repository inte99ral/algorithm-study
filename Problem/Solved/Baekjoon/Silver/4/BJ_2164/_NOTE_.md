# <img alt="s4" src="https://d2gd6pc034wcta.cloudfront.net/tier/7.svg" width="16" /> BJ 2164：카드2：오답노트

## 힌트

- ~~카드덱을 구현합니다.~~
- ~~일일히 구현은 속도가 매우 늦습니다. 구현없이도 수학적인 패턴이 존재합니다.~~

## 정답

### Java：2023-12-27：구현

- 직접 구현 풀이를 채택, Queue 로 카드 덱을 생성한 후에 카드를 뽑았다.

```java
import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class Main {
  public static void main(String[] args) throws Exception {
    System.setIn(new FileInputStream("question/input.txt")); // -- local input.txt

    int N;
    Queue<Integer> deck = new LinkedList<>();

    {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      N = Integer.parseInt(br.readLine());
      br.close();
    }

    for(int i = 1; i <= N; i++) deck.offer(i);
    while(deck.size() != 1){
      deck.poll();
      deck.offer(deck.poll());
    }

    System.out.println(deck.poll());
  }
}

```

### C++：2023-12-27：구현

- queue 를 이용하여 카드덱을 직접 구현한다.

```cpp
#include <iostream>
#include <queue>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  freopen("Problem\\Solved\\Baekjoon\\Silver\\4\\BJ_2164\\question\\input.txt", "rt", stdin);

  int N;
  queue<int> deck;

  cin >> N;
  for(int n = 1; n <= N; n++) deck.push(n);

  while(deck.size() != 1) {
    deck.pop();
    deck.push(deck.front());
    deck.pop();
  }

  cout << deck.front();

  return 0;
}
```

### C++：2024-12-20：수학

- 답에는 규칙이 존재합니다.
- 답은 항상 2의 배수이고 2의 거듭제곱에 맞춰서 아래의 순서로 패턴이 반복됩니다.
  - 1 | 2 | 2 4 | 2 4 6 8 | 2 4 6 8 10 12 14 16 ...
- 따라서 2의 거듭제곱의 누적합 = 등비수열의 합으로 값의 추론이 가능합니다.

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

  int N;
  int exp;
  cin >> N;
  exp = 1;
  while (exp << 1 < N) exp <<= 1;
  cout << (N == 1 ? 1 : (N - exp) * 2);

  return 0;
}
```

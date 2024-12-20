# <img alt="b1" src="https://d2gd6pc034wcta.cloudfront.net/tier/5.svg" width="16" /> BJ 2851：슈퍼 마리오：오답노트

## 힌트

- ~~100을 넘어선 순간만 체크하면 됩니다.~~

## 정답

### Java：2023-12-27

- 더했을 때 100이 아닌 시점에서 대소 비교를 합니다.

```java
import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

  public static void main(String[] args) throws IOException, NumberFormatException {
    System.setIn(new FileInputStream("input.txt"));
    int answer = 0;

    {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

      for (int i = 0; i < 10; i++) {
        int tempInt = Integer.parseInt(br.readLine());
        if (answer + tempInt <= 100) {
          answer += tempInt;
        }

        else {
          if (100 - answer < answer + tempInt - 100) {
            break;
          }
          else {
            answer += tempInt;
            break;
          }
        }
      }

      br.close();
    }

    System.out.println(answer);
    return;
  }
}

```

### C++：2023-12-27

- abs 절댓값 함수를 사용하여 다음 input 을 더한 것과 원본과의 100과의 거리를 확인합니다.

```cpp
#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  freopen("Problem\\Solved\\Baekjoon\\Bronze\\1\\BJ_2851\\question\\input.txt", "rt", stdin);

  int answer = 0;

  for(int i = 0; i < 10; i++) {
    int input;
    cin >> input;
    if(abs(answer - 100) < abs(answer + input - 100)) break;
    answer += input;
  }

  cout << answer;

  return 0;
}
```

### C++：2024-12-20

- abs 함수는 사실 필요가 없습니다. 어차피 100을 사이에 둔 시점에서만 판별하면 되기 때문에 명백히 input 을 더하기 전 값이 100보다 작고 더한 후 값이 100보다 큽니다.

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

  int answer = 0;

  for (int i = 0; i < 10; i++) {
    int temp; cin >> temp;

    if (100 - answer >= answer + temp - 100) answer += temp;
    else break;
  }

  cout << answer;

  return 0;
}
```

# 오답노트

## 정답

### 정답 > Java > 2023-12-20

- 사각형 모든 꼭짓점에 대하여 비교연산을 시도함

```java
import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

  public static void main(String[] args) throws IOException, NumberFormatException {
    System.setIn(new FileInputStream("input.txt"));
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringBuilder sb = new StringBuilder();
    for (int t = 0; t < 4; t++) {
      String[] line = br.readLine().split(" ");
      int x1 = Integer.parseInt(line[0]);
      int y1 = Integer.parseInt(line[1]);
      int p1 = Integer.parseInt(line[2]);
      int q1 = Integer.parseInt(line[3]);

      int x2 = Integer.parseInt(line[4]);
      int y2 = Integer.parseInt(line[5]);
      int p2 = Integer.parseInt(line[6]);
      int q2 = Integer.parseInt(line[7]);

      if (p1 < x2 || q1 < y2 || p2 < x1 || q2 < y1) {
        sb.append("d").append("\n");
      } else if (
        (x1 == p2 && y1 == q2) ||
        (p1 == x2 && y1 == q2) ||
        (p1 == x2 && q1 == y2) ||
        (x1 == p2 && q1 == y2)
      ) {
        sb.append("c").append("\n");
      } else if (x1 == p2 || p1 == x2 || q1 == y2 || q2 == y1) {
        sb.append("b").append("\n");
      } else {
        sb.append("a").append("\n");
      }
    }
    br.close();
    System.out.print(sb);
    return;
  }
}

```

### 정답 > C++ > 2024-11-07

- 두 사각형의 X 간의 겹치는 범위와 Y 간의 겹치는 범위만 안다면 답을 구할 수 있습니다.

```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {

  freopen("Problem\\Solved\\Baekjoon\\Silver\\1\\BJ_2527\\_input.txt", "rt", stdin);

  for (int i = 0; i < 4; i++) {
    int x1, y1, p1, q1, x2, y2, p2, q2;
    cin >> x1 >> y1 >> p1 >> q1 >> x2 >> y2 >> p2 >> q2;

    int xState = 2, yState = 2; // 0 Out, 1 Border, 2 In

    if (p2 < x1 || p1 < x2) xState = 0;
    else if (p2 == x1 || p1 == x2) xState = 1;

    if (q2 < y1 || q1 < y2) yState = 0;
    else if (q2 == y1 || q1 == y2) yState = 1;

    if (xState == 0 || yState == 0) cout << "d\n";
    else if (xState == 1 && yState == 1) cout << "c\n";
    else if (xState == 1 || yState == 1) cout << "b\n";
    else cout << "a\n";
  }
  return 0;
}
```

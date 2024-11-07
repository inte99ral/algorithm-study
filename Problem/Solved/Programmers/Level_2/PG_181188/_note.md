# 오답노트

## 정답

### 정답 > Java > 2023-12-15

```java
import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.StringTokenizer;

class Solution {
  // -- Local Input ====================
  public static void main(String[] args) throws IOException, NumberFormatException {
    System.setIn(new FileInputStream("question/input.txt"));
    Solution solInstance = new Solution();

    LinkedList<LinkedList<Integer>> rawInput = new LinkedList<LinkedList<Integer>>();
    int[][] input;

    {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      StringTokenizer st = new StringTokenizer(br.readLine(), "[, ]");

      while(st.hasMoreTokens()) {
        rawInput.add(
          new LinkedList<Integer>(Arrays.asList(
            Integer.parseInt(st.nextToken()),
            Integer.parseInt(st.nextToken())
          ))
        );
      }
      br.close();
    }

    input = rawInput.stream().map(e -> e.stream().mapToInt(i -> i).toArray()).toArray(int[][]::new);

    System.out.println(solInstance.solution(input));
    return;
  }

  // -- Solution =======================
  /**
   * 이상하게 풀었음 ㄹㅇ
   */
  public int solution(int[][] targets) {
    ArrayList<ArrayList<Integer>> memory = new ArrayList<ArrayList<Integer>>();

    // 소팅부터 박는다
    Arrays.sort(targets, (x, y) -> (x[0] - y[0]));

    ArrayList<Integer> tempIntList = new ArrayList<Integer>();
    tempIntList.add(targets[0][0]);
    tempIntList.add(targets[0][1]);
    tempIntList.add(targets[0][0]);

    memory.add(tempIntList);

    for (int i = 1; i < targets.length; i++) {
      if (targets[i][0] < memory.get(memory.size() - 1).get(1)) {
        memory
          .get(memory.size() - 1)
          .set(0, targets[i][0]);
        if (targets[i][1] < memory.get(memory.size() - 1).get(1))
        memory
          .get(memory.size() - 1)
          .set(1, targets[i][1]);
        memory.get(memory.size() - 1).add(targets[i][0]);
      } else {
        ArrayList<Integer> tempMemory = new ArrayList<Integer>();
        tempMemory.add(targets[i][0]);
        tempMemory.add(targets[i][1]);
        tempMemory.add(targets[i][0]);

        memory.add(tempMemory);
      }
    }

    return memory.size();
  }
}
```

<br />

### 정답 > C++ > 2024-11-07

- 처음 오답 풀이에서는 정렬을 하지 않고 개구간 시작과 끝을 기억하면서 겹치지 않는 경우를 계산하였다.
- 하지만 다음의 발상은 두 가지 오류를 가지고 있었다.
  1. 어차피 겹치는 이상 겹치는 구간을 알 필요없이 구간의 시작점이나 끝점만 보면 된다는 것
  2. [[3, 6], [2, 4], [5, 6], [1, 3]] 의 경우 처럼 소팅을 하지 않으면 이미 다른 구간과 겹쳐서 계산이 필요없는 구간을 구분 못하고 별개로 계산한다.
- 따라서 오름차순 소팅을 시도하고 구간의 끝부분만 확인하면서 진행하였다.

```cpp
#include <bits/stdc++.h>

using namespace std;

// # Prototype Declaration ==============================
int solution(vector<vector<int>> targets);

// # Global Variable & Constant =========================

// # Implements Definition ==============================
// ## Main
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  vector<vector<int>> input;

  // * Input
  {
    freopen("Problem\\Solved\\Programmers\\Level_2\\PG_181188\\_input.txt", "rt", stdin);

    {
      string rawInput;
      regex regExp("[0-9]+"); // Numbers
      sregex_token_iterator iter;
      sregex_token_iterator end;

      getline(cin, rawInput);
      iter = sregex_token_iterator(rawInput.begin(), rawInput.end(), regExp);

      while (iter != end) {
        input.push_back({stoi(*iter++), stoi(*iter++)});
      }
    }
  }

  // * Output
  {
    int answer = solution(input);
    cout << "[OUTPUT] : " << answer << "\n";
  }

  return 0;
}

// ## Solution
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> targets) {
  int minE = 0;
  int count = 0;

  sort(targets.begin(), targets.end());

  for (vector<int> iVec : targets) {
    int s = iVec[0];
    int e = iVec[1];

    if (s < minE) {
      minE = min(minE, e);
      continue;
    }

    count++;
    minE = e;
  }

  return count;
}
```

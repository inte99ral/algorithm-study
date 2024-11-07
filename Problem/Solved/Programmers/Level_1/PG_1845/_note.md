# 오답노트

## 정답

### 정답 > Java > 2023-12-10

- HashMap 을 이용해서 Map의 요소 수로 카운트해서 비교합니다.

```java
/**
 * java Solution.java
 */
import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.StringTokenizer;

class Solution {

  public static void main(String[] args) throws Exception {
    System.setIn(new FileInputStream("question/input.txt"));
    Solution solInstance = new Solution();

    int[] input;
    {
      ArrayList<Integer> rawInput = new ArrayList<>();
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      StringTokenizer st = new StringTokenizer(br.readLine(),"[, ]");

      while (st.hasMoreTokens()) rawInput.add(Integer.parseInt(st.nextToken()));
      input = rawInput.stream().mapToInt(e -> e).toArray();
      br.close();
    }

    System.out.println(solInstance.solution(input));
    return;
  }

  public int solution(int[] nums) {
    HashMap<Integer, Integer> monsterMap = new HashMap<Integer, Integer>();

    for (int monster : nums) {
      if (!monsterMap.containsKey(monster)) {
        monsterMap.put(monster, 1);
      }
    }

    if (monsterMap.size() < nums.length / 2) return monsterMap.size();
    return nums.length / 2;
  }
}

```

### 정답 > C++ > 2024-11-07

- set 을 사용하면 추가 연산 없이도 중복을 제거할 수 있습니다.

```cpp
#include <bits/stdc++.h>

using namespace std;

// # Prototype Declaration ==================================================

int solution(vector<int> nums);

// # Global Variable & Constant =============================================

// # Implements Definition ==================================================

// ## Main
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  vector<int> input;

  // * Input
  {
    freopen("Problem\\Solved\\Programmers\\Level_1\\PG_1845\\.input.txt", "rt", stdin);

      string rawInput;
      regex regExp("[0-9]+");
      sregex_token_iterator iter;
      sregex_token_iterator end;

      getline(cin, rawInput);
      iter = sregex_token_iterator(rawInput.begin(), rawInput.end(), regExp);

      while (iter != end) input.push_back(stoi(*iter++));
  }

  // * Output
  {
    int answer = solution(input);
    cout << "[OUTPUT] : " << answer << "\n";
  }

  return 0;
}


// ## Solution
#include <vector>
#include <unordered_set>

using namespace std;

int solution(vector<int> nums) {
  unordered_set<int> s(nums.begin(), nums.end());
  return min(nums.size() / 2, s.size());
}
```

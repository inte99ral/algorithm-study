# 오답노트

## 정답

### 정답 > 1 > 인라인 조합

```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
  vector<int> origin(9);

  int sum = 0;
  int gap = 0;

  for (int i = 0; i < 9; i++) {
    cin >> origin[i];
  }

  for (int i : origin) sum += i;
  gap = sum - 100;

  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < i; j++) {
      if (j == i) continue;
      if (origin[i] + origin[j] == gap) {
        origin.erase(origin.begin() + j);
        origin.erase(origin.begin() + i - 1);
        break;
      }
    }
  }

  for (int i : origin) cout << i << "\n";

  return 0;
}
```

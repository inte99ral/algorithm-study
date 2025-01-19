# 오답노트

## 오답

### 오답 > 1

- 기여코 벡터 써보겠다고 쇼하다 타임아웃

- 값의 추가/삭제가 많을 경우 더블링크드리스트 기반인 list가 압도적으로 빠르다는 것을 잊지 말자

```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  // freopen("Problem\\Unsolved\\Baekjoon\\Silver\\2\\BJ_5397\\question\\input.txt", "rt", stdin);

  int T;
  int L;
  int cursor;
  string str;
  vector<char> cVec;

  cin >> T;

  for (int t = 0; t < T; t++) {
    cin >> str;
    L = str.size();
    cursor = 0;
    cVec = vector<char>(L + 1);

    for (char c : str) {
      switch (c) {
        case '<':
          if (cursor > 0) cursor--;
          break;
        case '>':
          if (cVec[cursor]) cursor++;
          break;
        case '-':
          if (cursor > 0) {
            cursor--;
            cVec.erase(cVec.begin() + cursor);
          }
          break;
        default:
          // cVec[cursor] = c;
          cVec.insert(cVec.begin() + cursor, c);
          cursor++;
          break;
      }
    }

    cout << string(cVec.begin(), cVec.begin() + L) << "\n";
  }

  return 0;
}
```

## 정답

### 정답 > 1

```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  #ifndef ONLINE_JUDGE
  freopen("Problem\\Failed\\Baekjoon\\Silver\\2\\BJ_5397\\question\\input.txt", "rt", stdin);
  #endif

  int T;
  string str;
  list<char> cList;
  list<char>::iterator iter;

  cin >> T;

  for (int t = 0; t < T; t++) {
    cin >> str;
    cList = list<char>();
    iter = cList.begin();

    for (char c : str) {
      switch (c) {
        case '-':
          if (iter != cList.begin()) iter = cList.erase(--iter);
          break;
        case '<':
          if (iter != cList.begin()) iter--;
          break;
        case '>':
          if (iter != cList.end()) iter++;
          break;
        default:
          cList.insert(iter, c);
          break;
      }
    }

    for (char c : cList) cout << c;
    cout << '\n';
  }

  return 0;
}
```

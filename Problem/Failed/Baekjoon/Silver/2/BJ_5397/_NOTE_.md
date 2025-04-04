# <img alt="s2" src="https://d2gd6pc034wcta.cloudfront.net/tier/9.svg" width="16" /> [BJ 5397](https://www.acmicpc.net/problem/5397)：키로거：오답노트

## 힌트

- ~~벡터는 원소의 추가, 삭제가 매우 느린 컨테이너 입니다.~~
- ~~iterator 반복자는 원소 추가, 삭제시에 변경될 위험요소가 있습니다. 반환값을 받아 iter 를 새로 맞춰줘야 합니다.~~

## 오답

### C++：2024-10-18：벡터로 풀이 시도

- | 메모리 |   시간   | 코드 길이 |
  | :----: | :------: | :-------: |
  |   -    | 시간초과 |     -     |

- 기여코 벡터 써보겠다고 쇼하다 타임아웃 당했습니다.

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

### C++：2024-10-18：리스트로 풀이

- |  메모리  |  시간  | 코드 길이 |
  | :------: | :----: | :-------: |
  | 18724 KB | 176 ms |   786 B   |

- 값의 추가/삭제가 많을 경우 더블링크드리스트 기반인 list 컨테이너가 압도적으로 빠릅니다.

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

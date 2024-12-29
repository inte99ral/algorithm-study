# <img alt="s2" src="https://d2gd6pc034wcta.cloudfront.net/tier/9.svg" width="16" /> [BJ 15666：N과 M (12)](https://www.acmicpc.net/problem/15666)：오답노트

## 힌트

- ~-~중복된 값의 원소들을 가지고 중복조합을 만드는 문제입니다.~~
- ~-~이미 원소의 중복을 허용하므로 아예 중복된 원소들을 무시해도 됩니다. ~~

## 정답

### C++：2024-12-27：인라인 풀이

- | 메모리  | 시간 | 코드 길이 |
  | :-----: | :--: | :-------: |
  | 2024 KB | 0 ms |  1400 B   |

- while 루프 구조로 풀었습니다.
- 초기화 과정에서만 쓰이는 메모리가 있기 때문에 블록화시켜 관리하였습니다.
- 원소의 중복 선택을 허용하므로 값이 중복된 다른 원소들을 전부 제거하고 중복조합을 구하면 똑같은 결과가 나옵니다.
- 중복 원소를 허용하지 않는 Set 컨테이너를 이용하여 중복처리를 하였습니다.

  > ```cpp
  > set<int> elements;
  > for (int n = 0; n < N; n++) {
  >   int temp;
  >   cin >> temp;
  >   elements.insert(temp);
  > }
  > ```

- Set 컨테이너의 값을 origin 에 복사해주고, origin 의 크기를 조정하였습니다.

  > ```cpp
  > copy(elements.begin(), elements.end(), origin);
  > N = elements.size();
  > ```

- 그대로 원소 n 개의 집합에서 r 개를 고르는 중복조합 $_{n}\mathrm{H}_{r} = C'(n, r) = \binom{n+r-1}{r} = \binom{n+r-1}{n-1}$ 을 구하면 됩니다.

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
  int R;
  int* origin;
  int* select;
  int* data;
  int size;

  {
    cin >> N;
    cin >> R;

    origin = new int[N];
    set<int> elements;
    for (int n = 0; n < N; n++) {
      int temp;
      cin >> temp;
      elements.insert(temp);
    }
    copy(elements.begin(), elements.end(), origin);
    N = elements.size();

    select = new int[R]();
    data = new int[R]();
    size = 0;
  }

  while (data[0] < N) {
    if (size == R) {
      for (int r = 0; r < R; r++) cout << select[r] << ' ';
      cout << '\n';

      size--;
      data[size]++;
      continue;
    }

    if (data[size] == N) {
      data[size] = 0;
      size--;
      data[size]++;
      continue;
    }

    if ((size != 0) && (data[size - 1] > data[size])) {
      data[size]++;
      continue;
    }

    select[size] = origin[data[size]];
    size++;
  }

  delete[] origin;
  delete[] select;
  delete[] data;
  return 0;
}
```

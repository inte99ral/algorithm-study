# 문제 코드：문제 제목：오답노트

1. 나머지 연산자는 분배공식을 적용할 수 있다.
2. 거듭제곱 관련 연산은 분할 정복으로 풀지 않는다면 시간이 초과한다.
3. int 세제곱은 long long 이어도 범위가 초과한다.

## 오답

### <LANGUAGE_TYPE>：xxxx-xx-xx：<ANNOTATION_COMMENT>

### C++ > 1차 풀이

- 타임아웃

```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  freopen("Problem\\Unsolved\\Baekjoon\\Silver\\1\\BJ_1629\\question\\input.txt", "rt", stdin);

  int A, B, C;
  int answer;

  answer = A % C;

  for (int b = 0; b < B; b++) {
    if (b * 2 < B) {
      answer *= answer;
      answer %= C;
    }
  }

  cout << answer;

  return 0;
}
```

## 2차 풀이

- 반례 못찾음

```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  // freopen("Problem\\Unsolved\\Baekjoon\\Silver\\1\\BJ_1629\\question\\input.txt", "rt", stdin);

  int A, B, C;
  long long answer;
  bool isOdd;

  cin >> A >> B >> C;
  answer = A % C;
  isOdd = (B % 2 != 0);

  for (int i = B - isOdd; i > 1; i /= 2) {
    answer *= answer;
    answer %= C;
  }

  if (B != 1 && isOdd) {
    answer *= A;
    answer %= C;
  }

  cout << answer;

  return 0;
}
```

## 3차 풀이

- 자존심 굽히고 재귀함수 사용
- 반례 하나 찾음 `2 10 1000` 의 경우 24가 나와야하는데 256이 나왔음.

```cpp
#include <bits/stdc++.h>

using namespace std;

long long modRecur(int A, int B, int C) {
  if (B == 1) {
    return A % C;
  }
  if (B % 2 != 0) {
    return modRecur(A, B - 1, C) * A % C;
  }
  return (long long) pow(modRecur(A, B / 2, C), 2) % C;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  freopen("Problem\\Unsolved\\Baekjoon\\Silver\\1\\BJ_1629\\question\\input.txt", "rt", stdin);

  int A, B, C;
  long long answer;

  cin >> A >> B >> C;

  answer = modRecur(A, B, C);

  cout << answer;

  return 0;
}
```

## 4차 풀이

- 홀수 부분 문제

```cpp
#include <bits/stdc++.h>

using namespace std;

long long modRecur(int A, int B, int C) {
  if (B == 1) {
    return A % C;
  }
  if (B % 2 != 0) {
    return (long long) pow(modRecur(A, (B - 1) / 2, C), 2) * A % C;
  }
  return (long long) pow(modRecur(A, B / 2, C), 2) % C;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  freopen("Problem\\Unsolved\\Baekjoon\\Silver\\1\\BJ_1629\\question\\input.txt", "rt", stdin);

  int A, B, C;
  long long answer;

  cin >> A >> B >> C;

  answer = modRecur(A, B, C);

  cout << answer;

  return 0;
}
```

## 5차 풀이

- 아니 진짜로 모르겠네
- 정석 풀이 거의 복붙했는데 왜 나만 틀렸을까
- 아웃풋이나 자료형 문제인가?

```cpp
#include <bits/stdc++.h>

using namespace std;

long long modRecur(int A, int B, int C) {
  if (B == 1) {
    return A % C;
  }
  if (B % 2 == 0) {
    long long temp = modRecur(A, B / 2, C);
    return temp * temp % C;
  }

  long long temp = modRecur(A, (B - 1) / 2, C);
  return temp * temp * A % C;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  freopen("Problem\\Unsolved\\Baekjoon\\Silver\\1\\BJ_1629\\question\\input.txt", "rt", stdin);

  int A, B, C;
  long long answer;

  cin >> A >> B >> C;

  answer = modRecur(A, B, C);

  cout << answer;

  return 0;
}
```

## 정답

- 정확한 반례는 찾아봐야 할 거 같음
- 홀수 연산시에 괜찮다고 판단하고 %C를 넘기고 마지막에만 했는데 `temp * temp "% C" * A % C` 이 부분만 수정하자 해결되었음.
- 예상가는 첫번째 문제는 `temp * temp * A` 가 10^9 + 7 이상 값의 세제곱이라면 long long 범위를 나가는 부분이 문제인 듯 하다.

```cpp
#include <bits/stdc++.h>

using namespace std;

long long modRecur(long long A, long long B, long long C) {
  if (B == 1) {
    return A % C;
  }
  if (B % 2 == 0) {
    long long temp = modRecur(A, B / 2, C) % C;
    return temp * temp % C;
  }

  long long temp = modRecur(A, (B - 1) / 2, C) % C;
  return temp * temp % C * A % C;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  freopen("Problem\\Unsolved\\Baekjoon\\Silver\\1\\BJ_1629\\question\\input.txt", "rt", stdin);

  long long A, B, C;
  long long answer;

  cin >> A >> B >> C;

  answer = modRecur(A, B, C);

  cout << answer;

  return 0;
}
```

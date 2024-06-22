# 중복순열：Permutation With Repetition

</br>

## 목차

- 중복순열이란?
- [1. 수학적 경우의 수 계산](./중복순열：Permutation%20With%20Repetition.md#1-수학적-경우의-수-계산)

</br>

## 중복순열이란?

- 서로 다른 n개의 원소에서 r (단, 0 < r ≤ n)개를 중복을 허용하고 뽑을 때 나올 수 있는 경우의 집합을 말한다.

</br>

## 1. 수학적 경우의 수 계산

- N 개 중 하나를 뽑는 것을 R번 반복하기 때문에 N의 R제곱을 하면 경우의 수를 구할 수 있다.

### c++

```cpp
#include <iostream>

using namespace std;

// # Prototype Declaration ====================
// ## 1. Math : Factorial Calculation ==========
int factorial(int x);


// # Implements Definition ====================
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  const int N = 5;
  const int R = 3;

  int origin[N][3] = {{1, 11, 111}, {2, 22, 222}, {3, 33, 333}, {4, 44, 444}, {5, 55, 555}};

  // 1. Math : Factorial Calculation
  {
    // nPr = n! / (n - r)!
    cout << "\n[CASES]: Don't know!\n";
    cout << "[ANSWER]: " << factorial(N) / factorial(N - R) << '\n';
  }

  return 0;
}

// ## 1. Math : Factorial Calculation ==========
int factorial(int x) {
  return (x == 1) || (x == 0) ? 1 : x * factorial(x - 1);
}
```

<br />

## 2. For

<br />

## 3. While

- N 개 중 하나를 뽑는 것을 R번 반복하기 때문에 N의 R제곱을 하면 경우의 수를 구할 수 있다.

### c++

```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N = 2;
  int R = 3;
  int size = 0;
  int data[R] = {};

  while (data[0] != N) {
    if (size == R) {
      for (int r = 0; r < R; r++) {
        cout << data[r] << ", ";
      }
      cout << "\b\b \n";

      size--;
      data[size]++;
      continue;
    }

    // * 커서 후퇴
    if (data[size] == N) {
      data[size] = 0;
      size--;
      data[size]++;
    }
    // * 커서 전진
    else {
      size++;
    }
  }

  return 0;
}
```

<br />

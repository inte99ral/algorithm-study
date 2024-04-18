# 순열

- 서로 다른 n개의 원소에서 r (단, 0 < r ≤ n)개를 중복없이 순서를 고려하여 선택하거나 나열하거나 하는 것을 순열(permutation)이라고 한다.

</br>

## 1. 수학적 경우의 수 계산

- N 개를 순서대로 나열하는 모든 경우의 수 N! 에서 R 개만을 뽑는다면, 뽑지 않은 것들을 나열하는 경우의 수 (N - R)! 만큼이 중복되므로 나누어 해당 경우의 수를 제거

```cpp
#include <iostream>

using namespace std;

// # Prototype Declaration ====================
// ## 0. Default ===============================
// ## 1. Math : Factorial Calculation ==========
int factorial(int x);


// # Implements Definition ====================
// ## 0. Default ===============================
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  const int N = 5;
  const int R = 3;

  int origin[N][3] = {{1, 11, 111}, {2, 22, 222}, {3, 33, 333}, {4, 44, 444}, {5, 55, 555}};

  // ## 1. Math : Factorial Calculation ==========
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

## 2. 지역적 풀이 : For 루프 사용

- 지역적으로 뽑을 수 만큼 일일히 For 루프 코드를 작성하여 중복되지 않는 경우의 수를 모두 구현한다.

```cpp
#include <array>
#include <cstdarg>
#include <deque>
#include <iostream>
#include <regex>

using namespace std;

// # Prototype Declaration ====================
// ## 0. Default ===============================
template <typename T, size_t N>
void printArr(T (&arr)[N], int begin = 0, ...);
void printArrRecur(int* arr, deque<int> arrData);


// # Implements Definition ====================
// ## 0. Default ===============================
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  const int N = 5;
  const int R = 3;

  int origin[N][3] = {{1, 11, 111}, {2, 22, 222}, {3, 33, 333}, {4, 44, 444}, {5, 55, 555}};

  // ## 2. Inline : For Loop =====================
  {
    // R 고정. 뽑을 수 만큼 FOR 루프를 돌면 된다.
    int select[3][3] = {};
    int count = 0;

    cout << "\n[CASES]:\n";

    for (int i = 0; i < N; i++) {
      copy((int*)origin[i], (int*)origin[i + 1], (int*)select[0]);

      for (int j = 0; j < N; j++) {
        if (j == i) continue;
        copy((int*)origin[j], (int*)origin[j + 1], (int*)select[1]);

        for (int k = 0; k < N; k++) {
          if (k == i || k == j) continue;
          copy((int*)origin[k], (int*)origin[k + 1], (int*)select[2]);
          printArr(select);
          count++;
        }
      }
    }

    cout << "[ANSWER]: " << count << '\n';
  }

  return 0;
}

template <typename T, size_t N>
void printArr(T (&arr)[N], int begin, ...) {
  deque<int> arrData;
  string arrType = typeid(arr).name();

  regex regExp("A[0-9]+_", regex::optimize);
  sregex_token_iterator iter(arrType.begin(), arrType.end(), regExp), end;

  va_list ap;
  va_start(ap, begin);
  int buffer = begin;

  while (iter != end) {
    string token = (string)*iter++;
    if (buffer) {
      arrData.push_back(buffer);
      buffer = va_arg(ap, int);
    }
    else {
      arrData.push_back(stoi(token.substr(1, token.size() - 2)));
    }
  }

  va_end(ap);

  printArrRecur((int*)arr, arrData);
  cout << "\b\b  " << endl;
}

void printArrRecur(int* arr, deque<int> arrData) {
  if (arrData.size() == 0) cout << "\033[0m" << *arr << ", ";
  else {
    int N = arrData.front();
    arrData.pop_front();
    int gap = 1;
    int color = 31 + (arrData.size() % 6);
    for (int i : arrData) gap *= i;
    cout << "\033[" << color << "m[";

    for (int n = 0; n < N; n++) {
      printArrRecur(arr, arrData);
      arr += gap;
    }
    cout << "\033[" << color << "m\b\b]\033[0m, ";
  }
}
```

<br />

## 3. 지역적 풀이 : While 루프 사용

- For 루프와 완벽히 똑같은 알고리즘.
- 정보를 남겨 N R 값을 유동적으로 바꿀 수 있다.
- i 루프, j 루프... 루프 안으로 들어가는 상황과 나오는 상황을 if 문으로 구현한다.

```cpp
#include <array>
#include <cstdarg>
#include <deque>
#include <iostream>
#include <regex>

using namespace std;

// # Prototype Declaration ====================
// ## 0. Default ===============================
template <typename T, size_t N>
void printArr(T (&arr)[N], int begin = 0, ...);
void printArrRecur(int* arr, deque<int> arrData);


// # Implements Definition ====================
// ## 0. Default ===============================
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  const int N = 5;
  const int R = 3;

  int origin[N][3] = {{1, 11, 111}, {2, 22, 222}, {3, 33, 333}, {4, 44, 444}, {5, 55, 555}};

  // ## 3. Inline : While Loop ===================
  {
    int select[R][3] = {};
    int count = 0;
    int size = 0;
    int data[R] = {};
    bool isSelected = false;

    cout << "\n[CASES]:\n";

    while (data[0] != N) {
      if (size == R) {
        printArr(select);
        count++;
        size -= 1;
        data[size] += 1;
        continue;
      }

      copy((int*)origin[data[size]], (int*)origin[data[size] + 1], (int*)select[size]);

      if (data[size] == N) {
        data[size] = 0;
        size--;
        data[size]++;
        continue;
      }

      isSelected = false;

      for (int i = 0; i < size; i++) {
        if (data[i] == data[size]) {
          isSelected = true;
          continue;
        }
      }

      if (isSelected) {
        data[size]++;
      }
      else {
        size++;
      }
    }

    cout << "[ANSWER]: " << count << '\n';
  }

  return 0;
}

// ## 0. Default ===============================
template <typename T, size_t N>
void printArr(T (&arr)[N], int begin, ...) {
  deque<int> arrData;
  string arrType = typeid(arr).name();

  regex regExp("A[0-9]+_", regex::optimize);
  sregex_token_iterator iter(arrType.begin(), arrType.end(), regExp), end;

  va_list ap;
  va_start(ap, begin);
  int buffer = begin;

  while (iter != end) {
    string token = (string)*iter++;
    if (buffer) {
      arrData.push_back(buffer);
      buffer = va_arg(ap, int);
    }
    else {
      arrData.push_back(stoi(token.substr(1, token.size() - 2)));
    }
  }

  va_end(ap);

  printArrRecur((int*)arr, arrData);
  cout << "\b\b  " << endl;
}

void printArrRecur(int* arr, deque<int> arrData) {
  if (arrData.size() == 0) cout << "\033[0m" << *arr << ", ";
  else {
    int N = arrData.front();
    arrData.pop_front();
    int gap = 1;
    int color = 31 + (arrData.size() % 6);
    for (int i : arrData) gap *= i;
    cout << "\033[" << color << "m[";

    for (int n = 0; n < N; n++) {
      printArrRecur(arr, arrData);
      arr += gap;
    }
    cout << "\033[" << color << "m\b\b]\033[0m, ";
  }
}
```

<br />

## 4. 지역적 풀이 : DFS 스택과 비트 연산자

- 3의 풀이는 while 루프 하나가 매 상황 분기마다 i, k, j... 루프 상태를 구현하기 위해 과하게 복잡한 구조를 가진다.
- 스택을 활용하여 한 요소를 다루는 상황 당, 해당 순서의 요소를 선택하지 않는 경우의 수와 선택하는 경우의 수를 스택에 쌓고, 쌓인 순서의 역순으로 빼내며 작업을 처리하면 코드 구조가 단순해진다.
- 비트 연산자를 활용하여 int 값 하나로 32 가지의 참거짓 여부를 기록할 수 있다.

```cpp
#include <array>
#include <cstdarg>
#include <deque>
#include <iostream>
#include <regex>

using namespace std;

// # Prototype Declaration ====================
// ## 0. Default ===============================
template <typename T, size_t N>
void printArr(T (&arr)[N], int begin = 0, ...);
void printArrRecur(int* arr, deque<int> arrData);


// # Implements Definition ====================
// ## 0. Default ===============================

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  const int N = 5;
  const int R = 3;

  int origin[N][3] = {{1, 11, 111}, {2, 22, 222}, {3, 33, 333}, {4, 44, 444}, {5, 55, 555}};

  // ## 4. Inline Stack & Bitwise Operator =======
  {
    int count = 0;
    int select[R][3] = {};
    deque<array<int, 3>> task = {{0, 0, 0}};

    cout << "\n[CASES]:\n";

    while (!task.empty()) {
      int data = task.back()[0];
      int size = task.back()[1];
      int curr = task.back()[2];

      task.pop_back();

      if (size == R) {
        printArr(select);
        count++;
        continue;
      }

      if (curr == N) {
        continue;
      }

      task.push_back({data, size, curr + 1});

      if (data & (1 << curr)) continue;
      copy((int*)origin[curr], (int*)origin[curr + 1], (int*)select[size]);

      task.push_back({data | (1 << curr), size + 1, 0});
    }

    cout << "[ANSWER]: " << count << '\n';
  }

  return 0;
}

// ## 0. Default ===============================
template <typename T, size_t N>
void printArr(T (&arr)[N], int begin, ...) {
  deque<int> arrData;
  string arrType = typeid(arr).name();

  regex regExp("A[0-9]+_", regex::optimize);
  sregex_token_iterator iter(arrType.begin(), arrType.end(), regExp), end;

  va_list ap;
  va_start(ap, begin);
  int buffer = begin;

  while (iter != end) {
    string token = (string)*iter++;
    if (buffer) {
      arrData.push_back(buffer);
      buffer = va_arg(ap, int);
    }
    else {
      arrData.push_back(stoi(token.substr(1, token.size() - 2)));
    }
  }

  va_end(ap);

  printArrRecur((int*)arr, arrData);
  cout << "\b\b  " << endl;
}

void printArrRecur(int* arr, deque<int> arrData) {
  if (arrData.size() == 0) cout << "\033[0m" << *arr << ", ";
  else {
    int N = arrData.front();
    arrData.pop_front();
    int gap = 1;
    int color = 31 + (arrData.size() % 6);
    for (int i : arrData) gap *= i;
    cout << "\033[" << color << "m[";

    for (int n = 0; n < N; n++) {
      printArrRecur(arr, arrData);
      arr += gap;
    }
    cout << "\033[" << color << "m\b\b]\033[0m, ";
  }
}
```

<br />

## 5. 반복자 풀이 : 오름차순과 내림차순

- 2 ~ 4 번의 출력값들을 자세히 보면 순열 데이터의 오름차순 출력 과정은 원본 배열이 오름차순 배열에서 시작하여 내림차순으로 정렬되는 과정과 같다는 것을 눈치챌 수 있다.
- (시작은 오름차순) 1 - 2 - 3 >>> (끝은 내림차순) 3 - 2 - 1
- 이를 응용하여 오름차순 정렬이 확실하다면 내림차순으로 바꾸는 알고리즘 만으로 모든 순열 경우를 얻을 수 있다.

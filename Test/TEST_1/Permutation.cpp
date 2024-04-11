#include <array>
#include <cstdarg>
#include <deque>
#include <iostream>
#include <regex>

using namespace std;

// # Prototype Declaration ====================

int factorial(int x);
template <typename T, size_t N>
void printArr(T (&arr)[N], int begin = 0, ...);
void printArrRecur(int* arr, deque<int> arrData);
template <typename T, size_t N>
void swapArr(T (&arr1)[N], T (&arr2)[N]);

// ## 4. Recursive & Bitwise Operator =========
template <typename T, size_t N> 
int perm4(T (&origin)[N], int n, int r);
template <typename T1, size_t N1, typename T2, size_t N2> 
void perm4Recur(T1 (&origin)[N1], T2 (&select)[N2], int n, int r, int data, int size, int *count);

template <typename T, size_t N>
int perm00(T (&origin)[N], int n, int r);
template <typename T, size_t N>
void perm00Recur(T (&select)[N], int size, int n, int r, int *count);

// # Implements Definition ====================

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  const int N = 3;
  const int R = 3;

  // int origin[N][3] = {{1, 11, 111}, {2, 22, 222}, {3, 33, 333}, {4, 44, 444}};
  int origin[N][3] = {{1, 11, 111}, {2, 22, 222}, {3, 33, 333}};

  // ## 1. Mathematical Calculation =============
  {
    // nPr = n! / (n - r)!
    // cout << "\n[CASES]: Don't know!\n";
    // cout << "[ANSWER]: " << factorial(N) / factorial(N - R) << '\n';
  }

  // ## 2. Inline For Loop ======================
  {
    // int count = 0;
    // int select[3][3] = {};

    // cout << "\n[CASES]:\n";

    // for (int i = 0; i < N; i++) {
    //   copy((int*)origin[i], (int*)origin[i + 1], (int*)select[0]);

    //   for (int j = 0; j < N; j++) {
    //     if (j == i) continue;
    //     copy((int*)origin[j], (int*)origin[j + 1], (int*)select[1]);

    //     for (int k = 0; k < N; k++) {
    //       if (k == i || k == j) continue;
    //       copy((int*)origin[k], (int*)origin[k + 1], (int*)select[2]);
    //       printArr(select);
    //       count++;
    //     }
    //   }
    // }

    // cout << "[ANSWER]: " << count << '\n';
  }

  // ## 3. Inline Stack & Bitwise Operator ======
  {
    // // 비트 연산자를 사용하기 때문에 Int = 32bit, 32개 이상 선택 불가. bool 배열로 대체 가능
    // int count = 0;
    // int select[R][3] = {};
    // deque<array<int, 3>> task = {{0, 0, 0}};

    // cout << "\n[CASES]:\n";

    // while (!task.empty()) {
    //   int data = task.back()[0];
    //   int size = task.back()[1];
    //   int curr = task.back()[2];

    //   task.pop_back();

    //   if (size == R) {
    //     printArr(select);
    //     count++;
    //     continue;
    //   }

    //   if (curr == N) {
    //     continue;
    //   }

    //   task.push_back({data, size, curr + 1});
    //   if (data & (1 << curr)) continue;
    //   copy((int*)origin[curr], (int*)origin[curr + 1], (int*)select[size]);
    //   task.push_back({data | (1 << curr), size + 1, 0});
    // }

    // cout << "[ANSWER]: " << count << '\n';
  }

  // ## 4. Recursive & Bitwise Operator =========
  {
    cout << "\n[CASES]:\n";
    int count = perm4(origin, N, R);
    cout << "[ANSWER]: " << count << '\n';
  }

  // ## 5. Iterative ============================
  {
    // cout << "\n[CASES]:\n";
    // int count = perm5(origin, N, R);
    // cout << "[ANSWER]: " << count << '\n';
  }

  // ## 00. Recursive Function & Swap ============
  {
    //   // 구현과 계산속도가 빠른 대신 오름차순이 아님
    //   cout << "\n[CASES]:\n";
    //   int count = perm4(origin, N, R);
    //   cout << "[ANSWER]: " << count << '\n';
  }

  return 0;
}

int factorial(int x) {
  return (x == 1) || (x == 0) ? 1 : x * factorial(x - 1);
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

template <typename T, size_t N> 
void swapArr(T (&arr1)[N], T (&arr2)[N]) {
  T temp[N] = {};
  copy((int*)arr1, (int*)arr1 + size(arr1), (int*)temp);
  copy((int*)arr2, (int*)arr2 + size(arr2), (int*)arr1);
  copy((int*)temp, (int*)temp + size(temp), (int*)arr2);
  return;
}

// ## 4. Recursive & Bitwise Operator =========

template <typename T, size_t N> 
int perm4(T (&origin)[N], int n, int r) {
  int count;
  T select[r] = {};
  perm4Recur(origin, select, n, r, 0, 0, &count);

  return count;
}

template <typename T1, size_t N1, typename T2, size_t N2> 
void perm4Recur(T1 (&origin)[N1], T2 (&select)[N2], int n, int r, int data, int size, int *count) {
  if (size == r) {
    printArr(select);
    *count++;
    return;
  }

  for (int i = 0; i < n; i++) {
    if ((data >> i) & 1) continue;
    permRecur(origin, select, n, r, data | (i << i), size + 1);
  }

  return;
}

template <typename T, size_t N> int perm00(T (&origin)[N], int n, int r) {
  // int count;
  // T select[N] = {};
  // copy((int*)origin[0], (int*)origin[size(origin)], (int*)select);

  // perm4Recur(select, 0, n, r, &count);
  // return count;

  return 0;
}

template <typename T, size_t N> void perm00Recur(T (&select)[N], int size, int n, int r, int* count) {
  // if (size == r) {
  //   printArr(select, r, NULL);
  //   *count++;
  //   return;
  // }

  // for (int i = size; i < n; i++) {
  //   swapArr(select[size], select[i]);
  //   perm4Recur(select, size + 1, n, r, count);
  //   swapArr(select[size], select[i]);
  // }
  // return;
}
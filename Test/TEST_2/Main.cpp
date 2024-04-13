#include <array>
#include <cstdarg>
#include <deque>
#include <iostream>
#include <regex>

using namespace std;

// # Prototype Declaration ====================
// ## 1. Mathematical Calculation =============
int factorial(int x);
template <typename T, size_t N>
void printArr(T (&arr)[N], int begin = 0, ...);
void printArrRecur(int* arr, deque<int> arrData);

// ## 4. Recursive & Bitwise Operator =========
template <typename T, size_t N>
int perm4(T (&origin)[N], int n, int r);
template <typename T, size_t N>
void perm4Recur(T (&origin)[N], T (&select)[N], int n, int r, int data, int size, int* count);

// # Implements Definition ====================

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  const int N = 5;
  const int R = 3;

  int origin[N][3] = {{1, 11, 111}, {2, 22, 222}, {3, 33, 333}, {4}, {5}};
  // int origin[N][3] = {{1, 11, 111}, {2, 22, 222}, {3, 33, 333}};

  // ## 1. Mathematical Calculation =============
  {
    // nPr = n! / (n - r)!
    cout << "\n[CASES]: Don't know!\n";
    cout << "[ANSWER]: " << factorial(N) / factorial(N - R) << '\n';
  }

  // ## 4. Recursive & Bitwise Operator =========
  {
    cout << "\n[CASES]:\n";
    int count = perm4(origin, N, R);
    cout << "[ANSWER]: " << count << '\n';
  }

  return 0;
}

// ## 1. Mathematical Calculation =============
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

// ## 4. Recursive & Bitwise Operator =========
template <typename T, size_t N>
int perm4(T (&origin)[N], int n, int r) {
  int count = 0;
  T select[N] = {};
  perm4Recur(origin, select, n, r, 0, 0, &count);

  return count;
}

template <typename T, size_t N>
void perm4Recur(T (&origin)[N], T (&select)[N], int n, int r, int data, int size, int* count) {
  if (size == r) {
    printArr(select, r, NULL);
    (*count)++;
    return;
  }

  for (int i = 0; i < n; i++) {
    if ((data >> i) & 1) continue;
    copy((int*)origin[i], (int*)origin[i + 1], (int*)select[size]);
    perm4Recur(origin, select, n, r, data | (1 << i), size + 1, count);
  }

  return;
}
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

// ## 4. Recursive & Bitwise Operator =========
template <typename T, size_t N>
int perm4(T (&origin)[N], int n, int r);
template <typename T1, size_t N1, typename T2, size_t N2>
void perm4Recur(T1 (&origin)[N1], T2 (&select)[N2], int n, int r, int data, int size, int* count);

// # Implements Definition ====================

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  const int N = 3;
  const int R = 3;

  int origin[N][3] = {{1, 11, 111}, {2, 22, 222}, {3, 33, 333}};

  // ## 1. Mathematical Calculation =============
  {
    // nPr = n! / (n - r)!
    // cout << "\n[CASES]: Don't know!\n";
    // cout << "[ANSWER]: " << factorial(N) / factorial(N - R) << '\n';
  }

  // ## 4. Recursive & Bitwise Operator =========
  {
    // cout << "\n[CASES]:\n";
    // int count = perm4(origin, N, R);
    // cout << "[ANSWER]: " << count << '\n';
  }

  int r = 3;
  int arr1[r] = {1, 11, 111};
  // printArr(origin);

  for(const auto& a : arr1) {
    cout << a << '\n';
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

// ## 4. Recursive & Bitwise Operator =========

template <typename T, size_t N>
int perm4(T (&origin)[N], int n, int r) {
  int count = 0;
  T select[3] = {{1,2}};
  // perm4Recur(origin, select, n, r, 0, 0, &count);

  // printArr(select);
  printArr(origin);
  printArr(select);

  return count;
}

template <typename T1, size_t N1, typename T2, size_t N2>
void perm4Recur(T1 (&origin)[N1], T2 (&select)[N2], int n, int r, int data, int size, int* count) {
  if (size == r) {
    printArr(select);
    *count++;
    return;
  }

  for (int i = 0; i < n; i++) {
    if ((data >> i) & 1) continue;
    perm4Recur(origin, select, n, r, data | (i << i), size + 1);
  }

  return;
}
#include <array>
#include <deque>
#include <iostream>
#include <regex>

using namespace std;
// # Prototype Declaration ====================
int factorial(int x);
template <typename T, size_t N>
void print(T (&arr)[N]);
void printRecur(int* arr, std::deque<int> arrData);

// # Implements Definition ====================
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  const int N = 5;
  const int R = 2;

  int origin[N][3] = {{1, 11, 111}, {2, 22, 222}, {3, 33, 333}, {4, 44, 444}, {5, 55, 555}};

  /* 1. Mathematical Calculation ============ *
  {
    // nPr = n! / (n - r)!
    cout << "\n[CASES]: Don't know!\n";
    cout << "[ANSWER]: " << factorial(N) / factorial(N - R) << '\n';
  }
  /* ================== †† ================== */

  /* 2. For Loop ============================ */
  {
    // R 값 수정 불가 3개 뽑기
    int count = 0;
    int select[R][3] = {};

    for (int i = 0; i < N - 2; i++) {
      copy((int*)origin[i], (int*)origin[i + 1], (int*)select[0]);
      for (int j = 0; j < N - 1; j++) {
        for (int k = 0; k < N; k++) {
        }
      }
    }

    cout << "\n[CASES]:\n";
  }
  /* ================== †† ================== */

  {  // ## 2. Stack ================================
    int count = 0;
    int select[R][3] = {};
    deque<array<int, 3>> task = {{0, 0, -1}};

    cout << "\n[CASES]:\n";

    while (!task.empty()) {
      int data = task.back()[0];
      int size = task.back()[1];
      int prev = task.back()[2];
      task.pop_back();

      if (size != 0) {
        copy((int*)origin[prev], (int*)origin[prev + 1], (int*)select[size - 1]);
      }

      if (size == R) {
        print(select);
        count++;
        continue;
      }

      for (int n = N - 1; n >= 0; n--) {
        if (!(data & (1 << n))) {
          task.push_back({data | (1 << n), size + 1, n});
        }
      }
    }

    cout << "[ANSWER]: " << count << '\n';
  }

  {
    // ## 2. DFS With Stack =======================
    // ## 3. Swap =======================
  }

  return 0;
}

int factorial(int x) { return (x == 1) || (x == 0) ? 1 : x * factorial(x - 1); }

template <typename T, size_t N>
void print(T (&arr)[N]) {
  std::deque<int> arrData;
  std::string arrType = typeid(arr).name();
  std::regex regExp("A[0-9]+_", std::regex::optimize);

  std::sregex_token_iterator iter(arrType.begin(), arrType.end(), regExp), end;

  while (iter != end) {
    std::string token = (std::string)*iter++;
    arrData.push_back(std::stoi(token.substr(1, token.size() - 2)));
  }

  printRecur((int*)arr, arrData);
  std::cout << "\b\b  " << std::endl;
}

void printRecur(int* arr, std::deque<int> arrData) {
  if (arrData.size() == 0) std::cout << "\033[0m" << *arr << ", ";
  else {
    int N = arrData.front();
    arrData.pop_front();
    int gap = 1;
    int color = 31 + (arrData.size() % 6);
    for (int i : arrData) gap *= i;
    std::cout << "\033[" << color << "m[";

    for (int n = 0; n < N; n++) {
      printRecur(arr, arrData);
      arr += gap;
    }
    std::cout << "\033[" << color << "m\b\b]\033[0m, ";
  }
}
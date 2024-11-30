#include <array>
#include <deque>
#include <iostream>
#include <sstream>
#include <fstream>

#define SET_IO(INPUT_DATA) std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);std::ifstream fs(INPUT_DATA);std::stringstream ss(INPUT_DATA);if(fs.is_open())std::cin.rdbuf(fs.rdbuf());else std::cin.rdbuf(ss.rdbuf())

using namespace std;

// ## Global Variable & Constant =====

// ## Prototype Declaration ==========

int comb(int* origin, int N, int R);
void combRecur(int* origin, int* select, int* ptrCount, int N, int R, int size, int curr);

// ## Implements Definition ==========

int main() {
  SET_IO("5 2");

  int N;
  int R;
  int count;
  int *origin;

  cin >> N;
  cin >> R;
  count = 0;
  origin = new int[N];
  for (int n = 1; n <= N; n++) origin[n - 1] = n;

  cout << "[CASES]:\n";

  {
    // ### 4. Recursive Solution - DFS
    count = comb(origin, N, R);
  }

  delete[] origin;

  cout << "\n";
  cout << "[NUMBER]: " << count << "\n";

  return 0;
}

int comb(int* origin, int N, int R) {

}

void combRecur(int* origin, int* select, int* ptrCount, int N, int R, int size, int curr) {
  if (size == R) {
    (*ptrCount)++;
    for (int r = 0; r < R; r++) cout << select[r] << ' ';
    cout << '\n';
    return;
  }

  if (curr == N) return;

  for (int i = curr; i < N; i++) {
    select[size] = origin[i];
    combRecur(size + 1, i + 1);
  }
}
/**
 * Combination
 */
#include <deque>
#include <iostream>
#include <sstream>

#include "Test.hpp"
ArrayTool at;

using namespace std;
// Prototype Declaration ====================
int factorial(int x);

// Implements Definition ====================
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  const int N = 5;
  const int R = 2;

  int origin[N][2] = {{1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0}};
  int fixed[R][2] = {};

  // Just Count ======================================
  {
    // nPr = n! / (n - r)!
    cout << "\n[CASES]: Don't know!\n";
    cout << "[ANSWER]: " << factorial(N) / (factorial(N - R) * factorial(R)) << '\n';
  }

  // No Recursive ====================================
  {
    int count = 0;
    deque<pair<int, int>> task;  // select, length

    cout << "\n[CASES]:\n";

    task.push_back({0, 0});
    while (task.size() != 0) {
      int select = task.back().first;
      int length = task.back().second;
      task.pop_back();

      if (length >= R) {
        count++;
        at.print(fixed);
        continue;
      }

      if (select >= N) {
        continue;
      }

      task.push_back({select + 1, length});
      copy((int*)origin[select], (int*)origin[select] + 2, (int*)fixed[length]);
      task.push_back({select + 1, length + 1});
    }

    cout << "[ANSWER]: " << count << '\n';
  }
  return 0;
}

int factorial(int x) { return (x == 1) || (x == 0) ? 1 : x * factorial(x - 1); }

int combRecur() {
  return 0;
}

int comb() {
  return 0;
}
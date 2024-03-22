#include <array>
#include <iostream>
#include <deque>

#include "include/_TOOL_.hpp"

using namespace std;

// Implements Definition ====================
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  const int N = 5;
  const int R = 2;

  int origin[N][2] = {{1, 11}, {2, 22}, {3,33}, {4, 44}, {5, 55}};

  // Prototype Declaration ====================

  { // 1. Mathematical Calculation ==============
    // nPr = n! / (n - r)!
    PermTool pt; // perm tool for factorial
    cout << "\n[CASES]: Don't know!\n";
    cout << "[ANSWER]: " << pt.factorial(N) / pt.factorial(N - R) << '\n';
  }

  { // 2. DFS With Stack ========================
    ArrayTool at; // array tool for printing array

    int count = 0;
    int fixed[R][2] = {};
    deque<array<int, 3>> task = {{0, 0, -1}};

    cout << "\n[CASES]:\n";

    while(!task.empty()) {
      int data = task.back()[0];
      int size = task.back()[1];
      int prev = task.back()[2];
      task.pop_back();

      if(size != 0) {
        copy((int*)origin[prev], (int*)origin[prev + 1], (int*)fixed[size - 1]);
      }

      if(size == R) {
        at.print(fixed);
        count++;

        continue;
      }

      for(int n = N - 1; n >= 0; n--) {
        // task.push_back({data || (1 << n), size + 1, n});
        if(!(data & (1 << n))) {
          task.push_back({data | (1 << n), size + 1, n});
        }
      }
    }

    cout << "[ANSWER]: " << count << '\n';

  }

  {

  }
  
  return 0;
}
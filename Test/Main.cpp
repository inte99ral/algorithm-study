/**
 * 순열과 조합 테스트
 */
#include <deque>
#include <iostream>
#include <sstream>

#include "Test.hpp"

using namespace std;

int main() {
  // ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  const int N = 5;
  const int R = 2;

  int origin[N][2] = {{1, 6}, {2, 7}, {3, 8}, {4, 9}, {5, 0}};
  int fixed[R][2] = {};

  {
    ArrayTool at;
    at.print(origin);
  }

  // Input ====================================
  {
    // deque<pair<int, int>> task;  // select, length

    // task.push_back({0, 0});
    // while (task.size() != 0) {
    //   int select = task.back().first;
    //   int length = task.back().second;
    //   task.pop_back();

    //   if (length >= R) {
    //     at.print(fixed);
    //     continue;
    //   }

    //   if (select >= N) {
    //     continue;
    //   }

    //   task.push_back({select + 1, length});
    //   copy((int*)origin[select], (int*)origin[select] + 2, (int*)fixed[length]);
    //   task.push_back({select + 1, length + 1});
    // }

    // at.print(origin);
    // at.print(fixed);

    return 0;
  }
}
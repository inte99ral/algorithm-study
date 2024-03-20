/**
 * 순열 테스트
 */
#include <array>
#include <iostream>
#include <deque>

#include "Test.hpp"
ArrayTool at;

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  array<int, 3> arra = {1, 2, 3};

  for(int i : arra) {
    cout << i << " - ";
  }
  cout << endl;

  const int N = 5;
  const int R = 2;

  int origin[N][2] = {{1, 6}, {2, 7}, {3, 8}, {4, 9}, {5, 0}};
  int fixed[R][2] = {};

  at.print(origin);

  deque<pair<int, int>> task = {{0, 0}};

  // while(!task.empty()) {
  //   int data = task.back().first;
  //   int size = task.back().second;
  //   task.pop_back();

  //   // std::array<int, 3> arra = {1, 2, 3};

  //   if(size == R) {
  //     at.print(fixed);
  //   }

  //   for(int n = N; n >= 0; n--) {
  //     fi
  //   }
  // }

  return 0;
}
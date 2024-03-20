#include <iostream>

#include "Test.hpp"
ArrayTool at;

using namespace std;

int Main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  const int N = 5;
  const int R = 2;

  int origin[N][2] = {{1, 6}, {2, 7}, {3, 8}, {4, 9}, {5, 0}};
  int fixed[R][2] = {};

  at.print(origin);

  return 0;
}
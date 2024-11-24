#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#define SET_IO(INPUT_PATH) std::ios_base::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);freopen(INPUT_PATH, "rt", stdin)
#else
#define SET_IO(INPUT_PATH) std::ios_base::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr)
#endif

using namespace std;

int main() {
  SET_IO("_INPUT_.txt");

  int N, M;
  cin >> N >> M;

  int *origin;
  int *select;
  bool *selected;
  int originIndex;
  int selectIndex;

  origin = new int[N];
  for (int n = 1; n <= N; n++) origin[n] = n;
  select = new int[N]();
  selected = new bool[N]();

  while (selectIndex < M)


  delete origin;
  delete select;
  delete selected;
  return 0;
}
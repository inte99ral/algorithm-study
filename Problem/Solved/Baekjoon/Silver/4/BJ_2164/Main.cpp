#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#define SET_IO(INPUT_PATH) ios_base::sync_with_stdio(false);cout.tie(nullptr);cin.tie(nullptr);freopen(INPUT_PATH, "rt", stdin)
#else
#define SET_IO(INPUT_PATH) ios_base::sync_with_stdio(false);cout.tie(nullptr);cin.tie(nullptr)
#endif

using namespace std;

int main() {
  SET_IO("_INPUT_.txt");

  int N;
  int exp;
  cin >> N;
  exp = 1;
  while (exp << 1 < N) exp <<= 1;
  cout << (N == 1 ? 1 : (N - exp) * 2);

  return 0;
}
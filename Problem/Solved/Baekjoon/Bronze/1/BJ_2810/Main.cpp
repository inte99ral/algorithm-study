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
  string seat;
  int holder;

  cin >> N;
  cin >> seat;
  holder = N + 1;

  for (int n = 0; n < N; n++) {
    if (seat[n] == 'S') continue;
    holder--;
    n++;
  }
  
  cout << min(holder, N);
  return 0;
}
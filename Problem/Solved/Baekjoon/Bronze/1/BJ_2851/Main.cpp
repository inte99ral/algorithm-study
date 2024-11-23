#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#define SET_IO(INPUT_PATH) ios_base::sync_with_stdio(false);cout.tie(nullptr);cin.tie(nullptr);freopen(INPUT_PATH, "rt", stdin)
#else
#define SET_IO(INPUT_PATH) ios_base::sync_with_stdio(false);cout.tie(nullptr);cin.tie(nullptr)
#endif

using namespace std;

int main() {
  SET_IO("_INPUT_.txt");

  int answer = 0;

  for (int i = 0; i < 10; i++) {
    int temp; cin >> temp;

    if (100 - answer >= answer + temp - 100) answer += temp;
    else break;
  }

  cout << answer;

  return 0;
}
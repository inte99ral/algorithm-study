#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N = 2;
  int R = 3;
  int size = 0;
  int data[R] = {};

  while (data[0] != N) {
    if (size == R) {
      for (int r = 0; r < R; r++) {
        cout << data[r] << ", ";
      }
      cout << "\b\b \n";

      size--;
      data[size]++;
      continue;
    }

    // * 커서 후퇴
    if (data[size] == N) {
      data[size] = 0;
      size--;
      data[size]++;
    }
    // * 커서 전진
    else {
      size++;
    }
  }

  return 0;
}
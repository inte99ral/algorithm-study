#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#define SET_IO(INPUT_DATA) std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);std::ifstream fs(INPUT_DATA);std::cin.rdbuf(fs.is_open()?((std::istream*)&fs)->rdbuf():((std::istream*)new std::stringstream(INPUT_DATA))->rdbuf())
#else
#define SET_IO(INPUT_PATH) std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr)
#endif

using namespace std;


void combRecur(int N, int R, int data, int index, int size) {
  if (size == R) {
    for (int n = 0; n < N; n++) {
      if (data & (1 << n)) {
        cout << n + 1 << " ";
      }
    }
    cout << "\n";
    return;
  }

  if (index == N) {
    return;
  }

  combRecur(N, R, data | (1 << index), index + 1, size + 1);
  combRecur(N, R, data, index + 1, size);
}

void comb(int N, int R) {
  combRecur(N, R, 0, 0, 0);
}

int main() {
  SET_IO("_INPUT_.txt");

  int N;
  int R;

  cin >> N;
  cin >> R;

  comb(N, R);

  return 0;
}


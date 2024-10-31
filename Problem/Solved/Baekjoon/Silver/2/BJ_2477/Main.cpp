#include <iostream>

using namespace std;

int main() {
  freopen("Problem\\Solved\\Baekjoon\\Silver\\2\\BJ_2477\\.input.txt", "rt", stdin);

  int K;
  int dirc[6] = {};
  int len[6] = {};

  cin >> K;

  for (int i = 0; i < 6; i++) cin >> dirc[i] >> len[i];

  for (int i = 0; i < 6; i++) {
    int i1 = i;
    int i2 = (i + 1) % 6;
    int i3 = (i + 2) % 6;
    int i4 = (i + 3) % 6;
    int i5 = (i + 4) % 6;
    int i6 = (i + 5) % 6;

    if ((dirc[i1] == dirc[i3]) && (dirc[i2] == dirc[i4])) {
      cout << K * ((len[i5] * len[i6]) - (len[i2]) * (len[i3]));
      break;
    }
  }

  return 0;
}
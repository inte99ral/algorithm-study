#include <bits/stdc++.h>

using namespace std;

int main() {

  freopen("Problem\\Solved\\Baekjoon\\Silver\\1\\BJ_2527\\_input.txt", "rt", stdin);

  for (int i = 0; i < 4; i++) {
    int x1, y1, p1, q1, x2, y2, p2, q2;
    cin >> x1 >> y1 >> p1 >> q1 >> x2 >> y2 >> p2 >> q2;

    int xState = 2, yState = 2; // 0 Out, 1 Border, 2 In

    if (p2 < x1 || p1 < x2) xState = 0;
    else if (p2 == x1 || p1 == x2) xState = 1;

    if (q2 < y1 || q1 < y2) yState = 0;
    else if (q2 == y1 || q1 == y2) yState = 1;

    if (xState == 0 || yState == 0) cout << "d\n";
    else if (xState == 1 && yState == 1) cout << "c\n";
    else if (xState == 1 || yState == 1) cout << "b\n";
    else cout << "a\n";
  }
  return 0;
}
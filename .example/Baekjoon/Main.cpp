#include <bits/stdc++.h>

using namespace std;
// # Prototype Declaration ==================================================

// # Global Variable & Constant =============================================

// # Implements Definition ==================================================

// ## Main
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  #ifndef ONLINE_JUDGE
  freopen(".example\\Baekjoon\\question\\input.txt", "rt", stdin);  // * 로컬 input.txt 입력 코드
  #endif

  string input;

  // -- String line
  // getline(cin, input);
  // cout << input << '\n';

  // -- Int Array
  for (int i = 0; i < 6; i++) {
    cin >> input;
    cout << input << '\n';
  }

  return 0;
}
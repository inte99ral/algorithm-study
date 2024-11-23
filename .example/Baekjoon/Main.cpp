// # <DIRECTORY_PATH>

/**
 * 추가 서술
 *
 * @see "https://www.google.co.kr/"
 * @author inte99ral
 * @version 2024-11-18
 */

// ## API & Library ==========================================================

#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#define SET_IO(INPUT_PATH) std::ios_base::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);freopen(INPUT_PATH, "rt", stdin)
#else
#define SET_IO(INPUT_PATH) std::ios_base::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr)
#endif

using namespace std;

// ## Prototype Declaration ==================================================

// ## Global Variable & Constant =============================================

// ## Implements Definition ==================================================

// ### Main
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  #ifndef ONLINE_JUDGE
  freopen("__INPUT__.txt", "rt", stdin);  // * 로컬 input.txt 입력 코드
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
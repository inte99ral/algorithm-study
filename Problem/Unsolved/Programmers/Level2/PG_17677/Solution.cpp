#include <bits/stdc++.h>

using namespace std;

// # Prototype Declaration ====================
int solution(string str1, string str2);

// # Global Variable & Constant================

// # Implements Definition ====================
// ## Main
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  string rawInput;
  string str1;
  string str2;

  // * Input
  {
    freopen("Problem/Unsolved/Programmers/Level2/PG_17677/question/input.txt", "rt", stdin);

    getline(cin, str1);
    getline(cin, str2);
  }


  cout << solution(str1, str2);

  return 0;
}

int solution(string str1, string str2) {
  int answer = 0;

  cout << str1 << " - " << str2 << "\n";

  return answer;
}
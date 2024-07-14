#include <bits/stdc++.h>

using namespace std;

// # Prototype Declaration ====================
int solution(vector<vector<string>> clothes);

// # Global Variable & Constant================

// # Implements Definition ====================
// ## Main
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  vector<vector<string>> clothes;

  {
    string rawInput;
    string buffer;
    regex regExp("[0-9A-Za-z_]+");

    freopen("Problem/Unsolved/Programmers/Level2/PG_42578/question/input.txt", "rt", stdin);
    getline(cin, rawInput);

    sregex_token_iterator iter;
    sregex_token_iterator end;

    iter = sregex_token_iterator(rawInput.begin(), rawInput.end(), regExp);

    while(iter != end) {
      clothes.push_back({*iter++, *iter++});
    }
  }

  cout << solution(clothes) << "\n";

  return 0;
}

int solution(vector<vector<string>> clothes) {
  int answer = 1;
  unordered_map<string, int> cMap;

  for (const auto& c : clothes) cMap[c[1]]++;
  for (const auto& c : cMap) answer *= c.second + 1;

  return answer - 1;
}
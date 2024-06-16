#include <bits/stdc++.h>

using namespace std;

// # Prototype Declaration ====================
string solution(vector<string> participant, vector<string> completion);
// # Global Variable & Constant================

// # Implements Definition ====================
// ## Main
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  vector<string> input[2]{};

  {
    string rawInput;
    string buffer;
    regex regExp("[a-zA-Z0-9]+");

    freopen("Problem/Solved/Programmers/Level_1/PG_42576/question/input.txt", "rt", stdin);
    
    for (int i = 0; i < 2; i++) {
      getline(cin, rawInput);

      sregex_token_iterator iter(
        rawInput.begin(),
        rawInput.end(),
        regExp
      ), end;

      while(iter != end) {
        input[i].push_back(*iter++);
      }
    }
  }

  cout << solution(input[0], input[1]) << '\n';
  return 0;
}

// ## Solution
string solution(vector<string> participant, vector<string> completion) {
  map<string, int> pMap;
  
  for (string s : participant) {
    if (pMap.find(s) == pMap.end()) pMap[s] = 0;
    else pMap[s]++;
  }
  
  for (string s : completion) {
    if (pMap[s] == 0) pMap.erase(s);
    else pMap[s]--;
  }
  
  return pMap.begin()->first;;
}



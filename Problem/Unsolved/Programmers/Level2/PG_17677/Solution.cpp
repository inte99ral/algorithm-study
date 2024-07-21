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

  unordered_map<string, int> jMap1;
  unordered_map<string, int> jMap2;

  set<string> jSet1;
  set<string> jSet2;

  for (int i = 1; i < (int) str1.size(); i++) {
    string temp;

    if (str1.at(i - 1) < 'A') continue;
    else if (str1.at(i - 1) <= 'Z') temp.push_back(str1.at(i - 1));
    else if (str1.at(i - 1) < 'a') continue;
    else if (str1.at(i - 1) <= 'z') temp.push_back(str1.at(i - 1) - 32);
    else continue;

    if (str1.at(i) < 'A') continue;
    else if (str1.at(i) <= 'Z') temp.push_back(str1.at(i));
    else if (str1.at(i) < 'a') continue;
    else if (str1.at(i) <= 'z') temp.push_back(str1.at(i) - 32);
    else continue;

    jSet1.insert(temp);

    cout << temp << "\n";
  }

  return answer;
}
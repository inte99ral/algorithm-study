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
  unordered_map<string, int> jMap;

  double interCount = 0;
  double unionCount = 0;

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

    jMap[temp]++;
    unionCount++;
  }

  for (int i = 1; i < (int) str2.size(); i++) {
    string temp;

    if (str2.at(i - 1) < 'A') continue;
    else if (str2.at(i - 1) <= 'Z') temp.push_back(str2.at(i - 1));
    else if (str2.at(i - 1) < 'a') continue;
    else if (str2.at(i - 1) <= 'z') temp.push_back(str2.at(i - 1) - 32);
    else continue;

    if (str2.at(i) < 'A') continue;
    else if (str2.at(i) <= 'Z') temp.push_back(str2.at(i));
    else if (str2.at(i) < 'a') continue;
    else if (str2.at(i) <= 'z') temp.push_back(str2.at(i) - 32);
    else continue;

    unionCount++;

    if(jMap[temp] > 0) {
      jMap[temp]--;
      unionCount--;
      interCount++;
    }
  }

  if (unionCount == 0) return 65536;

  return (interCount / unionCount) * 65536;
}
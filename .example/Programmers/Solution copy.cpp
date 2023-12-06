/**
 * 2차원 배열 
 */

// #include <bits/stdc++.h>
#include <iostream>
#include <map>
#include <sstream>
#include <vector>
#include <regex>

#include <typeinfo>

using namespace std;

// -- Header ====================
int solution(vector<vector<int>> nums);

// -- Local Input ====================
int main() {
  freopen("Problem\\Failed\\Programmers\\L2\\PG_181188\\input.txt", "rt", stdin);
  string rawInput;
  vector<vector<int>> input;
  string buffer;

  getline(cin, rawInput);
  regex regExp("[0-9]+");

  sregex_token_iterator iter(
    rawInput.begin(),
    rawInput.end(),
    regExp
  );
  sregex_token_iterator end;

  while (iter != end) {
    vector<int> tempVec = {stoi(*iter++), stoi(*iter++)};
    input.push_back(tempVec);
  }

  cout << solution(input) << '\n';
  return 0;
}

// -- Solution ====================
int solution(vector<vector<int>> targets) {
    int answer = 123456789;

    for(vector<int> iVec : targets) {
      cout << "[";
      for(int i : iVec) {
        cout << i << ",";
      }
      cout << "]" << '\n';
    }

    return answer;
}
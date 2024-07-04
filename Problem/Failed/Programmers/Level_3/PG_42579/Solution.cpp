#include <bits/stdc++.h>

using namespace std;

// # Prototype Declaration ====================
vector<int> solution(vector<string> genres, vector<int> plays);

// # Global Variable & Constant================

// # Implements Definition ====================
// ## Main
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  vector<string> genres;
  vector<int> plays;
  vector<int> output;

  {
    string rawInput;
    string buffer;
    regex regExp("[0-9a-zA-Z]+");

    freopen("Problem/Failed/Programmers/Level_3/PG_42579/question/input.txt", "rt", stdin);
    
    getline(cin, rawInput);

    sregex_token_iterator iter;
    sregex_token_iterator end;

    iter = sregex_token_iterator(
      rawInput.begin(),
      rawInput.end(),
      regExp
    );

    while(iter != end) {
      genres.push_back(*iter++);
    }

    getline(cin, rawInput);

    iter = sregex_token_iterator(
      rawInput.begin(),
      rawInput.end(),
      regExp
    );

    while(iter != end) {
      plays.push_back(stoi(*iter++));
    }
  }

  
  solution(genres, plays);

  return 0;
}

// ## Solution
vector<int> solution(vector<string> genres, vector<int> plays) {
  vector<int> answer;

  map<string, array<int, 2>> gMap;

  int N = genres.size();

  for (int n = 0; n < N; n++) {
    if(gMap.count(genres[n])) gMap[genres[n]] = {};

    gMap[genres[n]][0] += plays[n];

    if(gMap[genres[n]][1] < plays[n]) gMap[genres[n]][1] = n;
  }

  return answer;
}
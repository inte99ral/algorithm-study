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

  vector<int> answer = solution(genres, plays);
  
  // * TEST_00
  {
    cout << "[";
    for (const auto& i : answer) {
      cout << i << ", ";
    }
    cout << "\b\b]\n";
  }

  return 0;
}

// ## Solution
vector<int> solution(vector<string> genres, vector<int> plays) {
  vector<int> answer;

  map<string, array<int, 3>> gMap;
  priority_queue<array<int, 3>, vector<array<int, 3>>, function<bool(array<int, 3>, array<int, 3>)>> gPque([]( array<int, 3> o1, array<int, 3> o2 ) -> bool {return o1 < o2;});

  int N = genres.size();

  for (int n = 0; n < N; n++) {
    if(!gMap.count(genres[n])) gMap[genres[n]] = {0, -1, -1};

    gMap[genres[n]][0] += plays[n];

    if (gMap[genres[n]][1] == -1) {
      gMap[genres[n]][1] = n;
      continue;
    }

    if (plays[gMap[genres[n]][1]] < plays[n]) {
      gMap[genres[n]][2] = gMap[genres[n]][1];
      gMap[genres[n]][1] = n;
      continue;
    }

    if (gMap[genres[n]][2] == -1) {
      gMap[genres[n]][2] = n;
      continue;
    }
    
    if (plays[gMap[genres[n]][2]] < plays[n]) {
      gMap[genres[n]][2] = n;
      continue;
    }
  }

  for (const auto &gData : gMap) {
    gPque.push(gData.second);
  }

  while (!gPque.empty()) {
    answer.push_back(gPque.top()[1]); 
    if (gPque.top()[2] != -1) answer.push_back(gPque.top()[2]);
    
    gPque.pop();
  }

  return answer;
}
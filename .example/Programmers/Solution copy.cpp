/**
 * 2차원 배열 
 */
#include <bits/stdc++.h>

using namespace std;

// -- Header =========================
int solution(vector<vector<int>> targets);

// -- Local Input ====================
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  freopen("Problem\\Solved\\Programmers\\Level2\\PG_181188\\input.txt", "rt", stdin);

  string rawInput;
  vector<vector<int>> input;

  regex regExp("[0-9]+");
  string buffer;

  getline(cin, rawInput);

  sregex_token_iterator iter(
    rawInput.begin(),
    rawInput.end(),
    regExp
  ), end;

  while(iter != end) {
    vector<int> tempVec = {stoi(*iter++), stoi(*iter++)};
    input.push_back(tempVec);
  }

  cout << solution(input) << '\n';
  return 0;
}

// -- Solution =======================
int solution(vector<vector<int>> targets) {

  for(vector<int> target : targets) {
    cout << target[0] << ", " << target[1] << "\n";
  }
  return 0;
}


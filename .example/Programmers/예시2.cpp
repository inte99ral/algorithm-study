#include <bits/stdc++.h>

using namespace std;

// # Prototype Declaration ==============================
int solution(vector<vector<int>> targets);

// # Global Variable & Constant==========================

// # Implements Definition ==============================
// ## Main
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  vector<vector<int>> input;

  // * Input
  {
    string rawInput;
    regex regExp("[0-9A-Za-z_]+");
    //[A-Za-z0-9가-힣]+ or [\uAC00-\uD7A3]

    freopen(".example\\Programmers\\question\\input.txt", "rt", stdin);
    getline(cin, rawInput);

    sregex_token_iterator iter;
    sregex_token_iterator end;

    iter = sregex_token_iterator(
      rawInput.begin(),
      rawInput.end(),
      regExp
    );

    while(iter != end) {
      vector<int> tempVec = {stoi(*iter++), stoi(*iter++)};
      input.push_back(tempVec);
    }
  }

  cout << solution(input) << '\n';

  // * TEST_00
  {
    // cout << "[";
    // for (const auto& i : answer) {
    //   cout << i << ", ";
    // }
    // cout << "\b\b]\n";
  }

  return 0;
}

// ## Solution
int solution(vector<vector<int>> targets) {
  int answer = -1;

  for(vector<int> target : targets) {
    cout << "[" << target[0] << ", " << target[1] << "]\n";
  }

  return answer;
}
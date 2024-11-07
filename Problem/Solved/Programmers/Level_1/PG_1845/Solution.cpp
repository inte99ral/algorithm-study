#include <bits/stdc++.h>

using namespace std;

// # Prototype Declaration ==================================================

int solution(vector<int> nums);

// # Global Variable & Constant =============================================

// # Implements Definition ==================================================

// ## Main
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  vector<int> input;

  // * Input
  {
    freopen("Problem\\Solved\\Programmers\\Level_1\\PG_1845\\.input.txt", "rt", stdin);

      string rawInput;
      regex regExp("[0-9]+");
      sregex_token_iterator iter;
      sregex_token_iterator end;

      getline(cin, rawInput);
      iter = sregex_token_iterator(rawInput.begin(), rawInput.end(), regExp);

      while (iter != end) input.push_back(stoi(*iter++));
  }

  // * Output
  {
    int answer = solution(input);
    cout << "[OUTPUT] : " << answer << "\n";
  }

  return 0;
}


// ## Solution
#include <vector>
#include <unordered_set>

using namespace std;

int solution(vector<int> nums) {
  unordered_set<int> s(nums.begin(), nums.end());
  return min(nums.size() / 2, s.size());
}
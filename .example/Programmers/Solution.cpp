#include <bits/stdc++.h>

using namespace std;

// -- Header =========================
int solution(vector<vector<int>> targets);

// -- Local Input ====================
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  vector<vector<int>> input;

  {
    string rawInput;
    string buffer;
    regex regExp("[0-9]+");


    freopen(".example\\Programmers\\question\\input.txt", "rt", stdin);
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
  }

  cout << "[answer]: " + to_string(solution(input)) << '\n';
  return 0;
}

// -- Solution =======================
/**
 * 2차원 배열 데이터 전용
 */
int solution(vector<vector<int>> targets) {
  int answer = 0;

  for(vector<int> target : targets) {
    cout << "[" << target[0] << ", " << target[1] << "]" << "\n";
  }

  return answer;
}


#include <bits/stdc++.h>

using namespace std;

// # Prototype Declaration ==============================
int solution(vector<string> lines);

// # Global Variable & Constant =========================

// # Implements Definition ==============================
// ## Main
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  vector<string> lines; // Sentences between double quotation marks

  // * Input
  {
    freopen("Problem/Solved/Programmers/Level_3/PG_17676/question/input.txt", "rt", stdin);

    string rawInput;
    regex regExp("\\\"[^\\[\\\"\\,\\]]+"); // Sentences between double quotation marks
    sregex_token_iterator iter;
    sregex_token_iterator end;

    getline(cin, rawInput);
    iter = sregex_token_iterator(rawInput.begin(), rawInput.end(), regExp);

    while (iter != end) lines.push_back(((string) *iter++).substr(1));
  }

  // * Output
  {
    int answer = solution(lines);
    cout << "[OUTPUT] : " << answer << "\n";
  }

  return 0;
}

// ## Solution
#include <algorithm>
#include <map>
#include <regex>
#include <string>
#include <vector>

using namespace std;

int solution(vector<string> lines) {
  int answer = 1;
  vector<pair<int, int>> reqVec;

  for (const string& line : lines) {
    int request_end;
    int request_srt;

    request_end = (((stoi(line.substr(11, 2)) * 60) + stoi(line.substr(14, 2))) * 60 + stoi(line.substr(17, 2))) * 1000 + stoi(line.substr(20, 3));
    request_srt = request_end + 1;

    request_srt -= stoi(line.substr(24, 1)) * 1000;

    if (line[25] == '.') {
      int cursor = 26;
      while (line[cursor] <= '9') cursor++;
      request_srt -= stoi(line.substr(26, cursor - 26));
    }

    reqVec.push_back({request_end, request_srt});
  }

  const int SIZE = reqVec.size();
  for (int i = 0; i < SIZE; i++) {

    int count_end = 0;
    int count_srt = 0;

    for (int j = 0; j < SIZE; j++) {
      if ((reqVec[i].first - 1000 < reqVec[j].first) && (reqVec[j].second <= reqVec[i].first)) count_end++;
      if ((reqVec[i].second - 1000 < reqVec[j].first) && (reqVec[j].second <= reqVec[i].second)) count_srt++;
    }

    if (answer < count_end) answer = count_end;
    if (answer < count_srt) answer = count_srt;
  }

  return answer;
}
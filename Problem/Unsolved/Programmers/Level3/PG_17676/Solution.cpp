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
    freopen("Problem/Unsolved/Programmers/Level3/PG_17676/question/input.txt", "rt", stdin);

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
#include <map>
#include <regex>
#include <string>
#include <vector>

using namespace std;

int solution_1(vector<string> lines) {
  int answer = 0;

  map<int, int> req;

  for (const string& line : lines) {
    regex regExp("[0-9]+");
    sregex_token_iterator iter, end;

    iter = sregex_token_iterator(line.begin(), line.end(), regExp);
    iter++;
    iter++;
    iter++;

    int h = stoi(*iter++) * 1000 * 60 * 60;
    int m = stoi(*iter++) * 1000 * 60;
    int s = stoi(*iter++) * 1000;
    s += stoi(*iter++);
    int t = stoi(*iter++) * 1000;
    if (iter != end) t += stoi(*iter++);

    req[h + m + s - t + 1] = h + m + s;
  }

  for (const auto& target : req) {
    int count;
    
    count = 0;
    for (const auto& range : req) {
      // * TEST_01
      {
        // cout << "T.F: " << target.first << "\n";
        // cout << "T.S: " << target.second << "\n";
        // cout << "R.F: " << range.first << "\n";
        // cout << "R.S: " << range.second << "\n\n";
      }

      if ((target.first + 1000 <= range.first) || (range.second < target.first)) continue;
      count++;
    }
    if (answer < count) answer = count;

    count = 0;
    for (const auto& range : req) {

      // * TEST_02
      {
        // cout << "T.F: " << target.first << "\n";
        // cout << "T.S: " << target.second << "\n";
        // cout << "R.F: " << range.first << "\n";
        // cout << "R.S: " << range.second << "\n\n";
      }

      if ((target.second + 1000 <= range.first) || (range.second < target.second)) continue;
      count++;
    }
    
    if (answer < count) answer = count;
  }

  return answer;
}

int solution(vector<string> lines) {
  int answer = 0;
  deque<pair<int, int>> reqDq;

  for (const string& line : lines) {

    int end_time = ((stoi(line.substr(11, 2)) * 60 + stoi(line.substr(14, 2))) * 60 + stoi(line.substr(17, 2))) * 1000;

    int h = stoi(line.substr(11, 2)) * 60 * 60 * 1000;
    int m = stoi(line.substr(14, 2)) * 60 * 1000;
    int s = stoi(line.substr(17, 2)) * 1000;

    int t = stoi(line.substr(24, 1)) * 1000;

    if (line[25] == '.') {
      int cursor = 26;
      while (line[cursor] <= '9') cursor++;
      t += stoi(line.substr(26, cursor - 26));
    }

    cout << "\n";
  }

  // for (const auto& target : reqDq) {
  //   int count;
    
  //   count = 0;
  //   for (const auto& range : reqDq) {
  //     // * TEST_01
  //     {
  //       // cout << "T.F: " << target.first << "\n";
  //       // cout << "T.S: " << target.second << "\n";
  //       // cout << "R.F: " << range.first << "\n";
  //       // cout << "R.S: " << range.second << "\n\n";
  //     }

  //     if ((target.first + 1000 <= range.first) || (range.second < target.first)) continue;
  //     count++;
  //   }
  //   if (answer < count) answer = count;

  //   count = 0;
  //   for (const auto& range : reqDq) {

  //     // * TEST_02
  //     {
  //       // cout << "T.F: " << target.first << "\n";
  //       // cout << "T.S: " << target.second << "\n";
  //       // cout << "R.F: " << range.first << "\n";
  //       // cout << "R.S: " << range.second << "\n\n";
  //     }

  //     if ((target.second + 1000 <= range.first) || (range.second < target.second)) continue;
  //     count++;
  //   }
    
  //   if (answer < count) answer = count;
  // }

  return answer;
}
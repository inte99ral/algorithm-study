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

int solution(vector<string> lines) {
  int answer = 0;

  map<int, int> req;

  for (const string& line : lines) {
    regex regExp("[0-9\\.]+");
    sregex_token_iterator iter, end;

    iter = sregex_token_iterator(line.begin(), line.end(), regExp);
    iter++;
    iter++;
    iter++;

    int h = stoi(*iter++) * 1000 * 60 * 60;
    int m = stoi(*iter++) * 1000 * 60;
    int s = stof(*iter++) * 1000;
    int t = stof(*iter++) * 1000;

    // * TEST_01
    {
      cout << "s: " << s << "\n";
      cout << "t: " << t << "\n\n";
    }

    req[h + m + s - t + 1] = h + m + s;
  }

  // * TEST_00
  {
    for (const auto& target : req) {
      cout << "t.f: " << target.first << "\n";
      cout << "t.s: " << target.second << "\n\n";
    }
  }

  // for (const auto& target : req) {
  //   int count;
    
  //   count = 0;
  //   for (const auto& range : req) {
  //     if ((range.first < target.first + 1000) && (target.first <= range.second)) {
  //       count++;
  //     }
  //   }
  //   if (answer < count) answer = count;

  //   count = 0;
  //   for (const auto& range : req) {
  //     cout << "t.s: " << target.second << "\n";
  //     cout << "r.f: " << range.first << "\n";
  //     cout << "r.s: " << range.second << "\n\n";
  //     if ((range.first < target.second + 1000) && (target.second <= range.second)) {
  //       count++;
  //     }
  //   }
    
  //   if (answer < count) answer = count;
  // }

  return answer;
}
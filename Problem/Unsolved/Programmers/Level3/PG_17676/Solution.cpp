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
  int answer = 1;
  vector<pair<int, int>> reqVec;
  deque<pair<int, int>> reqDq;

  for (const string& line : lines) {
    int end_time = (((stoi(line.substr(11, 2)) * 60 + stoi(line.substr(14, 2))) * 60 + stoi(line.substr(17, 2))) * 1000) + stoi(line.substr(20, 3));
    int start_time = end_time + 1;
    
    start_time -= stoi(line.substr(24, 1)) * 1000;
    if (line[25] == '.') {
      int cursor = 26;
      while (line[cursor] <= '9') cursor++;
      start_time -= stoi(line.substr(26, cursor - 26));
    }

    reqDq.push_front({end_time, start_time});
  }

  reqVec = vector<pair<int, int>> {reqDq.begin(), reqDq.end()};

  // * TEST_00
  {
    for (const auto& a : reqVec) {
      cout << a.first << " - " << a.second << "\n";
    }
    cout << "\n";
  }

  const int N = reqVec.size();

  for (int i = 0; i < N; i++) {

    
    // * TEST_01
    {
      cout << reqVec[i].first << " to " << reqVec[i].second << "\n";
    }

    int endCount = 1;
    int startCount = 1;
    for (int j = i + 1; j < N; j++) {
      // 뒷 시간대가 겹치는가?
      if (reqVec[j].first > reqVec[i].first - 1000) {


        endCount++;

        // * TEST_02
        {
          cout << "E" << endCount << ": " << reqVec[i].first << " <- [" << reqVec[j].first << " " << reqVec[j].second << "] <- " << reqVec[i].first - 1000 << "\n";
        }
      }


      // 앞 시간대가 겹치는가?
      if ((reqVec[i].second >= reqVec[j].second) || (reqVec[j].first > reqVec[i].second - 1000)) {

        startCount++;

        // * TEST_03
        {
          cout << "S" << startCount << ": " << reqVec[i].second << " <- [" << reqVec[j].first << " " << reqVec[j].second << "] <- " << reqVec[i].second - 1000 << "\n";
        }
      }
    }

    // * TEST_
    {
      // cout << reqVec[i].first << " : " << endCount << "\n";
      // cout << reqVec[i].second << " : " << startCount << "\n";
      // cout << "\n";
    }

    if (answer < endCount) answer = endCount;
    if (answer < startCount) answer = startCount;
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
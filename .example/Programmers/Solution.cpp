#include <bits/stdc++.h>

using namespace std;

// # Prototype Declaration ==============================
int solution(int input1, vector<string> input2, vector<string> input3, vector<pair<int, int>> input4);

// # Global Variable & Constant =========================

// # Implements Definition ==============================
// ## Main
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int input1; // Number
  vector<string> input2; // Korean Words
  vector<string> input3; // Sentences between double quotation marks
  vector<pair<int, int>> input4; // Multi-Dimensional Array

  // * Input
  {
    freopen(".example\\Programmers\\question\\input.txt", "rt", stdin);

    // * Input 1: Number
    {
      cin >> input1;
      cin.ignore(); // input buffer "\n" release
    }

    // * Input 2: Korean Words
    {
      string rawInput2;
      regex regExp2("[0-9A-Za-z가-힣\\s]+"); // Korean Words
      sregex_token_iterator iter;
      sregex_token_iterator end;

      getline(cin, rawInput2);
      iter = sregex_token_iterator(rawInput2.begin(), rawInput2.end(), regExp2);

      while (iter != end) input2.push_back(*iter++);
    }

    // * Input 3: Sentences between double quotation marks
    {
      string rawInput3;
      regex regExp3("\\\"[^\\[\\\"\\,\\]]+"); // Sentences between double quotation marks
      sregex_token_iterator iter;
      sregex_token_iterator end;

      getline(cin, rawInput3);
      iter = sregex_token_iterator(rawInput3.begin(), rawInput3.end(), regExp3);

      while (iter != end) input3.push_back(((string) *iter++).substr(1));
    }

    // * Input 4: Multi-Dimensional Array
    {
      string rawInput4;
      regex regExp4("[0-9]+"); // Numbers
      sregex_token_iterator iter;
      sregex_token_iterator end;

      getline(cin, rawInput4);
      iter = sregex_token_iterator(rawInput4.begin(), rawInput4.end(), regExp4);

      while (iter != end) {
        input4.push_back({stoi(*iter++), stoi(*iter++)});
      }
    }
  }

  // * Output
  {
    int answer = solution(input1, input2, input3, input4);
    cout << "[OUTPUT] : " << answer << "\n";
  }

  return 0;
}

// ## Solution
#include <iostream>
#include <vector>

using namespace std;

int solution(int input1, vector<string> input2, vector<string> input3, vector<pair<int, int>> input4) {
  int answer = 99;

  cout << "[INPUT 1]: " << input1 << endl;

  cout << "[INPUT 2]: ";
  for (string s : input2) {
    cout << s << ", ";
  }
  cout << "\b\b " << endl;

  cout << "[INPUT 3]: ";
  for (string s : input3) {
    cout << s << ", ";
  }
  cout << "\b\b " << endl;

  cout << "[INPUT 4]: [";
  for (const auto& p : input4) {
    cout << "[" << p.first << ", " << p.second << "], ";
  }
  cout << "\b\b]" << endl;

  return answer;
}
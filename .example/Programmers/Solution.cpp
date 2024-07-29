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
      regex regExp2("[A-Za-z]+"); // Korean Words
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

    // * Input 3: Numbers
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
    int answer = solution(input1, input2);
    cout << "[output] : " << answer << "\n";
  }

  return 0;
}

// ## Solution
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
  int answer = 0;

  vector<string> cache;

  for (string& city : cities) {
    transform(city.begin(), city.end(), city.begin(), ::toupper);
    answer += 5;
    for (int i = 0; i < (int) cache.size(); i++) {
      if (cache[i] == city) {
        cache.erase(cache.begin() + i);
        answer -= 4;
        break;
      }
    }

    cache.push_back(city);
    
    if ((int) cache.size() > cacheSize) cache.erase(cache.begin());
  }

  return answer;
}
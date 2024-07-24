#include <bits/stdc++.h>

using namespace std;

// # Prototype Declaration ==============================
int solution(int cacheSize, vector<string> cities);

// # Global Variable & Constant =========================

// # Implements Definition ==============================
// ## Main
int main() {
  int cacheSize;
  vector<string> cities;

  // * Input
  {
    string rawInput;
    regex regExp("\\\"[^\\[\\\"\\,\\]]+");

    freopen("Problem/Unsolved/Programmers/Level2/PG_17680/question/input.txt", "rt", stdin);
    
    cin >> cacheSize;
    cin.ignore();

    getline(cin, rawInput);

    sregex_token_iterator iter;
    sregex_token_iterator end;
    iter = sregex_token_iterator(rawInput.begin(), rawInput.end(), regExp);

    while (iter != end) cities.push_back(((string) *iter++).substr(1));
  }

  // * Output
  {
    int answer = solution(cacheSize, cities);
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
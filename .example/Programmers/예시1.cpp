#include <bits/stdc++.h>

using namespace std;

// # Prototype Declaration ==============================
int solution(int cacheSize, vector<string> cities);

// # Global Variable & Constant =========================

// # Implements Definition ==============================
// ## Main
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int input1;
  vector<string> input2;

  // * Input
  {
    string rawInput;
    regex regExp("\\\"[^\\[\\\"\\,\\]]+"); // "로 시작하되 [",] 기호가 없는 가장 긴 문자열 = "" 내부 글자

    freopen(".example\\Programmers\\question\\input.txt", "rt", stdin);
    
    cin >> input1;
    cin.ignore(); // 입력 버퍼 초기화 \n 제거
 
    getline(cin, rawInput);

    sregex_token_iterator iter;
    sregex_token_iterator end;
    iter = sregex_token_iterator(rawInput.begin(), rawInput.end(), regExp);

    while (iter != end) input2.push_back(((string) *iter++).substr(1));
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
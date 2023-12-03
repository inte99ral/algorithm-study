// #include <bits/stdc++.h>
#include <iostream>
#include <map>
#include <sstream>
#include <vector>
#include <regex>

using namespace std;

// -- Header ====================
int solution(vector<int> nums);

// -- Local Input ====================
int main() {
  freopen("Problem\\Failed\\Programmers\\L2\\PG_181188\\input.txt", "rt", stdin);
  string rawData;
  string buffer;
  vector<int> input;

  // {
  //   getline(cin, rawData);
  //   stringstream ss(rawData.substr(1,rawData.size() - 2));

  //   while(getline(ss, buffer, ',')) input.push_back(stoi(buffer));
  // }

  getline(cin, rawData);
  regex rg("[,\\s]");

  vector<string> out(sregex_token_iterator(rawData.begin(), rawData.end(), rg, -1), sregex_token_iterator());

  for(auto s: out) {
    cout << s << endl;
  }

  cout << solution(input) << '\n';
  return 0;
}

// -- Solution ====================
int solution(vector<vector<int>> targets) {
    int answer = 0;
    return answer;
}
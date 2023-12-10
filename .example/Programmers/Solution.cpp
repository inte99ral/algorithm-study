#include <bits/stdc++.h>
// #include <iostream>
// #include <sstream>
// #include <vector>

using namespace std;

// -- Header =========================
int solution(vector<int> nums);

// -- Local Input ====================
int main() {
  freopen("Problem\\Failed\\Programmers\\L1\\PG_1845\\input.txt", "rt", stdin);
  string rawData;
  string buffer;
  vector<int> input;

  getline(cin, rawData);
  stringstream ss(rawData.substr(1,rawData.size() - 2));

  while(getline(ss, buffer, ',')) input.push_back(7);

  cout << solution(input) << '\n';
  return 0;
}

// -- Solution =======================
int solution(vector<int> nums)
{
  for(int num : nums) {
    cout << num << endl;
  }
  int answer = 0;
  return answer;
}
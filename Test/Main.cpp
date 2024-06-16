#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  map<int, int> iMap;

  iMap[2] = 5;
  iMap[2] = -5;

  iMap[2]++;

  vector<string> t = {"1", "1", "1", "1", "1", "1"};

  for (string s : t) {
    cout << s << " ";
  }
  
  // cout << iMap[2];

  return 0;
}
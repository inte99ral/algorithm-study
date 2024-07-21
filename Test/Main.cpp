#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  map<int, int> iMap;

  cout << iMap.count(2) << "\n";
  cout << iMap[2] << "\n";
  cout << iMap.count(2) << "\n";

  return 0;
}
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  #ifndef ONLINE_JUDGE
  freopen("Problem\\Failed\\Baekjoon\\Silver\\2\\BJ_5397\\question\\input.txt", "rt", stdin);
  #endif

  int T;
  string str;
  list<char> cList;
  list<char>::iterator iter;
  
  cin >> T;

  for (int t = 0; t < T; t++) {
    cin >> str;
    cList = list<char>();
    iter = cList.begin();

    for (char c : str) {
      switch (c) {
        case '-':
          if (iter != cList.begin()) iter = cList.erase(--iter);
          break;
        case '<':
          if (iter != cList.begin()) iter--;
          break;
        case '>':
          if (iter != cList.end()) iter++;
          break;
        default:
          cList.insert(iter, c);
          break;
      }
    }

    for (char c : cList) cout << c;
    cout << '\n';
  }

  return 0;  
}
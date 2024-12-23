#include <iostream>
#include <vector>

using namespace std;

void permRep(int N, int R);
void permRepRecur(vector<int> origin, vector<int> fixed, int N, int R, int length);

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  
  freopen("Problem\\Solved\\Baekjoon\\Silver\\3\\BJ_15651\\question\\input.txt", "rt", stdin);

  int N, M;
  cin >> N >> M;

  permRep(N, M);
  return 0;
}

void permRep(int N, int R) {
  vector<int> origin;
  vector<int> fixed;
  for(int n = 1; n <= N; n++) origin.push_back(n);
  permRepRecur(origin, fixed, N, R, 0);
}

void permRepRecur(vector<int> origin, vector<int> fixed, int N, int R, int length) {
  if(length == R) {
    for(int i : fixed) cout << i << ' ';
    cout << '\n';
    return;
  }

  for(int n = 0; n < N; n++) {
    fixed.push_back(origin.at(n));
    permRepRecur(origin, fixed, N, R, length + 1);
    fixed.pop_back();
  }
}
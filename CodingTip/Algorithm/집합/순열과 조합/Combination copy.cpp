#include <iostream>
#include <vector>

using namespace std;

void comb(int N, int R);
void combRecur(vector<int> origin, vector<int> fixed, int N, int R, int selected, int length);

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  freopen("Problem\\Unsolved\\Baekjoon\\Silver\\3\\BJ_15650\\question\\input.txt", "rt", stdin);

  int N, M;
  cin >> N >> M;

  comb(N, M);
  return 0;
}

void comb(int N, int R) {
  vector<int> origin;
  vector<int> fixed;
  for (int n = 1; n <= N; n++) origin.push_back(n);
  combRecur(origin, fixed, N, R, -1, 0);
}

// N R origin select memory count
void combRecur(vector<int> origin, vector<int> fixed, int N, int R, int selected, int length) {
  if (length == R) {
    for (int i : fixed) cout << i << ' ';
    cout << '\n';
    return;
  }

  for (int n = selected + 1; n < N; n++) {
    fixed.push_back(origin.at(n));
    combRecur(origin, fixed, N, R, n, length + 1);
    fixed.pop_back();
  }
}
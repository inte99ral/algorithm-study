#include <iostream>
#include <vector>

using namespace std;

void perm(vector<int> origin, int N, int M);
void permRecur(vector<int> origin, vector<int> fixed, int N, int M, int select, int length);

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  freopen("Problem\\Failed\\Baekjoon\\Silver\\3\\BJ_15649\\question\\input.txt", "rt", stdin); // -- local input.txt

  int N, M;
  vector<int> iVec;

  cin >> N >> M;
  for(int n = 0; n < N; n++) iVec.push_back(n + 1);
  perm(iVec, N, M);

  return 0;
}

void perm(vector<int> origin, int N, int M) {
  vector<int> fixed(M);
  permRecur(origin, fixed, N, M, 0, 0);
}

void permRecur(vector<int> origin, vector<int> fixed, int N, int M, int select, int length) {
  if(length == M) {
    for(int f : fixed) cout << f << ' ';
    cout << '\n';
    return;
  }

  for(int n = 0; n < N; n++) {
    if((select >> n) & 1) continue;
    fixed[length] = origin[n];
    permRecur(origin, fixed, N, M, select | (1 << n), length + 1);
  }
}
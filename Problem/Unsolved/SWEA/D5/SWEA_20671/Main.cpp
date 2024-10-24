#include <iostream>
#include <functional>
#include <queue>

using namespace std;

const long long mod = 1000000007;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  freopen("Problem\\Unsolved\\SWEA\\D5\\SWEA_20671\\question\\input.txt", "rt", stdin);  // * 로컬 input.txt 입력 코드


  int T;
  int N;

  // * 나눗셈 보조 tenof 생성 ==================================================
  vector<long long> tenof(35);
  tenof[0] = 1;

  for (int i = 1; i < 35; i++) {
    tenof[i] = (tenof[i - 1] * 10) % mod;
  }

  // * T 루프 진입 ==================================================
  cin >> T;
  for (int t = 0; t < T; t++) {
    cin >> N;

    for (int n = 0; n < N; n++) {
      long long answer;
      cin >> answer;

      // # 10^30 자릿수까지 통일 후 크기 순서로 배열하고 그대로 출력, 힙정렬 바로 쓰기
      // priority_queue<long, vector<long>, function<bool(long, long)>> pq([](long o1, long o2) -> bool { return o1 < o2; });

      cout << "#" << n << " " << (answer) << "\n";

      cin >> answer;
      cout << "#" << n << " " << (answer) << "\n";
    }
  }

  return 0;
}
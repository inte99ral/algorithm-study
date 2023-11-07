#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  freopen("Problem\\Failed\\Baekjoon\\Bronze\\2\\BJ_1592\\input.txt", "rt", stdin); // -- 로컬 input.txt 입력 코드
  
  int N;
  int M;
  int L;
  int count;
  int cond;
  int *arr;

  cin >> N >> M >> L;
  count = 0;
  cond = 0;

  arr = new int[N]();
  arr[0] = 1;

  while(arr[cond] < M) {
    cond = (cond + N + ((arr[cond] % 2 == 0) ? -L : L)) % N;
    arr[cond]++;
    count++;
  }

  cout << count;
  
  return 0;
}
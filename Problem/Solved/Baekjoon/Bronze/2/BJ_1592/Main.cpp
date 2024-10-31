#include <bits/stdc++.h>

using namespace std;

int main() {
  freopen("Problem\\Solved\\Baekjoon\\Bronze\\2\\BJ_1592\\.input.txt", "rt", stdin);

  int N, M, L;
  int *arr;
  int count;
  int curr;

  cin >> N >> M >> L;
  arr = new int[N]();
  count = 0;
  curr = 0;

  while((++arr[curr]) < M) {
    curr = (curr + N + ((arr[curr] % 2 == 0) ? -L : L)) % N;
    count++;
  }

  cout << count;

  delete[] arr;
  return 0;
}
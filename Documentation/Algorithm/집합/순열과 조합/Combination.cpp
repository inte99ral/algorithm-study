#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  freopen("Problem\\Unsolved\\Baekjoon\\Silver\\3\\BJ_15650\\question\\input.txt", "rt", stdin);

  int N = 5;
  int R = 3;

  int arr[5][2] = {{0, 0}, {1, 1}};

  for (int *a : arr) {
    cout << a[0] << ", " << a[1] << "\n";
  }

  return 0;
}
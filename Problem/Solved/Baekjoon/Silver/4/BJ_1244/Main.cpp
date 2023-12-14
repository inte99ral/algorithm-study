#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  freopen("Problem\\Solved\\Baekjoon\\Silver\\4\\BJ_1244\\question\\input.txt", "rt", stdin); // -- 로컬 input.txt 입력 코드

  int L;
  int N;
  int *arr;

  cin >> L;
  arr = new int[L + 1]();


  for(int l = 1; l <= L; l++) {
    cin >> arr[l];
  }

  cin >> N;

  for(int n = 0; n < N; n++) {
    int gender;
    int target;

    cin >> gender >> target;
    target;

    switch(gender) {
      case 1: // man
        for(int i = 1; target * i <= L; i++) {
          arr[target * i] = 1 - arr[target * i];
        }
        break;
      case 2: // girl
        for(int i = 0; target - i > 0 && target + i <= L; i++) {
          if(arr[target + i] != arr[target - i]) break;

          int alt = 1 - arr[target + i];
          arr[target + i] = alt;
          arr[target - i] = alt;
        }
        break;
    }
  }

  for(int l = 1; l <= L; l++) {
    cout << arr[l] << ' ';
    if(l % 20 == 0) cout << '\n';
  }

  return 0;
}
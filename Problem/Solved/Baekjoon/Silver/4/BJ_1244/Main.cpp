#include <iostream>

using namespace std;

int main() {
  int L;
  int N;
  int *sArr;

  // freopen("Problem\\Solved\\Baekjoon\\Silver\\4\\BJ_1244\\info\\input.txt", "rt", stdin);

  cin >> L;
  sArr = new int[L + 1];

  for (int l = 1; l <= L; l++) {
    cin >> sArr[l];
  }

  cin >> N;

  for (int n = 0; n < N; n++) {
    int gender, number;
    cin >> gender >> number;

    if (gender == 1) {
      int sum = number;
      while (sum < L + 1) {
        sArr[sum] = !sArr[sum];
        sum += number;
      }
    }

    else {
      int gap = 1;
      sArr[number] = !sArr[number];
      while ((0 < number - gap) && (number + gap < L + 1)) {
        if (sArr[number - gap] != sArr[number + gap]) break;

        sArr[number - gap] = !sArr[number - gap];
        sArr[number + gap] = !sArr[number + gap];
        gap++;
      }
    }
  }

  for (int l = 1; l <= L; l++) {
    cout << sArr[l] << ' ';
    if(l % 20 == 0) cout << '\n';
  }

  delete[] sArr;
  return 0;
}

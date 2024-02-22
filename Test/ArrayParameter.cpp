/**
 * Array Parameter
 */
#include <iostream>
#include <sstream>

using namespace std;

void arrayParaneter(int* x) {
  for (int i = 0; i < 4; i++) {
    std::cout << x[i] << " ";
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  string input =
      "2 3 2 "
      "11 12 "
      "23 24 "
      "35 36 ";

  stringbuf inputBuf(input);
  streambuf* backup = cin.rdbuf(&inputBuf);

  int D = 1;  // Dimension
  int N = 1;
  int* size;
  int* tempArr;

  cin >> D;
  size = new int[D];

  for (int d = 0; d < D; d++) {
    cin >> size[d];
    N *= size[d];
  }

  tempArr = new int[N];
  for (int n = 0; n < N; n++) {
    cin >> tempArr[n];
  }

  for (int n = 0; n < N; n++) {
    cout << tempArr[n] << ' ';
  }

  // {
  //   int size;

  //   cout << "Size : ";
  //   cin >> size;
  //   int* dyary;
  //   dyary = new int[size];  // 동적 배열 생성

  //   // 입력 받기
  //   for (int i = 0; i < size; i++) {
  //     cin >> dyary[i];
  //   }

  //   // 출력 하기
  //   int* curr = 0;
  //   int *begin, *end;
  //   begin = dyary;
  //   end = dyary + size;

  //   curr = begin;

  //   while (curr != end) {
  //     cout << *(curr) << "\t";
  //     curr++;
  //   }
  //   cout << endl;

  //   // 배열 삭제하기
  //   delete[] dyary;
  // }

  cin.clear();
  cin.rdbuf(backup);
  return 0;
}
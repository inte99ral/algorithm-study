/**
 * Array Parameter
 */
#include <iostream>
#include <sstream>

using namespace std;

void arrayParaneter(int size, int* x) {
  for (int i = 0; i < size; i++) {
    std::cout << x[i] << " ";
    x[i] = 0;
  }
}

int main() {
  // template <typename T, size_t N>
  // void idCheck(T (&arr)[N]) {
  //   cout << "[" << typeid(arr).name() << "]" << endl;
  // };
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

  int arr[size[0]][size[1]];

  for (int i = 0; i < size[0]; i++) {
    for (int j = 0; j < size[1]; j++) {
      cin >> arr[i][j];
    }
  }
  arrayParaneter(N, (int*)arr);

  for (int i = 0; i < size[0]; i++) {
    for (int j = 0; j < size[1]; j++) {
      cout << arr[i][j];
    }
  }

  cin.clear();
  cin.rdbuf(backup);
  return 0;
}

// 동적할당
void save1() {
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
}
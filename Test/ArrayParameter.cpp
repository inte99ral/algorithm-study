/**
 * Array Parameter
 */
#include <iostream>
#include <sstream>

using namespace std;

void arrayParaneter(int* a) {
  // int(*b)[2][2] = (int*)a;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  string input =
      "5 3 3\n"
      "0 0 0\n"
      "1 0 0\n"
      "2 0 0\n"
      "3 0 0\n"
      "4 0 0";

  stringbuf inputBuf(input);
  streambuf* backup = cin.rdbuf(&inputBuf);

  int size;

  cout << "Size : ";
  cin >> size;
  int* dyary;
  dyary = new int[size];  // 동적 배열 생성

  // 입력 받기
  for (int i = 0; i < size; i++) {
    cin >> dyary[i];
  }

  // 출력 하기
  int* curr = 0;
  int *begin, *end;
  begin = dyary;
  end = dyary + size;

  curr = begin;

  while (curr != end) {
    cout << *(curr) << "\t";
    curr++;
  }
  cout << endl;

  // 배열 삭제하기
  delete[] dyary;

  cin.clear();
  cin.rdbuf(backup);
  return 0;
}
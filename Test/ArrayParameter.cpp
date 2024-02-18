/**
 * Dynamic Array
 */
#include <iostream>

using namespace std;

int main() {
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

  return 0;
}
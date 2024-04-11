#include <iostream>

using namespace std;

template <typename T1, size_t N1>
void func(T1 (&arr1)[N1]);

int main() {
  int arr1[5] = {0, 1, 2, 3, 4};
  func(arr1);
  return 0;
}

template <typename T1, size_t N1>
void func(T1 (&arr1)[N1]) {
  cout << "[";
  for (const auto &a : arr1) {
    cout << a << ", ";
  }
  cout << "\b\b]\n";
}
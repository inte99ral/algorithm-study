#include <iostream>
#include <sstream>
#include <vector>

#define PRINT_ARR(arr)                                    \
  cout << "[";                                            \
  for (auto arrElement : arr) cout << arrElement << ", "; \
  cout << "\b\b]\n";

#define TEST_1(x) cout << x << " | TEST_1\n";
#define TEST_2(x) cout << x << " | TEST_2\n";
#define TEST(left, right) left##right;
#define TEST_() left##right;

using namespace std;

void printArr(int* x) {
  cout << "TYPE : " << typeid(x).name() << " - " << sizeof(int) << "bite" << endl;
  return;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int arr[2][2][2] = {{{1, 2}, {3, 4}}, {{5, 6}, {7, 8}}};

  printArr((int*)arr);

  return 0;
}
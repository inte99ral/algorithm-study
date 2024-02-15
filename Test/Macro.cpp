#include <iostream>
#include <sstream>
#include <vector>

#define PRINT_ARR(arr)                                    \
  cout << "[";                                            \
  for (auto arrElement : arr) cout << arrElement << ", "; \
  cout << "\b\b]\n";

#define TEST_1() cout << "TEST_1\n";
#define TEST_2() cout << "TEST_2\n";

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int arr[2][2][2] = {{{1, 2}, {3, 4}}, {{5, 6}, {7, 8}}};

  // TEST_1();

  return 0;
}
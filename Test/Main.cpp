#include <iostream>
#include <fstream>
#include <sstream>

#define SET_IO(INPUT_DATA) std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);std::ifstream fs(INPUT_DATA);std::stringstream ss(INPUT_DATA);if(fs.is_open())std::cin.rdbuf(fs.rdbuf());else std::cin.rdbuf(ss.rdbuf())

using namespace std;

int perm(const int* origin, int N, int R);
void permRecur(const int* origin, const int* select, int N, int R, int data, int size, const int* count);

int main() {
  SET_IO("3 2");

  int N;
  int R;
  int count;
  int* origin;

  cin >> N;
  cin >> R;
  count = 0;
  origin = new int[N];
  for (int n = 1; n <= N; n++) origin[n - 1] = n;

  cout << "[CASES]:\n";

  {
    // ### 4. Recursive Solution - Bitmask
    int count = perm(origin, N, R);
  }
  
  delete[] origin;

  cout << "\n";
  cout << "[NUMBER]: " << count << "\n";

  return 0;
}


int perm(const int* origin, int N, int R) {
  int count;
  int* select = new int[R]();
  permRecur(origin, select, N, R, 0, 0, &count);
  return count;
}

void permRecur(const int* origin, const int* select, int N, int R, int data, int size, int* count) {
  if (size == R) {
    *count++;
    for (int r = 0; r < R; r++) cout << select[r] << ' ';
    cout << '\n';
    return;
  }

  for (int i = 0; i < N; i++) {
    // 지금의 i번째 값 (=origin index) 을 이전에 선택한 적이 있다면?
    if((data >> i) & 1) continue;

    permRecur(origin, select, N, R, data, size + 1, count);
  }
  return;
}

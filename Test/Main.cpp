#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#define SET_IO(INPUT_DATA) std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);std::ifstream fs(INPUT_DATA);std::stringstream ss(INPUT_DATA);if(fs.is_open())std::cin.rdbuf(fs.rdbuf());else std::cin.rdbuf(ss.rdbuf())

using namespace std;

template <typename It>
bool next_perm(It begin, It end) {
  if (begin == end) return false;

  It i = end;
  if (begin == --i) return false;

  while (true) {
    It i1, i2;

    i1 = i;

    if (*--i < *i1) {
      i2 = end;
      while (!(*i < *--i2));
      iter_swap(i, i2);
      reverse(i1, end);
      return true;
    }
    if (i == begin) {
      reverse(begin, end);
      return false;
    }
  }
}

int main() {
  SET_IO("4 1");

  int N;
  int R;
  int count = 0;
  vector<int> origin;

  cin >> N;
  cin >> R;
  origin = vector<int>(N);
  for (int n = 0; n < N; n++) origin[n] = n + 1;

  cout << "[CASES]:\n";

  {
    // ### 6. Iterator Solution

    // 선택할 범위까지 1로 안하는 범위를 0으로 채웁니다.
    vector<int> v(N);
    fill(v.begin(), v.begin() + R, 1);
    fill(v.begin() + R, v.end() + R, 0);

    do {
      count++;
      for (int r = 0; r < R; r++) cout << origin[r] << ' ';
      cout << '\n';
    } while (next_perm(origin.begin(), origin.end()));
    
  }

  cout << "\n";
  cout << "[NUMBER]: " << count << "\n";

  return 0;
}

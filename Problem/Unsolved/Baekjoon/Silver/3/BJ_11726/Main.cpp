#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
  #define SET_IO(INPUT_DATA) \
    std::ios::sync_with_stdio(false); \
    std::cin.tie(nullptr); \
    std::cout.tie(nullptr); \
    std::istream* IO_S = (std::filesystem::exists(INPUT_DATA)) \
      ? (std::istream*) new std::ifstream(INPUT_DATA) \
      : (std::istream*) new std::stringstream(INPUT_DATA); \
    std::streambuf* IO_BACKUP = std::cin.rdbuf(IO_S->rdbuf())

  #define UNSET_IO() \
    std::cin.rdbuf(IO_BACKUP); \
    delete IO_S
    
#else
  #define SET_IO(INPUT_DATA) \
    std::ios::sync_with_stdio(false); \
    std::cin.tie(nullptr); \
    std::cout.tie(nullptr)

  #define UNSET_IO() ((void) 0)
#endif

using namespace std;

int main(int argc, char* argv[]) {
  SET_IO("_INPUT_.txt");

  int N;
  int* arr;

  cin >> N;
  arr = new int[N + 1]();

  for (int n = 0; n <= N; n++) {
    if (n <= 2) {
      arr[n] = n;
      continue;
    }

    arr[n] = (arr[n - 2] + arr[n - 1]) % 10007;
  }

  cout << arr[N];

  UNSET_IO();
  return 0;
}
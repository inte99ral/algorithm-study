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

long long longMod(long long A, long long B, long long C) {
  if (B <= 1) {
    return (B == 0) ? (1 % C) : (A % C);
  }

  if (B % 2 == 0) {
    long long temp = longMod(A, B / 2, C);
    temp %= C;
    temp *= temp;
    temp %= C;
    return temp;
  }
  else {
    long long temp = longMod(A, B / 2, C);
    temp %= C;
    temp *= temp;
    temp %= C;
    temp *= (A % C);
    temp %= C;
    return temp;
  }
}

int main() {
  SET_IO("_INPUT_.txt");

  long long A, B, C;
  cin >> A >> B >> C;
  cout << longMod(A, B, C) << endl;

  UNSET_IO();
  return 0;
}
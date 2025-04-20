#define LOCAL_JUDGE 0 // <-- 로컬파일 입력용

#define TEST bits/stdc++.h

// # 『DIRECTORY_PATH』

#include <bits/stdc++.h>

#include "./src/"

#ifdef LOCAL_JUDGE
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

long long MOD_NUM = 1000000007;

long long stollMod00(const string &s) {
  return stoll(s) % MOD_NUM;
}

long long stollMod01(const string &s) {
  long long ret = 0;
  for (char digit : s) {
    ret = (ret * 10 + (digit - '0')) % MOD_NUM;
  }
  return ret;
}

long long stollMod02(const string &s) {
  long long ret = 0;
  for (char digit : s) {
    ret = (ret * 10 + (digit - '0')) % MOD_NUM;
  }
  return ret;
}

int main() {
  SET_IO("_INPUT_.txt");

  string str = "1546722115";
  long long l0, l1, l2;

  l0 = stoll(str) % MOD_NUM;
  l1 = stollMod00(str);

  cout << l0 << "\n";
  cout << l1 << "\n";



  UNSET_IO();
  return 0;
}
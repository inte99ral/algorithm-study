#define LOCAL_JUDGE 0 // <-- 로컬파일 입력용

// # 제한 시간 초과남

#include <bits/stdc++.h>

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

const long long MOD_NUM = 1000000007;

int main(int argc, char* argv[]) {
	SET_IO("_INPUT_.txt");
	int T;
  cin >> T;

	for(int t = 1; t <= T; t++) {
    int N;
	}

	UNSET_IO();
	return 0;
}
#define LOCAL_JUDGE 0 // <-- 로컬파일 입력용

// # 『DIRECTORY_PATH』

// ## Documentation ==========================================================
/**
 * @name 19118. 언덕길
 * @see "https://swexpertacademy.com/main/code/problem/problemDetail.do?problemLevel=5&problemLevel=6&contestProbId=AYxCewMqiqwDFASu&categoryId=AYxCewMqiqwDFASu&categoryType=CODE&problemTitle=&orderBy=FIRST_REG_DATETIME&selectCodeLang=ALL&select-1=6&pageSize=10&pageIndex=1"
 * @author inte99ral
 * @version 2024-11-18
 */


// ## Import Declaration =====================================================

// ### API & Library:

#include <bits/stdc++.h>
// #include <iostream>
// #include <fstream>
// #include <sstream>
// #include <filesystem>

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

// ### Namespace:

using namespace std;

// ## Variable & Constant ====================================================

const long long MOD_NUM = 1000000007;

// ## Prototype Declaration ==================================================

// ## Implements Definition ==================================================

// ### Main

int main() {

	// SET_IO(
  //   "INNER1 \n"
  //   "INNER2 \n"
  //   "INNER3 \n"
  // );

	SET_IO("_INPUT_.txt");

	int T;
	int N;

	cin >> T;

	for(int t = 1; t <= T; t++) {
		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
			 이 부분에 여러분의 알고리즘 구현이 들어갑니다.
		 */
		/////////////////////////////////////////////////////////////////////////////////////////////
	}

	UNSET_IO();
	return 0;
}
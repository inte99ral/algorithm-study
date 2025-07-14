// # 『DIRECTORY_PATH』

// ## Documentation ==========================================================
/**
 * @name 『PROBLEM_CODE』
 * 
 * @description
 * 각 함수에 대한 설명이 아니라
 *
 * 이 파일의 목적에 대한 초록 및 요약 서술을 여기에 적습니다.
 *
 * @example
 * ```
 * // * 파일의 목적과 사용 예시를 적습니다.
 * function<int()> func1 = []() -> int { return 0; };
 * ```
 *
 * @see "https://www.google.co.kr/"
 * @author inte99ral
 * @version 2024-11-18
 */

/**
 * 예시
 * @name BJ_xxxx
 * @see "https://www.acmicpc.net/problem/xxxx"
 * @version xxxx-xx-xx
 */

// ## Import Declaration =====================================================

// ### API & Library:

#include <bits/stdc++.h>
// #include <iostream>
// #include <fstream>
// #include <sstream>
// #include <filesystem>

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

// ### Namespace:

using namespace std;

// ## Variable & Constant ====================================================

// ## Prototype Declaration ==================================================

// ## Implements Definition ==================================================

// ### Main
int main(int argc, char* argv[]) {
  // freopen("__INPUT__.txt", "rt", stdin);

  // SET_IO(
  //   "INNER1 \n"
  //   "INNER2 \n"
  //   "INNER3 \n"
  // );

  SET_IO("_INPUT_.txt");

  for (string buf; cin >> buf;) {
    cout << buf << endl;
  }

  UNSET_IO();
  return 0;
}
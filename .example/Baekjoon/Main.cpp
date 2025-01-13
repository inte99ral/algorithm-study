// # 『DIRECTORY_PATH』

// ## Documentation ==========================================================
/**
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

// ## Import Declaration =====================================================

// ### API & Library:
#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#define SET_IO(INPUT_DATA) std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);std::ifstream fs(INPUT_DATA);std::cin.rdbuf(fs.is_open()?((std::istream*)&fs)->rdbuf():((std::istream*)new std::stringstream(INPUT_DATA))->rdbuf())
#else
#define SET_IO(INPUT_PATH) std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr)
#endif


using namespace std;

// ## Variable & Constant ====================================================

// ## Prototype Declaration ==================================================

// ## Implements Definition ==================================================

// ### Main
int main() {
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

  return 0;
}
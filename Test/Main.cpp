#include <iostream>
#include <sstream>
#include <fstream>

#ifndef ONLINE_JUDGE
#define SET_IO(INPUT_DATA) std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);std::ifstream fs(INPUT_DATA);std::cin.rdbuf(fs.is_open()?((std::istream*)&fs)->rdbuf():((std::istream*)new std::stringstream(INPUT_DATA))->rdbuf())
#else
#define SET_IO(INPUT_PATH) std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr)
#endif


using namespace std;

int main() {
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
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

int main() {
  SET_IO("_INPUT_.txt");

  int T;
  string line;

  cin >> T;
  cin.ignore();
  
  for (int t = 0; t < T; t++) {
    getline(cin, line);
    list<char> cList;
    list<char>::iterator iter = cList.begin();

    for (char c : line) {
      switch (c) {
       case '<':
        if (iter == cList.begin()) break;
        iter--;
        break;

       case '>':
        if (iter == cList.end()) break;
        iter++;
        break;

       case '-':
        if (iter == cList.begin()) break;
        iter = cList.erase(--iter);
       break;
      
       default:
        iter = ++(cList.emplace(iter, c));
        break;
      }
    }
    
    cout << string(cList.begin(), cList.end()) << "\n";
  }

  UNSET_IO();
  return 0;
}
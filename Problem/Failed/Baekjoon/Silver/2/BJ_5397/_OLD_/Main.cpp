#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#define SET_IO(INPUT_DATA) std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);std::ifstream IO_FS(INPUT_DATA);std::streambuf *IO_BACKUP=std::cin.rdbuf(IO_FS.is_open()?((std::istream*)&IO_FS)->rdbuf():((std::istream*)new std::stringstream(INPUT_DATA))->rdbuf())
#define TEST_IO(TEST_CODE) TEST_CODE
#define UNSET_IO() std::cin.rdbuf(IO_BACKUP)
#else
#define SET_IO(INPUT_PATH) std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr)
#define TEST_IO(TEST_CODE) ((void) 0)
#define UNSET_IO() ((void) 0)
#endif


using namespace std;

int main() {
  SET_IO("_INPUT_.txt");

  int T;
  cin >> T;
  cin.ignore();

  while(T--) {
    string keylog;
    list<char> pw;
    list<char>::iterator iter = pw.begin();

    cin >> keylog;

    for (char key : keylog) {
      switch (key) {
       case '<':
        if (iter != pw.begin()) iter--;
        break;
       case '>':
        if (iter != pw.end()) iter++;
        break;
       case '-':
        if (iter != pw.begin()) iter = pw.erase(--iter);
        break;
       default:
        pw.insert(iter, key);
        break;
      }
    }

    cout << string(pw.begin(), pw.end()) << "\n";
  }

  UNSET_IO();
  return 0;
}
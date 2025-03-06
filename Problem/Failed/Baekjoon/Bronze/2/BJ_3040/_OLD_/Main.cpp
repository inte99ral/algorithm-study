#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#define SET_IO(INPUT_DATA) std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);std::ifstream fs(INPUT_DATA);std::cin.rdbuf(fs.is_open()?((std::istream*)&fs)->rdbuf():((std::istream*)new std::stringstream(INPUT_DATA))->rdbuf())
#else
#define SET_IO(INPUT_PATH) std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr)
#endif


using namespace std;

int main() {
  SET_IO("_INPUT_.txt");

  int dwarf[9] = {};
  int sum = 0;

  for (int n = 0; n < 9; n++) {
    cin >> dwarf[n];
    sum += dwarf[n];
  }

  sum -= 100;

  {
    int data[2] = {};
    int size = 0;

    while (data[0] != 9) {
      if (size == 2) {
        if (sum == dwarf[data[0]] + dwarf[data[1]]) break;

        size--;
        data[size]++; 
        continue;
      }

      if (data[size] == 9) {
        data[size] = 0;
        size--;
        data[size]++;
        continue;
      }

      if ((size != 0) && (data[size - 1] >= data[size])) {
        data[size]++;
        continue;
      }

      size++;
    }

    for (int n = 0; n < 9; n++) {
      if ((n != data[0]) && (n != data[1])) {
        cout << dwarf[n] << "\n";
      }
    }
  }

  return 0;
}
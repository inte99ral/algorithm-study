#include <bits/stdc++.h>
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
  SET_IO("5");

  {
    int x = 1;
    int arr[5] = {0, 1, 2, 3, 4};

    arr[x] = arr[x++];

    for (int i = 0; i < 5; i++) cout << arr[x];
    cout << '\n';
  }

  {
    int x = 1;
    int arr[5] = {0, 1, 2, 3, 4};

    arr[x++] = arr[x];

    for (int i = 0; i < 5; i++) cout << arr[x];
    cout << '\n';
  }

  {
    int x = 1;
    int arr[5] = {0, 1, 2, 3, 4};

    arr[x++] = arr[x++];

    for (int i = 0; i < 5; i++) cout << arr[x];
    cout << '\n';
  }

  return 0;
}
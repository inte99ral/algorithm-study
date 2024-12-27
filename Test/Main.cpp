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
    // set<int> iSet;

    // iSet.emplace(1);
    // if(iSet.find(1) != iSet.end()) {
    //   cout << "Y";
    // }
    // else {
    //   cout << "N";
    // }
  }

  {
    set<int> iSet;

    iSet.insert(9);
    iSet.insert(1);
    iSet.insert(9);
    iSet.insert(7);
    iSet.insert(8);
    iSet.insert(2);
    iSet.insert(5);
    iSet.insert(7);

    vector<int> iVec(iSet.begin(), iSet.end());

    int* iArr = iVec.data();
    int* tArr;
    tArr = vector<int>(iSet.begin(), iSet.end()).data();

    for(int i = 0; i < (int)iVec.size(); i++) cout << iArr[i] << ' ';
    cout << '\n';
    for(int i = 0; i < (int)iVec.size(); i++) cout << tArr[i] << ' ';
  }

  return 0;
}
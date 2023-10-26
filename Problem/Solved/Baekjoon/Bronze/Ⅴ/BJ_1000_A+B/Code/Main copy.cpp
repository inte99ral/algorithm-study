#include <string>
#include <iostream>
#include <fstream>
#include <filesystem>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

  ifstream fin;
  fin.open("Problem\\Solved\\Baekjoon\\Bronze\\Ⅴ\\BJ_1000_A+B\\Code\\input.txt");
  int T;
  string str;

  cout << "루프 시작\n";

  if(fin) {
    fin >> str;
    cout << "열렸다\n" << str << '\n';
  }
  else {
    cout << "아 좆됬다\n";
  }

  cout << "종료\n";

  fin.close();
  return 0;
}
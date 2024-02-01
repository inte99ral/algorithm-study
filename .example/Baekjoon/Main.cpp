#include <iostream>

using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  freopen(".example\\Baekjoon\\question\\input.txt", "rt", stdin); // -- 로컬 input.txt 입력 코드

  string input;

  // -- String line
  // getline(cin, input);
  // cout << input << '\n';

  // -- Int Array
  for (int i = 0; i < 6; i++)
  {
    cin >> input;
    cout << input << '\n';
  }

  return 0;
}
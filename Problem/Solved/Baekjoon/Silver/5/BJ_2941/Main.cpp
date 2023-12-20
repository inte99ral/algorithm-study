#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  freopen("Problem\\Solved\\Baekjoon\\Silver\\5\\BJ_2941\\question\\input.txt", "rt", stdin);

  char input[103];
  int index = 0;
  int answer = 0;

  cin.getline(input, 103);

  while (input[index] != '\0') {
    switch (input[index]) {
      case 'c':
        if(input[index + 1] == '=' || input[index + 1] == '-') index++;
        break;
      case 'd':
        if(input[index + 1] == 'z' && input[index + 2] == '=') index += 2;
        else if(input[index + 1] == '-') index++;
        break;
      case 'l':
        if(input[index + 1] == 'j') index++;
        break;
      case 'n':
        if(input[index + 1] == 'j') index++;
        break;
      case 's':
        if(input[index + 1] == '=') index++;
        break;
      case 'z':
        if(input[index + 1] == '=') index++;
        break;
    }
    index++;
    answer++;
  }

  cout << answer;

  return 0;
}
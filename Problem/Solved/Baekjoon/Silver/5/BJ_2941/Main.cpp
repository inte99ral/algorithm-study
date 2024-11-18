#include <bits/stdc++.h>

using namespace std;

int main() {
  int answer;
  int N;
  string input;

  freopen("Problem\\Solved\\Baekjoon\\Silver\\5\\BJ_2941\\_INPUT_.txt", "rt", stdin);
  
  cin >> input;
  answer = N = input.size();

  for (int n = 1; n < N; n++) {
    switch (input[n]) {
     case 'j':
      if (input[n - 1] == 'l' || input[n - 1] == 'n') answer--;
      break;
     case '-':
      if (input[n - 1] == 'c' || input[n - 1] == 'd') answer--;
      break;
     case '=':
      if (input[n - 1] == 'c' || input[n - 1] == 's' || input[n - 1] == 'z') answer--;
      if (n > 1 && input[n - 2] == 'd' && input[n - 1] == 'z') answer--;
      break;
    }
  }
  
  cout << answer;
  return 0;
}
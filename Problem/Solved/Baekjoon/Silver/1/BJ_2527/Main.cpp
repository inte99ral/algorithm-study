#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  freopen("Problem\\Solved\\Baekjoon\\Silver\\1\\BJ_2527\\question\\input.txt", "rt", stdin); // -- local

  for(int i = 0; i < 4; i++) {
    char answer = '0';
    int cord[8];
    int xState = 2;
    int yState = 2;
    for(int j = 0; j < 8; j++) cin >> cord[j];

    // x 비교
    if(cord[2] < cord[4] || cord[6] < cord[0]) xState = 0;
    else if(cord[2] == cord[4] || cord[6] == cord[0]) xState = 1;

    // y 비교
    if(cord[3] < cord[5] || cord[7] < cord[1]) yState = 0;
    else if(cord[3] == cord[5] || cord[7] == cord[1]) yState = 1;

    if(xState == 0 || yState == 0) answer = 'd';
    else if(xState == 1 && yState == 1) answer = 'c';
    else if(xState == 1 || yState == 1) answer = 'b';
    else answer = 'a';
    
    cout << answer << '\n';
  }
  return 0;  
}
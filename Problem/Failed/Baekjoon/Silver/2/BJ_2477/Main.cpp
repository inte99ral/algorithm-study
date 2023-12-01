#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  freopen("Problem\\Failed\\Baekjoon\\Silver\\2\\BJ_2477\\input.txt", "rt", stdin); // -- 로컬

  int answer;

  int K;
  int maxArea = 0;
  int delArea = 0;
  int prevDirc = 0;
  int currDirc = 0;
  int prevLen = 0;
  int currLen = 0;

  const int *clockwise = new int[5]{0, 3, 4, 2, 1};
  const int *counterclockwise = new int[5]{0, 4, 3, 1, 2};

  cin >> K;

  for(int i = 0; i < 7; i++) {
    int currArea;

    prevDirc = currDirc;
    prevLen = currLen;

    cin >> currDirc;
    cin >> currLen;

    currArea = prevLen * currLen;

    if(currDirc)

    if(maxArea < newArea) maxArea = newArea; 
  }

  cout << K;

  return 0;
}

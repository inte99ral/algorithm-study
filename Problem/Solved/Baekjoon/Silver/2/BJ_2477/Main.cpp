/*
 * 해설 ㄱ 자 모양을 추측하기 위하여 반시계방향 상수 배열을 만들고
 * ㄱ자 모양을 위해 시계방향으로 꺾이는 순간을 파악
 */

#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  freopen("Problem\\Solved\\Baekjoon\\Silver\\2\\BJ_2477\\question\\input.txt", "rt", stdin); // -- 로컬

  int answer;

  int K;
  int maxArea = 0;
  int delArea = 0;

  int firstDirc = 0;
  int prevDirc = 0;
  int currDirc = 0;

  int firstLen = 0;
  int prevLen = 0;
  int currLen = 0;

  const int *clockwise = new int[5]{-1, 3, 4, 2, 1};

  cin >> K;

  cin >> currDirc;
  cin >> currLen;

  firstDirc = currDirc;
  firstLen = currLen;

  for(int i = 0; i < 5; i++) {
    int currArea;

    prevDirc = currDirc;
    prevLen = currLen;

    cin >> currDirc;
    cin >> currLen;

    currArea = prevLen * currLen;

    if(currDirc == clockwise[prevDirc]) {
      delArea = currArea;
    }
    else {
      if(maxArea < currArea) {
        maxArea = currArea;
      } 
    }
  }

  {
    prevDirc = currDirc;
    prevLen = currLen;

    int currArea = firstLen * prevLen;

    if(firstDirc == clockwise[prevDirc]) {
      delArea = firstLen * prevLen;
    }
    else {
      int currArea = firstLen * prevLen;
      if(maxArea < currArea) maxArea = currArea; 
    }
  }

  cout << K * (maxArea - delArea);

  return 0;
}

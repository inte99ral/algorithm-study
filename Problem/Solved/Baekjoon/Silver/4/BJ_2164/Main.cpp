#include <iostream>
#include <queue>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  freopen("Problem\\Solved\\Baekjoon\\Silver\\4\\BJ_2164\\question\\input.txt", "rt", stdin);

  /** -- 풀이 1 : 직접 구현 ========================================
   * 카드의 덱을 큐로 직접 구현한다
   */
  
  // {
  //   int N;
  //   queue<int> deck;

  //   cin >> N;
  //   for(int n = 1; n <= N; n++) deck.push(n);

  //   while(deck.size() != 1) {
  //     deck.pop();
  //     deck.push(deck.front());
  //     deck.pop();
  //   }

  //   cout << deck.front();
  // }


  /** -- 풀이 2 : 패턴 파악 ========================================
   * 답에는 규칙이 존재한다.
   * 답은 항상 2의 배수이고 2의 거듭제곱에 맞춰서 아래의 순서로 패턴이 반복된다
   * 1  2  2 4  2 4 6 8  2 4 6 8 10 12 14 16
   */

  {
    int N = 0;
    int exp = 1;
    cin >> N;
    while(exp < N) exp <<= 1;
    cout << (N == exp ? exp : (N << 1) - exp);
  }

  return 0;
}
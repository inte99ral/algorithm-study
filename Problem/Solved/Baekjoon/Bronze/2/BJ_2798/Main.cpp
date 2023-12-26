#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  freopen("Problem\\Failed\\Baekjoon\\Bronze\\2\\BJ_2798\\question\\input.txt", "rt", stdin);

  int N;
  int M;
  int *card;
  int answer = 0;

  cin >> N >> M;

  card = new int[N];

  for(int n = 0; n < N; n++) cin >> card[n];

  for(int i = 0; i < N - 2; i++) {
    if(card[i] > M) continue;
    for(int j = i + 1; j < N - 1; j++) {
      if((card[i] + card[j]) > M) continue;
      for(int k = j + 1; k < N; k++) {
        if((card[i] + card[j] + card[k]) > M) continue;
        if((card[i] + card[j] + card[k]) < answer) continue;
        answer = card[i] + card[j] + card[k];
      }
    }
  }

  cout << answer;
  return 0;
}
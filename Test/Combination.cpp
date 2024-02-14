#include <iostream>
#include <queue>
#include <sstream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  string input =
      "5 3 3\n"
      "0 0 0\n"
      "1 0 0\n"
      "2 0 0\n"
      "3 0 0\n"
      "4 0 0";

  stringbuf inputBuf(input);
  streambuf* backup = cin.rdbuf(&inputBuf);

  int N;  // 전체 묶음 수
  int M;  // 묶음의 크기
  int R;  // 선택할 묶음 수

  cin >> N >> M >> R;

  int origin[N][M];
  int select[R][M];

  for (int n = 0; n < N; n++)
    for (int m = 0; m < M; m++)
      cin >> origin[n][m];

  // CASE 1 : RAW 한 구현
  {
    // count memory
    queue<pair<int, int>> taskQueue;
    taskQueue.push(make_pair<int, int>(8, 2));

    while (taskQueue.empty()) {
      cout << taskQueue.front().first << ", " << taskQueue.front().second << '\n';
      taskQueue.pop();
    }
    // do {
    //   cout << taskQueue.front().first << ", " << taskQueue.front().second << '\n';
    //   taskQueue.pop();
    //   /* code */
    // }
    // while (taskQueue.empty());
  }

  // TEST
  // {
  //   for (int n = 0; n < N; n++) {
  //     for (int m = 0; m < M; m++) {
  //       cout << origin[n][m] << ' ';
  //     }
  //     cout << '\n';
  //   }
  // }

  cin.clear();
  cin.rdbuf(backup);
  freopen("Test\\input.txt", "rt", stdin);

  string tempInput;
  while (cin >> tempInput) cout << tempInput << '\n';
  return 0;
}
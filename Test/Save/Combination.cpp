#include <iostream>
#include <sstream>
#include <vector>

#define PRINT_ARR(arr)                                    \
  cout << "[";                                            \
  for (auto arrElement : arr) cout << arrElement << ", "; \
  cout << "\b\b]\n";

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
    // memory count stack
    vector<pair<int, int>> task;
    task.push_back(make_pair<int, int>(0, 0));

    while (!task.empty()) {
      if (task.front().second == R) {
        PRINT_ARR(select);
      }
      task.pop_back();
    }
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
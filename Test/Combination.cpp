#include <iostream>  // for cin
#include <sstream>   // for istringstream, stringbuf, streambuf

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  string input =
      "5 2 3\n"
      "0 0\n"
      "1 0\n"
      "2 0\n"
      "3 0\n"
      "4 0";

  stringbuf inputBuf(input);
  streambuf* backup = cin.rdbuf(&inputBuf);

  int N;  // 전체 묶음 수
  int M;  // 묶음의 크기
  int R;  // 선택할 묶음 수

  cin >> N >> M >> R;

  int origin[N][M];
  int select[R][M];

  for (int n = 0; n < N; n++) {
    for (int m = 0; m < M; m++) {
      cin >> origin[n][m];
    }
  }

  for (int* arr : origin) {
    cout << arr[0] << ", " << arr[1] << '\n';
  }

  // CASE 1 : RAW 한 구현
  // {
  //   // cin 스트림 버퍼를 더 이상 못 받을 때까지 하나씩 받아와서 출력
  //   string buffer;
  //   while (cin >> buffer) cout << buffer << '\n';

  //   // sb 버퍼에 연결되어 있던 cin을 초기화, 다시 backup 에 남겨둔 stdin cin 버퍼에 연결
  //   cin.clear();
  //   cin.rdbuf(backup);

  //   // txt 파일을 입력받아 stdin cin 버퍼에 정상적으로 연결되었는지 확인
  //   freopen("Test\\input.txt", "rt", stdin);

  //   // cin 스트림 버퍼를 더 이상 못 받을 때까지 하나씩 받아와서 출력
  //   while (cin >> buffer) cout << buffer << '\n';
  // }
}
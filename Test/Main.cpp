/**
붙어있는 원소끼리 묶어서 출력

-- -- -- -- -- -- 17 17
21 21 -- -- -- -- 17 17
21 21 -- -- -- -- -- --
21 21 -- -- -- 46 46 --
-- -- -- -- -- 46 46 --
-- -- -- -- -- -- -- --
71 71 71 71 71 71 71 71
*/

#include <iostream>
#include <sstream>

using namespace std;

const int dy[4] = {-1, 0, 0, 1};
const int dx[4] = {0, -1, 1, 0};
// const string input = 
//   "7 8\n"
//   "0 0 0 0 0 0 1 1\n"
//   "1 1 0 0 0 0 1 1\n"
//   "1 1 0 0 0 0 0 0\n"
//   "1 1 0 0 0 1 1 0\n"
//   "0 0 0 0 0 1 1 0\n"
//   "0 0 0 0 0 0 0 0\n"
//   "1 1 1 1 1 1 1 1\n";

const string input = 
  "7 8\n"
  "1 0 0 0 0 0 1 1\n"
  "1 0 0 0 0 0 1 1\n"
  "1 0 0 0 0 0 0 1\n"
  "1 0 0 0 0 1 1 1\n"
  "1 0 0 0 0 1 1 1\n"
  "1 0 0 0 0 0 0 1\n"
  "1 1 1 1 1 1 1 1\n";

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int Y;
  int X;
  int** matrix;
  
  // # input
  {
    stringbuf sb(input);
    streambuf *backup = cin.rdbuf(&sb);

    cin >> Y >> X;
    matrix = new int*[Y + 2]();
    matrix[0] = new int[X + 2]();

    for (int y = 1; y < Y + 1; y++) {
      matrix[y] = new int[X + 2]();
      for (int x = 1; x < X + 1; x++) {
        cin >> matrix[y][x];
        if(matrix[y][x] == 0) continue;

        // 고유한 위치정보 할당
        matrix[y][x] = (y * (X + 2)) + x;

        for (int i = 0; i < 2; i++) {
          int prevY = matrix[y][x] / (X + 2);
          int prevX = matrix[y][x] % (X + 2);
          int nextY = y + dy[i];
          int nextX = x + dx[i];

          if(matrix[nextY][nextX] == 0) continue;

          while ((nextY != matrix[nextY][nextX] / (X + 2)) || (nextX != matrix[nextY][nextX] % (X + 2))) {
            cout << (y * (X + 2)) + x << " <==> " << matrix[nextY][nextX] << "\n";
            nextY = matrix[nextY][nextX] / (X + 2);
            nextX = matrix[nextY][nextX] % (X + 2);
          }



          if (matrix[prevY][prevX] < matrix[nextY][nextX]) {
            cout << (y * (X + 2)) + x << " -> " << matrix[nextY][nextX] << "\n";
            matrix[nextY][nextX] = matrix[prevY][prevX];
          }
          else {
            cout << (y * (X + 2)) + x << " <- " << matrix[nextY][nextX] << "\n";
            matrix[prevY][prevX] = matrix[nextY][nextX];
          }
        }
      }
    }

    matrix[Y + 1] = new int[X + 2]();
    cin.clear();
    cin.rdbuf(backup);
  }

  // # OUTPUT
  {
    cout << "\nNUMBER:\n";
    for (int y = 1; y < Y + 1; y++) {
      for (int x = 1; x < X + 1; x++) {
        cout.width(2);
        cout.fill('-');
        cout << y * (X + 2) + x << ' ';
      }
      cout << '\n';
    }
    cout << "\nOUTPUT:\n";
    for (int y = 1; y < Y + 1; y++) {
      for (int x = 1; x < X + 1; x++) {
        if (matrix[y][x] == 0) {
          cout << "-- ";
          continue;
        }

        cout.width(2);
        cout.fill('-');
        cout << matrix[y][x] << ' ';
      }
      cout << endl;
    }
  }

  delete[] matrix;
  return 0;
}
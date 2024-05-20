#include <iostream>
#include <sstream>

using namespace std;

const int dy[4] = {-1, 0, 0, 1};
const int dx[4] = {0, -1, 1, 0};
const string input = 
  "7 8\n"
  "0 0 0 0 0 0 1 1\n"
  "1 1 0 0 0 0 1 1\n"
  "1 1 0 0 0 0 0 0\n"
  "1 1 0 0 0 1 1 0\n"
  "0 0 0 0 0 1 1 0\n"
  "0 0 0 0 0 0 0 0\n"
  "1 1 1 1 1 1 1 1\n";

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int X;
  int Y;
  int** matrix;
  
  // # input
  {
    stringbuf sb(input);
    streambuf *backup = cin.rdbuf(&sb);

    cin >> X >> Y;
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
          int currY = matrix[y][x] / (X + 2);
          int currX = matrix[y][x] % (X + 2);
          int nextY = y + dy[i];
          int nextX = x + dx[i];

          while ((nextY != matrix[nextY][nextX] / (X + 2)) || (nextX != matrix[nextY][nextX] % (X + 2))) {
            nextY = matrix[nextY][nextX] / (X + 2);
            nextX = matrix[nextY][nextX] % (X + 2);
          }

          if (matrix[currY][currX] < matrix[nextY][nextX]) matrix[nextY][nextX] = matrix[currY][currX];
          else matrix[currY][currX] = matrix[nextY][nextX];
        }
      }
    }

    matrix[Y + 1] = new int[X + 2]();
    cin.clear();
    cin.rdbuf(backup);
  }

  delete[] matrix;
  return 0;
}
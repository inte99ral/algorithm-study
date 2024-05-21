[참고 링크](https://www.google.co.kr/search?q=%ED%81%B4%EB%9F%AC%EC%8A%A4%ED%84%B0%EB%A7%81+%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98+c%2B%2B&sca_esv=77a235444057b71d&sca_upv=1&hl=ko&sxsrf=ACQVn09Ie6BR1znxvUdC2QHWWpOVkcHpjA%3A1712133326921&ei=zhQNZqnyN6jt1e8P1OqL0AU&ved=0ahUKEwipkYnW0aWFAxWodvUHHVT1AloQ4dUDCBA&uact=5&oq=%ED%81%B4%EB%9F%AC%EC%8A%A4%ED%84%B0%EB%A7%81+%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98+c%2B%2B&gs_lp=Egxnd3Mtd2l6LXNlcnAiIO2BtOufrOyKpO2EsOungSDslYzqs6DrpqzsppggYysrMggQIRigARjDBEjGK1AAWOsqcAh4AZABA5gBoQGgAZAOqgEEMC4xNLgBA8gBAPgBAZgCDKAClQTCAgYQABgHGB7CAgwQIRgKGKABGMMEGCrCAgoQIRgKGKABGMMEwgIEECEYCsICDhAhGAoYoAEYwwQYChgqmAMAkgcDOC40oAe9Jw&sclient=gws-wiz-serp)

# 클러스터링

## 2차원 배열에서 붙어있는 것들만 묶기

```cpp
/**
붙어있는 원소끼리 묶어서 출력

                   1  1
 2  2              1  1
 2  2
 2  2           3  3
                3  3

 4  4  4  4  4  4  4  4
*/

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
          int currY = 0;
          int currX = 0;
          int nextY = y + dy[i];
          int nextX = x + dx[i];

          if(matrix[nextY][nextX] == 0) continue;

          while ((nextY != matrix[nextY][nextX] / (X + 2)) || (nextX != matrix[nextY][nextX] % (X + 2))) {
            currY = nextY;
            currX = nextX;
            nextY = matrix[currY][currX] / (X + 2);
            nextX = matrix[currY][currX] % (X + 2);
          }



          if (matrix[prevY][prevX] < matrix[nextY][nextX]) {
            matrix[nextY][nextX] = matrix[prevY][prevX];
          }
          else {
            matrix[prevY][prevX] = matrix[nextY][nextX];
          }
        }
      }
    }

    matrix[Y + 1] = new int[X + 2]();
    cin.clear();
    cin.rdbuf(backup);
  }

  // # DEFRAG
  {
    int count = 0;

    for (int y = 1; y < Y + 1; y++) {
      for (int x = 1; x < X + 1; x++) {
        if (matrix[y][x] == 0) continue;
        if ((y == matrix[y][x] / (X + 2)) && (x == matrix[y][x] % (X + 2))) matrix[y][x] = ++count;
        else matrix[y][x] = matrix[matrix[y][x] / (X + 2)][matrix[y][x] % (X + 2)];
      }
    }
  }

  // # OUTPUT
  {
    for (int y = 1; y < Y + 1; y++) {
      for (int x = 1; x < X + 1; x++) {
        if (matrix[y][x] == 0) {
          cout << "   ";
          continue;
        }

        cout.width(2);
        cout.fill(' ');
        cout << matrix[y][x] << ' ';
      }
      cout << endl;
    }
  }

  delete[] matrix;
  return 0;
}
```

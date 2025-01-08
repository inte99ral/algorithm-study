#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#define SET_IO(INPUT_DATA) std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);std::ifstream fs(INPUT_DATA);std::cin.rdbuf(fs.is_open()?((std::istream*)&fs)->rdbuf():((std::istream*)new std::stringstream(INPUT_DATA))->rdbuf())
#else
#define SET_IO(INPUT_PATH) std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr)
#endif

using namespace std;

int main() {
  SET_IO("_INPUT_.txt");

  for(int X, Y; cin >> X >> Y;) {
    if (X == 0) break;

    int count = 0;
    int dy[9] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
    int dx[9] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};
    vector<vector<int>> matrix(Y + 2, vector<int>(X + 2));
    vector<vector<bool>> visited(Y + 2, vector<bool>(X + 2));

    for (int y = 1; y < Y + 1; y++) {
      for (int x = 1; x < X + 1; x++) {
        cin >> matrix[y][x];
      }
    }

    for (int y = 1; y < Y + 1; y++) {
      for (int x = 1; x < X + 1; x++) {
        if (matrix[y][x] == 0) continue;
        if (visited[y][x] == true) continue;

        count++;

        stack<pair<int, int>> task;
        task.emplace(y, x);
      
        while (!task.empty()) {
          int currY = task.top().first;
          int currX = task.top().second;
          task.pop();

          matrix[currY][currX] = count;
          visited[currY][currX] = true;

          for (int i = 0; i < 9; i++) {
            int nextY = currY + dy[i];
            int nextX = currX + dx[i];

            if (matrix[nextY][nextX] == 0) continue;
            if (visited[nextY][nextX]) continue;

            matrix[nextY][nextX] = count;
            visited[nextY][nextX] = true;

            task.emplace(nextY, nextX);
          }
        }
      }
    }

    cout << count << "\n";
  }
  
  return 0;
}
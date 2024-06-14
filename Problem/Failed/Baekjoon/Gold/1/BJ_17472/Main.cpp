#include <iostream>
#include <deque>

using namespace std;

const int dy[4] = {-1, 0, 0, 1};
const int dx[4] = {0, -1, 1, 1};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  freopen("Problem/Failed/Baekjoon/Gold/1/BJ_17472/question/input.txt", "rt", stdin);

  int answer = 0;

  int N; 
  int M;
  int V = 0; // 섬의 수

  int** matrix;
  int** graph;

  // * INPUT
  {
    cin >> N >> M;
    matrix = new int*[N + 2];

    matrix[0] = new int[M + 2];
    fill(matrix[0], matrix[0] + M + 2, -1);

    for (int y = 1; y < N + 2; y++) {
      matrix[y] = new int[M + 2];
      matrix[y][0] = -1;

      for (int x = 1; x < M + 1; x++) {
        int buffer;
        cin >> buffer;
        matrix[y][x] = (buffer == 0) ? -1 : -2;
      }

      matrix[y][M + 1] = -1;
    }

    matrix[N + 1] = new int[M];
    fill(matrix[N + 1], matrix[N + 1] + M + 2, -1);
  }

  // * 정점 체크
  {
    for (int y = 1; y < N + 1; y++) {
      for (int x = 1; x < M + 1; x++) {
        if (matrix[y][x] > -2) continue;

        deque<pair<int, int>> dq;
        dq.push_back(make_pair(y, x));


        while (!dq.empty()) {
          int currY = dq[0].first;
          int currX = dq[0].second;
          matrix[currY][currX] = V;

          for (int i = 0; i < 4; i++) {
            int nextY = currY + dy[i];
            int nextX = currX + dx[i];
            if (matrix[nextY][nextX] >= -1) continue;
            dq.push_back(make_pair(nextY, nextX));
          }

          dq.pop_front();
        }

        V++;
      }
    }
  }

  // * 간선 체크
  {
    graph = new int*[V];
    for (int v = 0; v < V; v++) {
      graph[v] = new int[V];
      fill(graph[v], graph[v] + V, INT_MAX);
    }

    int v1;
    int v2;
    int w;

    for (int y = 1; y < N + 1; y++) {
      v1 = -1;
      v2 = -1;
      w = 0;

      for (int x = 1; x < M + 1; x++) {
        if (v1 == matrix[y][x]) continue;
        
        if (matrix[y][x] == -1) {
          w++;
          continue;
        }

        v2 = matrix[y][x];
        if((v1 != -1) && (w > 1) && (graph[v1][v2] > w)) graph[v1][v2] = graph[v2][v1] = w;

        v1 = matrix[y][x];
        w = 0;
      }
    }

    for (int x = 1; x < M + 1; x++) {
      v1 = -1;
      v2 = -1;
      w = 0;

      for (int y = 1; y < N + 1; y++) {
        if (v1 == matrix[y][x]) continue;
        
        if (matrix[y][x] == -1) {
          w++;
          continue;
        }

        v2 = matrix[y][x];
        if((v1 != -1) && (w > 1) && (graph[v1][v2] > w)) graph[v1][v2] = graph[v2][v1] = w;

        v1 = matrix[y][x];
        w = 0;
      }
    }
  }

  // * MST PRIM
  {
    int w[V];
    bool selected[V] = {};

    fill(w, w + V, INT_MAX);

    w[0] = 0;

    for (int i = 0; i < V - 1; i++) {
      int v1 = -1;
      int min = INT_MAX;

      for (int v = 0; v < V; v++) {
        if (min <= w[v]) continue;

        v1 = v;
        min = w[v];
      }

      for (int v2 = 0; v2 < V; v2++) {
        if (w[v2] <= graph[v1][v2]) continue;

        w[v2] = graph[v1][v2];
      }
    }

    cout << "[W] : ";
    for (int v = 0; v < V; v++) {
      cout << w[v] << " ";
    }
    cout << "\n";
  }


  // * TEST_00
  {
    cout << "\n[V] : " << V;
    cout << "\n[MATRIX]\n";
    for (int y = 0; y < N + 2; y++) {
      for (int x = 0; x < M + 2; x++) {
        if (matrix[y][x] != -1) {
          cout.width(2);
          cout.fill(' ');
          cout << matrix[y][x] << " ";
        }
        else {
          cout << "   ";
        }
      }
      cout << "\n";
    }
  }

  // * TEST_01
  {
    cout << "\n[GRAPH]\n";
    for (int y = 0; y < V; y++) {
      for (int x = 0; x < V; x++) {
        if (graph[y][x] != INT_MAX) {
          cout.width(2);
          cout.fill(' ');
          cout << graph[y][x] << " ";
        }
        else {
          cout << " - ";
        }
      }
      cout << "\n";
    }
  }

  // * TEST_02
  {
    // int test[5];
    // fill(test, test + 5, INT_MAX);
    // for (int i = 0; i < 5; i++) {
    //   cout << test[i] << "\n";
    // }
  }


  // * OUTPUT
  {

    cout << "\n[ANSWER] : ";
    cout << answer;
  }
  
  delete[] matrix;
  delete[] graph;
  return 0;
}
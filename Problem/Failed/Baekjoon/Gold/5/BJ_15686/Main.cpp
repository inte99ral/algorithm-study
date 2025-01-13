#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#define SET_IO(INPUT_DATA) std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);std::ifstream fs(INPUT_DATA);std::cin.rdbuf(fs.is_open()?((std::istream*)&fs)->rdbuf():((std::istream*)new std::stringstream(INPUT_DATA))->rdbuf())
#else
#define SET_IO(INPUT_PATH) std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr)
#endif

using namespace std;

int main() {
  SET_IO("_INPUT_.txt");

  int answer = INT_MAX;
  int N;
  int M;

  vector<pair<int, int>> chicken;
  vector<pair<int, int>> house;

  vector<int> data;
  int size;

  { // * 초기화
    cin >> N;
    cin >> M;

    for (int y = 0; y < N; y++) {
      for (int x = 0; x < N; x++) {
        int temp;
        cin >> temp;

        switch (temp) {
        case 1:
          house.emplace_back(y, x);
          break;
        case 2:
          chicken.emplace_back(y, x);
          break;
        default:
          break;
        }
      }
    }

    data = vector<int>(M, 0);
    size = 0;
  }

  { // * 조합
    while (data[0] != (int) chicken.size()) {
      if (size == M) {
        { // * 치킨 거리 체크
          int sum = 0;
          for (int h = 0; h < (int) house.size(); h++) {
            int distance = INT_MAX;
            for (int m = 0; m < M; m++) {
              distance = min(distance, abs(house[h].first - chicken[data[m]].first) + abs(house[h].second - chicken[data[m]].second));
            }
            sum += distance;
          }

          answer = min(answer, sum);
        }

        size--;
        data[size]++;
        continue;
      }

      if (data[size] == (int) chicken.size()) {
        data[size] = 0;
        size--;
        data[size]++;
        continue;
      }

      if ((size != 0) && (data[size - 1] >= data[size])) {
        data[size]++;
        continue;
      }

      size++;
    }
  }
  cout << answer;
  return 0;
}
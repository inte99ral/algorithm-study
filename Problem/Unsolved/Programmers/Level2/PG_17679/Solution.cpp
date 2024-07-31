// #include <bits/stdc++.h>

// using namespace std;

// // # Prototype Declaration ==============================
// int solution(int m, int n, vector<string> board);

// // # Global Variable & Constant =========================

// // # Implements Definition ==============================
// // ## Main
// int main() {
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
//   cout.tie(nullptr);

//   int m;
//   int n;
//   vector<string> board;

//   // * Input
//   {
//     freopen("Problem/Unsolved/Programmers/Level2/PG_17679/question/input.txt", "rt", stdin);
    
//     string rawInput;
//     regex regExp("[A-Z]+"); // Korean Words
//     sregex_token_iterator iter;
//     sregex_token_iterator end;

//     cin >> m;
//     cin >> n;

//     cin.ignore();

//     getline(cin, rawInput);
//     iter = sregex_token_iterator(rawInput.begin(), rawInput.end(), regExp);

//     while (iter != end) {board.push_back(*iter++);}
//   }

//   // * Output
//   {
//     int answer = solution(m, n, board);
//     cout << "[OUTPUT] : " << answer << "\n";
//   }

//   return 0;
// }

// ## Solution
#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<string> board) {
  int answer = 0;

  vector<vector<char>> matrix(n, vector<char> (m));
  vector<vector<bool>> flag(n, vector<bool> (m));

  for (int y = 0; y < n; y++) {
    for (int x = 0; x < m; x++) {
      matrix[y][x] = board[m - 1 - x].at(y);
    }
  }

  int count;
  do {
    count = 0;

    for (int y = 0; y < n - 1; y++) {
      for (int x = 0; x < m - 1; x++) {
        if ((matrix[y][x] != ' ') && (matrix[y][x] == matrix[y][x + 1]) && (matrix[y][x] == matrix[y + 1][x]) && (matrix[y + 1][x] == matrix[y + 1][x + 1])) {
          flag[y][x] = flag[y][x + 1] = flag[y + 1][x] = flag[y + 1][x + 1] = true;
        }
      }
    }

    for (int y = 0; y < n; y++) {
      for (int x = 0; x < m; x++) {
        if (flag[y][x]) {
          flag[y].erase(flag[y].begin() + x);
          flag[y].push_back(false);
          matrix[y].erase(matrix[y].begin() + x);
          matrix[y].push_back(' ');
          count++;
          x--;
        }
      }
    }

    answer += count;
  } 
  while (count != 0);

  return answer;
}
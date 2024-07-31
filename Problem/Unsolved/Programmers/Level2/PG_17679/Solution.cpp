#include <bits/stdc++.h>

using namespace std;

// # Prototype Declaration ==============================
int solution(int m, int n, vector<string> board);

// # Global Variable & Constant =========================

// # Implements Definition ==============================
// ## Main
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int m;
  int n;
  vector<string> board;

  // * Input
  {
    freopen("Problem/Unsolved/Programmers/Level2/PG_17679/question/input.txt", "rt", stdin);
    
    string rawInput;
    regex regExp("[A-Z]+"); // Korean Words
    sregex_token_iterator iter;
    sregex_token_iterator end;

    cin >> m;
    cin >> n;

    cin.ignore();

    getline(cin, rawInput);
    iter = sregex_token_iterator(rawInput.begin(), rawInput.end(), regExp);

    while (iter != end) {board.push_back(*iter++);}
  }

  // * Output
  {
    int answer = solution(m, n, board);
    cout << "[OUTPUT] : " << answer << "\n";
  }

  return 0;
}

// ## Solution
#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<string> board) {
  int answer = 0;

  vector<vector<char>> matrix(n, vector<char> (m));

  for (int y = 0; y < n; y++) {
    for (int x = 0; x < m; x++) {
      matrix[y][x] = board[m - 1 - x].at(y);
    }
  }

  int count = 0;
  do {
    cout << count << "\n";
    count++;
  } 
  while (count < 10);

  return answer;
}
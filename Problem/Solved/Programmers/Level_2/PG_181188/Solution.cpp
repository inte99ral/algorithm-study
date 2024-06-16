#include <bits/stdc++.h>

using namespace std;

// -- Header =========================
int solution(vector<vector<int>> targets);

// -- Local Input ====================
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  freopen("E:\\StudySpace\\Coding\\Algorithm_Study\\Problem\\Solved\\Programmers\\Level2\\PG_181188\\question\\input.txt", "rt", stdin);

  string rawInput;
  vector<vector<int>> input;

  regex regExp("[0-9]+");
  string buffer;

  getline(cin, rawInput);

  sregex_token_iterator iter(
    rawInput.begin(),
    rawInput.end(),
    regExp
  ), end;

  while(iter != end) {
    vector<int> tempVec = {stoi(*iter++), stoi(*iter++)};
    input.push_back(tempVec);
  }

  cout << solution(input) << '\n';
  return 0;
}

// -- Solution =======================
/**
 * 처음 오답 풀이에서는 정렬을 하지 않고 개구간 시작과 끝을 기억하면서 겹치지 않는 경우를 계산하였다.
 * 하지만 다음의 발상은 두 가지 오류를 가지고 있었다.
 * 1. 어차피 겹치는 이상 겹치는 구간을 알 필요없이 구간의 시작점이나 끝점만 보면 된다는 것
 * 2. [[3, 6], [2, 4], [5, 6], [1, 3]] 의 경우 처럼 소팅을 하지 않으면 이미 다른 구간과 겹쳐서 계산이 필요없는 구간을 구분 못하고 별개로 계산한다.
 * 따라서 오름차순 소팅을 시도하고 구간의 끝부분만 확인하면서 진행하였다. 
*/
int solution(vector<vector<int>> targets) {
  int answer = 1;
  int cursor = targets[0][1];

  sort(targets.begin(), targets.end(), [](vector<int> x, vector<int> y) -> int{return y[0] == x[0]? x[1] < y[1] : x[0] < y[0];});

  for(vector<int> target : targets) {
    if(target[0] < cursor) {
      if(target[1] < cursor) cursor = target[1];
    }
    else {
      cursor = target[1];
      answer++;
    }
  }

  return answer;
}


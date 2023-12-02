#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

// -- Header
int solution();
int solution(vector<int> nums);

// -- Main
int main() {
  cout << solution() << '\n';
  return 0;
}

int solution(vector<int> nums)
{
  for(int num : nums) {
    cout << num << endl;
  }
  int answer = 0;
  return answer;
}

int solution()
{
  return 1234;
}
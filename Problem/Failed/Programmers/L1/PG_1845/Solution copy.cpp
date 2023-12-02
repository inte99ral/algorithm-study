#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

// -- Header
int solution(vector<int> nums);

// -- Main
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  freopen("Problem\\Failed\\Programmers\\L1\\PG_1845\\input.txt", "rt", stdin); // -- 로컬
  
  vector<int> *args;
  string input;
  // stringstream ss;
  // int test;

  getline(cin, input);
  cout << input;

  // cin >> input;
  // input = "456 756";
  // ss.str(input);
  // args = new vector<int>(2,2);

  // while (ss >> test)
  // {
  //   cout << test << endl;
  // }
  
  for(int i: *args) {
    cout << i << endl;
  }

  // iVec = new vector<int>(5, 2);
  // for(int num : *iVec) {
  //   cout << num << endl;
  // }
  // solution(*iVec);
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
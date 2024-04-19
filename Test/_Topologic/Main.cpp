
/**
 * 1 → 2 → 3 → 4
 *  ↘       ↙
 *     5 → 6 → 7
*/

#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N;

  {
    /**
     * 1 → 2 → 3 → 4
     *  ↘       ↙
     *     5 → 6 → 7
     */
    
    string input =
        "7\n"
        "1 2 "
        "1 5 "
        "2 3 "
        "5 6 "
        "3 4 "
        "4 6 "
        "6 7";

    stringbuf sb(input);
    streambuf *backup = cin.rdbuf(&sb);

    cin >> N;


    cin.clear();
    cin.rdbuf(backup);
  }
  
}
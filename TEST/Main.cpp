#include <iostream>
#include <iomanip>
// └ setw()

using namespace std;

int main() {
  cout << "╔════════════════╦════════════════╗\n";
  cout << "║" << setw(16) << left << " File Line" << "║ " << setw(15) << left << "0" << "║\n";
  cout << "║" << setw(16) << left << " File Byte" << "║ " << setw(15) << left << "0" << "║\n";
  cout << "║" << setw(16) << left << " File Unopened" << "║ " << setw(15) << left << "0" << "║\n";
  cout << "╚════════════════╩════════════════╝\n";
  return 0;  
}
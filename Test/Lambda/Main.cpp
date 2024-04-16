#include <iostream>

using namespace std;

int main() {
  []() -> void {cout << "lambda test" << endl;}();
  return 0;
}
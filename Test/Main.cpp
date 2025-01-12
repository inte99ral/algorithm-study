// #include <bits/stdc++.h>
#include <iostream>
#include <thread>
// #include <sstream>
// #include <fstream>

// #ifndef ONLINE_JUDGE
// #define SET_IO(INPUT_DATA) std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);std::ifstream fs(INPUT_DATA);std::cin.rdbuf(fs.is_open()?((std::istream*)&fs)->rdbuf():((std::istream*)new std::stringstream(INPUT_DATA))->rdbuf())
// #else
// #define SET_IO(INPUT_PATH) std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr)
// #endif


using namespace std;

void func1(string tag, int count) {
  for (int i = 0; i < count; i++) cout << tag + " : " + to_string(i) << endl;
}

void func2(string tag, int count) {
  // for (int i = 0; i < count; i++) cout << tag << " : " << i << endl;

for (int i = 0; i < count; i++) cout << tag + " : " + to_string(i) + "\n";
}

int main() {
  thread t1(func2, "task1", 5);
  thread t2(func2, "task2", 5);

  cout << "Main thread: Waiting for threads to finish..." << endl;

  t1.join();
  t2.join();

  cout << "Main thread: All threads have finished." << endl;

  return 0;
}
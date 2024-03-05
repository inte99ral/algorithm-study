#ifndef TEST_HPP
#define TEST_HPP

#include <cstdarg>
#include <iostream>
#include <vector>

using namespace std;

class arrayParameter {
 private:
  int a;

 public:
  void printArr(int* arr, ...);
};

#endif
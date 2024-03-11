# 그 외

## Bool

### [Bool 값의 출력 | Boolean Alphabet](https://en.cppreference.com/w/cpp/io/manip/boolalpha)

- std::boolalpha 이후로는 bool 값의 출력을 1, 0 에서 "true" 와 "false" 로 출력한다.
- std::noboolalpha 이후로는 bool 값의 출력을 "true", "false" 에서 1 과 0 으로 출력한다.

```cpp
#include <iostream>
#include <sstream>

using namespace std;

int main() {
  // boolalpha output
  cout << "default true: " << true << '\n'
       << "default false: " << false << '\n'
       << '\n'
       << boolalpha
       << "boolalpha true: " << true << '\n'
       << "boolalpha false: " << false << '\n'
       << '\n'
       << noboolalpha
       << "noboolalpha true: " << true << '\n'
       << "noboolalpha false: " << false << '\n'
       << '\n';

  // boolalpha parse
  bool b1, b2;
  istringstream is("true false");
  is >> boolalpha >> b1 >> b2;

  cout << '"' << is.str() << "\" parsed as: "
       << noboolalpha << b1 << ' ' << b2 << '\n';

  return 0;
}
```

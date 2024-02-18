#include <cstdarg>
#include <iostream>

template <typename _Ty>
void func(_Ty first, _Ty...)  // 마지막 인자로 NULL과 같은 값을 전달
{
  va_list list;

  va_start(list, first);  // list는 first의 다음 인자를 가리키게 된다.

  _Ty val = first;

  std::cout << first << " ";  // list는 first의 다음 인자를 가리키기에 first는 따로 출력해주어야 한다.
  while (val != 0) {
    std::cout << (val = va_arg(list, _Ty)) << " \n";
  }

  va_end(list);
}

int main() {
  func('a', 'c', 'g', 'x', '\0');  // a c g x

  return 0;
}
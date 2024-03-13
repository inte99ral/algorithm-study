# 리눅스 Linux

## [터미널에 컬러로 출력해보자](https://bigbigpark.github.io/cpp_useful/color-print/)

|         | foreground | background |
| ------- | ---------- | ---------- |
| black   | 30         | 40         |
| red     | 31         | 41         |
| green   | 32         | 42         |
| yellow  | 33         | 43         |
| blue    | 34         | 44         |
| magenta | 35         | 45         |
| cyan    | 36         | 46         |
| white   | 37         | 47         |
| Default | 38         | 39         |
| Off     | 0          | 0          |

```cpp
// \033[#;#;#m 형태로 적용 \033[0m 으로 해제
#include <iostream>

int main(int argc, char** argv)
{
  std::cout << "\033[1;30m" << "black " << "\033[0m" << std::endl;
  std::cout << "\033[1;31m" << "red " << "\033[0m" << std::endl;
  std::cout << "\033[1;32m" << "green " << "\033[0m" << std::endl;
  std::cout << "\033[1;33m" << "yellow " << "\033[0m" << std::endl;
  std::cout << "\033[1;34m" << "blue " << "\033[0m" << std::endl;
  std::cout << "\033[1;35m" << "magenta " << "\033[0m" << std::endl;
  std::cout << "\033[1;36m" << "cyan " << "\033[0m" << std::endl;
  std::cout << "\033[1;37m" << "white " << "\033[0m" << std::endl;

  return 0;
}
```

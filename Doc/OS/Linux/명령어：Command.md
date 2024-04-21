# 명령어：Command

## Shell Script

### 출력

[참고링크](https://directori.tistory.com/133)

- 기본 출력
  - echo
  - print

```bash
echo "Echo Test" # 자동 개행
printf "printf Test" # 자동 개행X
printf "%s %s" print test # 뒤에 오는 문자열들이 전달되는 인자라고 생각하면 됩니다.
```

<br/>

- $ - arguments 전달인자 값으로 전환
  - $# : 스크립트에 전달되는 인자들의 수(C언어에서 args)
  - $0 : 실행하는 스크립트의 파일명으로 실행했을 때 경로를 포함한다면 경로를 포함해서 나옵니다.
  - $1, $2 … : 스크립트로 전달된 인자들(C언어에서 argv[0], argv[1]…)

```bash
#!/bin/bash

echo "Echo Test"
printf "printf Test\n"
printf "Name of script : %s\n" $0
printf "%d arguments %s %s\n" $# $1 $2
```

<br/>

- ${parameter} - parameter substitution 매개변수 값으로 전환

```bash
#!/bin/bash

test="abc"
num=100

echo "${test}"
echo "${num}"
```

<br/>

- $(command) - command substitution 명령어 값으로 전환

```bash
echo "Echo Test" # 자동 개행
printf "printf Test" # 자동 개행X
printf "%s %s" print test # 뒤에 오는 문자열들이 전달되는 인자라고 생각하면 됩니다.
```

<br/>

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

# MSYS2

[참고링크](https://wikidocs.net/219732)

# Module：모듈

```py
# echo.py

import shlex
import sys

def echo(phrase: str) -> None:
   """A dummy wrapper around print."""
   print(phrase)

def main() -> int:
    """Echo the input arguments to standard output"""
    phrase = shlex.join(sys.argv)
    echo(phrase)
    return 0

if __name__ == '__main__':
    sys.exit(main())
```

- **if \_\_name\_\_ == '\_\_main\_\_':**

  &nbsp; `__name__` 은 현재 모듈의 이름을 담고있는 모듈의 내장 변수입니다.

  &nbsp; 모듈이 다른 main() 함수로 인하여 호출된 것이 아니라 직접 실행된 파일일 경우 모듈명 `__name__` 의 값은 "\_\_main\_\_" 이 됩니다. 파이썬은 이를 통해 모듈 호출과 main 함수로써의 동작을 구분할 수 있습니다.

- **sys.exit(main())**

  &nbsp; main 에 대한 호출이 sys.exit()을 통해 래핑되어 있는 구조입니다. 함수가 sys.exit()에 대한 입력으로 허용되는 일부 값을 반환합니다.

  &nbsp; 일반적으로 정수 또는 None(함수에 return 문이 없는 경우 암시적으로 반환됨)입니다.

  &nbsp; 이 구조에서 main 함수의 문자열 반환은 주의해야 합니다. sys.exit()는 문자열 인수를 실패 메시지로 해석하므로 프로그램은 실패를 나타내는 종료 코드 1을 가지며 문자열은 sys.stderr에 기록됩니다.

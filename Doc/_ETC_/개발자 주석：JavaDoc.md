# 개발자 주석：JavaDoc

```java
/**
 * @author https://velog.io/@ming/JavaDoc-%EC%A3%BC%EC%84%9D-%EC%95%8C%EA%B3%A0%EC%93%B0%EC%9E%90
 */
```

````java
/**
 * @description
 *
 * Custom Axios 를 생성하여 배열에 저장하고 리턴한다.
 * @author inte99ral
 * @version 2024-11-18
 * @param 값
 * @return 폭
 * @dependency
 * - [x] package-installed-check
 * - [ ] package-uninstalled-check
 *
 * @see <a href="http://gochigo.kr">고치고</a>
 * @deprecated 미권장 대체되었다
 * @throws
 * @exception
 * @example 예시
 * ```
 * Foo foo = new Foo();
 * ```
 * <pre>
 * {@code
 * Foo foo = new Foo();
 * foo.foo();
 * }
 * </pre>
 */
````

## JSDoc

&nbsp; JavaScript 파일에서 JSDoc(JavaDoc과 유사한 JavaScript 문서화 도구)

&nbsp; JSDoc 은 각 항목을 복수형으로 표기하는 것을 선호합니다.

## Usage Message：명령어 사용법 표기

- [참고링크](https://en.wikipedia.org/wiki/Usage_message)

```txt
Usage: mytool (-set <value> | -unset) [-admin] | [-h]
```

&nbsp; [] (대괄호), () (소괄호), <> (꺾쇠), | (파이프) 등은 명령어 사용법에서 각기 다른 의미를 가집니다.
아래는 대표적인 표기법의 의미입니다.

- [] (대괄호) - "옵션"

  대괄호로 감싸진 부분은 선택적(optional) 요소임을 의미합니다.

  즉, 있어도 되고 없어도 됩니다.

  `[ -admin ]` → -admin 옵션은 써도 되고 안 써도 됨.

- <> (꺾쇠) - "필수 인자"

  꺾쇠로 감싸진 부분은 필수(required) 요소임을 의미합니다.

  반드시 값을 채워서 입력해야 합니다.

  `<value>` → 반드시 값을 입력해야 함.

  - | (파이프) - "선택 또는"

  파이프 기호는 둘 중 하나만 선택해야 함을 의미합니다.

  `-set <value> | -unset` → -set 또는 -unset 중 하나만 선택.

- () (소괄호) - "그룹화"

  소괄호는 여러 요소를 그룹으로 묶을 때 사용합니다.

  보통 파이프와 함께 써서, 그룹 내에서 하나를 선택해야 함을 나타냅니다.

  `(-set <value> | -unset) | -get` → -set 또는 -unset 중 하나를 반드시 선택하거나, -get 를 선택.

&nbsp; 정리하면 다음과 같습니다.

- "[ ]" : 옵션(선택)

- "< >" : 필수 인자

- "( )" : 그룹화

- "|" : OR(둘 중 하나)

- "..." : 반복 가능

# 코드 작성 규칙：Coding Conventions

</br>

- 컨벤션이란?

  - 코드 개발시 함수명이나 프로젝트 구조 등 개발하는 형식에 대한 관습적 약속

- c++ [참고링크](https://docs.popekim.com/ko/coding-standards/cpp)

- [참고링크](https://velog.io/@rex/%EC%BD%94%EB%93%9C-%EC%9E%91%EC%84%B1-%EA%B7%9C%EC%B9%99%EB%93%A4-Coding-Conventions)

## 명명 규칙

1. java 의 경우 패키지명은 모두 소문자로 쓴다.

   - com.(개인 혹은 그룹이름).(프로젝트명).(상위패키지).(하위패키지).(클래스)

2. 프로젝트 이름은 모든 글자를 대문자 스네이크 표기법 또는 파스칼 표기법을 따른다.
3. 클래스와 구조체의 이름은 파스칼 표기법을 따른다.
4. 인터페이스 이름은 형용사로 짓는 것을 지향한다. 파스칼 표기법을 따른다.
5. 메서드 이름은 동사로 짓는 것을 지향한다. 카멜 표기법을 따른다.
6. 변수 명은 None 으로 짓는 것을 지향한다. 카멜 표기법을 따른다.
7. 상수 명은 대문자 스네이크 표기법을 따른다.

```java
// 프로젝트명 대문자 스네이크 ALGORITHM_STUDY

// 패키지명 com.(개인 혹은 그룹이름).(프로젝트명).(상위패키지).(하위패키지).(클래스)
package com.inte99ral.algorithm-study;

//
class Main {

}



```

## 유니코드 양식

[참고 링크](https://ko.rakko.tools/tools/89/)

유니코드 캐릭터 블록 Box Drawing (2500부터 257F까지)를 근간으로 사용합니다.

─ (U+2500) <br/>
┌ (U+250C) ┬ (U+252C) ┐ (U+2510) <br/>
├ (U+251C) ┼ (U+253C) ┤ (U+2524) <br/>
└ (U+2514) ┴ (U+2534) ┘ (U+2518) <br/>

═ (U+2550) <br/>
╔ (U+2554) ╦ (U+2566) ╗ (U+2557) <br/>
╠ (U+2560) ╬ (U+256C) ╣ (U+2563) <br/>
╚ (U+255A) ╩ (U+2569) ╝ (U+255D) <br/>

⟶ (U+27F6) <br/>
⤏ (U+290F)

- 인수에 대한 설명이 필요할 경우 대문자 스네이크 표기법에 『(U+300E), 』(U+300F) 로 감싸서 표기합니다.

예시(React 의 useState) : `const [『GETTER_NAME』, 『SETTER_NAME』] = useState<『VALUE_TYPE』>(『INITIAL_VALUE』);`

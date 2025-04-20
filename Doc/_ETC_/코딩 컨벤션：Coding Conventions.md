# 코드 작성 규칙：Coding Conventions

</br>

- 코딩 컨벤션이란?

  - 코드 작성 규칙을 말합니다.
  - 함수명이나 프로젝트 구조 등 개발하는 형식에 대한 규칙을 관습화하여 코드 구조의 일관성을 유지하고 직관적인 이해를 돕습니다.

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

─ (U+2500) │ (U+2502)<br/>
┌ (U+250C) ┬ (U+252C) ┐ (U+2510) <br/>
├ (U+251C) ┼ (U+253C) ┤ (U+2524) <br/>
└ (U+2514) ┴ (U+2534) ┘ (U+2518) <br/>

═ (U+2550) ║ (U+2551)<br/>
╔ (U+2554) ╦ (U+2566) ╗ (U+2557) <br/>
╠ (U+2560) ╬ (U+256C) ╣ (U+2563) <br/>
╚ (U+255A) ╩ (U+2569) ╝ (U+255D) <br/>

⟵ (U+27F5) ⟶ (U+27F6) <br/>
⤎ (U+290E) ⤏ (U+290F)

- 인수에 대한 설명이 필요할 경우 대문자 스네이크 표기법에 『(U+300E), 』(U+300F) 로 감싸서 표기합니다.

예시(React 의 useState) : `const [『GETTER_NAME』, 『SETTER_NAME』] = useState<『VALUE_TYPE』>(『INITIAL_VALUE』);`

## 코드 문서화 정리 양식

&nbsp; 코드가 복잡해지는 과정에서 작성된 라인들의 목적이 모호해지지 않도록 문서화 시점에서 역할과 목표에 맞춰 단락를 구분하는 것을 권장합니다.

&nbsp; 주석처리를 통하여 시각적으로 단락 구분을 표현하여 직관성을 올릴 수도 있습니다.

- `#` 해당 파일의 상대경로와 파일명을 명시합니다.

- `##` 전체 공백 포함 78 글자를 원칙으로 합니다. 제목 이후에는 `===` 처리하여 단락을 시각적으로 분리해줍니다.

```cpp
// # 『DIRECTORY_PATH』

// ## Documentation ==========================================================
/**
 * 『JAVA_DOC』
 */

// ## API & Library ==========================================================
『LIBRARY_DECLARATION』

// ## Asset ==================================================================
『EXTERNAL_ASSET_DECLARATION』

// ## Prototype Declaration ==================================================
『FUNCTION_DECLARATION』

// ## Global Variable & Constant =============================================
『VARIABLE_DEFINITION』

// ## Implements Definition ==================================================
『FUNCTION_DEFINITION』
```

### Javascript

- import 되는 모듈들을 한 곳으로 모아 정리합니다.
- javascript 코드에서는 호이스팅이 발생하기 때문에 선언부 구현부가 분리될 필요는 없습니다.

```javascript
// # 『DIRECTORY_PATH』

// ## Documentation ==========================================================
/**
 * 『JAVA_DOC』
 */

// ## Import Declaration =====================================================

// ### API & Library:
import {『LIBRARY』} from '『LIBRARY_PATH』';

// ### Asset:
import 『ASSET』 from '『ASSET_PATH』';

// ## Interface & Class ======================================================

// ### 『TYPE』
/**
 * 『JS_DOC』
 */
export interface 『TYPE』 {
  id: number;
  name: string;
}

// ### 『CLASS』
/**
 * 『JS_DOC』
 */
class『CLASS』 {
  // #### Private:
  // ##### Private > Field
  private static 『MEMBER_VARIABLE_1』: 『MEMBER_VARIABLE_TYPE_1』;

  // ##### Private > Method
  private constructor() {
    this.『MEMBER_FUNCTION』 = this.『MEMBER_FUNCTION』.bind(this); // this 바인딩
  }

  // #### Public:
  // ##### Public > Field
  public 『MEMBER_VARIABLE_2』: 『MEMBER_VARIABLE_TYPE_2』;

  // ##### Public > Method
  public 『MEMBER_FUNCTION』():『RETURN_TYPE』 {}
}

// ## Variable & Constant ====================================================

const 『CONSTANT』 = 『CONSTANT_VALUE』;
let 『VARIABLE』 = 『VARIABLE_VALUE』;

// ## Function ===============================================================

// ### 『FUNCTION』
/**
 * 『JS_DOC』
 */
const 『FUNCTION』 = () : 『RETURN_TYPE』 => {
  // #### Variable:
  let 『LOCAL_VARIABLE』 = 0;

  // #### Function:
  (() => 『LOCAL_VARIABLE』++)();

  // #### Return:
  return 『LOCAL_VARIABLE』;
}
```

#### Javascript > React

- React 의 컴포넌트 코드에서는 임포트되는 CSS 또는 스타일 컴포넌트의 정보와 자식 컴포넌트들의 정보가 추가됩니다.
- React 의 컴포넌트 코드에서는 컴포넌트의 스타일 객체가 추가됩니다.
- React 의 컴포넌트 코드에서는 렌더링되는 컴포넌트의 정보가 추가됩니다.

```javascript
// # 『DIRECTORY_PATH』

...

// ## Import Declaration =====================================================

// ### API & Library:
import {『LIBRARY』} from '『LIBRARY_PATH』';

// ### Component:
import {『COMPONENT』} from '『COMPONENT_PATH』';

// ### Style:
import {『STYLE』} from '『STYLE_PATH』';

// ### Asset:
import 『ASSET』 from '『ASSET_PATH』';

...

// ## Style ==================================================================

const 『STYLE_OBJECT』 : CSSProperties = {『CSS_SCRIPT』};
const 『STYLE_COMPONENT』 = Styled.div`『CSS_SCRIPT』`;

// ## Component ==============================================================

// ### 『COMPONENT』
const『COMPONENT』 = () => {
  // #### Variable:

  // #### Function:

  // #### Hook:

  // #### Return:
}
```
